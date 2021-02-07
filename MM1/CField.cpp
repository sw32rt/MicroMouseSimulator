#include "pch.h"
#include "CField.h"

floatSize::floatSize()
	: width(0)
	, height(0)
{
}

floatSize::floatSize(double width, double height)
	: width(width)
	, height(height)
{
}

floatSize::~floatSize()
{
}

floatPoint::floatPoint()
	: x(0)
	, y(0)
{
}

floatPoint::floatPoint(double x, double y)
	: x(x)
	, y(y)
{
}

floatPoint::~floatPoint()
{
}

floatPoint& floatPoint::operator=(const CPoint &point)
{
	this->x = point.x;
	this->y = point.y;
	return *this;
}

floatPoint floatPoint::operator+(const floatPoint point) const
{
	return floatPoint(this->x + point.x, this->y + point.y);
}

floatPoint floatPoint::operator-(const floatPoint point) const
{
	return floatPoint(this->x - point.x, this->y - point.y);
}

floatPoint& floatPoint::operator+=(const floatPoint& point)
{
	*this = *this + point;
	return *this;
}

floatPoint& floatPoint::operator-=(const floatPoint& point)
{
	*this = *this - point;
	return *this;
}

floatPoint floatPoint::operator*(const floatPoint point) const
{
	return floatPoint(this->x * point.x, this->y * point.y);
}

floatPoint floatPoint::operator/(const floatPoint point) const
{
	return floatPoint(this->x / point.x, this->y / point.y);
}

floatPoint floatPoint::operator*(const double multi) const
{
	return floatPoint(this->x * multi, this->y * multi);
}

floatPoint floatPoint::operator/(const double division) const
{
	return floatPoint(this->x * division, this->y * division);
}

floatRect::floatRect()
	: lefttop()
	, rightbottom()
{
}

floatRect::floatRect(floatPoint lefttop, floatPoint rightbottom)
	: lefttop(lefttop)
	, rightbottom(rightbottom)
{
}

floatRect::~floatRect()
{
}

floatRect floatRect::operator+(const floatRect frect) const
{
	floatRect ret;
	ret.lefttop = lefttop + frect.lefttop;
	ret.rightbottom = rightbottom + frect.rightbottom;

	return ret;
}

floatRect floatRect::operator-(const floatRect frect) const
{
	floatRect ret;
	ret.lefttop = this->lefttop - frect.lefttop;
	ret.rightbottom = this->rightbottom - frect.rightbottom;

	return ret;
}

CField::CField(floatSize size, floatPoint center)
	: m_MapSize(size)
	, m_MapOrigin(center)
	, m_AbsoluteMap()
	, m_RelativeMap()
{
	m_AbsoluteMap.lefttop = floatPoint(0, 0);
	m_AbsoluteMap.rightbottom = floatPoint(size.width, size.height);

	/* ÉZÉìÉ^Å[çáÇÌÇπ */
	m_RelativeMap.lefttop = m_AbsoluteMap.lefttop - (m_MapOrigin / 2.0);
	m_RelativeMap.rightbottom = m_AbsoluteMap.rightbottom - (m_MapOrigin / 2.0);

}

CField::CField()
{
}

CField::~CField()
{
}


