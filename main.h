#ifndef MAIN_H
#define MAIN_H

#define STATE_OFF   2
#define STATE_ON    1

typedef enum{

    RED='R',
    ORANGE = 'O',
    GREEN = 'G'

}TRAFFIC_LIGHT;

typedef struct 
{
    int Engine_State;
    char Traffic_Light_Color;

    int Room_Temperature;
    int Engine_Temperature;
    int Engine_Temperature_Controller_State;

    int Speed;
    int AC_State;

}Vehicle;

void TURN_ENGINE_OFF(Vehicle *Copy_Vehicle);
void SET_TRAFFIC_LIGHT_COLOR(Vehicle *Copy_Vehicle);
void SET_ROOM_TEMPERATURE(Vehicle *Copy_Vehicle);
void SET_ENGINE_TEMPERATURE(Vehicle *Copy_Vehicle);


void (*Car_Func_Control[4])(Vehicle *Copy_Vehicle) = {TURN_ENGINE_OFF,SET_TRAFFIC_LIGHT_COLOR,SET_ROOM_TEMPERATURE,SET_ENGINE_TEMPERATURE};

#endif