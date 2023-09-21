
// MFCprojectDlg.h: 헤더 파일
//

#pragma once


// CMFCprojectDlg 대화 상자
class CMFCprojectDlg : public CDialogEx
{
private:
	CImage m_image;
// 생성입니다.
public:
	CMFCprojectDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


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
	INT nSize;
	void UpdateDisplay(int x, int y);
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	bool isInCircle(int i, int j, int nCenterX, int nCentery, int nRadius);
	void drawCross(unsigned char* fm, int x, int y, int nSize, int nWhite);
	void drawCircleBorder(unsigned char* fm, int x, int y, int nRadius, int nBorderSize, COLORREF BorderColor);
	afx_msg void OnBnClickedButton();
	afx_msg void OnBnClickedButtonDraw();
};
