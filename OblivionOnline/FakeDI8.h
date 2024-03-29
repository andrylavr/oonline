#pragma once
/*

Copyright(c) 2007-2010   Julian Bangert 

This file is part of OblivionOnline.

    OblivionOnline is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    OblivionOnline is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	Linking OblivionOnline statically or dynamically with other modules is making a combined work based
	on OblivionOnline. Thus, the terms and conditions of the GNU General Public License cover 
	the whole combination.

    In addition, as a special exception, the copyright holders of  OblivionOnline give you permission to 
	combine OblivionOnline program with free software programs or libraries that are released under
	the GNU LGPL and with code included in the standard release of Oblivion Script Extender by Ian Patterson (OBSE)
	under the OBSE license (or modified versions of such code, with unchanged license). You may copy and distribute such a system 
	following the terms of the GNU GPL for  OblivionOnline and the licenses of the other code concerned,
	provided that you include the source code of that other code when and as the GNU GPL
	requires distribution of source code.

	Note that people who make modified versions of  OblivionOnline are not obligated to grant this special exception
	for their modified versions; it is their choice whether to do so. 
	The GNU General Public License gives permission to release a modified version without this
	exception; this exception also makes it possible to release a modified version which carries 
	forward this exception.
*/
#include <dinput.h>
#include "InputHook.h"
CEGUI::utf32 keycodeToUTF32( unsigned int scanCode);
//based on a tutorial by Muhammad Hajag , his fingers are in pain for writing all the methods - thank you ;)
#define min(a,b)            (((a) < (b)) ? (a) : (b))
static const GUID GUID_SysMouse    = { 0x6F1D2B60, 0xD5A0, 0x11CF, { 0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00} };
static const GUID GUID_SysKeyboard = { 0x6F1D2B61, 0xD5A0, 0x11CF, { 0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00} };
#define KEYDOWN(name, key) (name[key] & 0x80)

bool SendButton_Click();
class MyDirectInputDevice8: public IDirectInputDevice8
{
public:
	MyDirectInputDevice8(IDirectInputDevice8* device, bool Keyboard) : m_device(device)
	{
		bIsKeyboard = Keyboard;
	}

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(REFIID riid, void** ppvObj)
	{
		return m_device->QueryInterface(riid, ppvObj);
	}

	STDMETHOD_(ULONG,AddRef)()
	{
		return m_device->AddRef();
	}

	STDMETHOD_(ULONG,Release)()
	{
		ULONG count = m_device->Release();
		if(0 == count)
			delete this;

		return count;
	}

	/*** IDirectInputDevice8 methods ***/
	STDMETHOD(GetCapabilities)(LPDIDEVCAPS devCaps)
	{
		return m_device->GetCapabilities(devCaps);
	}

	STDMETHOD(EnumObjects)(LPDIENUMDEVICEOBJECTSCALLBACK callback, LPVOID ref, DWORD flags)	
	{
		return m_device->EnumObjects(callback, ref, flags);
	}

	STDMETHOD(GetProperty)(REFGUID rguid, LPDIPROPHEADER ph)
	{
		return m_device->GetProperty(rguid, ph);
	}

	STDMETHOD(SetProperty)(REFGUID rguid, LPCDIPROPHEADER ph)
	{
		return m_device->SetProperty(rguid, ph);
	}

	STDMETHOD(Acquire)()
	{
		return m_device->Acquire();
	}

	STDMETHOD(Unacquire)()
	{
		return m_device->Unacquire();
	}

	STDMETHOD(GetDeviceState)(DWORD size, LPVOID data)
	{
		static BYTE LastKeyState[256];
		static BYTE KeyState[256];
		static BYTE LastMouseButtons[8];
		static bool MaskedMouseButtons[8];
		static bool MaskedKeys[256];
		static bool InputEnabled = true;
		HRESULT hr = m_device->GetDeviceState(size, data);

		if(SUCCEEDED(hr) && CEGUI::System::getSingletonPtr())
		{
			if(bIsKeyboard)
			{
				BYTE* keys = static_cast<BYTE*>(data);	
				if(KEYDOWN(keys,DIK_F1))
					InputEnabled = !InputEnabled;
				for(int i = 0;i < 256;i++)
				{
					//iterate all keys
					if(KEYDOWN(keys,i) == KEYDOWN(LastKeyState,i))
						continue;
					//we detected a change
					LastKeyState[i] = keys[i];
					if(KEYDOWN(keys,i)) // Button pressed
					{

						bool  function = CEGUI::System::getSingleton().injectKeyDown(i);
						if(i == DIK_RSHIFT || i == DIK_LSHIFT || i== DIK_BACKSPACE)
							continue;
						if(i == DIK_RETURN)
						{
							//Send chat
							SendButton_Click();
							continue;
						}
						bool  text = false;
						CEGUI::utf32 temp = keycodeToUTF32(i);
						_MESSAGE("Key pressed %u as key %u",i,temp);
						if(temp > 32 || temp < 126)	//ASCII printable characters
									text     =CEGUI::System::getSingleton().injectChar(temp);
						if(function || text) //either was processed - do not concenate to prevent tuning from compiler that would break it 
						{
							//Drop the input from the game
							MaskedKeys[i] = true;
						}
					}
					else
					{
						CEGUI::System::getSingleton().injectKeyUp(i);
						if(MaskedKeys[i] == true)
							MaskedKeys[i] = false;
					}
				}
				for(int i = 0;i<256;i++)
				{
					if(MaskedKeys[i])
						keys[i] = 0;
				}
			}
			else
			{
				DIMOUSESTATE2 * mousedata = (LPDIMOUSESTATE2)data;
				DIPROPDWORD AxisMode;
				int mousewheel = 0;
				AxisMode.diph.dwHeaderSize	= sizeof(DIPROPHEADER);
				AxisMode.diph.dwHow			= DIPH_DEVICE;
				AxisMode.diph.dwObj			= 0;
				AxisMode.diph.dwSize		= sizeof(DIPROPDWORD);
				this->GetProperty(DIPROP_AXISMODE,&AxisMode.diph);				
				if(AxisMode.dwData == DIPROPAXISMODE_ABS)
				{
					CEGUI::System::getSingleton().injectMousePosition(mousedata->lX,mousedata->lY);
					CEGUI::System::getSingleton().injectMouseWheelChange(mousewheel - mousedata->lZ);
					mousewheel = mousedata->lZ;
				}
				else if(AxisMode.dwData == DIPROPAXISMODE_REL)
				{					
					CEGUI::System::getSingleton().injectMouseMove(mousedata->lX,mousedata->lY);
					CEGUI::System::getSingleton().injectMouseWheelChange(mousedata->lZ);
				}
				else
				{
					_ERROR("Incompatible Mouse Axis Mode detected");
				}
				//mouse buttons
				/*if( memcmp(LastMouseButtons,mousedata->rgbButtons,8) )
				{*/
				/*_MESSAGE("Mouse status : old / %u %u %u %u %u %u %u %u   new / %u %u %u %u %u %u %u %u",
					LastMouseButtons[1],LastMouseButtons[2],LastMouseButtons[3],LastMouseButtons[4],
					LastMouseButtons[5],LastMouseButtons[6],LastMouseButtons[7],LastMouseButtons[8],
					mousedata->rgbButtons[1],mousedata->rgbButtons[2],mousedata->rgbButtons[3],
					mousedata->rgbButtons[4],mousedata->rgbButtons[5],mousedata->rgbButtons[6],
					mousedata->rgbButtons[7],mousedata->rgbButtons[8]); */
					for(int i = 0; i < min(CEGUI::MouseButton::MouseButtonCount,8);i++) 
					{
						if(LastMouseButtons[i] == mousedata->rgbButtons[i]) // no change here
							continue;						
						if(LastMouseButtons[i]) // The button was released
						{
							if(MaskedMouseButtons[i])
								MaskedMouseButtons[i] = false;
							CEGUI::System::getSingleton().injectMouseButtonUp((CEGUI::MouseButton)i);
						}
						else //The button was pressed
						{
							if(CEGUI::System::getSingleton().injectMouseButtonDown((CEGUI::MouseButton)i))
								MaskedMouseButtons[i] = true;
						}
					}
					memcpy(LastMouseButtons,mousedata->rgbButtons,8);
					for(int i = 0; i< 8;i++)
					{
						if(MaskedMouseButtons[i])
							mousedata->rgbButtons[i] = 0;
					}
				//}
			}
		}

		return hr;
	}

	STDMETHOD(GetDeviceData)(DWORD size, LPDIDEVICEOBJECTDATA data, LPDWORD numElements, DWORD flags)
	{
		return m_device->GetDeviceData(size, data, numElements, flags);
	}

	STDMETHOD(SetDataFormat)(LPCDIDATAFORMAT df)
	{
		return m_device->SetDataFormat(df);
	}

	STDMETHOD(SetEventNotification)(HANDLE event)
	{
		return m_device->SetEventNotification(event);
	}

	STDMETHOD(SetCooperativeLevel)(HWND window, DWORD level)
	{
		return m_device->SetCooperativeLevel(window, level);
	}

	STDMETHOD(GetObjectInfo)(LPDIDEVICEOBJECTINSTANCE object, DWORD objId, DWORD objHow)
	{
		return m_device->GetObjectInfo(object, objId, objHow);
	}

	STDMETHOD(GetDeviceInfo)(LPDIDEVICEINSTANCE di)
	{
		return m_device->GetDeviceInfo(di);
	}

	STDMETHOD(RunControlPanel)(HWND owner, DWORD flags)
	{
		return m_device->RunControlPanel(owner, flags);
	}

	STDMETHOD(Initialize)(HINSTANCE instance, DWORD version, REFGUID rguid)
	{
		return m_device->Initialize(instance, version, rguid);
	}

	STDMETHOD(CreateEffect)(REFGUID rguid, LPCDIEFFECT effect_params, LPDIRECTINPUTEFFECT* effect, LPUNKNOWN unknown)
	{
		return m_device->CreateEffect(rguid, effect_params, effect, unknown);
	}

    STDMETHOD(EnumEffects)(LPDIENUMEFFECTSCALLBACK callback, LPVOID ref, DWORD type)
	{
		return m_device->EnumEffects(callback, ref, type);
	}

    STDMETHOD(GetEffectInfo)(LPDIEFFECTINFO effect_info, REFGUID rguid)
	{
		return m_device->GetEffectInfo(effect_info, rguid);
	}

    STDMETHOD(GetForceFeedbackState)(LPDWORD state)
	{
		return m_device->GetForceFeedbackState(state);
	}

    STDMETHOD(SendForceFeedbackCommand)(DWORD flags)
	{
		return m_device->SendForceFeedbackCommand(flags);
	}

    STDMETHOD(EnumCreatedEffectObjects)(LPDIENUMCREATEDEFFECTOBJECTSCALLBACK callback, LPVOID ref, DWORD flags)
	{
		return m_device->EnumCreatedEffectObjects(callback, ref, flags);
	}

    STDMETHOD(Escape)(LPDIEFFESCAPE escape)
	{
		return m_device->Escape(escape);
	}

    STDMETHOD(Poll)()
	{
		return m_device->Poll();
	}

	STDMETHOD(SendDeviceData)(DWORD size, LPCDIDEVICEOBJECTDATA data, LPDWORD num_elements, DWORD flags)
	{
		return m_device->SendDeviceData(size, data, num_elements, flags);
	}

	STDMETHOD(EnumEffectsInFile)(LPCTSTR file_name, LPDIENUMEFFECTSINFILECALLBACK callback, LPVOID ref, DWORD flags)
	{
		return m_device->EnumEffectsInFile(file_name, callback, ref, flags);
	}

    STDMETHOD(WriteEffectToFile)(LPCTSTR file_name, DWORD num_entries, LPDIFILEEFFECT effects, DWORD flags)
	{
		return m_device->WriteEffectToFile(file_name, num_entries, effects, flags);
	}

    STDMETHOD(BuildActionMap)(LPDIACTIONFORMAT format, LPCTSTR username, DWORD flags)
	{
		return m_device->BuildActionMap(format, username, flags);
	}

    STDMETHOD(SetActionMap)(LPDIACTIONFORMAT format, LPCTSTR username, DWORD flags)
	{
		return m_device->SetActionMap(format, username, flags);
	}

    STDMETHOD(GetImageInfo)(LPDIDEVICEIMAGEINFOHEADER image_header)
	{
		return m_device->GetImageInfo(image_header);
	}

private:
	IDirectInputDevice8* m_device;	
	bool bIsKeyboard;
};

// The DI 8 Interface



class MyDirectInput8 : public IDirectInput8
{
public:
	MyDirectInput8(void* di) : m_di((IDirectInput8 *)di)
	{
		_MESSAGE("Fake constructor called");
	}

	/*** IUnknown methods ***/
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObj)
	{
		_MESSAGE("Fake QueryInterface called");
		return m_di->QueryInterface(riid, ppvObj);
	}

    ULONG STDMETHODCALLTYPE AddRef()
	{
		_MESSAGE("Fake AddRef called");
		return m_di->AddRef();
	}

    ULONG STDMETHODCALLTYPE Release()
	{
		_MESSAGE("Fake Release");
		ULONG count = m_di->Release();
		if(0 == count)
			delete this;

		return count;
	}

    /*** IDirectInput8 methods ***/
    STDMETHOD(CreateDevice)(REFGUID rguid, IDirectInputDevice8** device, LPUNKNOWN unknown)
	{
		HRESULT hr = m_di->CreateDevice(rguid, device, unknown);
		if(SUCCEEDED(hr) && rguid == GUID_SysKeyboard)
		{
			_MESSAGE("Fake keyboard created");
			// Return our own keyboard device that checks for injected keypresses
			*device = new MyDirectInputDevice8(*device,true);
		}
		else if(SUCCEEDED(hr) &&rguid == GUID_SysMouse)
		{
			_MESSAGE("Fake mouse created");			
			*device = new MyDirectInputDevice8(*device,false);
		}
		_MESSAGE("Leaving Fake CreateDevice");
		return hr;
	}

    STDMETHOD(EnumDevices)(DWORD devType,LPDIENUMDEVICESCALLBACK callback, LPVOID ref, DWORD flags)
	{
		return m_di->EnumDevices(devType, callback, ref, flags);
	}

    STDMETHOD(GetDeviceStatus)(REFGUID rguid)
	{
		return m_di->GetDeviceStatus(rguid);
	}

    STDMETHOD(RunControlPanel)(HWND owner, DWORD flags)
	{
		return m_di->RunControlPanel(owner, flags);
	}

    STDMETHOD(Initialize)(HINSTANCE instance, DWORD version)
	{
		return m_di->Initialize(instance, version);
	}

    STDMETHOD(FindDevice)(REFGUID rguid, LPCTSTR name, LPGUID guidInstance)
	{
		return m_di->FindDevice(rguid, name, guidInstance);
	}

    STDMETHOD(EnumDevicesBySemantics)(LPCTSTR username, LPDIACTIONFORMAT action,
		LPDIENUMDEVICESBYSEMANTICSCB callback, LPVOID ref, DWORD flags)
	{
		_MESSAGE("Fake EnumDevices called");
		return m_di->EnumDevicesBySemantics(username, action, callback, ref, flags);
	}

    STDMETHOD(ConfigureDevices)(LPDICONFIGUREDEVICESCALLBACK callback, LPDICONFIGUREDEVICESPARAMS params,
		DWORD flags, LPVOID ref)
	{
		return m_di->ConfigureDevices(callback, params, flags, ref);
	}

private:
	IDirectInput8* m_di;
};