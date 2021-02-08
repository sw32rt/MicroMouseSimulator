#include "pch.h"
#include "CField.h"

CField::CField(int cells, floatSize size, floatPoint center)
	: m_MapOrigin(center)
	, m_AbsoluteMap()
	, m_RelativeMap()
	, m_MazeWall(cells)
{
	m_AbsoluteMap.lefttop = floatPoint(0, 0);
	m_AbsoluteMap.rightbottom = floatPoint(size.width, size.height);

	/* ÉZÉìÉ^Å[çáÇÌÇπ */
	m_RelativeMap.lefttop = m_AbsoluteMap.lefttop - (m_AbsoluteMap.rightbottom / 2.0);
	m_RelativeMap.rightbottom = m_AbsoluteMap.rightbottom - (m_AbsoluteMap.rightbottom / 2.0);
}

CField::CField()
	: m_MazeWall(16)
{

}

CField::~CField()
{
}


