
// MM1Dlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "MM1.h"
#include "MM1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
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


// CMM1Dlg ダイアログ



CMM1Dlg::CMM1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MM1_DIALOG, pParent)
	, m_Screen(this)
	, m_rotateSlider(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMM1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER1, m_rotateSlider);
	DDV_MinMaxInt(pDX, m_rotateSlider, 0, 360);
	DDX_Control(pDX, IDC_SLIDER1, m_rotateSliderCtrl);
	DDX_Control(pDX, IDC_RADIO_CURSORMODE_HAND, m_ddx_CursorModeHandRdioCtrl);
	DDX_Control(pDX, IDC_RADIO_CURSORMODE_MEASURE, m_ddx_CursorModeMeasureRdioCtrl);
	DDX_Control(pDX, IDC_RADIO_CURSORMODE_CURSOR, m_ddx_CursorModeCursorRdioCtrl);
}

BEGIN_MESSAGE_MAP(CMM1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMM1Dlg::OnBnClickedOk)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEWHEEL()
	ON_WM_MBUTTONDBLCLK()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_NCLBUTTONDOWN()
	ON_WM_NCLBUTTONUP()
	ON_WM_NCMBUTTONDOWN()
	ON_WM_NCMBUTTONUP()
	ON_WM_NCRBUTTONDOWN()
	ON_WM_NCRBUTTONUP()
	ON_WM_NCMOUSELEAVE()
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER1, &CMM1Dlg::OnTRBNThumbPosChangingSlider1)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_RADIO_CURSORMODE_HAND, &CMM1Dlg::OnBnClickedRadioCursormodeHand)
	ON_BN_CLICKED(IDC_RADIO_CURSORMODE_MEASURE, &CMM1Dlg::OnBnClickedRadioCursormodeMeasure)
	ON_BN_CLICKED(IDC_RADIO_CURSORMODE_CURSOR, &CMM1Dlg::OnBnClickedRadioCursormodeCursor)
END_MESSAGE_MAP()


// CMM1Dlg メッセージ ハンドラー

void CMM1Dlg::OnCursorModeRadioClick(int mode)
{
	m_ddx_CursorModeHandRdioCtrl.SetBitmap(m_bmpCursorModeHandOff);
	m_ddx_CursorModeMeasureRdioCtrl.SetBitmap(m_bmpCursorModeHandOff);
	m_ddx_CursorModeCursorRdioCtrl.SetBitmap(m_bmpCursorModeHandOff);

	switch (mode)
	{
	case E_CursorMode_Hand:
		m_CursorMode = E_CursorMode_Hand;
		m_ddx_CursorModeHandRdioCtrl.SetBitmap(m_bmpCursorModeHandOn);
		m_ddx_CursorModeHandRdioCtrl.Invalidate(TRUE);
		break;
	case E_CursorMode_Measure:
		m_CursorMode = E_CursorMode_Measure;
		m_ddx_CursorModeMeasureRdioCtrl.SetBitmap(m_bmpCursorModeHandOn);
		m_ddx_CursorModeMeasureRdioCtrl.Invalidate(TRUE);
		break;
	case E_CursorMode_Cursor:
		m_CursorMode = E_CursorMode_Cursor;
		m_ddx_CursorModeCursorRdioCtrl.SetBitmap(m_bmpCursorModeHandOn);
		m_ddx_CursorModeCursorRdioCtrl.Invalidate(TRUE);
		break;
	default:
		break;
	}
}

BOOL CMM1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
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

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	//SetTimer(m_TickTimerID, m_TickTimerInterval, NULL);
	/* 前回位置を初期値にしておく */
	m_SCreenDisplayPreOffset = m_Screen.m_DisplayOffset;

	m_bmpCursorModeHandOn.LoadBitmap(IDB_HANDTOOL_ON);
	m_bmpCursorModeHandOff.LoadBitmap(IDB_HANDTOOL_OFF);

	// 従来の CButton の場合、ボタンにビットマップを割り当てると、強制的にクラシック スタイルになる。
	CRect checkButtonRect;
	m_ddx_CursorModeHandRdioCtrl.SetBitmap(m_bmpCursorModeHandOff);
	m_ddx_CursorModeHandRdioCtrl.SetWindowPos(NULL, 0, 0, 24, 24, SWP_NOMOVE | SWP_NOZORDER);
	m_ddx_CursorModeHandRdioCtrl.SetCheck(BST_CHECKED);
	OnBnClickedRadioCursormodeHand();
	m_ddx_CursorModeHandRdioCtrl.GetWindowRect(checkButtonRect);
	ScreenToClient(checkButtonRect);
	m_ddx_CursorModeMeasureRdioCtrl.SetBitmap(m_bmpCursorModeHandOff);
	m_ddx_CursorModeMeasureRdioCtrl.SetWindowPos(NULL, checkButtonRect.right, checkButtonRect.top, 24, 24, SWP_NOZORDER);
	m_ddx_CursorModeMeasureRdioCtrl.GetWindowRect(checkButtonRect);
	ScreenToClient(checkButtonRect);
	m_ddx_CursorModeCursorRdioCtrl.SetBitmap(m_bmpCursorModeHandOff);
	m_ddx_CursorModeCursorRdioCtrl.SetWindowPos(NULL, checkButtonRect.right, checkButtonRect.top, 24, 24, SWP_NOZORDER);

	// debug
	m_Screen.m_MeasureLines.resize(1);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CMM1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CMM1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{

		CDialogEx::OnPaint();
	}
		m_Screen.Update();
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CMM1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMM1Dlg::OnBnClickedOk()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	//CDialogEx::OnOK();
}


void CMM1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	//Invalidate(FALSE);

	CDialogEx::OnTimer(nIDEvent);
}


void CMM1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	m_IsMouseLButtonDown = true;
	switch (m_CursorMode)
	{
	case E_CursorMode_Hand:
		TRACKMOUSEEVENT track;

		track.cbSize = sizeof(track);
		track.hwndTrack = *this;
		track.dwHoverTime = HOVER_DEFAULT;

		// WM_MOUSEHOVER，WM_MOUSELEAVE をリクエストする．
		track.dwFlags = TME_HOVER | TME_LEAVE;
		TrackMouseEvent(&track);
		m_MouseMoveStart = point;
		break;
	case E_CursorMode_Measure:
		if (m_MeasureStart)
		{// 終点処理
			m_MeasureStart = !m_MeasureStart; //falseにする　=falseとか書くとケアレスミスしやすい
			CPoint diffp = point - m_MeasureStartPoint;
			m_Screen.m_MeasureLines.at(0) = (stLine_t{ point, m_MeasureStartPoint });
			Invalidate(FALSE);
		}
		else
		{// 始点処理
			m_MeasureStart = !m_MeasureStart;
			m_MeasureStartPoint = point;
		}
		break;
	case E_CursorMode_Cursor:
		break;
	default:
		break;
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMM1Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	switch (m_CursorMode)
	{
	case E_CursorMode_Hand:
		m_IsMouseLButtonDown = false;
		m_SCreenDisplayPreOffset = m_Screen.m_DisplayOffset;
		break;
	case E_CursorMode_Measure:
		break;
	case E_CursorMode_Cursor:
		break;
	default:
		break;
	}


	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMM1Dlg::OnMButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnMButtonDblClk(nFlags, point);
}


void CMM1Dlg::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	TRACKMOUSEEVENT track;

	track.cbSize = sizeof(track);
	track.hwndTrack = *this;
	track.dwHoverTime = HOVER_DEFAULT;

	// WM_MOUSEHOVER，WM_MOUSELEAVE をリクエストする．
	track.dwFlags = TME_HOVER | TME_LEAVE;
	TrackMouseEvent(&track);

	m_IsMouseLButtonDown = true;
	m_MouseMoveStart = point;
	CDialogEx::OnMButtonDown(nFlags, point);
}


void CMM1Dlg::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	m_IsMouseLButtonDown = false;
	m_SCreenDisplayPreOffset = m_Screen.m_DisplayOffset;
	CDialogEx::OnMButtonUp(nFlags, point);
}


void CMM1Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	
	switch (m_CursorMode)
	{
	case E_CursorMode_Hand:
		if (m_IsMouseLButtonDown)
		{
			m_Screen.m_DisplayOffset = m_SCreenDisplayPreOffset + (point - m_MouseMoveStart);
			Invalidate(TRUE); /* 再描画させる */
		}
		break;
	case E_CursorMode_Measure:
		if (m_MeasureStart)
		{
			m_Screen.m_MeasureLines.at(0) = (stLine_t{ point, m_MeasureStartPoint });
			Invalidate(TRUE); /* 再描画させる */
		}
		break;
	case E_CursorMode_Cursor:
		break;
	default:
		break;
	}


	CDialogEx::OnMouseMove(nFlags, point);
}


void CMM1Dlg::OnMouseLeave()
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	switch (m_CursorMode)
	{
	case E_CursorMode_Hand:
		if (m_IsMouseLButtonDown)
		{
			m_IsMouseLButtonDown = false;
			m_SCreenDisplayPreOffset = m_Screen.m_DisplayOffset;
		}
		break;
	case E_CursorMode_Measure:
		break;
	case E_CursorMode_Cursor:
		break;
	default:
		break;
	}
	CDialogEx::OnMouseLeave();
}


void CMM1Dlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnRButtonDown(nFlags, point);
}


void CMM1Dlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnRButtonUp(nFlags, point);
}


void CMM1Dlg::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnRButtonDblClk(nFlags, point);
}


void CMM1Dlg::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnNcLButtonDown(nHitTest, point);
}


void CMM1Dlg::OnNcLButtonUp(UINT nHitTest, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnNcLButtonUp(nHitTest, point);
}


void CMM1Dlg::OnNcMButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnNcMButtonDown(nHitTest, point);
}


void CMM1Dlg::OnNcMButtonUp(UINT nHitTest, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnNcMButtonUp(nHitTest, point);
}


void CMM1Dlg::OnNcRButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnNcRButtonDown(nHitTest, point);
}


void CMM1Dlg::OnNcRButtonUp(UINT nHitTest, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnNcRButtonUp(nHitTest, point);
}


void CMM1Dlg::OnNcMouseLeave()
{
	// この機能は Windows 2000 かそれ以降のバージョンを必要とします。
	// シンボル _WIN32_WINNTと WINVER は >= 0x0500 にならなければなりません。
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	CDialogEx::OnNcMouseLeave();
}


BOOL CMM1Dlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	ScreenToClient(&pt);
	static double pre = 0;
	floatPoint cursorPoint = pt;
	pre = m_Screen.m_DisplayScale;
	if (zDelta > 0)
	{ /* Up */
		m_Screen.m_DisplayScale *= ZOOMIN_RATE;
		if(m_Screen.m_DisplayScale > 10.0)
		{
			m_Screen.m_DisplayScale = 10.0;
		}
		/* マウスカーソルの位置を中心にズームするように見せるため、ズームした後位置調整する */
		m_Screen.m_DisplayOffset += (m_Screen.m_DisplayOffset - cursorPoint) * ((m_Screen.m_DisplayScale / pre) - 1);
	}
	else
	{ /* Down */
		m_Screen.m_DisplayScale *= ZOOMOUT_RATE;
		if (m_Screen.m_DisplayScale <= 0.1)
		{
			m_Screen.m_DisplayScale = 0.1;
		}
		/* マウスカーソルの位置を中心にズームするように見せるため、ズームした後位置調整する */
		m_Screen.m_DisplayOffset -= (m_Screen.m_DisplayOffset - cursorPoint) * (1 - (m_Screen.m_DisplayScale / pre));
	}

	m_SCreenDisplayPreOffset = m_Screen.m_DisplayOffset;

	Invalidate(TRUE); /* 再描画させる */
	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}



void CMM1Dlg::OnTRBNThumbPosChangingSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// この機能には Windows Vista 以降のバージョンが必要です。
	// シンボル _WIN32_WINNT は >= 0x0600 にする必要があります。
	NMTRBTHUMBPOSCHANGING* pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING*>(pNMHDR);
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	UpdateData(FALSE);
	m_Screen.m_DisplayRotate = m_rotateSlider;
	UpdateData(TRUE);

	*pResult = 0;
}


void CMM1Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。

	if (pScrollBar == (CScrollBar*)&m_rotateSliderCtrl)
	{
		m_Screen.m_DisplayRotate = m_rotateSliderCtrl.GetPos();
		Invalidate(TRUE); /* 再描画させる */
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMM1Dlg::OnBnClickedRadioCursormodeHand()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	// 従来の CButton の場合、ボタンにビットマップを割り当てると、強制的にクラシック スタイルになる。
	OnCursorModeRadioClick(E_CursorMode_Hand);
}


void CMM1Dlg::OnBnClickedRadioCursormodeMeasure()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	OnCursorModeRadioClick(E_CursorMode_Measure);
}


void CMM1Dlg::OnBnClickedRadioCursormodeCursor()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	OnCursorModeRadioClick(E_CursorMode_Cursor);
}


void CMM1Dlg::OnCancel()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。

	CDialogEx::OnCancel();
}
