#pragma once


// MyFirstDialog 대화 상자

class MyFirstDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MyFirstDialog)
	int m_nTimer;
public:
	MyFirstDialog(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~MyFirstDialog();


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MyFirstDialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
	BOOL m_bCheck1;
	BOOL m_bCheck2;
	CString m_strID;
	CString m_strPasswd;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
