#include "key.h"
#include "delay.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//按键输入驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	 

//按键初始化函数
void KEY_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOB, ENABLE);//使能GPIOA,GPIOE时钟
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_13;//KEY0 KEY1 KEY2对应引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化GPIOE2,3,4
	
	
 // GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;//
	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;//
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP  ;//上拉
  GPIO_Init(GPIOA, &GPIO_InitStructure); //初始化GPIOA0
	
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP  ;//上拉
  GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOA0
  
} 
//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;

//注意此函数有响应优先级,KEY0>KEY1>KEY2>WK_UP!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0||KEY5==0||KEY6==0||KEY7==0||KEY11==0||KEY12==0))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(KEY1==0)return 1;
		else if(KEY2==0)return 2;
		else if(KEY3==0)return 3;
		else if(KEY4==0)return 4;
		else if(KEY5==0)return 5;
		else if(KEY6==0)return 6;
		else if(KEY7==0)return 7;
//		else if(KEY8==0)return 8;
//		else if(KEY9==0)return 9;
//		else if(KEY10==0)return 10;
		else if(KEY11==0)return 11;
		else if(KEY12==0)return 12;
	}
	else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1&&KEY5==1&&KEY6==1&&KEY7==1&&KEY11==1&&KEY12==1)
	key_up=1; 	    
 	return 0;// 无按键按下
}




















