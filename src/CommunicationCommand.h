/*
 * CommunicationCommand.h
 *
 *  Created on: 2009-12-28
 *      Author: mxx
 */

#ifndef COMMUNICATIONCOMMAND_H_
#define COMMUNICATIONCOMMAND_H_
#include "Packet.h"
namespace bitcomm
{

class CommunicationCommand:public virtual Packet
{
public:
	CommunicationCommand();
	virtual ~CommunicationCommand();

	static const char DataRequest[2];

	void SetCommand(const char* szCmd,unsigned char Machine);

};

}

#endif /* COMMUNICATIONCOMMAND_H_ */
