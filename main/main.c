#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

#include "caliper.h"


static void caliper_cb(caliper_handle handle, caliper_data data)
{
    if (data->units == CALIPER_UNITS_MM) {
        printf("%s,%s,%0.2f,mm\n", data->name, data->power ? "on" : "off", data->value);
    } else {
        printf("%s,%s,%0.4f,in\n", data->name, data->power ? "on" : "off", data->value);
    }
}


void app_main(void)
{
    caliper_init();

    caliper_handle handle = caliper_add("X", 18, 23, caliper_cb);
    assert(handle);

    struct caliper_data data;
    caliper_poll(handle, &data);
    caliper_cb(handle, &data);
}
