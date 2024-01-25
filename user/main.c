#include "stm32f4xx.h"
#include "delay.h"
#include "oled.h"
#include  "iic1.h"
#include "i2c.h"
#include "tim.h"
extern int Second;
int Minute=0;
int Hour=0;

int main(void){
  delay_init(168);
	I2C1_Init();
	OLED_Init();
	OLED_Clear();
	TIM3_Init(10000,8400);
while(1){
	
	if(Second >= 60){
		Second = 0;
		Minute++;
	}
	if(Minute >= 60){
		Minute = 0;
		Hour++;
	}
	if(Hour>=24){
		Hour = 0;
	}
	OLED_ShowChar(1,4,'H');
	OLED_ShowChar(1,8,'M');
	OLED_ShowChar(1,12,'S');
	OLED_ShowSignedNum(3,3,Hour,2);
	OLED_ShowChar(3,6,':');
	OLED_ShowSignedNum(3,7,Minute,2);
	OLED_ShowChar(3,10,':');
	OLED_ShowSignedNum(3,11,Second,2);
	}
}