// UserAddDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ADM.h"
#include "UserAddDlg.h"
#include "maindlg.h"
#include "ADSIworker.h"
#include "afxdialogex.h"


// UserAddDlg 대화 상자

IMPLEMENT_DYNAMIC(UserAddDlg, CDialogEx)

UserAddDlg::UserAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADM_USERADD, pParent)
	, m_strName(_T(""))
	, m_strLogonName(_T(""))
	, m_strPwd(_T(""))
{
	m_pMainwnd = (maindlg*)pParent;
}

UserAddDlg::~UserAddDlg()
{
}

void UserAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDX_Text(pDX, IDC_EDIT2, m_strLogonName);
	DDX_Text(pDX, IDC_EDIT3, m_strPwd);
}


BEGIN_MESSAGE_MAP(UserAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &UserAddDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// UserAddDlg 메시지 처리기


void UserAddDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	ADSIWorker* m_pAW=NULL;
	HRESULT hr = m_pAW->CreateUser((LPCTSTR)m_pMainwnd->m_strIP, (LPCTSTR)m_pMainwnd->m_strID, (LPCTSTR)m_pMainwnd->m_strPWD, (LPCTSTR)m_pMainwnd->m_strPATH,(LPCTSTR)m_strName, (LPCTSTR)m_strLogonName, (LPCTSTR)m_strPwd);
	
	if(hr==S_OK)
	{
		AfxMessageBox(_T("사용자가 추가되었습니다."));
		m_pMainwnd->m_TreeADM.InsertItem(_T("CN=")+m_strName,5,5, m_pMainwnd->m_hSelItem,TVI_SORT);
		m_pMainwnd->m_TreeADM.Expand(m_pMainwnd->m_hSelItem, TVE_EXPAND);
		CDialogEx::OnOK();
		return;
	}
	else {
		AfxMessageBox(m_pAW->FormatMessageW(hr));
	}
	CDialogEx::OnCancel();
}
