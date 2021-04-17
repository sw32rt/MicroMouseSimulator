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

void CScreen::Update(void)
{
	m_maze.Draw(m_hWnd, m_DisplayOffset, m_DisplayScale, m_DisplayRotate);

	{ // スタック節約するためスコープをつける
		CClientDC dc(m_hWnd);
		CString distance_xStr;
		CString distance_yStr;
		CString distance_rStr;
		for (auto line : m_MeasureLines)
		{
			dc.MoveTo(line.from);
			dc.LineTo(line.to);
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
		pFont = dc.SelectObject(&font);        // フォントを設定。
		dc.SetTextColor(RGB(230, 230, 230));     // 色も変えられる。
		dc.SetBkColor(RGB(50, 50, 50));       // 背景色も変えたり出来る。
		//dc.SetBkColor(RGB(230, 230, 230));       // 背景色も変えたり出来る。
		CRect rect;
		GetClientRect(m_hWnd->m_hWnd, rect);
		//m_hWnd->ScreenToClient(rect);
		CSize textSize = dc.GetTextExtent(distance_xStr);
		LONG textOffset_x = 0;
		dc.TextOutW(0, rect.bottom - FontSize, distance_xStr);
		textOffset_x += textSize.cx + 10;
		dc.TextOutW(textOffset_x, rect.bottom - FontSize, distance_yStr);
		textOffset_x += textSize.cx + 10;
		dc.TextOutW(textOffset_x, rect.bottom - FontSize, distance_rStr);
		dc.SelectObject(pFont);                // フォントを元に戻す。
	}

}

void CScreen::InitMaze(void)
{

}
