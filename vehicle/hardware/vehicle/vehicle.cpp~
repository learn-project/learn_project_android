#define LOG_TAG "vehicle-hal"

#include "vehicle.h"

#include <cutils/log.h>
#include <fcntl.h>


#define DEBUG	1
#if DEBUG


#endif


static int fd;

static int vehicle_open()
{
    ALOGI("gonglz:%s", __FUNCTION__);

    fd = open("/dev/zh_dev", O_RDWR);
    if(fd < 0)
    {
        printf("open error");
    }
    
    return 0;
}

static void vehicle_close()
{
    ALOGI("gonglz:%s", __FUNCTION__);

    close(fd);
}
int vehicle_get_fast_reverse_state()
{
    int value = 0;
    int ret = 0;

    ret = ioctl(fd,0x610b,&value);
    if(ret)
	value = 0;
    	
    ALOGI("gonglz:%s ioctl %s value=%d", __FUNCTION__,ret ? "fail" : "success",value);

    return value;
}
int vehicle_get_video_signal()
{
    int value = 0;
    int ret = 0;

    ret = ioctl(fd,0x610A,&value);
    if(ret)
	value = 0;
    	
    ALOGI("gonglz:%s ioctl %s value=%d", __FUNCTION__,ret ? "fail" : "success",value);

    return value;
}
void vehicle_set_video_channel(int channel)
{
    int ret = 0;

    ret = ioctl(fd,0x6001,&channel);
    	
    ALOGI("gonglz:%s ioctl %s channel=%d", __FUNCTION__,ret ? "fail" : "success",channel);
}
void vehicle_set_bt_power(int on)
{
    int ret = 0;

    ret = ioctl(fd,0x6010,&on);

    ALOGI("gonglz:%s ioctl %s on=%d", __FUNCTION__,ret ? "fail" : "success",on);
}
void vehicle_set_bt_reset(int on)
{
    
}
void vehicle_set_usb_power(int on)
{
    int ret = 0;

    ret = ioctl(fd,0x6013,&on);

    ALOGI("gonglz:%s ioctl %s on=%d", __FUNCTION__,ret ? "fail" : "success",on);
}
void vehicle_set_hub_power(int on)
{
    int ret = 0;

    ret = ioctl(fd,0x6013,&on);

    ALOGI("gonglz:%s ioctl %s on=%d", __FUNCTION__,ret ? "fail" : "success",on);
}


int vehicle_device_close(struct hw_device_t* device)
{
	struct vehicle_device_t* dev;

	ALOGI("gonglz:%s", __FUNCTION__);

	dev = (vehicle_device_t*)device;
	free(dev);

	return 0;
}
static int vehicle_device_open(const struct hw_module_t* module, char const* name, struct hw_device_t** device)
{
        static struct vehicle_device_t *dev = NULL;
	

	ALOGI("gonglz:%s", __FUNCTION__);

        dev = (struct vehicle_device_t *)malloc(sizeof(vehicle_device_t));
	dev->common.tag = HARDWARE_DEVICE_TAG;
	dev->common.version = 0;
        dev->common.module = (struct hw_module_t*)module;
	dev->common.close = vehicle_device_close;

        dev->vehicle_open = vehicle_open;
        dev->vehicle_close = vehicle_close;
	dev->vehicle_get_fast_reverse_state = vehicle_get_fast_reverse_state;
	dev->vehicle_get_video_signal = vehicle_get_video_signal;
	dev->vehicle_set_video_channel = vehicle_set_video_channel;
	dev->vehicle_set_bt_power = vehicle_set_bt_power;
	dev->vehicle_set_bt_reset = vehicle_set_bt_reset;
	dev->vehicle_set_usb_power = vehicle_set_usb_power;
	dev->vehicle_set_hub_power = vehicle_set_hub_power;
	
        *device = (struct hw_device_t *)dev;

        return 0;   
}

static struct hw_module_methods_t vehicle_module_methods = {
    .open =  vehicle_device_open,
};


struct hw_module_t HAL_MODULE_INFO_SYM = {
    .tag = HARDWARE_MODULE_TAG,
    .version_major = 1,
    .version_minor = 0,
    .id = "vehicle",
    .name = "vehicle system",
    .author = "gonglz",
    .methods = &vehicle_module_methods,
    .dso =  NULL,
    .reserved = {0},
};

