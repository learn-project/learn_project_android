#ifndef _TESTBINDERSERVICE_H_
#define _TESTBINDERSERVICE_H_


#include "ITestBinderService.h"

namespace android{
class TestBinderService : public BnTestBinderService
{
public:
	static void instantiate();
 	virtual int setTest();
	virtual int getTest();
protected:


private:
	TestBinderService();
	~TestBinderService();
};
}
#endif
