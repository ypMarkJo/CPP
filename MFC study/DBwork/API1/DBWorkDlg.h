
// DBWorkDlg.h: 헤더 파일
//

#pragma once
#include <mysql.h>

// CDBWorkDlg 대화 상자
class CDBWorkDlg : public CDialogEx
{
	// 생성입니다.
public:
	CDBWorkDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.

 // 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DBWORK_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);   // DDX/DDV 지원입니다.

public:
	void SetctrlTitle(MYSQL_RES* result);
	// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrlListCtrl;
	afx_msg void OnBnClickedButton1();
	int m_nRecSize;
	CString m_strQuery;
	CListBox m_ctrlLog;
	afx_msg void OnSelchangeList2();
	afx_msg void OnBnClickedButton2();
};