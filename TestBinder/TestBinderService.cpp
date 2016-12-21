
#define LOG_TAG "TestBinderService"

#include <utils/String8.h>
#include <utils/Debug.h>
#include <utils/Log.h>
#include <binder/IServiceManager.h>  
#include "TestBinderService.h"

namespace android{
void TestBinderService::instantiate()
{
	defaultServiceManager()->addService(String16("TestBinder"), new TestBinderService());
}
int TestBinderService::setTest()
{
	ALOGD("TestBinderService setTest");
	return 0;
}
int TestBinderService::getTest()
{
	ALOGD("TestBinderService getTest");
	return 0;
}
TestBinderService::TestBinderService()
{
	ALOGD("TestBinderService ");
}
TestBinderService::~TestBinderService()
{
	ALOGD("~TestBinderService ");
}
}