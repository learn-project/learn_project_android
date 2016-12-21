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
	sp<ProcessState> proc(ProcessState::self());
	sp<IServiceManager> sm = defaultServiceManager();

	//sm->addService(String16("TestBinder"), new TestBinderService());
	TestBinderService::instantiate();
	
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}

