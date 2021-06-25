// maindlg.cpp: 구현 파일
//

#include "pch.h"
#include "ADM.h"
#include "maindlg.h"
#include "logindlg.h"
#include "ADSIWorker.h"
#include "afxdialogex.h"
#include "UserAddDlg.h"
#include "OUAddDlg.h"
#include "GrpAddDlg.h"
#include "DelDlg.h"
#include "Loading.h"
#include <stack>

// maindlg 대화 상자

IMPLEMENT_DYNAMIC(maindlg, CDialogEx)

maindlg::maindlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADM_MAIN, pParent)
{
	m_plginwnd = (logindlg*)pParent;
}

maindlg::~maindlg()
{
	OnDestroy();
}

void maindlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_TreeADM);;
	DDX_Control(pDX, IDC_EDIT5, m_strName);
	DDX_Control(pDX, IDC_EDIT1, m_strCate);
	DDX_Control(pDX, IDC_EDIT4, m_strGroup);
	DDX_Control(pDX, IDC_EDIT6, m_strDesc);
}


BEGIN_MESSAGE_MAP(maindlg, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &maindlg::OnTvnSelchangedTree1)
	ON_BN_CLICKED(IDC_USERADD, &maindlg::OnBnClickedUseradd)
	ON_BN_CLICKED(IDC_BUTTON1, &maindlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_DELBT, &maindlg::OnBnClickedDelbt)
	ON_BN_CLICKED(IDC_OUADD, &maindlg::OnBnClickedOuadd)
	ON_BN_CLICKED(IDC_GROUPADD, &maindlg::OnBnClickedGroupadd)
	ON_COMMAND(ID_ACCELERATOR32777, &maindlg::OnAccelerator32777)
	ON_NOTIFY(TVN_BEGINDRAG, IDC_TREE1, &maindlg::OnBegindragTree)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// maindlg 메시지 처리기
BOOL maindlg::OnInitDialog()
{
	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));
	m_plginwnd->EndDialog(IDOK);
	CDialogEx::OnInitDialog();
	m_imgList.Create(16, 16, ILC_COLOR32 | ILC_MASK, 4, 4);
	HICON m_hIcon;
	m_hIcon = theApp.LoadIcon(IDI_ICON1);
	m_imgList.Add(m_hIcon);
	m_hIcon = theApp.LoadIcon(IDI_ICON2);
	m_imgList.Add(m_hIcon);
	m_hIcon = theApp.LoadIcon(IDI_ICON3);
	m_imgList.Add(m_hIcon);
	m_hIcon = theApp.LoadIcon(IDI_ICON4);
	m_imgList.Add(m_hIcon);
	m_hIcon = theApp.LoadIcon(IDI_ICON5);
	m_imgList.Add(m_hIcon);
	m_hIcon = theApp.LoadIcon(IDI_ICON6);
	m_imgList.Add(m_hIcon);
	m_hIcon = theApp.LoadIcon(IDI_ICON7);
	m_imgList.Add(m_hIcon);
	m_hIcon = theApp.LoadIcon(IDI_ICON8);
	m_imgList.Add(m_hIcon);
	maindlg::OnBnClickedViewTreeADM();
	m_TreeADM.Expand(m_TreeADM.GetRootItem(), TVE_EXPAND);
	if (m_pThread == NULL)
	{
		m_pThread = AfxBeginThread(RunThread, this);
		hThread = m_pThread->m_hThread;
		m_bStop = false;
		m_bRun = false;
		if (!m_pThread)
		{
			AfxMessageBox(_T("Thread could not be created,"));
			return FALSE;
		}
	}
	return TRUE;  
}


//아이템 찾기
HTREEITEM FindItem(const CString& name, CTreeCtrl& tree, HTREEITEM hRoot)
{
	// check whether the current item is the searched one
	CString text = tree.GetItemText(hRoot);
	if (text.Compare(name) == 0)
		return hRoot;

	// get a handle to the first child item
	HTREEITEM hSub = tree.GetChildItem(hRoot);
	// iterate as long a new item is found
	while (hSub)
	{
		// check the children of the current item
		HTREEITEM hFound = FindItem(name, tree, hSub);
		if (hFound)
			return hFound;

		// get the next sibling of the current item
		hSub = tree.GetNextSiblingItem(hSub);
	}
	// return NULL if nothing was found
	return NULL;
}
HTREEITEM FindItem(const CString& name, CTreeCtrl& tree)
{
	HTREEITEM root = tree.GetRootItem();
	while (root != NULL)
	{
		HTREEITEM hFound = FindItem(name, tree,root);
		if (hFound)
			return hFound;

		root = tree.GetNextSiblingItem(root);
	}
	return NULL;
}
UINT maindlg::RunThread(LPVOID pParam)
{
	maindlg *g_pDlg = (maindlg*)pParam;
	while (1)
	{
		if (g_pDlg->m_bRun == true)
		{
			//작동 함수
			if (g_pDlg->MoveTreeItem(&g_pDlg->m_TreeADM, g_pDlg->m_hSource, g_pDlg->m_hDestination)==TRUE)
			{
				g_pDlg->LDdlg.SendMessage(WM_CLOSE, NULL, NULL);
				AfxMessageBox(_T("이동되었습니다."), MB_TOPMOST);
			}
			g_pDlg->m_bRun = false;
		}
		if (g_pDlg->m_bStop == true)
		{
			return 0;
		}
	}
	return 0;
}
void maindlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_pThread != NULL)
	{
		m_bStop = true;
		m_pThread = NULL;
	}
}
void maindlg::OnBnClickedViewTreeADM()
{
	CString buf,buf2;
	CStringArray Treeobj;
	
	m_strIP = m_plginwnd->m_strIP;
	m_strID = m_plginwnd->m_strID;
	m_strPWD = m_plginwnd->m_strPWD;
	m_plginwnd->m_pAW->GetADUsers(Treeobj, (LPCTSTR)m_plginwnd->m_strIP, (LPCTSTR)m_plginwnd->m_strID, (LPCTSTR)m_plginwnd->m_strPWD);
	HTREEITEM h_root = m_TreeADM.GetRootItem();
	
	m_TreeADM.SetImageList(&m_imgList, TVSIL_NORMAL);
	for (int i = 0; i < Treeobj.GetSize(); i++)
	{
		buf = Treeobj.GetAt(i);
		CString Seperator = _T("/");
		int Position =0;
		buf2 = buf.Tokenize(Seperator,Position);
		CString Type=buf.Tokenize(Seperator, Position);
		buf = buf2;
		Seperator = _T(",");
		Position = 0;
		CString Token;
		std::stack<CString> st;
		
		Token = buf.Tokenize(Seperator, Position);
		while (!Token.IsEmpty())
		{
			st.push(Token);
			// Get next token.
			Token = buf.Tokenize(Seperator, Position);
		}
		CString c = st.top();
		st.pop();
		st.top().Append(','+c);
		while (!st.empty())
		{
			if (FindItem(st.top(), m_TreeADM)!= NULL)h_root = FindItem(st.top(), m_TreeADM);
			else
			{
				if (Type == "domain")
				{
					h_root = m_TreeADM.InsertItem(st.top(), 0, 0, h_root, TVI_SORT);
				}
				else if (Type == "group") h_root = m_TreeADM.InsertItem(st.top(), 1, 1, h_root, TVI_SORT);
				else if (Type == "builtinDomain") h_root = m_TreeADM.InsertItem(st.top(), 2, 2, h_root, TVI_SORT);
				else if (Type == "etc") h_root = m_TreeADM.InsertItem(st.top(), 4, 4, h_root, TVI_SORT);
				else if (Type == "container")h_root = m_TreeADM.InsertItem(st.top(), 4, 4, h_root, TVI_SORT);
				else if (Type == "computer") h_root = m_TreeADM.InsertItem(st.top(), 3, 3, h_root, TVI_SORT);
				else if (Type == "user") h_root = m_TreeADM.InsertItem(st.top(), 5, 5, h_root, TVI_SORT);
				else if (Type == "organizationalUnit") h_root = m_TreeADM.InsertItem(st.top(), 6, 6, h_root, TVI_SORT);
				else if (Type == "secret") h_root = m_TreeADM.InsertItem(st.top(), 7, 7, h_root, TVI_SORT);
			}
			st.pop();
		}
	}
}
void maindlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	HTREEITEM hTreeItem = m_TreeADM.GetSelectedItem();
	m_hSelItem = hTreeItem;
	m_strObjCN= m_TreeADM.GetItemText(hTreeItem);
	while (m_TreeADM.GetParentItem(hTreeItem))
	{
		hTreeItem = m_TreeADM.GetParentItem(hTreeItem);
		m_strObjCN.Append(','+m_TreeADM.GetItemText(hTreeItem));
	}
	CStringArray strRstData;
	m_plginwnd->m_pAW->GetAttribute(strRstData, (LPCTSTR)m_strObjCN,(LPCTSTR)m_plginwnd->m_strIP, (LPCTSTR)m_plginwnd->m_strID, (LPCTSTR)m_plginwnd->m_strPWD);
	CString Type = strRstData.GetAt(1);
	int pos = 0;
	CString Token = Type.Tokenize(_T(","), pos);
	pos = 0;
	Token.Tokenize(_T("="), pos);
	Type=Token.Tokenize(_T("="), pos);
	if (Type == "Person") Type = "사용자";
	else if(Type == "Group") Type = "그룹";
	else if(Type == "Organizational-Unit") Type = "조직 구성 단위";
	else if(Type == "Computer") Type = "컴퓨터";
	else if(Type == "Container") Type = "컨테이너";

	m_strName.SetWindowText(strRstData.GetAt(0));
	m_strCate.SetWindowText(Type);
	m_strGroup.SetWindowText(strRstData.GetAt(2));
	m_strDesc.SetWindowText(strRstData.GetAt(3));
	m_strPATH = m_strObjCN;
	m_strOName = strRstData.GetAt(0);
	m_strOCate = strRstData.GetAt(1);

	*pResult = 0;
}
void maindlg::OnBnClickedUseradd()
{
	UserAddDlg dlg(this);
	dlg.DoModal();
}
void maindlg::OnBnClickedButton1()
{
	m_TreeADM.DeleteAllItems();
	CDialogEx::OnInitDialog();
	maindlg::OnBnClickedViewTreeADM();
	m_TreeADM.Expand(m_TreeADM.GetRootItem(), TVE_EXPAND);
}
void maindlg::DelLeaf(HTREEITEM m_hTreeItem)
{
	HTREEITEM prntItem = m_hTreeItem;
	m_strObjCN = m_TreeADM.GetItemText(prntItem);
	while (m_TreeADM.GetParentItem(prntItem))
	{
		prntItem = m_TreeADM.GetParentItem(prntItem);
		m_strObjCN.Append(',' + m_TreeADM.GetItemText(prntItem));
	}
	CStringArray strRstData;
	m_plginwnd->m_pAW->GetAttribute(strRstData, (LPCTSTR)m_strObjCN, (LPCTSTR)m_plginwnd->m_strIP, (LPCTSTR)m_plginwnd->m_strID, (LPCTSTR)m_plginwnd->m_strPWD);
	CString Type = strRstData.GetAt(1);
	CString Seperator = _T(",");
	int Position = 0;
	CString Token;

	Token = Type.Tokenize(Seperator, Position);
	if (!Token.Compare(_T("CN=Person")))
	{
		Type = "User";
		Token = _T("CN=") + strRstData.GetAt(0);//name
	}
	else if (!Token.Compare(_T("CN=Organizational-Unit")))
	{
		Type = "organizationalUnit";
		Token = _T("OU=") + strRstData.GetAt(0);
	}
	else
	{
		Token.Remove(_T('-'));
		Position = 0;
		Token.Tokenize(_T("="), Position);
		Type = Token.Tokenize(_T("="), Position);
		Token = _T("CN=") + strRstData.GetAt(0);
	}
	CString orgPath = m_strObjCN;
	CString delPath;
	CString TK;
	Position = 0;
	TK = orgPath.Tokenize(_T(","), Position);

	while (!TK.IsEmpty())
	{
		TK = orgPath.Tokenize(_T(","), Position);
		if (TK.Compare(_T("DC=com")) == 0)
		{
			delPath.Append(TK); break;
		}
		else delPath.Append(TK + ',');
	}
	HRESULT hr = m_plginwnd->m_pAW->DeleteObject((LPCTSTR)m_plginwnd->m_strIP, (LPCTSTR)m_plginwnd->m_strID,
		(LPCTSTR)m_plginwnd->m_strPWD, (LPCTSTR)delPath, (LPCTSTR)Type, (LPCTSTR)Token);

	m_TreeADM.DeleteItem(m_hTreeItem);
	return;
}
void maindlg::DelHasChild(HTREEITEM m_hTreeItem)
{
	m_strObjCN ="";
	while (m_TreeADM.ItemHasChildren(m_hTreeItem)) {
		HTREEITEM childItem = m_TreeADM.GetChildItem(m_hTreeItem);
		DelHasChild(childItem);
	}
	while (m_TreeADM.GetNextSiblingItem(m_hTreeItem)) {
		HTREEITEM siblItem = m_TreeADM.GetNextSiblingItem(m_hTreeItem);
		DelHasChild(siblItem);
	}
	HTREEITEM prntItem = m_hTreeItem;
	m_strObjCN = m_TreeADM.GetItemText(prntItem);
	while (m_TreeADM.GetParentItem(prntItem))
	{
		prntItem = m_TreeADM.GetParentItem(prntItem);
		m_strObjCN.Append(',' + m_TreeADM.GetItemText(prntItem));
	}
	CStringArray strRstData;
	m_plginwnd->m_pAW->GetAttribute(strRstData, (LPCTSTR)m_strObjCN, (LPCTSTR)m_plginwnd->m_strIP, (LPCTSTR)m_plginwnd->m_strID, (LPCTSTR)m_plginwnd->m_strPWD);
	CString Type = strRstData.GetAt(1);
	CString Seperator = _T(",");
	int Position = 0;
	CString Token;

	Token = Type.Tokenize(Seperator, Position);
	if (!Token.Compare(_T("CN=Person")))
	{
		Type = "User";
		Token = _T("CN=") + strRstData.GetAt(0);//name
	}
	else if (!Token.Compare(_T("CN=Organizational-Unit")))
	{
		Type = "organizationalUnit";
		Token = _T("OU=") + strRstData.GetAt(0);
	}
	else
	{
		Token.Remove(_T('-'));
		Position = 0;
		Token.Tokenize(_T("="), Position);
		Type = Token.Tokenize(_T("="), Position);
		Token = _T("CN=") + strRstData.GetAt(0);
	}
	CString orgPath = m_strObjCN;
	CString delPath;
	CString TK;
	Position = 0;
	TK = orgPath.Tokenize(_T(","), Position);

	while (!TK.IsEmpty())
	{
		TK = orgPath.Tokenize(_T(","), Position);
		if (TK.Compare(_T("DC=com")) == 0)
		{
			delPath.Append(TK); break;
		}
		else delPath.Append(TK + ',');
	}
	HRESULT hr = m_plginwnd->m_pAW->DeleteObject((LPCTSTR)m_plginwnd->m_strIP, (LPCTSTR)m_plginwnd->m_strID,
		(LPCTSTR)m_plginwnd->m_strPWD, (LPCTSTR)delPath, (LPCTSTR)Type, (LPCTSTR)Token);

	m_TreeADM.DeleteItem(m_hTreeItem);
	return;
	
}
void maindlg::OnBnClickedDelbt()
{
	DelDlg dlg(this);
	dlg.DoModal();
}
void maindlg::OnBnClickedOuadd()
{
	OUAddDlg dlg(this);
	dlg.DoModal();
}
void maindlg::OnBnClickedGroupadd()
{
	GrpAddDlg dlg(this);
	dlg.DoModal();
}
void maindlg::OnAccelerator32777()
{
	OnBnClickedButton1();
}
BOOL maindlg::PreTranslateMessage(MSG* pMsg)
{
	if (::TranslateAccelerator(this->m_hWnd, m_hAccel, pMsg)) return TRUE;
	return CDialogEx::PreTranslateMessage(pMsg);
}

CImageList  *m_pTreeDragImage = NULL;       // 드래그시 생성된 이미지 사용
HTREEITEM  m_hDragItem = NULL;

void maindlg::OnBegindragTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	// 드래그 이미지 생성
	if (m_pTreeDragImage) m_pTreeDragImage->DeleteImageList();
	m_pTreeDragImage = m_TreeADM.CreateDragImage(pNMTreeView->itemNew.hItem);
	// 드래그시 사용할 이미지 크기 계산
	RECT  rc;
	m_TreeADM.GetItemRect(pNMTreeView->itemNew.hItem, &rc, TRUE); // 아이콘을 포함하는 크기
	// 드래그를 시작
	m_pTreeDragImage->BeginDrag(0, CPoint(pNMTreeView->ptDrag.x - rc.left + 16,
		pNMTreeView->ptDrag.y - rc.top));
	// 드래그 이미지 표시
	m_pTreeDragImage->DragEnter(&m_TreeADM, pNMTreeView->ptDrag);
	// 마우스 메시지를 잡아두고
	SetCapture();
	// 현재 선택된 아이템 핸들을 기억
	m_hDragItem = pNMTreeView->itemNew.hItem;
	*pResult = 0;
}
void maindlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// 드래그 중이라면
	if (m_pTreeDragImage)
	{
		// 트리컨트롤 기준으로 마우스 좌표 계산
		CPoint  p = point;
		ClientToScreen(&p);
		::ScreenToClient(m_TreeADM.m_hWnd, &p);
		// 마우스가 위치한 아이템을 검사한다.항목이 트리 뷰 항목위에 있는지 확인하고 그렇다면 항목이 밝게 표시되도록한다.
		HTREEITEM hItem = m_TreeADM.HitTest(p);
		// 밝게 표시된 부분과 현재 선택된 아이템이 틀리다면
		if (hItem != m_TreeADM.GetDropHilightItem())
		{
			// 드래그 이미지 그리기 중지
			m_pTreeDragImage->DragLeave(&m_TreeADM);
			// 새로운 항목을 밝게 표시한다.
			m_TreeADM.SelectDropTarget(hItem);
			// 드래그 이미지를 다시 보여준다.
			m_pTreeDragImage->DragEnter(&m_TreeADM, p);
		}
		else
		{
			m_pTreeDragImage->DragMove(p);
		}
	}
	CDialog::OnMouseMove(nFlags, point);
}
void maindlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	// 드래그 중이 었다면
	if (m_pTreeDragImage)
	{
		// 마우스 메시지 캡쳐 기능을 제거한다.
		ReleaseCapture();
		// 드래그 과정을 중단한다.
		m_pTreeDragImage->DragLeave(&m_TreeADM);
		m_pTreeDragImage->EndDrag();
		m_pTreeDragImage->DeleteImageList();
		delete m_pTreeDragImage;
		m_pTreeDragImage = NULL;
		// 일단 마지막으로 밝게 표시되었던 항목을 찾는다.
		HTREEITEM hTargetItem = m_TreeADM.GetDropHilightItem();
		// 밝게 표시된 드롭 항목의 선택을 취소한다.
		m_TreeADM.SelectDropTarget(NULL);
		// 선택된 항목(아이템)이 있다면
		if (hTargetItem)
		{
			// 선택된 아이템과 이동될 곳의 아이템이 같다면 이동할 필요가 없다.

			if (m_hDragItem != hTargetItem)
			{
				// 현재 자식의 부모 아이템 핸들을 구한다.
				HTREEITEM hParentItem = m_TreeADM.GetNextItem(m_hDragItem,
					TVGN_PARENT);
				// 이동하려는 곳이 자신이 직접속한 항목 이라면 이동할 필요가 없다.
				if (hParentItem != hTargetItem)
				{
					// 트리의 내용을 이동하자.
					if (IDYES == AfxMessageBox(_T("  객체를 이동하시겠습니까?\n ( OU를 이동시키는 경우 다소 시간이 소요됩니다.)"), MB_YESNO))
					{
						// OK Action	
						m_hSource = m_hDragItem;
						m_hDestination = hTargetItem;
						m_bRun = true;
						
						LDdlg.DoModal();
						
						// 이동된 곳의 트리를 확장하자.
						m_TreeADM.Expand(hTargetItem, TVE_EXPAND);
						// 이미지도 확장한걸로 바꾸자
						//m_ctrlTreeD.SetItemImage(hTargetItem, 1, 1);
						// 원본 트리의 모든 아이템이 사라졌다면 이미지 그림을 기본으로 바꾸자.
						//HTREEITEM hItem = m_TreeADM.GetChildItem(hParentItem);
						/*if (!hItem)
						{
							m_TreeADM.SetItemImage(hParentItem, 0, 0);
						}*/
					}
					else if (IDNO)

					{
						// NO Action
						AfxMessageBox(_T("작업을 취소했습니다."));
						return;
					}
					
				}
			}
		}
		m_hDragItem = NULL;
	}
	CDialog::OnLButtonUp(nFlags, point);
}

BOOL maindlg::MoveTreeItem(CTreeCtrl *pTree, HTREEITEM hSrcItem, HTREEITEM hDestItem)
{
	// 이동할 아이템의 정보를 알아내자.

	TVITEM    TV;
	char    str[256];
	ZeroMemory(str, sizeof(str));
	TV.hItem = hSrcItem;
	TV.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
	TV.pszText = (LPWSTR)str;
	TV.cchTextMax = sizeof(str);
	m_TreeADM.GetItem(&TV);
	DWORD dwData = pTree->GetItemData(hSrcItem);
	// 아이템을 추가 하자.
	TVINSERTSTRUCT  TI;
	TI.hParent = hDestItem;
	TI.hInsertAfter = TVI_SORT;
	TI.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
	TI.item.iImage = TV.iImage;
	TI.item.iSelectedImage = TV.iSelectedImage;
	TI.item.pszText = TV.pszText;


	//실제 파일도 이동.------------------------------------------------------------------------
	HTREEITEM prntItem = hDestItem;
	m_strObjCN = m_TreeADM.GetItemText(prntItem);
	while (m_TreeADM.GetParentItem(prntItem))
	{
		prntItem = m_TreeADM.GetParentItem(prntItem);
		m_strObjCN.Append(',' + m_TreeADM.GetItemText(prntItem));
	}

	CStringArray strRstData;
	m_plginwnd->m_pAW->GetAttribute(strRstData, (LPCTSTR)m_strObjCN, (LPCTSTR)m_plginwnd->m_strIP, (LPCTSTR)m_plginwnd->m_strID, (LPCTSTR)m_plginwnd->m_strPWD);
	CString Type = strRstData.GetAt(1);
	CString Seperator = _T(",");
	int Position = 0;
	CString Token;

	Token = Type.Tokenize(Seperator, Position);
	if (!Token.Compare(_T("CN=Person"))|| !Token.Compare(_T("CN=Group")))
	{
		LDdlg.SendMessage(WM_CLOSE, NULL, NULL);
		AfxMessageBox(_T("사용자나 그룹 객체는 하위 트리를 가질 수 없습니다."), MB_TOPMOST);
		return FALSE;
	}


	HTREEITEM SrcItem = hSrcItem;
	CString m_strSrcObj;
	m_strSrcObj = m_TreeADM.GetItemText(SrcItem);
	while (m_TreeADM.GetParentItem(SrcItem))
	{
		SrcItem = m_TreeADM.GetParentItem(SrcItem);
		m_strSrcObj.Append(',' + m_TreeADM.GetItemText(SrcItem));
	}
	m_plginwnd->m_pAW->MoveObject((LPCTSTR)m_plginwnd->m_strIP, (LPCTSTR)m_plginwnd->m_strID, (LPCTSTR)m_plginwnd->m_strPWD,(LPCTSTR)m_strObjCN,(LPCTSTR)m_strSrcObj);
	//-----------------------------------------------------------------------------------------


	HTREEITEM hItem = pTree->InsertItem(&TI);
	pTree->SetItemData(hItem, dwData);
	// 현재 아이템에 자식 아이템이 있다면
	HTREEITEM hChildItem = pTree->GetChildItem(hSrcItem);
	if (hChildItem)
	{
		// 자식 아이템이 있다면 같이 이동하자.
		MoveChildTreeItem(pTree, hChildItem, hItem);
	}
	// 확장 여부를 알아서 똑같이 하자.
	TVITEM  item;
	item.mask = TVIF_HANDLE;
	item.hItem = hSrcItem;
	pTree->GetItem(&item);
	if (item.state & TVIS_EXPANDED)
	{
		pTree->Expand(hItem, TVE_EXPAND);
	}
	// 아이템을 선택하자.
	pTree->SelectItem(hItem);
	// 기존 아이템을 제거한다.
	pTree->DeleteItem(hSrcItem);
	return TRUE;
}
// 현재 트리의 모든 아이템 데이터 이동
BOOL maindlg::MoveChildTreeItem(CTreeCtrl *pTree, HTREEITEM hChildItem,	HTREEITEM hDestItem)
{
	HTREEITEM hSrcItem = hChildItem;
	while (hSrcItem)
	{
		// 이동할 아이템의 정보를 알아내자.
		TVITEM    TV;
		char    str[256];
		ZeroMemory(str, sizeof(str));
		TV.hItem = hSrcItem;
		TV.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
		TV.pszText = (LPWSTR)str;
		TV.cchTextMax = sizeof(str);
		m_TreeADM.GetItem(&TV);
		DWORD dwData = pTree->GetItemData(hSrcItem);
		// 아이템을 추가 하자.
		TVINSERTSTRUCT  TI;
		TI.hParent = hDestItem;
		TI.hInsertAfter = TVI_SORT;
		TI.item.mask = TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
		TI.item.iImage = TV.iImage;
		TI.item.iSelectedImage = TV.iSelectedImage;
		TI.item.pszText = TV.pszText;

		//---------------------------------------------------------------------
		HTREEITEM prntItem = hDestItem;
		m_strObjCN = m_TreeADM.GetItemText(prntItem);
		while (m_TreeADM.GetParentItem(prntItem))
		{
			prntItem = m_TreeADM.GetParentItem(prntItem);
			m_strObjCN.Append(',' + m_TreeADM.GetItemText(prntItem));
		}

		/*CStringArray strRstData;
		m_plginwnd->m_pAW->GetAttribute(strRstData, (LPCTSTR)m_strObjCN, (LPCTSTR)m_plginwnd->m_strIP, (LPCTSTR)m_plginwnd->m_strID, (LPCTSTR)m_plginwnd->m_strPWD);
		CString Type = strRstData.GetAt(1);
		CString Seperator = _T(",");
		int Position = 0;
		CString Token;

		Token = Type.Tokenize(Seperator, Position);
		if (!Token.Compare(_T("CN=Person"))||!Token.Compare(_T("CN=Group")))
		{
			AfxMessageBox(_T("사용자나 그룹 객체는 하위 트리를 가질 수 없습니다."));
			return FALSE;
		}
*/

		HTREEITEM SrcItem = hSrcItem;
		CString m_strSrcObj;
		m_strSrcObj = m_TreeADM.GetItemText(SrcItem);
		while (m_TreeADM.GetParentItem(SrcItem))
		{
			SrcItem = m_TreeADM.GetParentItem(SrcItem);
			m_strSrcObj.Append(',' + m_TreeADM.GetItemText(SrcItem));
		}
		m_plginwnd->m_pAW->MoveObject((LPCTSTR)m_plginwnd->m_strIP, (LPCTSTR)m_plginwnd->m_strID, (LPCTSTR)m_plginwnd->m_strPWD, (LPCTSTR)m_strObjCN, (LPCTSTR)m_strSrcObj);
		//---------------------------------------------------------------------



		HTREEITEM hItem = pTree->InsertItem(&TI);
		pTree->SetItemData(hItem, dwData);
		// 현재 아이템에 자식 아이템이 있다면
		HTREEITEM hChildItem = pTree->GetChildItem(hSrcItem);
		// pTree->GetNextItem(hSrcItem, TVGN_CHILD);
		if (hChildItem)
		{
			MoveChildTreeItem(pTree, hChildItem, hItem);
		}
		// 확장 여부를 알아서 똑같이 하자.
		TVITEM  item;
		item.mask = TVIF_HANDLE;
		item.hItem = hSrcItem;
		pTree->GetItem(&item);
		if (item.state & TVIS_EXPANDED)
		{
			pTree->Expand(hItem, TVE_EXPAND);
		}
		// 다음 아이템을 알아보자.
		hSrcItem = pTree->GetNextItem(hSrcItem, TVGN_NEXT);
	}
	// 기존 아이템을 제거한다.
	pTree->DeleteItem(hChildItem);
	return TRUE;
}

