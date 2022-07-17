#ifndef CSCREENAUDIORECORD_H
#define CSCREENAUDIORECORD_H

#include "IScreeAudioRecord.h"
#include "IMediaFileRecorder.h"
#include "IScreenGrabber.h"
#include "IAudioCapture.h"

namespace MediaFileRecorder
{
	// ¼���ӿ��࣬UIֱ�ӵ���
	class CScreenAudioRecord : public IScreenAudioRecord,
		                       public IScreenGrabberDataCb,
							   public IAudioCaptureDataCb
	{
	public:
		CScreenAudioRecord();
		~CScreenAudioRecord();

		void SetLogCb();
		int SetRecordInfo(const RECORD_INFO& recordInfo) override;
		// ��ʼ¼��
		int StartRecord() override;
		int SuspendRecord() override;
		int ResumeRecord() override;
		int StopRecord() override;
		// �ɼ������ݺ�ص�
		void OnScreenData(void* data, const VIDEO_INFO& videoInfo) override;
		void OnCapturedData(const void* audioSamples, int nSamples, 
			DEV_TYPE devType, const AUDIO_INFO& audioInfo) override;
	private:
		int CheckRecordInfo();
		void CleanUp();
		// �������вɼ��߳�
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
		RECORD_STATE m_nRecordState;			// ¼��״̬
		RECORD_INFO m_stRecordInfo;				// ¼����Ϣ
		IMediaFileRecorder* m_pFileRecorder;	// ���븴��
		IScreenGrabber* m_pScreenGrabber;		// ��Ƶ�ɼ�
		IAudioCapture* m_pMicAudioCapturer;		// ��˷�ɼ�
		IAudioCapture* m_pSpeakerAudioCapturer;	// �������ɼ�
	};
}
#endif // !CSCREENAUDIORECORD_H
