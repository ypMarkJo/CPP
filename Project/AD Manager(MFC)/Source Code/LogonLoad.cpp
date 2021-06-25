// LogonLoad.cpp: 구현 파일
//

#include "pch.h"
#include "ADM.h"
#include "LogonLoad.h"
#include "logindlg.h"
#include "afxdialogex.h"


// LogonLoad 대화 상자

IMPLEMENT_DYNAMIC(LogonLoad, CDialogEx)

LogonLoad::LogonLoad(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADM_LGLOAD, pParent)
{
	m_lginwnd = (logindlg*)pParent;
}

LogonLoad::~LogonLoad()
{
}

void LogonLoad::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STC_GIF, m_ctrlGif1);
}


BEGIN_MESSAGE_MAP(LogonLoad, CDialogEx)
END_MESSAGE_MAP()


// LogonLoad 메시지 처리기


BOOL LogonLoad::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (m_ctrlGif1.Load(MAKEINTRESOURCE(IDR_GIF1), _T("GIF")))
	{
		m_ctrlGif1.Draw();
	}

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void LogonLoad::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	CDialogEx::OnCancel();
}
