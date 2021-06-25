#pragma once
#include"pch.h"

// Loadingdlg 대화 상자

class Loadingdlg : public CDialogEx
{
	DECLARE_DYNAMIC(Loadingdlg)

public:
	Loadingdlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Loadingdlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADM_LOADING };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

};
