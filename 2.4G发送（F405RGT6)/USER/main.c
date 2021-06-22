#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "spi.h"
#include "key.h" 
#include "24l01.h"

//ALIENTEK 探索者STM32F407开发板 实验33
//NRF24L02无线通信实验-库函数版本
//技术支持：www.openedv.com
//淘宝店铺：http://eboard.taobao.com  
//广州市星翼电子科技有限公司  
//作者：正点原子 @ALIENTEK
 
//要写入到W25Q16的字符串数组
const u8 TEXT_Buffer[]={"Explorer STM32F4 SPI TEST"};
#define SIZE sizeof(TEXT_Buffer)	 
	
int main(void)
{ 
	
	u8 key;
  u8 last_value;	
	u8 tmp_buf[20];	
	
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168); 
	uart_init(115200);
	LED_Init();
 	KEY_Init();
 	NRF24L01_Init();

	
	/////检查24l01
	
	while(NRF24L01_Check())
	{
		printf("%s\r\n","NRF24L01 Error");//NRF24L01 Error
		delay_ms(200);
		LED0=!LED0;
		
	}
        printf("%s\r\n","NRF24L01 OK");//NRF24L01 OK
	

	  ////TX模式
						    
		printf("%s\r\n","NRF24L01 TX_Mode");	
		printf("%s\r\n","Sended DATA:");
//		while(1)
//	{ 
//    key=KEY_Scan(1);
//		if(key==NO_KEY)
//		{
//       sprintf((char*)tmp_buf,"0");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;			  
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
//		}
//		else if(key==KEY1_PRES)
//		{
//       sprintf((char*)tmp_buf,"1");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;			  
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
//		}
//		else if(key==KEY2_PRES)
//			
//		{
//            sprintf((char*)tmp_buf,"2");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//发送成功，LED2亮		  
//				
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
//		
//	    }    
//		else if(key==KEY3_PRES)
//			
//		{
//            sprintf((char*)tmp_buf,"3");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//发送成功，LED2亮		  
//				
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     }
//				 }
//    else if(key==KEY4_PRES)
//			
//		{
//            sprintf((char*)tmp_buf,"4");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//发送成功，LED2亮		  
//				
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
//		
//	    } 
//else if(key==KEY5_PRES)
//			
//		{
//      sprintf((char*)tmp_buf,"5");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//发送成功，LED2亮		  
//				
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
//		
//	    } 
//else if(key==KEY6_PRES)
//			
//		{
//            sprintf((char*)tmp_buf,"6");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//发送成功，LED2亮		  
//				
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
//		
//	    } 
//else if(key==KEY7_PRES)
//			
//		{
//            sprintf((char*)tmp_buf,"7");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//发送成功，LED2亮		  
//				
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
//		
//	    } 
////		else if(key==KEY8_PRES)
////			
////		{
////            sprintf((char*)tmp_buf,"+key8");//格式化字符串
////			printf("%s\r\n",tmp_buf);	//显示发送数据	
////		    NRF24L01_TX_Mode();	  			
////			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
////			{	
////				LED0=!LED0;	//发送成功，LED2亮		  
////				
////			}
////			
////			else{										   
////				     printf("%s\r\n","Send Failed");
////			     };			    
////		
////	    } 
////		else if(key==KEY9_PRES)
////			
////		{
////            sprintf((char*)tmp_buf,"+key9");//格式化字符串
////			printf("%s\r\n",tmp_buf);	//显示发送数据	
////		    NRF24L01_TX_Mode();	  			
////			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
////			{	
////				LED0=!LED0;	//发送成功，LED2亮		  
////				
////			}
////			
////			else{										   
////				     printf("%s\r\n","Send Failed");
////			     };			    
////		
////	    } 
////else if(key==KEY10_PRES)
////			
////		{
////            sprintf((char*)tmp_buf,"+key10");//格式化字符串
////			printf("%s\r\n",tmp_buf);	//显示发送数据	
////		    NRF24L01_TX_Mode();	  			
////			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
////			{	
////				LED0=!LED0;	//发送成功，LED2亮		  
////				
////			}
////			
////			else{										   
////				     printf("%s\r\n","Send Failed");
////			     };			    
////		
////	    } 
//else if(key==KEY11_PRES)
//			
//		{
//            sprintf((char*)tmp_buf,"11");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//发送成功，LED2亮		  
//				
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
//		
//	    } 
//else if(key==KEY12_PRES)
//			
//		{
//            sprintf((char*)tmp_buf,"12");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//发送成功，LED2亮		  
//				
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
//		
//	    } ;    		
//		
//	    }    
	/*new*/
			
	while(1)
	{
		
		key=KEY_Scan(1);
	  switch(key)
		{ 
			
			case KEY1_PRES:
		  {
				if(last_value!=KEY1_PRES)
		 {
				sprintf((char*)tmp_buf,"1");//格式化字符串
				printf("%s\r\n",tmp_buf);	//显示发送数据	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//发送成功，LED2亮		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
			
			case KEY2_PRES:
		  {
				if(last_value!=KEY2_PRES)
		 {
				sprintf((char*)tmp_buf,"2");//格式化字符串
				printf("%s\r\n",tmp_buf);	//显示发送数据	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//发送成功，LED2亮		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
			
			case KEY3_PRES:
		  {
				if(last_value!=KEY3_PRES)
		 {
				sprintf((char*)tmp_buf,"3");//格式化字符串
				printf("%s\r\n",tmp_buf);	//显示发送数据	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//发送成功，LED2亮		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
			
			case KEY4_PRES:
		  {
				if(last_value!=KEY4_PRES)
		 {
				sprintf((char*)tmp_buf,"4");//格式化字符串
				printf("%s\r\n",tmp_buf);	//显示发送数据	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//发送成功，LED2亮		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
			
			case KEY5_PRES:
		  {
				if(last_value!=KEY5_PRES)
		 {
				sprintf((char*)tmp_buf,"5");//格式化字符串
				printf("%s\r\n",tmp_buf);	//显示发送数据	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//发送成功，LED2亮		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
			
			
			case KEY6_PRES:
		  {
				if(last_value!=KEY6_PRES)
		 {
				sprintf((char*)tmp_buf,"6");//格式化字符串
				printf("%s\r\n",tmp_buf);	//显示发送数据	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//发送成功，LED2亮		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
			
			case KEY7_PRES:
		  {
				if(last_value!=KEY7_PRES)
		 {
				sprintf((char*)tmp_buf,"7");//格式化字符串
				printf("%s\r\n",tmp_buf);	//显示发送数据	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//发送成功，LED2亮		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
			case KEY11_PRES:
		  {
				if(last_value!=KEY11_PRES)
		 {
				sprintf((char*)tmp_buf,"b");//格式化字符串
				printf("%s\r\n",tmp_buf);	//显示发送数据	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//发送成功，LED2亮		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
			
		
					case KEY12_PRES:
		  {
				if(last_value!=KEY12_PRES)
		 {
				sprintf((char*)tmp_buf,"c");//格式化字符串
				printf("%s\r\n",tmp_buf);	//显示发送数据	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//发送成功，LED2亮		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
		
		//		if(key==NO_KEY)
//		{
//       sprintf((char*)tmp_buf,"0");//格式化字符串
//			printf("%s\r\n",tmp_buf);	//显示发送数据	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;			  
//			}
//			
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
//		}
		
		
			case NO_KEY:
		  {
				if(last_value!=NO_KEY)
		 {
				sprintf((char*)tmp_buf,"0");//格式化字符串
				printf("%s\r\n",tmp_buf);	//显示发送数据	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//发送成功，LED2亮		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
		
		
		
		
		}
	
	
	
	
	
last_value=key;
	}		
			
			
			
   }
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	u8 key;
//	//u8 mode;
//	//u16 t=0;			 
//	u8 tmp_buf[33];	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
//	delay_init(168);  //初始化延时函数
//	uart_init(115200);	//初始化串口波特率为115200
//	LED_Init();					//初始化LED 
// 	//LCD_Init();					//LCD初始化  
// 	KEY_Init();					//按键初始化
// 	NRF24L01_Init();    		//初始化NRF24L01 

//// 	POINT_COLOR=RED;//设置字体为红色 
////	LCD_ShowString(30,50,200,16,16,"Explorer STM32F4");	
////	LCD_ShowString(30,70,200,16,16,"NRF24L01 TEST");	
////	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
////	LCD_ShowString(30,110,200,16,16,"2014/5/9");
//	LED3=0;
//	while(NRF24L01_Check())
//	{
//		LED2=0;
//		//LCD_ShowString(30,130,200,16,16,"NRF24L01 Error");
//		delay_ms(200);
//		//LCD_Fill(30,130,239,130+16,WHITE);
// 		//delay_ms(200);
//	}
//while(1)
//{
//	NRF24L01_TX_Mode();
//	if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//	{
//		u8 TX[5]={1,2,3,4,5};
//	key=KEY_Scan(0);	
//	switch(key)
// {	
//	case '1':
//		tmp_buf[0]=TX[0];
//	break;
//	case '2':
//		tmp_buf[1]=TX[1];
//	break;
// }
//  }
//}
//}
//LCD_ShowString(30,130,200,16,16,"NRF24L01 OK"); 	 
// 	while(1)
//	{	
//		key=KEY_Scan(0);
//		if(key==KEY1_PRES)
//		{
//			mode=0;   
//			break;
//		}else if(key==KEY2_PRES)
//		{
//			mode=1;
//			break;
//		}
//		t++;
//		if(t==100)
//		LED2=!LED2;	            //LCD_ShowString(10,150,230,16,16,"KEY0:RX_Mode  KEY1:TX_Mode"); //闪烁显示提示信息
// 		if(t==200)
//		{	
//			
//			//LCD_Fill(10,150,230,150+16,WHITE);
//			t=0; 
//		}
//		delay_ms(5);	  
//	}   
// 	//LCD_Fill(10,150,240,166,WHITE);//清空上面的显示		  
// 	//POINT_COLOR=BLUE;//设置字体为蓝色	   
//	if(mode==0)//RX模式
//	{
//		//LCD_ShowString(30,150,200,16,16,"NRF24L01 RX_Mode");	
//		//LCD_ShowString(30,170,200,16,16,"Received DATA:");	
//		NRF24L01_RX_Mode();		  
//		while(1)
//		{	  		    		    				 
//			if(NRF24L01_RxPacket(tmp_buf)==0)//一旦接收到信息,则显示出来.
//			{
//				//tmp_buf[32]=0;//加入字符串结束符
//				//LCD_ShowString(0,190,lcddev.width-1,32,16,tmp_buf);    
//			}else delay_us(100);	   
//			t++;
//			if(t==10000)//大约1s钟改变一次状态
//			{
//				t=0;
//				LED3=!LED3;
//			} 				    
//		};	
//	}else//TX模式
//	{							    
//		//LCD_ShowString(30,150,200,16,16,"NRF24L01 TX_Mode");	
//		NRF24L01_TX_Mode();
//		mode=' ';//从空格键开始  
//		while(1)
//		{	  		   				 
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{
//				//LCD_ShowString(30,170,239,32,16,"Sended DATA:");	
//				//LCD_ShowString(0,190,lcddev.width-1,32,16,tmp_buf); 
//				key=mode;
//				for(t=0;t<32;t++)
//				{
//					key++;
//					if(key>('~'))key=' ';
//					tmp_buf[t]=key;	
//				}
//				mode++; 
//				if(mode>'~')mode=' ';  	  
//				tmp_buf[32]=0;//加入结束符		   
//			}else
//			{										   	
// 				//LCD_Fill(0,170,lcddev.width,170+16*3,WHITE);//清空显示			   
//				//LCD_ShowString(30,170,lcddev.width-1,32,16,"Send Failed "); 
//			};
//			LED4=!LED4;
//			delay_ms(1500);				    
//		};
//	}     
//		
//}



