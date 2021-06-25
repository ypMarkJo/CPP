#pragma once
class maindlg;

// OUAddDlg 대화 상자

class OUAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(OUAddDlg)

public:
	OUAddDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~OUAddDlg();
	maindlg* m_pMainwnd;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADM_OUADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strOUName;
	afx_msg void OnBnClickedOk();
};
