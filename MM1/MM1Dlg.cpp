
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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMM1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
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
END_MESSAGE_MAP()


// CMM1Dlg メッセージ ハンドラー

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
	m_MouseMoveStart = point;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMM1Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	m_IsMouseLButtonDown = false;
	m_SCreenDisplayPreOffset = m_Screen.m_DisplayOffset;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CMM1Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	if (m_IsMouseLButtonDown)
	{
		m_Screen.m_DisplayOffset = m_SCreenDisplayPreOffset + (point - m_MouseMoveStart);
		Invalidate(TRUE); /* 再描画させる */
	}
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMM1Dlg::OnMouseLeave()
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	m_IsMouseLButtonDown = false;
	m_SCreenDisplayPreOffset = m_Screen.m_DisplayOffset;
	CDialogEx::OnMouseLeave();
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
