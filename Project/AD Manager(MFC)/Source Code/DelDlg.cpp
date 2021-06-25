// DelDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ADM.h"
#include "DelDlg.h"
#include "maindlg.h"
#include "ADSIworker.h"
#include "afxdialogex.h"


// DelDlg 대화 상자

IMPLEMENT_DYNAMIC(DelDlg, CDialogEx)

DelDlg::DelDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADM_DELOBJ, pParent)
{
	m_pMainwnd = (maindlg*)pParent;
}

DelDlg::~DelDlg()
{
}

void DelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXT, m_strObj);
}


BEGIN_MESSAGE_MAP(DelDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &DelDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// DelDlg 메시지 처리기
BOOL DelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetDlgItemText(IDC_TEXT,m_pMainwnd->m_strOName);
	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void DelDlg::OnBnClickedOk()
{
	if (m_pMainwnd->m_TreeADM.ItemHasChildren(m_pMainwnd->m_hSelItem))
	{
		m_pMainwnd->DelHasChild(m_pMainwnd->m_TreeADM.GetChildItem(m_pMainwnd->m_hSelItem));
	}
	m_pMainwnd->DelLeaf(m_pMainwnd->m_hSelItem);
	
	AfxMessageBox(_T("삭제되었습니다."));
	CDialogEx::OnOK();
}


