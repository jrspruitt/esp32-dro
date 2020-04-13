#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

#include "caliper.h"


static void caliper_cb(caliper_handle handle, double value, caliper_units_t units, bool power)
{
    if (units == CALIPER_UNITS_MM) {
        printf("%0.2f mm (%s)\n", value, power ? "on" : "off");
    } else {
        printf("%0.4f in (%s)\n", value, power ? "on" : "off");
    }
}

void app_main(void)
{
    caliper_init();

    caliper_handle handle = caliper_add(18, 23, caliper_cb);
    assert(handle);

    double value;
    caliper_units_t units;
    bool power;

    caliper_poll(handle, &value, &units, &power);

    if (units == CALIPER_UNITS_MM) {
        printf("%0.2f mm (%s)\n", value, power ? "on" : "off");
    } else {
        printf("%0.4f in (%s)\n", value, power ? "on" : "off");
    }
}
