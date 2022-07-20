/*******************************
 * 文件名称：PGA2311.cpp
 * 功能：控制   PGA2311UA  IC 
 * 作者：Mero@tearn
 * 日期：2022年7月20日
 * 版本：0.1 alpha
 * 程序编写参照 PGA2311UA 数据手册：https://www.ti.com.cn/product/cn/PGA2311
 *******************************/

#include<Arduino.h>
#include<PGA2311.h>

PGA2311::PGA2311(byte zpin,byte sclk,byte cs,byte sdi,byte mute):zcen(zpin),sclk(sclk),cs(cs),sdi(sdi),mute(mute)
{
    pinMode(zpin,OUTPUT);
    pinMode(sclk,OUTPUT);
    pinMode(cs,OUTPUT);
    pinMode(sdi,OUTPUT);
    pinMode(mute,OUTPUT);
    digitalWrite(mute,LOW);
    digitalWrite(zcen,HIGH);
}//PGA2311初始化
PGA2311::~PGA2311()
{
    disattach();
}
void PGA2311::disattach()
{
    pinMode(zcen,INPUT);
    pinMode(sclk,INPUT);
    pinMode(cs,INPUT);
    pinMode(sdi,INPUT);
    pinMode(mute,INPUT);
}//解除引脚
void PGA2311::setVolume(uint8_t vol)
{
    volu = vol;
    uint8_t i,j;
    digitalWrite(sclk,0);
    digitalWrite(cs,0);
    delayMicroseconds(1);
    for(i = 0 ; i < 2 ; i ++)
	{
				for(j = 0 ; j < 8 ; j ++)
			{			
  				if((vol<<j)&0x80)	
                    digitalWrite(sdi,1);  
					else
                    digitalWrite(sdi,0);
				    digitalWrite(sclk,1);
                    delayMicroseconds(1);
					digitalWrite(sclk,0);
				    delayMicroseconds(1);
  	  }
			delayMicroseconds(1);
	}
	delayMicroseconds(1);
	digitalWrite(cs,1); //结束传输
}
//!@param vol-音量值 0-255
void PGA2311::setMute()
{
    digitalWrite(mute,LOW);
}
void PGA2311::unSetMute()
{
    digitalWrite(mute,HIGH);
}
uint8_t PGA2311::readVolume()
{
    return volu;
}