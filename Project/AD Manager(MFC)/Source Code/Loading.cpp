// Loading.cpp: 구현 파일
//

#include "pch.h"
#include "ADM.h"
#include "Loading.h"
#include "maindlg.h"
#include "afxdialogex.h"


// Loading 대화 상자

IMPLEMENT_DYNAMIC(Loading, CDialogEx)

Loading::Loading(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADM_LOAD, pParent)
{
	m_pMainwnd = (maindlg*)pParent;
}
Loading::~Loading()
{
}

void Loading::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_STC_GIF, m_gifCtrl);
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_TEXT, m_ctrlMsg);
}


BEGIN_MESSAGE_MAP(Loading, CDialogEx)
END_MESSAGE_MAP()


// Loading 메시지 처리기


BOOL Loading::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	if (m_gifCtrl.Load(MAKEINTRESOURCE(IDR_GIF1), _T("GIF")))
	{
	   m_gifCtrl.Draw();
	}
	return TRUE;  
}

void Loading::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CDialogEx::OnCancel();
}
