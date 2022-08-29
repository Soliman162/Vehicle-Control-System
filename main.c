#include <stdio.h>
#include"main.h"


int main(void)
{
    int Iterator = 0;
    Vehicle Car = {STATE_OFF,RED,0,0,STATE_OFF,0,STATE_OFF};

    while (1)
    {
        printf("Please Choose one of the following:-\n");
        printf("\t1-Turn on the Vehicle Engine\n");
        printf("\t2-Turn off the Vehicle Engine\n");
        printf("\t3-Quit the system\n");
        printf("\tEnter number: ");
        scanf("%d",&Car.Engine_State);

        if( Car.Engine_State == STATE_ON )
        {
            printf("Turn on the Vehicle Engine\n");
            while (Car.Engine_State == STATE_ON)
            {
                printf("Sensor Menu:-\n");
                printf("\t1-Turn off the engine\n");
                printf("\t2-Set the Traffic Light\n");
                printf("\t3-Set the room temperature\n");
                printf("\t4-Set the engine temperature\n");
                printf("\tEnter number: ");
                scanf("%d",&Iterator);

                Car_Func_Control[Iterator-1](&Car);
            }

        }else if(Car.Engine_State == STATE_OFF)
        {
            printf("Turn off the Vehicle Engine\n");
            continue;

        }else
        {
            printf("Quit the system\n");
            break;
        }
    }
    return 0;
}


/***********************************************************************************************************/
static void SET_SPEED(Vehicle *Copy_Vehicle)
{
    switch (Copy_Vehicle->Traffic_Light_Color)
    {
        case ORANGE:
            Copy_Vehicle->Speed = 30;
            Copy_Vehicle->AC_State = STATE_ON;
            Copy_Vehicle->Engine_Temperature_Controller_State = STATE_ON;

            Copy_Vehicle->Room_Temperature = Copy_Vehicle->Room_Temperature * 1.25 +1;
            Copy_Vehicle->Engine_Temperature = Copy_Vehicle->Engine_Temperature* 1.25 +1;

        break;
        case RED:
            Copy_Vehicle->Speed = 0;
        break;
        case GREEN:
            Copy_Vehicle->Speed = 100;
        break;

    }
}
/***********************************************************************************************************/

static void AC_CONTROL(Vehicle *Copy_Vehicle)
{
    if( Copy_Vehicle->Room_Temperature<10 || Copy_Vehicle->Room_Temperature>30 )
    {
        Copy_Vehicle->AC_State = STATE_ON;
        Copy_Vehicle->Room_Temperature = 20;
        
    }else
    {
        Copy_Vehicle->AC_State = STATE_OFF;
    }
}
/***********************************************************************************************************/

static void DISPLAY_CAR_STATUS(Vehicle Copy_Vehicle)
{
    if(Copy_Vehicle.Engine_State==STATE_ON){printf("-Engine is ON\n");}
    else{printf("-Engine is OFF\n");}

    if(Copy_Vehicle.AC_State==STATE_ON){printf("-AC is ON\n");}
    else{printf("-AC is OFF\n");}

    printf("-Car Speed is %d\n",Copy_Vehicle.Speed);
    printf("-Room temperature is %d\n",Copy_Vehicle.Room_Temperature);

    if(Copy_Vehicle.Engine_Temperature_Controller_State==STATE_ON){printf("-Engine Temperature Controller is ON\n");}
    else{printf("-Engine Temperature Controller is OFF\n");}

    printf("-Engine Temperature is %d\n",Copy_Vehicle.Engine_Temperature);
}
/***********************************************************************************************************/

static void SET_ENGINE_TEMPERATURE_CONTROLLER(Vehicle *Copy_Vehicle)
{
    if(Copy_Vehicle->Engine_Temperature<100 || Copy_Vehicle->Engine_Temperature>150)
    {
        Copy_Vehicle->Engine_Temperature_Controller_State = STATE_ON;
        Copy_Vehicle->Engine_Temperature = 125;
    }else
    {
        Copy_Vehicle->Engine_Temperature_Controller_State = STATE_OFF;
    }
}
/***********************************************************************************************************/

void TURN_ENGINE_OFF(Vehicle *Copy_Vehicle)
{
    Copy_Vehicle->Engine_State = STATE_OFF;
}
/***********************************************************************************************************/

void SET_TRAFFIC_LIGHT_COLOR(Vehicle *Copy_Vehicle)
{
    printf("Which Color do you want?\n");
    printf("\t*O-->Orange");
    printf("\t*R-->Red");
    printf("\t*G-->Green\n");
    printf("Choose Color; ");
    scanf(" %c",&Copy_Vehicle->Traffic_Light_Color);

    SET_SPEED(Copy_Vehicle);
    DISPLAY_CAR_STATUS(*Copy_Vehicle);
}
/***********************************************************************************************************/

void SET_ROOM_TEMPERATURE(Vehicle *Copy_Vehicle)
{
    printf("please enter room Temperature: ");
    scanf("%d",&Copy_Vehicle->Room_Temperature);
    AC_CONTROL(Copy_Vehicle);

    SET_SPEED(Copy_Vehicle);

    DISPLAY_CAR_STATUS(*Copy_Vehicle);
}
/***********************************************************************************************************/

void SET_ENGINE_TEMPERATURE(Vehicle *Copy_Vehicle)
{
    printf("please enter engine Temperature: ");
    scanf("%d",&Copy_Vehicle->Engine_Temperature);
    SET_ENGINE_TEMPERATURE_CONTROLLER(Copy_Vehicle);

    SET_SPEED(Copy_Vehicle);

    DISPLAY_CAR_STATUS(*Copy_Vehicle);
}
