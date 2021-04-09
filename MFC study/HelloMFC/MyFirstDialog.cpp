// MyFirstDialog.cpp: 구현 파일
//

#include "pch.h"
#include "HelloMFC.h"
#include "MyFirstDialog.h"
#include "afxdialogex.h"


// MyFirstDialog 대화 상자

IMPLEMENT_DYNAMIC(MyFirstDialog, CDialogEx)

MyFirstDialog::MyFirstDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MyFirstDialog, pParent)
	,m_bCheck1(FALSE)
	,m_bCheck2(FALSE)
	,m_strID(_T(""))
	,m_strPasswd(_T(""))
{
	m_nTimer = -1;
}

MyFirstDialog::~MyFirstDialog()
{
}

void MyFirstDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_bCheck1);
	DDX_Check(pDX, IDC_CHECK2, m_bCheck2);
	DDX_Text(pDX, IDC_EDIT1, m_strID);
	DDX_Text(pDX, IDC_EDIT2, m_strPasswd);
}


BEGIN_MESSAGE_MAP(MyFirstDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyFirstDialog::OnClickedButton1)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// MyFirstDialog 메시지 처리기


void MyFirstDialog::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_nTimer < 0)
		m_nTimer = SetTimer(100, 1000, NULL);
	else
	{
		KillTimer(m_nTimer);
		m_nTimer = -1;
	}

}


void MyFirstDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == m_nTimer)
	{
		UpdateData(TRUE);

		m_bCheck1 = !m_bCheck1;
		m_bCheck2 = !m_bCheck2;

		UpdateData(FALSE);
	}

	CDialogEx::OnTimer(nIDEvent);
}
