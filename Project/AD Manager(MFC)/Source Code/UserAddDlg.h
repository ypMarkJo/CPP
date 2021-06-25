#pragma once
class maindlg;

// UserAddDlg 대화 상자

class UserAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UserAddDlg)

public:
	UserAddDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~UserAddDlg();
	maindlg* m_pMainwnd;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADM_USERADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strLogonName;
	CString m_strPwd;
	afx_msg void OnBnClickedOk();
};
