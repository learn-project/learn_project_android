#ifndef _ITESTBINDERSERVICE_H_
#define _ITESTBINDERSERVICE_H_

#include <utils/RefBase.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android{

class ITestBinderService : public IInterface
{
public:
	DECLARE_META_INTERFACE(TestBinderService);
	virtual int setTest() = 0;
	virtual int getTest() = 0;
	

protected:


private:


};

class BnTestBinderService : public BnInterface<ITestBinderService>
{
public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
};

}
#endif
