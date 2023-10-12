#include <mega32.h>;
#include <i2c.h>;
#include <alcd.h>;
#include <delay.h>;
#include <stdio.h>;
#include <math.h>;
#define I2C_DEVICE_ADDRESS 0xc0 
int i,freq; 
unsigned char scan[4]={0XFE,0XFD,0XFB,0XF7}; 
char 
state,Key,str[8],arrkey[16]={'7','8','9','/','4','5','6','*','1','2','3','-','C','0','=','+'}; 
#define c1 PINB.4 
#define c2 PINB.5 
#define c3 PINB.6 
#define c4 PINB.7 
#define keypad_port PORTB 

char keypad(){ 
    unsigned char r,c,k; 
    DDRB=0X0F; 
    keypad_port=0XFF; 
    while(1){ 
        for (r=0; r<4; r++){ 
            c=255; 
            keypad_port=scan[r]; 
            delay_us(10); 
            if(c1==0) c=0; if(c2==0) c=1; if(c3==0) c=2; if(c4==0) c=3; 
            if (c!=255){ 
                k=arrkey[(r*4)+c]; 
                while(c1==0); while(c2==0); while(c3==0); while(c4==0); 
                delay_ms(50); 
                return k;}}}} 

void SEND_DATA(unsigned int data){ 
    i2c_start(); 
    i2c_write(I2C_DEVICE_ADDRESS); 
    i2c_write(data >> 8); 
    i2c_write(data); 
    i2c_stop();} 

void RECT_PULSE(int freq){ 
    int data,T; 
    T = 2000*3.14/freq; 
    data=0xfff; 
    SEND_DATA(data); 
    delay_ms(T/2); 
    data=0x000; 
    SEND_DATA(data); 
    delay_ms(T/2);} 

void TRI_PULSE(int freq){ 
    int data,T,step; 
    data=0x000; 
    T = 2000*3.14/freq; 
    step = 4096/T; 
    for(i=0;i<=2*T;i++){ 
        if(i>=T){ 
        data = data - step; 
        SEND_DATA(data);} 
        if(i<=T){ 
        data = data + step; 
        SEND_DATA(data);}}} 

void SIN_PULSE(int freq){ 
    float data,F,i; 
    F = 2*3.14*freq; 
    for(i=-F;i<=F;i+=0.001){ 
        data = 2048*sin(freq*i/4)+2048; 
        SEND_DATA(data);}} 

void main(void){ 
    i2c_init(); 
    lcd_init(16); 
    #asm("sei") 
    lcd_clear(); 
    lcd_putsf("choose waveform"); 
    lcd_gotoxy(0,1); 
    lcd_putsf("1rect 2tri 3sin"); 
    Key=keypad(); 
    if (Key == '1'){state = 1;} 
    if (Key == '2'){state = 2;} 
    if (Key == '3'){state = 3;} 

while (1){ 
    lcd_clear(); 
    lcd_putsf("choose freq"); 
    while(1){ 
    Key=keypad(); 
    if(Key== '='){ 
        lcd_clear(); 
        sprintf(str,"freq=%d",freq); 
        lcd_puts(str); 
        switch(state){ 
            case 1:while(1){RECT_PULSE(freq);}break; 
            case 2:while(1){TRI_PULSE(freq);}break; 
            case 3:while(1){SIN_PULSE(freq);}break;}} 
    freq = freq * 10 + Key - 48;lcd_gotoxy(0,1); 
    sprintf(str,"freq=%d",freq);lcd_clear();lcd_puts(str);}}}#include &lt;mega32.h&gt;
#include &lt;i2c.h&gt;
#include &lt;alcd.h&gt;
#include &lt;delay.h&gt;
#include &lt;stdio.h&gt;
#include &lt;math.h&gt;
#define I2C_DEVICE_ADDRESS 0xc0 
int i,freq; 
unsigned char scan[4]={0XFE,0XFD,0XFB,0XF7}; 
char 
state,Key,str[8],arrkey[16]={'7','8','9','/','4','5','6','*','1','2','3','-','C','0','=','+'}; 
#define c1 PINB.4 
#define c2 PINB.5 
#define c3 PINB.6 
#define c4 PINB.7 
#define keypad_port PORTB 

char keypad(){ 
    unsigned char r,c,k; 
    DDRB=0X0F; 
    keypad_port=0XFF; 
    while(1){ 
        for (r=0; r<4; r++){ 
            c=255; 
            keypad_port=scan[r]; 
            delay_us(10); 
            if(c1==0) c=0; if(c2==0) c=1; if(c3==0) c=2; if(c4==0) c=3; 
            if (c!=255){ 
                k=arrkey[(r*4)+c]; 
                while(c1==0); while(c2==0); while(c3==0); while(c4==0); 
                delay_ms(50); 
                return k;}}}} 

void SEND_DATA(unsigned int data){ 
    i2c_start(); 
    i2c_write(I2C_DEVICE_ADDRESS); 
    i2c_write(data >> 8); 
    i2c_write(data); 
    i2c_stop();} 

void RECT_PULSE(int freq){ 
    int data,T; 
    T = 2000*3.14/freq; 
    data=0xfff; 
    SEND_DATA(data); 
    delay_ms(T/2); 
    data=0x000; 
    SEND_DATA(data); 
    delay_ms(T/2);} 

void TRI_PULSE(int freq){ 
    int data,T,step; 
    data=0x000; 
    T = 2000*3.14/freq; 
    step = 4096/T; 
    for(i=0;i<=2*T;i++){ 
        if(i>=T){ 
        data = data - step; 
        SEND_DATA(data);} 
        if(i<=T){ 
        data = data + step; 
        SEND_DATA(data);}}} 

void SIN_PULSE(int freq){ 
    float data,F,i; 
    F = 2*3.14*freq; 
    for(i=-F;i<=F;i+=0.001){ 
        data = 2048*sin(freq*i/4)+2048; 
        SEND_DATA(data);}} 

void main(void){ 
    i2c_init(); 
    lcd_init(16); 
    #asm("sei") 
    lcd_clear(); 
    lcd_putsf("choose waveform"); 
    lcd_gotoxy(0,1); 
    lcd_putsf("1rect 2tri 3sin"); 
    Key=keypad(); 
    if (Key == '1'){state = 1;} 
    if (Key == '2'){state = 2;} 
    if (Key == '3'){state = 3;} 

while (1){ 
    lcd_clear(); 
    lcd_putsf("choose freq"); 
    while(1){ 
    Key=keypad(); 
    if(Key== '='){ 
        lcd_clear(); 
        sprintf(str,"freq=%d",freq); 
        lcd_puts(str); 
        switch(state){ 
            case 1:while(1){RECT_PULSE(freq);}break; 
            case 2:while(1){TRI_PULSE(freq);}break; 
            case 3:while(1){SIN_PULSE(freq);}break;}} 
    freq = freq * 10 + Key - 48;lcd_gotoxy(0,1); 
    sprintf(str,"freq=%d",freq);lcd_clear();lcd_puts(str);}}}
