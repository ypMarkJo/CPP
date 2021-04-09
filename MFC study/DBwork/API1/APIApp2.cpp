// APIApp2.cpp: 구현 파일
//

#include "pch.h"
#include "APIApp2.h"
#include "afxdialogex.h"
#include "resource.h"
#include "mysql.h"



// APIApp2 대화 상자

IMPLEMENT_DYNAMIC(APIApp2, CDialogEx)

APIApp2::APIApp2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_APIApp2, pParent)
	, m_strUserID(_T("scott"))
	, m_strPasswd(_T("tiger"))
	, m_strCombo1(_T(""))
	, m_strSearch(_T(""))
	, m_strCombo2(_T(""))
	, m_strCombo3(_T(""))
	, m_dSearch(0)
	, m_strMessage(_T(""))
{

}

APIApp2::~APIApp2()
{
}

void APIApp2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_USERID, m_strUserID);
	DDX_Text(pDX, IDC_PASSWD, m_strPasswd);
	DDX_CBString(pDX, IDC_COMBO1, m_strCombo1);
	DDX_Text(pDX, IDC_SEARCHSTR1, m_strSearch);
	DDX_CBString(pDX, IDC_COMBO2, m_strCombo2);
	DDX_CBString(pDX, IDC_COMBO3, m_strCombo3);
	DDX_Text(pDX, IDC_SEARCHSTR2, m_dSearch);
	DDX_Text(pDX, IDC_MESSAGE, m_strMessage);
	DDX_Control(pDX, IDC_LIST1, m_ctrlListCtrl);
}


BEGIN_MESSAGE_MAP(APIApp2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &APIApp2::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &APIApp2::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &APIApp2::OnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &APIApp2::OnCbnSelchangeCombo1)
	ON_STN_CLICKED(IDC_MESSAGE, &APIApp2::OnStnClickedMessage)
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

//=======================================================================================================

BOOL APIApp2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	// List Ctrl Title Setting
	LV_COLUMN lvcolumn;	// 리스트 컨트롤 컬럼 속성을 입력할 변수 선언
	lvcolumn.mask = LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH | LVCF_FMT;	// 컬럼 마스크 설정

	// 리스트 컨트롤 스타일 수정
	m_ctrlListCtrl.SetExtendedStyle(m_ctrlListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	CString titlearr[7] = { _T("#"), _T("Code"), _T("Name"), _T("Region"), _T("Area"), _T("Population"), _T("GNP") };	// 컬럼 타이틀 문자 배열
	UINT titlewdt[7] = { 40, 50, 250, 180, 100, 100, 100 };				// 컬럼 타이틀 폭 배열
	UINT titlefmt[7] = { LVCFMT_LEFT, LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_RIGHT, LVCFMT_RIGHT, LVCFMT_RIGHT };
	// 컬럼 정렬 설정 배열

	for (int i = 0; i < 7; i++) {
		lvcolumn.pszText = (LPTSTR)(LPCTSTR)titlearr[i];	// 컬럼 타이틀 설정
		lvcolumn.iSubItem = i;			// 컬럼 인덱스 설정
		lvcolumn.cx = titlewdt[i];			// 컬럼 폭 설정
		lvcolumn.fmt = titlefmt[i];		// 컬럼 정렬 설정

		m_ctrlListCtrl.InsertColumn(i, &lvcolumn);	// 리스트 컨트롤에 컬럼 삽입
	}
	// ComboBox Setting
	CComboBox* pCbo = (CComboBox*)GetDlgItem(IDC_COMBO1);	// IDC_COMBO1 컨트롤 가져오기
	pCbo->AddString(_T("Code"));
	pCbo->AddString(_T("Name"));			// Combo Box에 데이터 추가
	pCbo->AddString(_T("Region"));			// Combo Box에 데이터 추가
	pCbo->SetCurSel(0);				// IDC_COMBO1 컨트롤의 디폴트 선택 데이터 설정

	pCbo = (CComboBox*)GetDlgItem(IDC_COMBO2);		 // IDC_COMBO2 컨트롤 가져오기
	pCbo->AddString(_T("SurfaceArea"));			 // Combo Box에 데이터 추가
	pCbo->AddString(_T("Population"));			 // Combo Box에 데이터 추가
	pCbo->AddString(_T("GNP"));				 // Combo Box에 데이터 추가
	pCbo->SetCurSel(0);				 // IDC_COMBO2 컨트롤의 디폴트 선택 데이터 설정

	pCbo = (CComboBox*)GetDlgItem(IDC_COMBO3);		 // IDC_COMBO3 컨트롤 가져오기
	pCbo->AddString(_T(">="));				 // Combo Box에 데이터 추가
	pCbo->AddString(_T("="));				 // Combo Box에 데이터 추가
	pCbo->AddString(_T("<="));				 // Combo Box에 데이터 추가
	pCbo->SetCurSel(0);				 // IDC_COMBO3 컨트롤의 디폴트 선택 데이터 설정

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

//=======================================================================================================

BOOL APIApp2::validCheck(int type)
{
	if (m_strUserID.IsEmpty())	 // userid가 빈문자열인지 점검
	{
		AfxMessageBox("You need a UserID");
		return FALSE;
	}
	if (m_strPasswd.IsEmpty())	// passwd가 빈문자열인지 점검
	{
		AfxMessageBox("You need a Password");
		return FALSE;
	}
	// 문자열 검색 validation
	if (type == 1 && m_strSearch.IsEmpty())	 // type이 1인 경우 검색 문자열이 빈문자열인지 점검
	{
		AfxMessageBox("You need a Search String");
		return FALSE;
	}
	return TRUE;
}

int APIApp2::setDataToList(CString& strUserID, CString& strPasswd, CString strFilter, CString& sqlstr)
{
	// TODO: 여기에 구현 코드 추가.
	MYSQL mysql;
	mysql_init(&mysql);
	if (mysql_real_connect(&mysql, "localhost", strUserID, strPasswd, "world", 0, NULL, 0) == FALSE)
	{
		AfxMessageBox(mysql_error(&mysql));
		return -1;
	}
	if (!strFilter.IsEmpty())
		sqlstr = _T("select Code,Name,Region,SurfaceArea,Population,GNP from country where ") + strFilter;
	else
		sqlstr = _T("select Code,Name,Region,SurfaceArea,Population,GNP from country");

	mysql_query(&mysql, sqlstr);

	MYSQL_RES* result = mysql_store_result(&mysql);
	if (!result)
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return -1;
	}
	int idx = 0;
	CString valstr;
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))
	{
		valstr.Format("%d", idx + 1);
		m_ctrlListCtrl.InsertItem(idx, valstr);

		for (int i = 0; i < 6; i++)
			m_ctrlListCtrl.SetItemText(idx, i + 1, row[i]);

		idx++;
	}
	mysql_free_result(result);

	mysql_close(&mysql);

	return idx;

}

//=======================================================================================================
//
// APIApp2 메시지 처리기
//
//=======================================================================================================

void APIApp2::OnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	if (validCheck() == FALSE)return;	// 실행 전에 userid, passwd 점검

	m_ctrlListCtrl.DeleteAllItems();	// 리스트 컨트롤에 이미 입력된 데이터 제거

	CString sqlstr;			// 실행되는 SQL문을 가져오기 위한 변수

	// DB서버에 질의를 해서 리스트 컨트롤에 데이터를 설정하는 함수
	// 리턴되어 오는 값은 질의 결과 row(record) 개수
	int rec = setDataToList(m_strUserID, m_strPasswd, _T(""), sqlstr);

	m_strMessage = _T("");
	if (0 <= rec)m_strMessage.Format(_T("[%d]%s"), rec, sqlstr);	 // 메시지 변수에 값 설정

	UpdateData(FALSE);

}

void APIApp2::OnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (validCheck(1) == FALSE)		 // 실행 전에 userid, passwd, strSearch점검
		return;
	m_ctrlListCtrl.DeleteAllItems();		// 기존 검색 결과 삭제

	CString strFilter = m_strCombo1 + _T(" like '%") + m_strSearch + _T("%'"); // 질의 필터 문자열 생성

	CString sqlstr;
	int rec = setDataToList(m_strUserID, m_strPasswd, strFilter, sqlstr);	// 질의 및 결과 설정

	m_strMessage = _T("");
	if (0 <= rec)m_strMessage.Format(_T("[%d]%s"), rec, sqlstr);	 	// 메시지 문자열 설정

	UpdateData(FALSE);


}


void APIApp2::OnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (validCheck(1) == FALSE)		 // 실행 전에 userid, passwd, strSearch점검
		return;
	m_ctrlListCtrl.DeleteAllItems();		// 기존 검색 결과 삭제

	CString val;
	if (m_strCombo2 == _T("Population"))	val.Format(_T("%d"), (int)m_dSearch);
	else				val.Format(_T("%.2f"), m_dSearch);

	CString strFilter = m_strCombo2 + m_strCombo3 + val;		 // 질의 필터 문자열 생성 
	CString sqlstr;
	int rec = setDataToList(m_strUserID, m_strPasswd, strFilter, sqlstr);	// 질의 및 결과 설정

	m_strMessage = _T("");
	if (0 <= rec)m_strMessage.Format(_T("[%d]%s"), rec, sqlstr);	 	// 메시지 문자열 설정

	UpdateData(FALSE);

}


void APIApp2::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void APIApp2::OnStnClickedMessage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void APIApp2::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	lpMMI->ptMinTrackSize.x = 1300;
	lpMMI->ptMinTrackSize.y = 800;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}
