#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

typedef enum
{
    EVENT_BUTTON_PRESS,
    EVENT_UART_RECEIVE,
    EVENT_CAN_RECEIVE,

    EVENT_MAX
} Event_t;

typedef void (*EventCallback_t)(void);

void Event_RegisterCallback(Event_t event, EventCallback_t callback);

void Event_Trigger(Event_t event);

#endif