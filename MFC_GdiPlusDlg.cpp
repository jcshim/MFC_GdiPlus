
// MFC_GdiPlusDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_GdiPlus.h"
#include "MFC_GdiPlusDlg.h"
#include "afxdialogex.h"

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


// CMFCGdiPlusDlg 대화 상자



CMFCGdiPlusDlg::CMFCGdiPlusDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_GDIPLUS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCGdiPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCGdiPlusDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCGdiPlusDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCGdiPlusDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCGdiPlusDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCGdiPlusDlg 메시지 처리기

BOOL CMFCGdiPlusDlg::OnInitDialog()
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
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCGdiPlusDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCGdiPlusDlg::OnPaint()
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
HCURSOR CMFCGdiPlusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCGdiPlusDlg::OnBnClickedButton1()
{
	CClientDC dc(this);
	Graphics g(dc);
	Pen      pen(Color(255, 0, 0, 255),64);
	g.DrawLine(&pen, 40, 40, 200, 50);
	g.SetSmoothingMode(SmoothingModeAntiAlias);
	g.DrawLine(&pen, 40, 40+80, 200, 50+80);
/*
	CClientDC dc(this);
	Graphics g(dc);
	Pen p(Color(127, 0, 0, 255), 16);
	g.SetSmoothingMode(SmoothingModeAntiAlias);
	g.DrawEllipse(&p, 10, 10, 300, 200);
*/
}


void CMFCGdiPlusDlg::OnBnClickedButton2()
{
	CClientDC dc(this);
	Image im(L"p.png");
	Graphics graphics(dc);
	graphics.DrawImage(&im, 0, 0,im.GetWidth()/2,
		im.GetHeight()/2);
}


void CMFCGdiPlusDlg::OnBnClickedButton3()
{ //https://docs.microsoft.com/en-us/windows/win32/gdiplus/-gdiplus-rotating-reflecting-and-skewing-images-use
	CClientDC dc(this);
	Graphics g(dc);
	Image im(L"m.png");
	int w = im.GetWidth() / 2;
	int h = im.GetHeight() / 2;
	Point dp[] = {
      Point(5+w, 0),  // destination for upper-left point of original
      Point(5+w+w/2 + 5, h/4),   // destination for upper-right point of original
      Point(5+w, h) }; // destination for lower-left point of original
	// Draw the image unaltered with its upper-left corner at (0, 0).
	g.DrawImage(&im, 0, 0, w, h);
	// Draw the image mapped to the parallelogram.
	g.DrawImage(&im, dp, 3);
}
