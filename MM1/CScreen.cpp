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
	//// �ΏۃR���g���[��(�܂��̓E�B���h�E)�̃f�o�C�X�R���e�L�X�g
	//CDC* pDC = m_hWnd->GetDC();
	//// ���z�f�o�C�X�R���e�L�X�g
	//CDC memDC;
	//// ���z�f�o�C�X�R���e�L�X�g�p�r�b�g�}�b�v
	//CBitmap memBmp;
	//// ��`
	//CRect rc;

	//// �ΏۃR���g���[��(�܂��̓E�B���h�E)�̋�`�擾
	//m_hWnd->GetClientRect(rc);
	//// ���z�f�o�C�X�R���e�L�X�g����
	//memDC.CreateCompatibleDC(pDC);
	//// ���z�f�o�C�X�R���e�L�X�g�p�r�b�g�}�b�v����
	//memBmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
	//// ���z�f�o�C�X�R���e�L�X�g�Ƀr�b�g�}�b�v���蓖��
	//memDC.SelectObject(&memBmp);

//pRenderTarget->FillSolidRect(rc, RGB(255, 255, 255));

	// �`�揈��(memDC�ɑ΂��ĕ`��)
	m_maze.Draw(pRenderTarget, m_DisplayOffset, m_DisplayScale, m_DisplayRotate);

#if 0 /* �����v�� �`�� */
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
	pFont = memDC.SelectObject(&font);        // �t�H���g��ݒ�B
	memDC.SetTextColor(RGB(230, 230, 230));     // �F���ς�����B
	memDC.SetBkColor(RGB(50, 50, 50));       // �w�i�F���ς�����o����B
	//memDC.SetBkColor(RGB(230, 230, 230));       // �w�i�F���ς�����o����B
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
	memDC.SelectObject(pFont);                // �t�H���g�����ɖ߂��B
#endif
	// �f�o�C�X�R���e�L�X�g�ɉ��z�f�o�C�X�R���e�L�X�g�\��t��
	//pDC->BitBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);
	// �������
	//memDC.DeleteDC();
	//memBmp.DeleteObject();
	//m_hWnd->ReleaseDC(pDC);
}

void CScreen::InitMaze(void)
{

}
