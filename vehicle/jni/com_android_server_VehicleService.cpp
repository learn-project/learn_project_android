#define LOG_TAG "VehicleService-JNI"

#include "jni.h"
#include "JNIHelp.h"
#include "android_runtime/AndroidRuntime.h"

#include <utils/misc.h>
#include <utils/Log.h>
#include <hardware/hardware.h>
#include <hardware/vehicle.h>

#include <stdio.h>

namespace android
{


static struct vehicle_device_t * vehicle_device;
static jint android_vehicle_open(JNIEnv *env, jclass clazz)
{
        int ret;	
        struct hw_module_t * module;

        ret = hw_get_module("vehicle", (const struct hw_module_t **)&module);
        if(ret)
        {
                ALOGI("get module failed\n");
                return -1;
        }

        hw_device_t* device;
        ret = module->methods->open(module, NULL, &device);
        if(ret)
        {
                ALOGI("device open failed\n");
                return -1;
        }

        vehicle_device = (struct vehicle_device_t *)device;
	if(vehicle_device)
        	vehicle_device->vehicle_open();

        return 0;
}


static void android_vehicle_close(JNIEnv *env, jclass clazz)
{
	if(vehicle_device){
        	vehicle_device->vehicle_close();
		vehicle_device->common.close((hw_device_t*)vehicle_device);	
	}
}

static jint android_vehicle_get_fast_reverse_state(JNIEnv *env, jclass clazz)
{
	jint ret = -1;
	if(vehicle_device)
        	ret = vehicle_device->vehicle_get_fast_reverse_state();	
	return ret;
}

static jint android_vehicle_get_video_signal(JNIEnv *env, jclass clazz)
{
	jint ret = -1;
	if(vehicle_device)
        	ret = vehicle_device->vehicle_get_video_signal();	
	return ret;
}

static void android_vehicle_set_video_channel(JNIEnv *env, jclass clazz,jint channel)
{
	if(vehicle_device)
        	vehicle_device->vehicle_set_video_channel(channel);	
}

static void android_vehicle_set_bt_power(JNIEnv *env, jclass clazz,jint on)
{
	if(vehicle_device)
        	vehicle_device->vehicle_set_bt_power(on);	
}

static void android_vehicle_set_bt_reset(JNIEnv *env, jclass clazz,jint on)
{
	if(vehicle_device)
        	vehicle_device->vehicle_set_bt_reset(on);	
}

static void android_vehicle_set_usb_power(JNIEnv *env, jclass clazz,jint on)
{
	if(vehicle_device)
        	vehicle_device->vehicle_set_usb_power(on);	
}

static void android_vehicle_set_hub_power(JNIEnv *env, jclass clazz,jint on)
{
	if(vehicle_device)
        	vehicle_device->vehicle_set_hub_power(on);	
}

static JNINativeMethod method_table[] = {
    { "native_open", "()I", (void*)android_vehicle_open },
    { "native_close", "()V", (void*)android_vehicle_close },
    { "native_get_fast_reverse_state", "()I", (void*)android_vehicle_get_fast_reverse_state },
    { "native_get_video_signal", "()I", (void*)android_vehicle_get_video_signal },
    { "native_set_video_channel", "(I)V", (void*)android_vehicle_set_video_channel },
    { "native_set_bt_power", "(I)V", (void*)android_vehicle_set_bt_power },
    { "native_set_bt_reset", "(I)V", (void*)android_vehicle_set_bt_reset },
    { "native_set_usb_power", "(I)V", (void*)android_vehicle_set_usb_power },
    { "native_set_hub_power", "(I)V", (void*)android_vehicle_set_hub_power },
};

int register_android_server_VehicleService(JNIEnv *env)
{
    return jniRegisterNativeMethods(env, "com/android/server/VehicleService",method_table, NELEM(method_table));
}

};
