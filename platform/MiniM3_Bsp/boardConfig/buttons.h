#pragma once
#include <stdint.h>
#include "hardware.h"

static uint8_t KEY_Scan(void)
{
    static uint8_t KEY_UP = 1;
    if (KEY_UP && (KEY1 == 0 || KEY2 == 0))
    {
        //Delay(10); //
        KEY_UP = 0;
        if (KEY1 == 0)
            return 1;
        else if (KEY2 == 0)
            return 2;
    }
    else if (KEY1 == 1 && KEY2 == 1)
        KEY_UP = 1;
    return 0; 
}