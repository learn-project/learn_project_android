#ifndef _vehicle_h_
#define _vehicle_h_

#include <hardware/hardware.h>

struct vehicle_device_t{
    struct hw_device_t common;
    int (*vehicle_open)();
    void (*vehicle_close)();
    int (*vehicle_get_fast_reverse_state)();
    int (*vehicle_get_video_signal)();
    void (*vehicle_set_video_channel)(int channel);
    void (*vehicle_set_bt_power)(int on);
    void (*vehicle_set_bt_reset)(int on);
    void (*vehicle_set_usb_power)(int on);
    void (*vehicle_set_hub_power)(int on);
};



#endif
