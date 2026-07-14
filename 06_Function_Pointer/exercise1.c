#include<stdio.h>
void ledOn(void)
{
    printf("LED ON\n");
}

void ledOff(void)
{
    printf("LED OFF\n");
}
void ledtoggle(void)
{
    static int state = 0;
    if(state == 0)
    {
        ledOn();
        state = 1;
    }
    else
    {
        ledOff();
        state = 0;
    }
}
void (*ledMode)(void);
int main()
{
    ledMode = ledOn;
    ledMode();
    ledMode = ledOff;
    ledMode();
    ledMode = ledtoggle;
    ledMode();
    ledMode();
    return 0;
}