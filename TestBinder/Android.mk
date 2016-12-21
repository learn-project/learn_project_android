

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := 	\
	ITestBinderService.cpp \
	TestBinderService.cpp \

LOCAL_LDLIBS += -lpthread
LOCAL_MODULE := libTestBinder
LOCAL_SHARED_LIBRARIES := liblog libcutils libutils libbinder
include $(BUILD_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_SRC_FILES := 	\
	main_TestBinderService.cpp \

LOCAL_MODULE := TestBinderService
LOCAL_SHARED_LIBRARIES := liblog libcutils libutils libbinder libTestBinder
include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)
LOCAL_SRC_FILES := 	\
	main_TestBinderClient.cpp \

LOCAL_MODULE := TestBinderClient
LOCAL_SHARED_LIBRARIES := liblog libcutils libutils libbinder libTestBinder
include $(BUILD_EXECUTABLE)
