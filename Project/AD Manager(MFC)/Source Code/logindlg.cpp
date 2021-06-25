// logindlg.cpp: 구현 파일
//

#include "pch.h"
#include "ADM.h"
#include "logindlg.h"
#include "maindlg.h"
#include "afxdialogex.h"


// logindlg 대화 상자

IMPLEMENT_DYNAMIC(logindlg, CDialogEx)

logindlg::logindlg(CWnd* pParent,ADSIWorker* pAW)
	: CDialogEx(IDD_ADM_LOGIN, pParent)
	, m_strIP(_T("172.16.10.101"))
	, m_strID(_T("DSTATIONLAB3\\administrator"))
	, m_strPWD(_T("Qo55dnjd1"))
{
	m_pAW = pAW;
}

logindlg::~logindlg()
{
	OnDestroy();
}

void logindlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strIP);
	DDX_Text(pDX, IDC_EDIT2, m_strID);
	DDX_Text(pDX, IDC_EDIT3, m_strPWD);
}


BEGIN_MESSAGE_MAP(logindlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &logindlg::OnBnClickedOk)
END_MESSAGE_MAP()


// logindlg 메시지 처리기

BOOL logindlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (m_pThread == NULL)
	{
		m_pThread = AfxBeginThread(RunThread, this);
		hThread = m_pThread->m_hThread;
		m_bStop = false;
		m_bRun = false;
		m_bClose = false;
		if (!m_pThread)
		{
			AfxMessageBox(_T("Thread could not be created,"));
			return FALSE;
		}
	}
	return TRUE;  
}
UINT logindlg::RunThread(LPVOID pParam)
{
	logindlg *g_pDlg = (logindlg*)pParam;
	while (1)
	{
		if (g_pDlg->m_bRun == true)
		{
			//작동 함수
			g_pDlg->LLdlg.DoModal();
			g_pDlg->m_bRun = false;
		}
		if (g_pDlg->m_bStop == true)
		{
			return 0;
		}
	}
	return 0;
}
void logindlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_pThread != NULL)
	{
		m_bStop = true;
		m_pThread = NULL;
	}
}
BOOL logindlg::OnClose() 
{
	CDialogEx::OnClose();
	return TRUE;
}
void logindlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_bRun = true;
	if (HRESULT hr = m_pAW->Authenticate((LPCTSTR)m_strIP, (LPCTSTR)m_strID, (LPCTSTR)m_strPWD) == S_OK)
	{
		LLdlg.SendMessage(WM_CLOSE, NULL, NULL);
		maindlg dlg(this);
		if (dlg.DoModal() == IDOK)
		{
			CDialogEx::OnOK();
		}
		else
		{
			CDialogEx::OnCancel();
		}
		return;
	}
	else
	{
		LLdlg.SendMessage(WM_CLOSE, NULL, NULL);
		AfxMessageBox(m_pAW->FormatMessageW(hr));
		return;
	}

}
