#pragma once
#include"LogonLoad.h"
class ADSIWorker;
// logindlg 대화 상자

class logindlg : public CDialogEx
{
	DECLARE_DYNAMIC(logindlg)

public:
	logindlg(CWnd* pParent,ADSIWorker* pAW);   // 표준 생성자입니다.
	virtual ~logindlg();

	ADSIWorker* m_pAW;
	LogonLoad LLdlg;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADM_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strIP;
	CString m_strID;
	CString m_strPWD;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	virtual BOOL OnClose();
	CWinThread* m_pThread;
	HANDLE hThread;
	bool m_bRun, m_bStop,m_bClose;
	static UINT RunThread(LPVOID pParam);
	void OnDestroy();
	
};
