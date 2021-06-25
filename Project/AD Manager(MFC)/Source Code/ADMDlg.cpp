
// ADMDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ADM.h"
#include "ADMDlg.h"
#include "afxdialogex.h"
#include "ADSIWorker.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif



CADMDlg::CADMDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON9);
}

void CADMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CADMDlg, CDialogEx)

END_MESSAGE_MAP()


// CADMDlg 메시지 처리기

BOOL CADMDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	return TRUE; 
}

