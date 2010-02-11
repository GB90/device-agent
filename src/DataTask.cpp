/*
 * DataTask.cpp
 *
 *  Created on: 2009-12-31
 *      Author: mxx
 */

#include "DataTask.h"
#include "TCPPort.h"
#include "SerialPort.h"
#include "PacketQueue.h"
#include "Protocol.h"
#include "pthread.h"
#include <queue>
#include "DebugLog.h"
namespace bitcomm
{

DataTask::DataTask(Protocol& p,Modem& m):protocol(p),modem(m)
{
	pidTask=-1;
}

DataTask::~DataTask()
{

}

void DataTask::SaveData()
{
	if (dataQueue.GetSize())
		dataQueue.Save("./Current.data");
}

void DataTask::run(void)
{
	//Start the thread to read and send data
	TRACE("pidTask=%d",pidTask);
	if (pidTask !=(pthread_t) -1) return;
	TRACE("create thread");
	pthread_create(&pidTask,NULL,DataTask::doProcess,this);
}

void* DataTask::doProcess(void* pThis)
{
	INFO("Started...");
	DataTask& task = *(DataTask*)pThis;
	TCPPort& portServer = task.protocol.GetDataPort();
	SerialPort& portMP = task.protocol.GetMPPort();
	Packet currentData;
	task.dataQueue.Load("./Current.data");
	while(1)
	{
		task.protocol.RequestCurrentData(portMP,currentData);

		task.dataQueue.Push(currentData);
		DEBUG("data queue:%d",task.dataQueue.GetSize());
		if (!task.modem.IsPowerOff())
		{
			task.protocol.SendCurrentData(task.modem,portServer,task.dataQueue);
		}
		currentData.Clear();
		task.protocol.HealthCheck(portMP,currentData);
		task.protocol.HealthCheckReport(portServer,currentData);

		if (portServer.IsOpen())
		{
			portServer.Close();
			INFO("Close data port");
		}
		currentData.Clear();
		task.protocol.PatrolRest();
	};

	return pThis;
}


}
