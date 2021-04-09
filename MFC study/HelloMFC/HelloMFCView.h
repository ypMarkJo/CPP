
// HelloMFCView.h: CHelloMFCView 클래스의 인터페이스
//

#pragma once


class CHelloMFCView : public CView
{
protected: // serialization에서만 만들어집니다.
	CHelloMFCView() noexcept;
	DECLARE_DYNCREATE(CHelloMFCView)

// 특성입니다.
public:
	CHelloMFCDoc* GetDocument() const;
	char str[256];
	int x, y;
	CPoint m_sp = CPoint(100, 100);
	CPoint m_ep = CPoint(-1, -1);

// 작업입니다.
public:
	void LButtonWork(UINT nflags, CPoint point);
// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CHelloMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMymenuFirst();
//	afx_msg void OnUpdateMymenuFirst(CCmdUI* pCmdUI);
	//afx_msg void OnIddMyfirstdialog();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // HelloMFCView.cpp의 디버그 버전
inline CHelloMFCDoc* CHelloMFCView::GetDocument() const
   { return reinterpret_cast<CHelloMFCDoc*>(m_pDocument); }
#endif

