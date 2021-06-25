#pragma once
class maindlg;

// DelDlg 대화 상자

class DelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DelDlg)

public:
	DelDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DelDlg();
	maindlg* m_pMainwnd;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADM_DELOBJ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CStatic m_strObj;
	virtual BOOL OnInitDialog();
};
