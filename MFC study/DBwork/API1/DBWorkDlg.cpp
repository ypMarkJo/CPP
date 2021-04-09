
// DBWorkDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "DBWork.h"
#include "DBWorkDlg.h"
#include "afxdialogex.h"
#include "APIApp2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

    // 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

 // 구현입니다.
protected:
    DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDBWorkDlg 대화 상자



CDBWorkDlg::CDBWorkDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_DBWORK_DIALOG, pParent)
    , m_nRecSize(0)
    , m_strQuery(_T("select* from film"))

{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDBWorkDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, m_ctrlListCtrl);
    DDX_Control(pDX, IDC_LIST2, m_ctrlLog);
    DDX_Text(pDX, IDC_RECSIZE, m_nRecSize);
    DDX_Text(pDX, IDC_EDIT1, m_strQuery);
}

BEGIN_MESSAGE_MAP(CDBWorkDlg, CDialogEx)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON1, &CDBWorkDlg::OnBnClickedButton1)
    ON_LBN_SELCHANGE(IDC_LIST2, &CDBWorkDlg::OnSelchangeList2)
    ON_BN_CLICKED(IDC_BUTTON2, &CDBWorkDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDBWorkDlg 메시지 처리기

BOOL CDBWorkDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

    // IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != nullptr)
    {
        BOOL bNameValid;
        CString strAboutMenu;
        bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
        ASSERT(bNameValid);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
    //  프레임워크가 이 작업을 자동으로 수행합니다.
    SetIcon(m_hIcon, TRUE);         // 큰 아이콘을 설정합니다.
    SetIcon(m_hIcon, FALSE);      // 작은 아이콘을 설정합니다.

    // TODO: 여기에 추가 초기화 작업을 추가합니다.
    //List Ctrl Title Setting

    LV_COLUMN lvcolumn;      //리스트 컨트롤 컬럼 속성을 입력할 변수를 선언
    lvcolumn.mask = LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH | LVCF_FMT;   //컬럼 마스크 설정

    // 리스트 컨트롤 스타일 수정
    m_ctrlListCtrl.SetExtendedStyle(m_ctrlListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    CString titlearr[7] = { _T("#"), _T("Code"), _T("Name"), _T("Continent"), _T("Population"), _T("GNP"), _T("GovernmentForm") };   // 컬럼 타이틀 문자 배열
    UINT titlewdt[7] = { 40, 50, 250, 180, 100, 100, 100 };            // 컬럼 타이틀 폭 배열
    UINT titlefmt[7] = { LVCFMT_LEFT, LVCFMT_CENTER, LVCFMT_LEFT, LVCFMT_LEFT, LVCFMT_RIGHT, LVCFMT_RIGHT, LVCFMT_RIGHT };
    // 컬럼 정렬 설정 배열

    for (int i = 0; i < 7; i++) {
        lvcolumn.pszText = (LPTSTR)(LPCTSTR)titlearr[i];   // 컬럼 타이틀 설정
        lvcolumn.iSubItem = i;         // 컬럼 인덱스 설정
        lvcolumn.cx = titlewdt[i];         // 컬럼 폭 설정
        lvcolumn.fmt = titlefmt[i];      // 컬럼 정렬 설정

        m_ctrlListCtrl.InsertColumn(i, &lvcolumn);   // 리스트 컨트롤에 컬럼 삽입
    }

    return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CDBWorkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)
    {
        CAboutDlg dlgAbout;
        dlgAbout.DoModal();
    }
    else
    {
        CDialogEx::OnSysCommand(nID, lParam);
    }
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDBWorkDlg::OnPaint()
{
    if (IsIconic())
    {
        CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

        SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

        // 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // 아이콘을 그립니다.
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialogEx::OnPaint();
    }
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDBWorkDlg::OnQueryDragIcon()
{
    return static_cast<HCURSOR>(m_hIcon);
}


void CDBWorkDlg::SetctrlTitle(MYSQL_RES* result)
{
    int nColumnCount = m_ctrlListCtrl.GetHeaderCtrl()->GetItemCount();

    // Delete all of the columns.
    for (int i = 0; i < nColumnCount; i++)
    {
        m_ctrlListCtrl.DeleteColumn(0);
    }
    unsigned int num_fields;
    unsigned int i;
    MYSQL_FIELD* fields;
    LV_COLUMN lvcolumn;      //리스트 컨트롤 컬럼 속성을 입력할 변수를 선언
    lvcolumn.mask = LVCF_TEXT | LVCF_SUBITEM | LVCF_WIDTH | LVCF_FMT;   //컬럼 마스크 설정

    lvcolumn.pszText = "#";   // 컬럼 타이틀 설정
    lvcolumn.iSubItem = 0;         // 컬럼 인덱스 설정
    lvcolumn.cx = 50;         // 컬럼 폭 설정
    lvcolumn.fmt = LVCFMT_LEFT;      // 컬럼 정렬 설정

    m_ctrlListCtrl.InsertColumn(0, &lvcolumn);   // 리스트 컨트롤에 컬럼 삽입

    num_fields = mysql_num_fields(result);
    fields = mysql_fetch_fields(result);
    for (i = 0; i < num_fields; i++)
    {
        //printf("Field %u is %s\n", i, fields[i].name);

        lvcolumn.pszText = fields[i].name;   // 컬럼 타이틀 설정
        lvcolumn.iSubItem = i + 1;         // 컬럼 인덱스 설정
        lvcolumn.cx = 150;         // 컬럼 폭 설정
        lvcolumn.fmt = LVCFMT_LEFT;      // 컬럼 정렬 설정

        m_ctrlListCtrl.InsertColumn(i + 1, &lvcolumn);   // 리스트 컨트롤에 컬럼 삽입

    }
}
void CDBWorkDlg::OnBnClickedButton1()
{
    MYSQL mysql;         //mysql을 사용하기 위한 변수
    mysql_init(&mysql);      //mysql 초기화

    if (!mysql_real_connect(&mysql, "localhost", "scott", "tiger", "world", 0, NULL, 0))
    {
        CString msg;
        msg.Format("Failed to connect to database: Error\n%s", mysql_error(&mysql));
        AfxMessageBox(msg);
        return;
    }
    mysql_query(&mysql, "set names euckr");      //출력 창에서 한글 깨지는거 없애준다.

    //mysql_query(&mysql, _T("select code, name from country"));   //mysql 질의 - query문 날리기
    //mysql_query(&mysql, _T("select code, name, continent,population, gnp, governmentform from country"));   //mysql 질의 - query문 날리기

    UpdateData(TRUE);
    if (m_strQuery.IsEmpty())
    {
        AfxMessageBox("No Kidding");
        return;
    }

    //m_ctrlLog.AddString(m_strQuery);
    m_ctrlLog.InsertString(0, m_strQuery);

    //mysql_query(&mysql, _T("select * from film where length<100"));   //mysql 질의
    if (mysql_query(&mysql, m_strQuery) != 0)   //mysql 질의
    {
        CString msg;
        msg.Format("Query Error : %s", mysql_error(&mysql));
        mysql_close(&mysql);
        AfxMessageBox(msg);
        return;
    }
    m_ctrlListCtrl.DeleteAllItems();   //리스트 컨트롤에 이미 입력되어 있는 데이터 제거

    MYSQL_RES* result = mysql_store_result(&mysql);      //질의 결과 받기
    if (!result)
    {
        mysql_close(&mysql);         //mysql 닫기
        return;
    }

    SetctrlTitle(result);

    m_nRecSize = 0;      //질의 결과 레코트 수를 담기 위한 변수, 초기화도 같이 진행   
    CString valstr;      //임시 레코드 번호를 컨트롤에 입력하기 위한 문자열 변수
    MYSQL_ROW row;      //질의 결과 데이터에서 한 개의 행(Record)를 저장할 변수
    unsigned int num_fields = mysql_num_fields(result);

    while (row = mysql_fetch_row(result))      //질의 결과를 한 행씩 가져와서 row 라는 변수에 넣어주기 (row 는 배열 형식으로 되어있다, 데이터 타입은 무조건 string으로 받는다.)
    {
        valstr.Format("%d", m_nRecSize + 1);
        m_ctrlListCtrl.InsertItem(m_nRecSize, valstr);      //리스트 컨트롤 제일 첫번째 열에 임시 레코드번호 삽입   최초에 넣을때는 insert

        for (int i = 0; i < num_fields; i++)                     //남은 6개의 데이터를 읽어서 리스트 컨트롤에 설정
            m_ctrlListCtrl.SetItemText(m_nRecSize, i + 1, row[i]);      //데이터는 배열 형식으로 접근            그 뒤에는 SetItem

        m_nRecSize++;
    }
    mysql_free_result(result);      //질의 결과 메모리 해제
    mysql_close(&mysql);
    UpdateData(FALSE);            //변경 값을 컨트롤에 적용 -> dialog box 왼쪽 하단에 m_nRecSize(행(데이터) 개수) 요고 업데이트 (변수 값 세팅 -> 화면에 보이게 할때는 FALSE)
}

void CDBWorkDlg::OnSelchangeList2()
{
    int idx = m_ctrlLog.GetCurSel();
    m_ctrlLog.GetText(idx, m_strQuery);
    UpdateData(FALSE);
}

void CDBWorkDlg::OnBnClickedButton2()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    APIApp2 dlg;
    dlg.DoModal();

}
