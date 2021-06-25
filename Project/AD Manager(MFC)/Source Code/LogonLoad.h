#pragma once
#include "PictureEx.h"
class logindlg;
// LogonLoad 대화 상자

class LogonLoad : public CDialogEx
{
	DECLARE_DYNAMIC(LogonLoad)

public:
	LogonLoad(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~LogonLoad();
	logindlg* m_lginwnd;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADM_LGLOAD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CPictureEx m_ctrlGif1;
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
};
