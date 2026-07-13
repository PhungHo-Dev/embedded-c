#include <stdio.h>

void ledOn(void)
{
    printf("LED ON\n");
}

void sendUART(void)
{
    printf("UART SEND\n");
}
static void (*buttonCallback)(void) = NULL;
void Button_RegisterCallback(void (*callback)(void))
{
    buttonCallback = callback;
}
void Button_Pressed(void)
{   
    if(buttonCallback != NULL)
    {
        buttonCallback();
    }
}
int main()
{
    Button_RegisterCallback(ledOn);
    Button_Pressed();
    Button_RegisterCallback(sendUART);
    Button_Pressed();
    return 0;
}