

---
  * the signal level for all the connector:
|Voltage|Level|
|:------|:----|
|+3.3V  |H    |
|0V     |L    |

  * Core Pin: the pin number of Core board

  * Out/In is from the view of this board

---

# Control (CN12) #
|**Pin**|**Core Pin**|**Port**_(software view)_|**Name**|**Meaning**|
|:------|:-----------|:------------------------|:-------|:----------|
|1      |        A10 |              PB5        |CTL\_IN2|Shut down,Input|
|2      |        A12 |              PB8        |CTL\_IN1|           |
|3      |        A13 |              PB15       |CTL\_OUT2|Level NG,Output|
|4      |        A15 |              PB17       |CTL\_OUT1|Shut down OK,Output|
|5      |        GND |                         |GND     |Ground     |
|6      |        A17 |              PB21       |/EXT\_RST1|External reset input|

---
# RS232 (CN10) #
|**Pin**|Input-Output|Signal name|Meaning|**Port**_(software view)_|Core Pin|
|:------|:-----------|:----------|:------|:------------------------|:-------|
|1      |O           |TXD2       |Data output，TTL 3.3V|PC12                     |D11     |
|2      |－         |GND        |GROUND |                         |        |
|3      |I           |RXD2       |Data input，TTL 3.3V|PC13                     |D13     |

---
# Status (CN3) #
|Pin|Input-Output|Signal name|Meaning|**Port**_(software view)_|Core Pin|
|:--|:-----------|:----------|:------|:------------------------|:-------|
|1  |－         |GND        |GROUND |                         |        |
|2  |O           |LEDG       |State of communication|PB3                      |A3      |
|3  |O           |LEDR       |State of communication|PB0                      |A4      |
|4  |O           |LEDGMS     |State of communication|PB1                      |A5      |
|5  |O           |ANT3       |Antenna Mark 3|PB2                      |A6      |
|6  |O           |ANT2       |Antenna Mark 2|PB7                      |A7      |
|7  |O           |ANT1       |Antenna Mark 1|PB4                      |A8      |
|8  |O           |PACKET     |Packet service/no service|PB11                     |A9      |