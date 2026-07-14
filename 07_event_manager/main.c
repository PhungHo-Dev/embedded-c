#include <stdio.h>

#include "button.h"
#include "event_manager.h"

/*================ Application Functions ================*/

void LedOn(void)
{
    printf("LED ON\n");
}

void SendUART(void)
{
    printf("UART SEND\n");
}

/*================ Main ================*/

int main(void)
{
    printf("===== Event Manager Demo =====\n\n");

    Event_RegisterCallback(EVENT_BUTTON_PRESS, LedOn);

    printf("Press Button:\n");
    Button_Press();

    printf("\n");

    Event_RegisterCallback(EVENT_BUTTON_PRESS, SendUART);

    printf("Press Button Again:\n");
    Button_Press();

    return 0;
}