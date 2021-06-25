#pragma once
class maindlg;

// GrpAddDlg 대화 상자

class GrpAddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(GrpAddDlg)

public:
	GrpAddDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~GrpAddDlg();
	maindlg* m_pMainwnd;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADM_GROUPADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_intGrpType;
	CString m_strGrpName;
	int m_radioScope;
	int m_radioType;
	afx_msg void OnBnClickedOk();
};
