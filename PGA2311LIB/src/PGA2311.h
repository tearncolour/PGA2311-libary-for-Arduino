/*******************************
 * 库名称：PGA2311.h
 * 功能：控制   PGA2311UA  IC 
 * 作者：Mero@tearn
 * 日期：2022年7月20日
 * 版本：0.1 alpha
 * 程序编写参照 PGA2311UA 数据手册：https://www.ti.com.cn/product/cn/PGA2311
 *******************************/
#ifndef _PGA2311_H__
#define _PGA2311_H__

#include<Arduino.h>

class PGA2311
{
private:
    byte zcen;
    byte sclk;
    byte cs;
    byte sdi;
    byte mute;  
    uint8_t volu;
public:
    PGA2311(byte zpin,byte sclk,byte cs,byte sdi,byte mute);
    /********************************
    //!@param zpin-zcen_control_pin
    //!@param sclk-SPI_sclk_pin
    //!@param cs-SPI_cs_pin
    //!@param sdi-SPI_sdi_pin
    //!@param mute-mute_control_pin
     ********************************/
    void setVolume(uint8_t vol);
    //设置音量
    uint8_t readVolume();
    //读取音量
    void setMute();
    //设置为静音模式
    void unSetMute();
    //解除静音模式
    void disattach();
    //解除定义
    ~PGA2311();

};






#endif