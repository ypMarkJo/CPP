#pragma once
#include <mysql.h>
#include "resource.h"	


// APIApp2 대화 상자

class APIApp2 : public CDialogEx
{
	DECLARE_DYNAMIC(APIApp2)

public:
	APIApp2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~APIApp2();

	BOOL validCheck(int type=0);
	int setDataToList(CString& strUserID, CString& strPasswd, CString strFilter, CString& sqlstr);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APIApp2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strUserID;
	CString m_strPasswd;
	CString m_strCombo1;
	CString m_strSearch;
	CString m_strCombo2;
	CString m_strCombo3;
	double m_dSearch;
	CString m_strMessage;
	CListCtrl m_ctrlListCtrl;
	afx_msg void OnClickedButton2();
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedButton1();
	
	afx_msg void OnClickedButton3();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnStnClickedMessage();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};
