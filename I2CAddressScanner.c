#include <reg52.h>
#include "I2C.h"
#include "LCD1602.h"
#include "Delay.h"



unsigned char count;

//Scan IIC address
void I2C_AddressScan() {
    unsigned char address;
    LCD_Init();

    // from 0x00 to 0xFF
    for (address = 0x00; address < 0xFF; address++) {
        I2C_Start();
        I2C_SendByte(address);
        if (!I2C_ReceiveAck()) {
            //delay for clearly see the address change on lcd1602
            Delay(2000);
            count+=1;
            LCD_ShowString(1,1,"0X");
            LCD_ShowHexNum(1,3,address,2);
        }

        // after done , the sum will be shown on the screen
        if(address == 0xFE) {
            LCD_ShowString(2,1, "Count:");
            LCD_ShowNum(2,7,count,3);
        }
        I2C_Stop();
    }
}
