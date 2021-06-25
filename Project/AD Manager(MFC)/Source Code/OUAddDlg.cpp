// OUAddDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ADM.h"
#include "OUAddDlg.h"
#include "maindlg.h"
#include "ADSIworker.h"
#include "afxdialogex.h"


// OUAddDlg 대화 상자

IMPLEMENT_DYNAMIC(OUAddDlg, CDialogEx)

OUAddDlg::OUAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADM_OUADD, pParent)
	, m_strOUName(_T(""))
{
	m_pMainwnd = (maindlg*)pParent;
}

OUAddDlg::~OUAddDlg()
{
}

void OUAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strOUName);
}


BEGIN_MESSAGE_MAP(OUAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &OUAddDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// OUAddDlg 메시지 처리기


void OUAddDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	ADSIWorker* m_pAW = NULL;
	HRESULT hr = m_pAW->CreateOU((LPCTSTR)m_pMainwnd->m_strIP, (LPCTSTR)m_pMainwnd->m_strID, (LPCTSTR)m_pMainwnd->m_strPWD, (LPCTSTR)m_pMainwnd->m_strPATH, (LPCTSTR)m_strOUName);
	if (hr == S_OK)
	{
		AfxMessageBox(_T("OU가 추가되었습니다."));
		m_pMainwnd->m_TreeADM.InsertItem(_T("OU=") + m_strOUName, 6, 6, m_pMainwnd->m_hSelItem, TVI_SORT);
		m_pMainwnd->m_TreeADM.Expand(m_pMainwnd->m_hSelItem, TVE_EXPAND);
		CDialogEx::OnOK();
		return;
	}
	else {
		AfxMessageBox(m_pAW->FormatMessageW(hr));
	}
	CDialogEx::OnCancel();
}
