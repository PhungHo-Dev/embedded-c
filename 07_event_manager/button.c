#include "button.h"
#include "event_manager.h"

void Button_Press(void)
{
    Event_Trigger(EVENT_BUTTON_PRESS);
}