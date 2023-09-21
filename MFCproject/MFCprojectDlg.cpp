
// MFCprojectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCproject.h"
#include "MFCprojectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

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


// CMFCprojectDlg 대화 상자



CMFCprojectDlg::CMFCprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
	, nSize(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_INPUT, nSize);
}

BEGIN_MESSAGE_MAP(CMFCprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON, &CMFCprojectDlg::OnBnClickedButton)
	ON_BN_CLICKED(IDC_BUTTON_DRAW, &CMFCprojectDlg::OnBnClickedButtonDraw)
END_MESSAGE_MAP()


// CMFCprojectDlg 메시지 처리기

BOOL CMFCprojectDlg::OnInitDialog()
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

void CMFCprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCprojectDlg::OnPaint()
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
HCURSOR CMFCprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCprojectDlg::OnBnClickedButton()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 24;

	m_image.Create(nWidth, -nHeight, nBpp);

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits(); //이미지의 첫 번째 포인터를 가져옴

	memset(fm, 255, sizeof(unsigned char) * 3 * nWidth * nHeight);

	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

void CMFCprojectDlg::UpdateDisplay(int x, int y)
{
	CClientDC dc(this);
	m_image.Draw(dc, x, y);
}

void CMFCprojectDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + nRadius * 2; j++)
	{
		for (int i = x; i < x + nRadius * 2; i++)
		{
			if (isInCircle(i, j, nCenterX, nCenterY, nRadius))
				fm[j * nPitch + i * 3] = fm[j * nPitch + i * 3 + 1] = fm[j * nPitch + i * 3 + 2] = nGray;
		}
	}
}

bool CMFCprojectDlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius)
	{
		bRet = true;
	}

	return bRet;
}

void CMFCprojectDlg::drawCross(unsigned char* fm, int x, int y, int nSize, int nWhite)
{
	int nCenterX = x + nSize / 2;
	int nCenterY = y + nSize / 2;
	int nPitch = m_image.GetPitch();

	for (int i = nCenterX - nSize / 10; i < nCenterX + nSize / 10; i++)
	{
		if (i >= 0 && i < m_image.GetWidth())
			fm[nCenterY * nPitch + i * 3] = fm[nCenterY * nPitch + i * 3 + 1] = fm[nCenterY * nPitch + i * 3 + 2] = nWhite;
	}

	for (int j = nCenterY - nSize / 10; j < nCenterY + nSize / 10; j++)
	{
		if (j >= 0 && j < m_image.GetHeight())
			fm[j * nPitch + nCenterX * 3] = fm[j * nPitch + nCenterX * 3 + 1] = fm[j * nPitch + nCenterX * 3 + 2] = nWhite;
	}
}


void CMFCprojectDlg::drawCircleBorder(unsigned char* fm, int x, int y, int nRadius, int nBorderSize, COLORREF nBorderColor)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	for (int j = 0; j < nHeight ; j++)
	{
		for (int i = 0; i < nWidth; i++)
		{
			double dX = i - nCenterX;
			double dY = j - nCenterY;
			double dDist = dX * dX + dY * dY;

			if (dDist >= (nRadius) * (nRadius) && dDist <= (nRadius+nBorderSize) * (nRadius+nBorderSize))
			{
					fm[j * nPitch + i * 3] = GetRValue(nBorderColor);
					fm[j * nPitch + i * 3 + 1] = GetGValue(nBorderColor);
					fm[j * nPitch + i * 3 + 2] = GetBValue(nBorderColor);
			}
		}
	}
}


#include <iostream>
using namespace std;
void CMFCprojectDlg::OnBnClickedButtonDraw()
{
	UpdateData(TRUE);

	int nGray = 80;
	int nWhite = 255;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = nSize / 2;
	int nBorderSize = 5; 
	COLORREF nBorderColor = RGB(0, 255, 255);

	int nSttX = rand() % (nWidth - nRadius * 2);
	int nSttY = rand() % (nHeight - nRadius * 2);
	
	cout << nSttX<< ":" << nSttY << ":" << nRadius << endl;

	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 255, sizeof(unsigned char) * 3 * nWidth * nHeight);

	drawCircleBorder(fm, nSttX, nSttY, nRadius, nBorderSize, nBorderColor);
	drawCircle(fm, nSttX, nSttY, nRadius, nGray);
	drawCross(fm, nSttX, nSttY, nRadius * 2, nWhite);

	UpdateDisplay(0, 0);
}