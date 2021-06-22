#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h" 
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

/*下面的方式是通过直接操作库函数方式读取IO*/
#define KEY1 		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1) //PE4
#define KEY2 		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)	//PE3 
#define KEY3 		GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3) //PE2
#define KEY4  	GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)	//PA0
#define KEY5  	GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0)	//PA0
#define KEY6  	GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)	//PA0
#define KEY7  	GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)	//PA0
//#define KEY8  	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)	//PA0
//#define KEY9  	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_11)	//PA0
//#define KEY10  	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_12)	//PA0
#define KEY11 	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)	//PA0
#define KEY12 	GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_10)	//PA0


/*下面方式是通过位带操作方式读取IO*/
/*
#define KEY0 		PEin(4)   	//PE4
#define KEY1 		PEin(3)		//PE3 
#define KEY2 		PEin(2)		//P32
#define WK_UP 	PAin(0)		//PA0
*/

#define NO_KEY      0
#define KEY1_PRES 	1
#define KEY2_PRES	  2
#define KEY3_PRES	  3
#define KEY4_PRES   4
#define KEY5_PRES   5
#define KEY6_PRES   6
#define KEY7_PRES   7
//#define KEY8_PRES   8
//#define KEY9_PRES   9
//#define KEY10_PRES   10
#define KEY11_PRES   11
#define KEY12_PRES   12
void KEY_Init(void);	//IO初始化
u8 KEY_Scan(u8);  		//按键扫描函数	

#endif
