#pragma once
#include "PictureEx.h"
class maindlg;

// Loading 대화 상자

class Loading : public CDialogEx
{
	DECLARE_DYNAMIC(Loading)

public:
	Loading(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Loading();
	maindlg* m_pMainwnd;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADM_LOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	CPictureEx m_gifCtrl;

	virtual void OnCancel();
};
