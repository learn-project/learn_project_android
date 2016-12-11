/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.server;

import android.app.AppOpsManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.database.ContentObserver;
import android.hardware.input.InputManager;
import android.os.BatteryStats;
import android.os.Handler;
import android.os.IHelloService;
import android.os.PowerManager;
import android.os.Process;
import android.os.RemoteException;
import android.os.IBinder;
import android.os.Binder;
import android.os.ServiceManager;
import android.os.SystemClock;
import android.os.UserHandle;
import android.os.WorkSource;
import android.provider.Settings;
import android.provider.Settings.SettingNotFoundException;
import android.util.Slog;
import android.view.InputDevice;

import com.android.internal.app.IAppOpsService;
import com.android.internal.app.IBatteryStats;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.ListIterator;

public class VehicleService extends IVehicleService.Stub{

	private static final String TAG = "VehicleService";

	native static int native_open();
	native static void native_close();
	native static int native_get_fast_reverse_state();
	native static int native_get_video_signal();
	native static void native_set_video_channel(int channel);
	native static void native_set_bt_power(int on);
	native static void native_set_bt_reset(int on);
	native static void native_set_usb_power(int on);
	native static void native_set_hub_power(int on);
	

	VehicleService(Context context){
		native_open();
	}

	public int get_fast_reverse_state(){
		int ret = 0;
		ret = native_get_fast_reverse_state();
		Slog.i(TAG, "vehicle get_fast_reverse_state[%d]",ret);
		return ret;
	}

	public int get_video_signal(){
		int ret = 0;
		ret = native_get_fast_reverse_state();
		Slog.i(TAG, "vehicle get_video_signal[%d]",ret);
		return ret;
	}

	public void set_video_channel(int channel){
		native_get_fast_reverse_state(channel);
		Slog.i(TAG, "vehicle set_video_channel");
	}

	public void set_bt_power(int on){
		native_get_fast_reverse_state(on);
		Slog.i(TAG, "vehicle set_bt_power[%d]",on);
	}

	public void set_bt_reset(int on){
		native_get_fast_reverse_state(on);
		Slog.i(TAG, "vehicle bt_reset[%d]",on);
	}

	public void set_usb_power(int on){
		native_get_fast_reverse_state(on);
		Slog.i(TAG, "vehicle set_usb_power[%d]",on);
	}

	public void set_hub_power(int on){
		native_get_fast_reverse_state(on);
		Slog.i(TAG, "vehicle set_hub_power[%d]",on);
	}


	protected void finalize()throws java.lang.Throwable{
		native_close();
		super.finalize();		
	}


};
