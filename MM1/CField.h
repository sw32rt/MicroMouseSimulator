#pragma once
#include <vector>
#include "CMazeWall.h"
#include "CFloatRect.h"

class CField
{
public:
	CField();
	CField(int cells, floatSize size, floatPoint center);
	~CField();
	floatPoint m_MapOrigin;
	floatRect m_RelativeMap; /* ���S��0,0�Ƃ�����W �}�b�v�`��̈ړ���]�Ɏg�� */
	floatRect m_AbsoluteMap; /* �����0,0�Ƃ�����W�@ */
	CMazeWall m_MazeWall;
};
