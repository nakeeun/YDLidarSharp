#ifndef YDLIDARSDK_H
#define YDLIDARSDK_H
#endif

#include <CYdLidar.h>

extern "C" {
using namespace std;
using namespace ydlidar;

	struct ExportData
	{
		uint32_t pointSize;

		uint64_t stamp;
		LaserConfig Config;
		LaserPoint* Points;
	};

	 extern char* GetLidarPortList();
	 extern void Free(void* pointer);

	//CYLidar
	 extern void* CreateInstance();
	 extern void DestroyInstance(void* instance);

	 extern float GetMaxRange(void* instance);
	 extern void SetMaxRange(void* instance, float value);

	 extern float GetMinRange(void* instance);
	 extern void SetMinRange(void* instance, float value);

	 extern float GetMaxAngle(void* instance);
	 extern void SetMaxAngle(void* instance, float value);

	 extern float GetMinAngle(void* instance);
	 extern void SetMinAngle(void* instance, float value);

	 extern int GetSampleRate(void* instance);
	 extern void SetSampleRate(void* instance, int value);

	 extern float GetScanFrequency(void* instance);
	 extern void SetScanFrequency(void* instance, float value);

	 extern bool GetFixedResolution(void* instance);
	 extern void SetFixedResolution(void* instance, bool value);

	 extern bool GetReversion(void* instance);
	 extern void SetReversion(void* instance, bool value);

	 extern bool GetInverted(void* instance);
	 extern void SetInverted(void* instance, bool value);

	 extern bool GetAutoReconnect(void* instance);
	 extern void SetAutoReconnect(void* instance, bool value);

	 extern int GetSerialBaudrate(void* instance);
	 extern void SetSerialBaudrate(void* instance, int value);

	 extern int GetAbnormalCheckCount(void* instance);
	 extern void SetAbnormalCheckCount(void* instance, int value);

	 extern char* GetSerialPort(void* instance);
	 extern void SetSerialPort(void* instance, char* value);

	 extern float GetOffsetTime(void* instance);
	 extern void SetOffsetTime(void* instance, float value);

	 extern bool GetSingleChannel(void* instance);
	 extern void SetSingleChannel(void* instance, bool value);

	 extern int GetLidarType(void* instance);
	 extern void SetLidarType(void* instance, int value);

	 extern bool Initialize(void* instance);

	 extern bool TurnOn(void* instance);
	 extern bool TurnOff(void* instance);

	 extern void Disconnecting(void* instance);

	 extern float GetAngleOffset(void* instance);
	 extern bool IsAngleOffsetCorrected(void* instance);
	 extern char* GetSoftVersion(void* instance);
	 extern char* GetHardwareVersion(void* instance);
	 extern char* GetSerialNumber(void* instance);

	 extern void* GetData(void* instance);
}
