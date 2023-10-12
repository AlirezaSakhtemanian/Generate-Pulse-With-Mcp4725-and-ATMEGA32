# Generate-Pulse-With-Mcp4725-and-ATMEGA32
![VideoCapture_20230216-151927_JSu6XuA](https://github.com/AlirezaSakhtemanian/Generate-Pulse-With-Mcp4725-and-ATMEGA32/assets/133151669/45a36e1d-0f5c-488d-9eb3-14b270d79528)

The MCP4725 is a low-power, high accuracy, single channel, 12-bit buffered voltage output Digital-to-Analog Convertor (DAC) with non-volatile memory(EEPROM). Its on-board precision output amplifier allows it to achieve rail-to-rail analog output swing.The DAC input and configuration data can be programmed to the non-volatile memory (EEPROM) by the user using I2C interface command. The non-volatile memory feature enables the DAC device to hold the DAC input code during power-off time, and the DAC output is available immediately after power-up. This feature is very useful when the DAC device is used as a supporting device for other devices in the network. The device includes a Power-On-Reset (POR) circuit to ensure reliable power-up and an on-board charge pump for the EEPROM programming voltage. The DAC reference is driven from VDD directly. In powerdown mode, the output amplifier can be configured to present a known low, medium, or high resistance output load. The MCP4725 has an external A0 address bit selection pin. This A0 pin can be tied to VDD or VSS of the user’s application board. The MCP4725 has a two-wire I2C™ compatible serial interface for standard (100 kHz), fast (400 kHz), or high speed (3.4 MHz) mode.

Device Addressing
The address byte is the first byte received following the START condition from the master device. The first part of the address byte consists of a 4-bit device code which is set to 1100 for the MCP4725. The device code is followed by three address bits (A2, A1, A0) which are programmed as follows:

The choice of A2 and A1 bits are provided by the customer as part of the ordering process. These bits are then programmed (hard-wired) during manufacturing The A2 and A1 are programmed to ‘00’ (default), if not requested by customer A0 bit is determined by the logic state of A0 pin. The A0 pin can be tied to VDD or VSS, or can be actively driven by digital logic levels. The advantage of using the A0 pin is that the users can control the A0 bit on their application PCB circuit and also two identical MCP4725 devices can be used on the same bus line.

![mcp6](https://github.com/AlirezaSakhtemanian/Generate-Pulse-With-Mcp4725-and-ATMEGA32/assets/133151669/23f6925d-f5a3-4651-9309-04e51515cd3d)
![mcp5](https://github.com/AlirezaSakhtemanian/Generate-Pulse-With-Mcp4725-and-ATMEGA32/assets/133151669/5e8d9127-00f0-4b0d-8daf-4ff3c06527eb)



