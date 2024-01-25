#include "tim.h"
#include "sys.h"
int Second = 0;
void TIM3_Init(u16 arr,u16 psc){
	TIM_TimeBaseInitTypeDef TIM_BaseInitstructure;
	NVIC_InitTypeDef NVIC_Initstructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_BaseInitstructure.TIM_Period=arr-1;  //������װ��ֵ
	TIM_BaseInitstructure.TIM_Prescaler=psc-1; //����Ԥ��Ƶϵ��
	TIM_BaseInitstructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_BaseInitstructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3,&TIM_BaseInitstructure);
	
	NVIC_Initstructure.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_Initstructure.NVIC_IRQChannelPreemptionPriority=0x00;
	NVIC_Initstructure.NVIC_IRQChannelSubPriority=0x00;
	NVIC_Initstructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_Initstructure);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	TIM_Cmd(TIM3,ENABLE);
}
void Second_goes(){
	Second++;
}

void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //����ж�
	{
		Second_goes();
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //����жϱ�־λ
}

