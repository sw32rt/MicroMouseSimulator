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

	{ // �X�^�b�N�ߖ񂷂邽�߃X�R�[�v������
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
		// �t�H���g���쐬����
		font.CreateFont(
			FontSize,                   // �t�H���g�̍���(�傫��)�B
			0,                    // �t�H���g�̕��B���ʂO�B
			0,                    // �p�x�B�O�łn�j�B
			0,                    // �������p�x�B������O�B
			FW_DONTCARE,          // �����̑����B
			FALSE,                // �t�H���g���C�^���b�N�Ȃ�TRUE���w��B
			FALSE,                // �����������Ȃ�TRUE�B
			FALSE,                // ���������������Ȃ�TRUE�B
			SHIFTJIS_CHARSET,     // �t�H���g�̕����Z�b�g�B���̂܂܂łn�j�B
			OUT_DEFAULT_PRECIS,   // �o�͐��x�̐ݒ�B���̂܂܂łn�j�B
			CLIP_DEFAULT_PRECIS,  // �N���b�s���O���x�B���̂܂܂łn�j�B
			DRAFT_QUALITY,        // �t�H���g�̏o�͕i���B���̂܂܂łn�j�B
			FIXED_PITCH,        // �t�H���g�̃s�b�`�ƃt�@�~�����w��B���̂܂܂łn�j�B
			//DEFAULT_PITCH,        // �t�H���g�̃s�b�`�ƃt�@�~�����w��B���̂܂܂łn�j�B
			_T("consolas") // �t�H���g�̃^�C�v�t�F�C�X���̎w��B����͌����܂�܁B
		);
		pFont = dc.SelectObject(&font);        // �t�H���g��ݒ�B
		dc.SetTextColor(RGB(230, 230, 230));     // �F���ς�����B
		dc.SetBkColor(RGB(50, 50, 50));       // �w�i�F���ς�����o����B
		//dc.SetBkColor(RGB(230, 230, 230));       // �w�i�F���ς�����o����B
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
		dc.SelectObject(pFont);                // �t�H���g�����ɖ߂��B
	}

}

void CScreen::InitMaze(void)
{

}
