#define LOG_TAG "TestBinderService"

#include "ITestBinderService.h"
#include <utils/String8.h>
#include <utils/Debug.h>
#include <utils/Log.h>

namespace android{

enum {  
    TEST_SET = IBinder::FIRST_CALL_TRANSACTION,
    TEST_GET,  
};

class BpTestBinderService: public BpInterface<ITestBinderService>
{
public:
	BpTestBinderService(const sp<IBinder>& impl)
        : BpInterface<ITestBinderService>(impl)
	{

	}
	int setTest()
	{
		Parcel data, reply;
		int32_t tmp = 100;
		data.writeInterfaceToken(ITestBinderService::getInterfaceDescriptor());
		data.writeInt32(tmp);
		ALOGD("enter BpTestBinderService setTest:%d ",tmp);
		remote()->transact(TEST_SET, data, &reply);
		tmp = reply.readInt32();
		ALOGD("Exit BpTestBinderService setTest:%d ",tmp);
		return tmp;
	}
	int getTest()
	{
		Parcel data, reply;
		data.writeInterfaceToken(ITestBinderService::getInterfaceDescriptor());
		remote()->transact(TEST_GET, data, &reply);
		const char *ptr = reply.readCString();
		ALOGD("enter BpTestBinderService getTest:%s ",ptr);
		return NO_ERROR;
	}
protected:


private:

};


IMPLEMENT_META_INTERFACE(TestBinderService, "android.test.ITestBinderService");

status_t BnTestBinderService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
	switch(code) {
		case TEST_SET: {
			CHECK_INTERFACE(ITestBinderService, data, reply);
			int32_t tmp = data.readInt32();
			ALOGD("enter BnTestBinderService setTest:%d ",tmp);

			tmp = 1;
			reply->writeInt32(tmp);

			ALOGD("Exit BnTestBinderService setTest:%d ",tmp);
			return NO_ERROR;
			} break;
		case TEST_GET: {
			CHECK_INTERFACE(ITestBinderService, data, reply);
			ALOGD("enter BnTestBinderService getTest ");
			reply->writeCString("Test");
			return NO_ERROR;
			} break;
		default:
			return BBinder::onTransact(code, data, reply, flags);
	}
}

}