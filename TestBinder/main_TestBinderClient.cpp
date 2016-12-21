#define LOG_TAG "TestBinderService"

#include <cutils/log.h>  
#include <utils/Log.h>  
#include <binder/IPCThreadState.h> 
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>  
#include <binder/PermissionCache.h>  
#include <utils/String16.h>
#include "TestBinderService.h"

using namespace android;

int main(int argc, char** argv)
{
    sp<ITestBinderService> mTestBinserService;  
	
    if (mTestBinserService.get() == 0) {  
        sp<IServiceManager> sm = defaultServiceManager();  
        sp<IBinder> binder;  
        do {  
            binder = sm->getService(String16("TestBinder"));  
            if (binder != 0)  
                break;  
                ALOGI("getService fail");  
            usleep(500000); // 0.5 s  
        } while (true);  
        mTestBinserService = interface_cast<ITestBinderService> (binder); 
		if(mTestBinserService == 0)
        	ALOGE("no ITestBinserService!?");  
    }
    mTestBinserService->setTest();
	mTestBinserService->getTest();

	return 0;
}

