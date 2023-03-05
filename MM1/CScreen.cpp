#include "pch.h"
#include "CScreen.h"
#include "MM1Dlg.h"

CScreen::CScreen(CMM1Dlg* hwnd)
	: m_hWnd(hwnd)
	, m_maze(MAZE_SIZE)
{
	InitMaze();
}

CScreen::~CScreen()
{
}

void CScreen::Update(CHwndRenderTarget* pRenderTarget)
{
	//CClientDC cldc(m_hWnd);
	//// 対象コントロール(またはウィンドウ)のデバイスコンテキスト
	//CDC* pDC = m_hWnd->GetDC();
	//// 仮想デバイスコンテキスト
	//CDC memDC;
	//// 仮想デバイスコンテキスト用ビットマップ
	//CBitmap memBmp;
	//// 矩形
	//CRect rc;

	//// 対象コントロール(またはウィンドウ)の矩形取得
	//m_hWnd->GetClientRect(rc);
	//// 仮想デバイスコンテキスト生成
	//memDC.CreateCompatibleDC(pDC);
	//// 仮想デバイスコンテキスト用ビットマップ生成
	//memBmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	//// 仮想デバイスコンテキストにビットマップ割り当て
	//memDC.SelectObject(&memBmp);

//pRenderTarget->FillSolidRect(rc, RGB(255, 255, 255));

	// 描画処理(memDCに対して描画)
	m_maze.Draw(pRenderTarget, m_DisplayOffset, m_DisplayScale, m_DisplayRotate);

#if 0 /* 距離計測 描画 */
	CString distance_xStr;
	CString distance_yStr;
	CString distance_rStr;
	for (auto line : m_MeasureLines)
	{
		pRenderTarget->MoveTo(line.from);
		pRenderTarget->LineTo(line.to);
		floatPoint distance = line.to - line.from;
		distance = distance / m_DisplayScale;
		distance_xStr.Format(L"x:%lf", abs(distance.x));
		distance_yStr.Format(L"y:%lf", abs(distance.y));
		distance_rStr.Format(L"r:%lf", abs(sqrt((distance.x * distance.x) + (distance.y * distance.y))));
	}
	CFont* pFont;
	CFont font;
	const int FontSize = 16;
	// フォントを作成する
	font.CreateFont(
		FontSize,                   // フォントの高さ(大きさ)。
		0,                    // フォントの幅。普通０。
		0,                    // 角度。０でＯＫ。
		0,                    // 同じく角度。これも０。
		FW_DONTCARE,          // 文字の太さ。
		FALSE,                // フォントがイタリックならTRUEを指定。
		FALSE,                // 下線を引くならTRUE。
		FALSE,                // 取り消し線を引くならTRUE。
		SHIFTJIS_CHARSET,     // フォントの文字セット。このままでＯＫ。
		OUT_DEFAULT_PRECIS,   // 出力精度の設定。このままでＯＫ。
		CLIP_DEFAULT_PRECIS,  // クリッピング精度。このままでＯＫ。
		DRAFT_QUALITY,        // フォントの出力品質。このままでＯＫ。
		FIXED_PITCH,        // フォントのピッチとファミリを指定。このままでＯＫ。
		//DEFAULT_PITCH,        // フォントのピッチとファミリを指定。このままでＯＫ。
		_T("consolas") // フォントのタイプフェイス名の指定。これは見たまんま。
	);
	pFont = memDC.SelectObject(&font);        // フォントを設定。
	memDC.SetTextColor(RGB(230, 230, 230));     // 色も変えられる。
	memDC.SetBkColor(RGB(50, 50, 50));       // 背景色も変えたり出来る。
	//memDC.SetBkColor(RGB(230, 230, 230));       // 背景色も変えたり出来る。
	CRect rect;
	GetClientRect(m_hWnd->m_hWnd, rect);
	//m_hWnd->ScreenToClient(rect);
	CSize textSize = memDC.GetTextExtent(distance_xStr);
	LONG textOffset_x = 0;
	memDC.TextOutW(0, rect.bottom - FontSize, distance_xStr);
	textOffset_x += textSize.cx + 10;
	memDC.TextOutW(textOffset_x, rect.bottom - FontSize, distance_yStr);
	textOffset_x += textSize.cx + 10;
	memDC.TextOutW(textOffset_x, rect.bottom - FontSize, distance_rStr);
	memDC.SelectObject(pFont);                // フォントを元に戻す。
#endif
	// デバイスコンテキストに仮想デバイスコンテキスト貼り付け
	//pDC->BitBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);
	// 解放処理
	//memDC.DeleteDC();
	//memBmp.DeleteObject();
	//m_hWnd->ReleaseDC(pDC);
}

void CScreen::InitMaze(void)
{

}
