#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

#include "caliper.h"


void app_main(void)
{
    caliper_init();
    struct caliper* caliper = caliper_add(18, 23);
    assert(caliper);

    while (true) {
        caliper_mode_t mode;
        bool power;
        double value = caliper_value(caliper, &mode, &power);
        if (mode == CALIPER_MODE_INCHES) {
            printf("%0.4f in (%s)\n", value, power ? "on" : "off");
        } else {
            printf("%0.2f mm (%s)\n", value, power ? "on" : "off");
        }
    }
}
