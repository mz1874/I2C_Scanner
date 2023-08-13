#ifndef __IIC_ADDRESS_SCANNER_H__
#define __IIC_ADDRESS_SCANNER_H__

//define IIC port
sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;


void I2C_AddressScan();


#endif