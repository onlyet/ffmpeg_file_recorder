#ifndef CSCREENAUDIORECORD_H
#define CSCREENAUDIORECORD_H

#include "IScreeAudioRecord.h"
#include "IMediaFileRecorder.h"
#include "IScreenGrabber.h"
#include "IAudioCapture.h"

namespace MediaFileRecorder
{
	// 录屏接口类，UI直接调用
	class CScreenAudioRecord : public IScreenAudioRecord,
		                       public IScreenGrabberDataCb,
							   public IAudioCaptureDataCb
	{
	public:
		CScreenAudioRecord();
		~CScreenAudioRecord();

		void SetLogCb();
		int SetRecordInfo(const RECORD_INFO& recordInfo) override;
		// 开始录制
		int StartRecord() override;
		int SuspendRecord() override;
		int ResumeRecord() override;
		int StopRecord() override;
		// 采集到数据后回调
		void OnScreenData(void* data, const VIDEO_INFO& videoInfo) override;
		void OnCapturedData(const void* audioSamples, int nSamples, 
			DEV_TYPE devType, const AUDIO_INFO& audioInfo) override;
	private:
		int CheckRecordInfo();
		void CleanUp();
		// 创建所有采集线程
		void StartCapture(int& ret);
		void StopCapture();
	private:
		enum RECORD_STATE
		{
			NOT_BEGIN,
			RECORDING,
			SUSPENDED,
		};
		bool m_bMicRecording;
		bool m_bSpeakerRecording;
		bool m_bVideoRecording;
		RECORD_STATE m_nRecordState;			// 录制状态
		RECORD_INFO m_stRecordInfo;				// 录制信息
		IMediaFileRecorder* m_pFileRecorder;	// 编码复用
		IScreenGrabber* m_pScreenGrabber;		// 视频采集
		IAudioCapture* m_pMicAudioCapturer;		// 麦克风采集
		IAudioCapture* m_pSpeakerAudioCapturer;	// 扬声器采集
	};
}
#endif // !CSCREENAUDIORECORD_H
