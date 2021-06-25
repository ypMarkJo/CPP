#pragma once
#include "Loading.h"
class logindlg;
// maindlg 대화 상자


class maindlg : public CDialogEx
{
	DECLARE_DYNAMIC(maindlg)

public:
	maindlg(CWnd* pParent=nullptr);   // 표준 생성자입니다.
	virtual ~maindlg();
	logindlg* m_plginwnd;
	Loading LDdlg;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADM_MAIN };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.


	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_TreeADM;
	CImageList m_imgList;//
	HICON m_hIcon;
	void OnBnClickedViewTreeADM();
	void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedUseradd();
	CString m_strIP;
	CString m_strID;
	CString m_strPWD;
	CString m_strPATH;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedDelbt();
	afx_msg void OnBnClickedOuadd();
	afx_msg void OnBnClickedGroupadd();
	CEdit m_strName;
	CEdit m_strCate;
	CEdit m_strGroup;
	CEdit m_strDesc;
	CString m_strOName;
	CString m_strOCate;
	HACCEL m_hAccel;
	afx_msg void OnAccelerator32777();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CStringArray m_arrDelList;
	void DelHasChild(HTREEITEM m_hTreeItem);
	void DelLeaf(HTREEITEM m_hTreeItem);
	HTREEITEM m_hSelItem;
	CString m_strObjCN;
	void OnBegindragTree(NMHDR* pNMHDR, LRESULT* pResult);
	void OnMouseMove(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	BOOL MoveTreeItem(CTreeCtrl *pTree, HTREEITEM hSrcItem, HTREEITEM hDestItem);
	BOOL MoveChildTreeItem(CTreeCtrl *pTree, HTREEITEM hChildItem, HTREEITEM hDestItem);
	CWinThread* m_pThread;
	HANDLE hThread;
	bool m_bRun, m_bStop;
	static UINT RunThread(LPVOID pParam);
	void OnDestroy();
	HTREEITEM m_hSource;
	HTREEITEM m_hDestination;
};
