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

floatPoint floatPoint::operator+(floatPoint point)
{
	return floatPoint(this->x * point.x, this->y + point.y);
}

floatPoint floatPoint::operator-(floatPoint point)
{
	return floatPoint(this->x - point.x, this->y - point.y);
}

floatRect::floatRect()
	: lefttop()
	, righttop()
	, rightbottom()
	, leftbottom()
{
}

floatRect::floatRect(floatPoint lefttop, floatPoint righttop, floatPoint rightbottom, floatPoint leftbottom)
	: lefttop(lefttop)
	, righttop(righttop)
	, rightbottom(rightbottom)
	, leftbottom(leftbottom)
{
}

floatRect::~floatRect()
{
}

floatRect floatRect::operator+(floatRect frect)
{
	floatRect ret;
	ret.lefttop = this->lefttop + frect.lefttop;
	ret.righttop = this->righttop + frect.righttop;
	ret.rightbottom = this->rightbottom + frect.rightbottom;
	ret.leftbottom = this->leftbottom + frect.leftbottom;

	return ret;
}

floatRect floatRect::operator-(floatRect frect)
{
	floatRect ret;
	ret.lefttop = this->lefttop - frect.lefttop;
	ret.righttop = this->righttop - frect.righttop;
	ret.rightbottom = this->rightbottom - frect.rightbottom;
	ret.leftbottom = this->leftbottom - frect.leftbottom;

	return ret;
}

CField::CField(floatSize size, floatPoint center)
	: m_MapSize(size)
	, m_MapOrigin(center)
	, m_AbsoluteMap()
	, m_RelativeMap()
{
	m_AbsoluteMap.leftbottom
}

CField::~CField()
{
}


