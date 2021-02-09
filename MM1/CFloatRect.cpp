#include "pch.h"
#include "CFloatRect.h"

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

floatPoint::floatPoint(const CPoint point)
{
	*this = point;
}

floatPoint::floatPoint(double x, double y)
	: x(x)
	, y(y)
{
}

floatPoint::~floatPoint()
{
}

floatPoint& floatPoint::operator=(const CPoint& point)
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
	return floatPoint(this->x / division, this->y / division);
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

floatRect floatRect::operator+(const floatPoint fpoint) const
{
	floatRect ret;
	ret.lefttop = lefttop + fpoint;
	ret.rightbottom = rightbottom + fpoint;

	return ret;
}

floatRect floatRect::operator-(const floatPoint fpoint) const
{
	floatRect ret;
	ret.lefttop = lefttop - fpoint;
	ret.rightbottom = rightbottom - fpoint;

	return ret;
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

floatRect floatRect::offset(const int x, const int y)
{
	this->lefttop += floatPoint(x, y);
	this->rightbottom += floatPoint(x, y);
	return *this;
}
