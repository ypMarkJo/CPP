// GrpAddDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ADM.h"
#include "GrpAddDlg.h"
#include "maindlg.h"
#include "ADSIworker.h"
#include "afxdialogex.h"


// GrpAddDlg 대화 상자

IMPLEMENT_DYNAMIC(GrpAddDlg, CDialogEx)

GrpAddDlg::GrpAddDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADM_GROUPADD, pParent)
	, m_strGrpName(_T(""))
	, m_radioScope()
	, m_radioType()
{
	m_pMainwnd = (maindlg*)pParent;
}

GrpAddDlg::~GrpAddDlg()
{
}

void GrpAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strGrpName);
	DDX_Radio(pDX, IDC_RADIO1, m_radioScope);
	DDX_Radio(pDX, IDC_RADIO5, m_radioType);
}


BEGIN_MESSAGE_MAP(GrpAddDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &GrpAddDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// GrpAddDlg 메시지 처리기


void GrpAddDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	int m_intScope = 0;
	int m_intType = 0;
	switch (m_radioScope)
	{
	case 0: m_intScope = 4; break;
	case 1: m_intScope = 2; break;
	case 2: m_intScope = 8; break;
	}
	switch (m_radioType)
	{
	case 0:m_intType = 2147483648; break;
	case 1:m_intType = 0; break;
	}
	m_intGrpType = m_intScope + m_intType;
	

	ADSIWorker* m_pAW = NULL;
	HRESULT hr = m_pAW->CreateGroup((LPCTSTR)m_pMainwnd->m_strIP, (LPCTSTR)m_pMainwnd->m_strID, 
		(LPCTSTR)m_pMainwnd->m_strPWD, (LPCTSTR)m_pMainwnd->m_strPATH, (LPCTSTR)m_strGrpName, 
		m_intGrpType);
	if (hr == S_OK)
	{
		AfxMessageBox(_T("그룹이 추가되었습니다."));
		m_pMainwnd->m_TreeADM.InsertItem(_T("CN=") + m_strGrpName, 1, 1, m_pMainwnd->m_hSelItem, TVI_SORT);
		m_pMainwnd->m_TreeADM.Expand(m_pMainwnd->m_hSelItem, TVE_EXPAND);
	}
	else
	{
		AfxMessageBox(m_pAW->FormatMessageW(hr));
	}

	CDialogEx::OnOK();
}
