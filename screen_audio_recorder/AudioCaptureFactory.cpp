
#include "stdafx.h"
#include "system_info.h"
#include "CWASAudioCapture.h"
#include "CWAVEAudioCapture.h"

namespace MediaFileRecorder
{
	IAudioCapture* CreateAudioCapture(DEV_TYPE devType)
	{
		IAudioCapture* pAudioCapture = NULL;
		SystemInfo systemInfo;
		if (systemInfo.windows_version() >= SystemInfo::WINDOWS_VISTA) // VISTA之后的系统用WAS
		{
			pAudioCapture = new CWASAudioCapture(devType);
		}
		else
		{
			pAudioCapture = new CWAVEAudioCapture(devType);
		}
		return pAudioCapture;
	}


	void DestroyAudioCatpure(IAudioCapture* pAudioCapture)
	{
		delete pAudioCapture;
	}

}