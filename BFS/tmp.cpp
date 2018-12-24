#include <reg51.h>
#include <absacc.h>
#define uchar unsigned char
#define uint unsigned int                  
#define CON8279   XBYTE[0xCFE9]                
#define DATA8279  XBYTE[0xCFE8]                    
#define DAC_DATA  XBYTE[0xCFB0]                   
#define DAC_START XBYTE[0xCFB1]                   

//正弦波码
uchar code SINTAB[]={0x7f,0x89,0x94,0x9f,0xaa,0xb4,0xbe,0xc8,0xd1,0xd9,0xe0,0xe7,0xed,0xf2,0xf7,0xfa,0xfc,0xfe,0xff};
uchar code keyval[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x10,0x11,0x12,0x13,0x18,0x19,0x1a,0x1b};
uchar code SEG[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};      //1-F
uchar a;
void KbDisInit()
{
    CON8279 = 0xD1;//清除8279显示
    while (CON8279&0x80);//等待清除结束                 
    DATA8279 = 0x34; //设置8279分频系数                  
}

uchar ReadKey()
{
    if(CON8279 & 0x07)//是否有按键按下
    {
        CON8279 = 0x40;
        a = DATA8279;//读键值
    }
    return 0;
}

void Display(uchar y)
{
    CON8279 = 0x80;
    DATA8279= SEG[y];
}

void delay()//延时                                 
{
    uchar i;
    for(i = 0; i < 0xa0; i++);
}




void Sawtooth_Wave()  //锯齿波              
{
    uchar i = 0;
    while(a == 0 && i <= 255){
        DAC_DATA = i++;
        DAC_START = i++;
    }
}

void Triangle_Wave()  //三角波                                    
{
    uchar i = 0;
    DAC_DATA = i;
    DAC_START = i;
    do{
        DAC_DATA = i;
        DAC_START = i;
        i++;
    }while(i<0xff);

    do{
        DAC_DATA = i;
        DAC_START = i;
        i--;
    }while(i>0x0);
}

void Square_Wave()   //方波                                      
{
    DAC_DATA = 0x00;
    DAC_START = 0x00;
    delay();
    DAC_DATA = 0xff;
    DAC_START = 0xff;
    delay();
}

void Sine_Wave()  //正弦波                                    
{
    //这边四个循环，两两一个周期
    uchar i;
    for(i=0;i<18;i++)
        {
            DAC_DATA = SINTAB[i]; 
            DAC_START = SINTAB[i];
        }
    for(i=18;i>0;i--) 
        {
            DAC_DATA = SINTAB[i];
            DAC_START = SINTAB[i];
        }

    for(i=0;i<18;i++)
        {
            DAC_DATA = ~SINTAB[i];
            DAC_START = ~SINTAB[i];
        }
    for(i=18;i>0;i--)
        {
            DAC_DATA = ~SINTAB[i];
            DAC_START = ~SINTAB[i];
        } 
}

void main()
{
        KbDisInit();
        Display(0);                     
        while(1)
        {
            if(CON8279&0x07)
            {
                ReadKey();                              
                a = a-192;
                Display(a);
                
                switch (a)
                {
                case 0:  while(!(CON8279 & 0x07)) //是否有按键按下
                            Sawtooth_Wave();  
                            break;
                case 1: while(!(CON8279 & 0x07)) 
                            Sine_Wave(); 
                            break;
                case 2: while (!(CON8279 & 0x07)) 
                            Square_Wave();  
                            break;
                case 3: while(!(CON8279 & 0x07)) 
                            Triangle_Wave();
                            break;
                }
            }
        }
}