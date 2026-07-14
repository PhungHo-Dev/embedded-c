#include "event_manager.h"

static EventCallback_t eventCallback[EVENT_MAX] = {0};

void Event_RegisterCallback(Event_t event, EventCallback_t callback)
{
    if (event < EVENT_MAX)
    {
        eventCallback[event] = callback;
    }
}

void Event_Trigger(Event_t event)
{
    if (event < EVENT_MAX && eventCallback[event] != 0)
    {
        eventCallback[event]();
    }
}