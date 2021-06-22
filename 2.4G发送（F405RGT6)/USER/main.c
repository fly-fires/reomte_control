#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "spi.h"
#include "key.h" 
#include "24l01.h"

//ALIENTEK ̽����STM32F407������ ʵ��33
//NRF24L02����ͨ��ʵ��-�⺯���汾
//����֧�֣�www.openedv.com
//�Ա����̣�http://eboard.taobao.com  
//������������ӿƼ����޹�˾  
//���ߣ�����ԭ�� @ALIENTEK
 
//Ҫд�뵽W25Q16���ַ�������
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

	
	/////���24l01
	
	while(NRF24L01_Check())
	{
		printf("%s\r\n","NRF24L01 Error");//NRF24L01 Error
		delay_ms(200);
		LED0=!LED0;
		
	}
        printf("%s\r\n","NRF24L01 OK");//NRF24L01 OK
	

	  ////TXģʽ
						    
		printf("%s\r\n","NRF24L01 TX_Mode");	
		printf("%s\r\n","Sended DATA:");
//		while(1)
//	{ 
//    key=KEY_Scan(1);
//		if(key==NO_KEY)
//		{
//       sprintf((char*)tmp_buf,"0");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
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
//       sprintf((char*)tmp_buf,"1");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
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
//            sprintf((char*)tmp_buf,"2");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//���ͳɹ���LED2��		  
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
//            sprintf((char*)tmp_buf,"3");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//���ͳɹ���LED2��		  
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
//            sprintf((char*)tmp_buf,"4");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//���ͳɹ���LED2��		  
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
//      sprintf((char*)tmp_buf,"5");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//���ͳɹ���LED2��		  
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
//            sprintf((char*)tmp_buf,"6");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//���ͳɹ���LED2��		  
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
//            sprintf((char*)tmp_buf,"7");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//���ͳɹ���LED2��		  
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
////            sprintf((char*)tmp_buf,"+key8");//��ʽ���ַ���
////			printf("%s\r\n",tmp_buf);	//��ʾ��������	
////		    NRF24L01_TX_Mode();	  			
////			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
////			{	
////				LED0=!LED0;	//���ͳɹ���LED2��		  
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
////            sprintf((char*)tmp_buf,"+key9");//��ʽ���ַ���
////			printf("%s\r\n",tmp_buf);	//��ʾ��������	
////		    NRF24L01_TX_Mode();	  			
////			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
////			{	
////				LED0=!LED0;	//���ͳɹ���LED2��		  
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
////            sprintf((char*)tmp_buf,"+key10");//��ʽ���ַ���
////			printf("%s\r\n",tmp_buf);	//��ʾ��������	
////		    NRF24L01_TX_Mode();	  			
////			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
////			{	
////				LED0=!LED0;	//���ͳɹ���LED2��		  
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
//            sprintf((char*)tmp_buf,"11");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//���ͳɹ���LED2��		  
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
//            sprintf((char*)tmp_buf,"12");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
//		    NRF24L01_TX_Mode();	  			
//			if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
//			{	
//				LED0=!LED0;	//���ͳɹ���LED2��		  
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
				sprintf((char*)tmp_buf,"1");//��ʽ���ַ���
				printf("%s\r\n",tmp_buf);	//��ʾ��������	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//���ͳɹ���LED2��		  
				
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
				sprintf((char*)tmp_buf,"2");//��ʽ���ַ���
				printf("%s\r\n",tmp_buf);	//��ʾ��������	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//���ͳɹ���LED2��		  
				
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
				sprintf((char*)tmp_buf,"3");//��ʽ���ַ���
				printf("%s\r\n",tmp_buf);	//��ʾ��������	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//���ͳɹ���LED2��		  
				
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
				sprintf((char*)tmp_buf,"4");//��ʽ���ַ���
				printf("%s\r\n",tmp_buf);	//��ʾ��������	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//���ͳɹ���LED2��		  
				
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
				sprintf((char*)tmp_buf,"5");//��ʽ���ַ���
				printf("%s\r\n",tmp_buf);	//��ʾ��������	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//���ͳɹ���LED2��		  
				
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
				sprintf((char*)tmp_buf,"6");//��ʽ���ַ���
				printf("%s\r\n",tmp_buf);	//��ʾ��������	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//���ͳɹ���LED2��		  
				
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
				sprintf((char*)tmp_buf,"7");//��ʽ���ַ���
				printf("%s\r\n",tmp_buf);	//��ʾ��������	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//���ͳɹ���LED2��		  
				
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
				sprintf((char*)tmp_buf,"b");//��ʽ���ַ���
				printf("%s\r\n",tmp_buf);	//��ʾ��������	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//���ͳɹ���LED2��		  
				
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
				sprintf((char*)tmp_buf,"c");//��ʽ���ַ���
				printf("%s\r\n",tmp_buf);	//��ʾ��������	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//���ͳɹ���LED2��		  
				
			}
		 }
//			else{										   
//				     printf("%s\r\n","Send Failed");
//			     };			    
		
	    }break;
		
		//		if(key==NO_KEY)
//		{
//       sprintf((char*)tmp_buf,"0");//��ʽ���ַ���
//			printf("%s\r\n",tmp_buf);	//��ʾ��������	
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
				sprintf((char*)tmp_buf,"0");//��ʽ���ַ���
				printf("%s\r\n",tmp_buf);	//��ʾ��������	
				NRF24L01_TX_Mode();	  			
				if(NRF24L01_TxPacket(tmp_buf)==TX_OK)
			{	
				LED0=!LED0;	//���ͳɹ���LED2��		  
				
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
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
//	delay_init(168);  //��ʼ����ʱ����
//	uart_init(115200);	//��ʼ�����ڲ�����Ϊ115200
//	LED_Init();					//��ʼ��LED 
// 	//LCD_Init();					//LCD��ʼ��  
// 	KEY_Init();					//������ʼ��
// 	NRF24L01_Init();    		//��ʼ��NRF24L01 

//// 	POINT_COLOR=RED;//��������Ϊ��ɫ 
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
//		LED2=!LED2;	            //LCD_ShowString(10,150,230,16,16,"KEY0:RX_Mode  KEY1:TX_Mode"); //��˸��ʾ��ʾ��Ϣ
// 		if(t==200)
//		{	
//			
//			//LCD_Fill(10,150,230,150+16,WHITE);
//			t=0; 
//		}
//		delay_ms(5);	  
//	}   
// 	//LCD_Fill(10,150,240,166,WHITE);//����������ʾ		  
// 	//POINT_COLOR=BLUE;//��������Ϊ��ɫ	   
//	if(mode==0)//RXģʽ
//	{
//		//LCD_ShowString(30,150,200,16,16,"NRF24L01 RX_Mode");	
//		//LCD_ShowString(30,170,200,16,16,"Received DATA:");	
//		NRF24L01_RX_Mode();		  
//		while(1)
//		{	  		    		    				 
//			if(NRF24L01_RxPacket(tmp_buf)==0)//һ�����յ���Ϣ,����ʾ����.
//			{
//				//tmp_buf[32]=0;//�����ַ���������
//				//LCD_ShowString(0,190,lcddev.width-1,32,16,tmp_buf);    
//			}else delay_us(100);	   
//			t++;
//			if(t==10000)//��Լ1s�Ӹı�һ��״̬
//			{
//				t=0;
//				LED3=!LED3;
//			} 				    
//		};	
//	}else//TXģʽ
//	{							    
//		//LCD_ShowString(30,150,200,16,16,"NRF24L01 TX_Mode");	
//		NRF24L01_TX_Mode();
//		mode=' ';//�ӿո����ʼ  
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
//				tmp_buf[32]=0;//���������		   
//			}else
//			{										   	
// 				//LCD_Fill(0,170,lcddev.width,170+16*3,WHITE);//�����ʾ			   
//				//LCD_ShowString(30,170,lcddev.width-1,32,16,"Send Failed "); 
//			};
//			LED4=!LED4;
//			delay_ms(1500);				    
//		};
//	}     
//		
//}



