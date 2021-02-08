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
	floatRect m_RelativeMap; /* 中心を0,0とする座標 マップ描画の移動回転に使う */
	floatRect m_AbsoluteMap; /* 左上を0,0とする座標　 */
	CMazeWall m_MazeWall;
};
