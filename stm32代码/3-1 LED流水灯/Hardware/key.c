#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;		//需要读取按键，选择上拉输入
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;  //实际无用
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

uint8_t Key_GetNum(void){
	uint8_t KeyNum = 0;
		
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12) == 1){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12) == 1){
		Delay_ms(20);
		}
		KeyNum=1;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15) == 1){
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15) == 1){
		Delay_ms(20);
		}
		KeyNum=2;
	}
	
	return KeyNum;
}

