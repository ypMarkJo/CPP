﻿
// HelloMFCView.cpp: CHelloMFCView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HelloMFC.h"
#endif

#include "HelloMFCDoc.h"
#include "HelloMFCView.h"
#include "MyFirstDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloMFCView

IMPLEMENT_DYNCREATE(CHelloMFCView, CView)

BEGIN_MESSAGE_MAP(CHelloMFCView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_MYMENU_FIRST, &CHelloMFCView::OnMymenuFirst)
//	ON_UPDATE_COMMAND_UI(ID_MYMENU_FIRST, &CHelloMFCView::OnUpdateMymenuFirst)
//ON_COMMAND(IDD_MyFirstDialog, &CHelloMFCView::OnIddMyfirstdialog)
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CHelloMFCView 생성/소멸

CHelloMFCView::CHelloMFCView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	char* text = "Hello MFC!";
	strcpy_s(str, strlen(text) + 1, text);
	x = y = 0;
}

CHelloMFCView::~CHelloMFCView()
{
}

BOOL CHelloMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CHelloMFCView 그리기

void CHelloMFCView::OnDraw(CDC*pDC)
{	
	
	
	//그리기 펜(GDI객체) 생성.
	CBrush Br;
	Br.CreateSolidBrush(RGB(m_sp.x%256,255-m_sp.x%256, 255-m_ep.x%256));
	//이전 펜 저장 및 새 펜 설정.
	CBrush* pOldBr = (CBrush*)pDC->SelectObject(&Br);
	//선그리기
	pDC->Rectangle(m_sp.x, m_sp.y, m_ep.x, m_ep.y);
	//pDC->Rectangle(x, y, x+90, y+90);
	//pDC->MoveTo(x, y); x += 100;
	//pDC->LineTo(x, y); y += 100;
	//pDC->LineTo(x, y); x -= 100;
	//pDC->LineTo(x, y); y -= 100;
	//pDC->LineTo(x, y);
	//이전 펜 설정으로 되돌림
	pDC->SelectObject(pOldBr);
	//사용한 펜 제거
	Br.DeleteObject();
	




	////const char* text = "Hello MFC!";
	//CHelloMFCDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);
	//if (!pDoc)
	//	return;

	//// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	//pDC->TextOut(x, y, str, strlen(str));
}



// CHelloMFCView 인쇄

BOOL CHelloMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CHelloMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CHelloMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CHelloMFCView 진단

#ifdef _DEBUG
void CHelloMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CHelloMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHelloMFCDoc* CHelloMFCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHelloMFCDoc)));
	return (CHelloMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CHelloMFCView 메시지 처리기


//void CHelloMFCView::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//
//	CView::OnLButtonDown(nFlags, point);
//}


void CHelloMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	/*LButtonWork(nFlags, point);
	CView::OnLButtonDown(nFlags, point);*/
	m_sp = point;
	
}


//void CHelloMFCView::OnRButtonDown(UINT nFlags, CPoint point)
//{
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	
//	AfxMessageBox("%d,%d",point.x,point.y);
//	CView::OnRButtonDown(nFlags, point);
//}

void CHelloMFCView::LButtonWork(UINT nFlags, CPoint point)
{
	sprintf_s(str, "%d,%d", point.x, point.y);
	x = point.x;
	y = point.y;
	Invalidate(FALSE);
}

void CHelloMFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_ep = point;
	Invalidate(true);
	//AfxMessageBox("Mouse Click", MB_OK);
	//CView::OnLButtonUp(nFlags, point);
}


void CHelloMFCView::OnMymenuFirst()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	MyFirstDialog dlg;
	int ret = dlg.DoModal();	//  Modal Dialog

	if (ret == IDOK)AfxMessageBox("OK Clicked");
	else AfxMessageBox("Cancel Clicked");
}




//void CHelloMFCView::OnUpdateMymenuFirst(CCmdUI* pCmdUI)
//{
//	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
//}




void CHelloMFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags & MK_LBUTTON) {
		m_ep = point;
		Invalidate(true);
	}
	CView::OnMouseMove(nFlags, point);
}
