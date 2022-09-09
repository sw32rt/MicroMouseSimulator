#include "pch.h"
#include "CFloatRect.h"
#include <cmath>

constexpr double PI = 3.141592653589793;

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

floatPoint floatPoint::rotate(double digree)
{
	double radian = digree * (PI / 180.0);
	floatPoint tempfp;
	//tempfp.x = (x * std::cos(radian) - (y * std::sin(radian)));
	//tempfp.y = (x * std::sin(radian) + (y * std::cos(radian)));
	tempfp.x = x;
	tempfp.y = y;
	*this = tempfp;
	return *this;
}

floatRect::floatRect()
	: lefttop()
	, righttop()
	, rightbottom()
	, leftbottom()
{
}

floatRect::floatRect(floatPoint lefttop, floatPoint rightbottom)
	: lefttop(lefttop)
	, righttop(rightbottom.x, lefttop.y)
	, rightbottom(rightbottom)
	, leftbottom(lefttop.x, rightbottom.y)
{
}

floatRect::~floatRect()
{
}

floatRect floatRect::operator+(const floatPoint fpoint) const
{
	floatRect ret;
	ret.lefttop = lefttop + fpoint;
	ret.righttop = righttop + fpoint;
	ret.rightbottom = rightbottom + fpoint;
	ret.leftbottom = leftbottom + fpoint;

	return ret;
}

floatRect floatRect::operator-(const floatPoint fpoint) const
{
	floatRect ret;
	ret.lefttop = lefttop - fpoint;
	ret.righttop = righttop - fpoint;
	ret.rightbottom = rightbottom - fpoint;
	ret.leftbottom = leftbottom - fpoint;

	return ret;
}

floatRect& floatRect::operator+=(const floatPoint& fpoint)
{
	// TODO: return ステートメントをここに挿入します
	*this = *this + fpoint;
	return *this;
}

floatRect& floatRect::operator-=(const floatPoint& fpoint)
{
	// TODO: return ステートメントをここに挿入します
	*this = *this - fpoint;
	return *this;
}

floatRect floatRect::operator+(const floatRect frect) const
{
	floatRect ret;
	ret.lefttop = lefttop + frect.lefttop;
	ret.righttop = righttop + frect.righttop;
	ret.rightbottom = rightbottom + frect.rightbottom;
	ret.leftbottom = leftbottom + frect.leftbottom;

	return ret;
}

floatRect floatRect::operator-(const floatRect frect) const
{
	floatRect ret;
	ret.lefttop = lefttop - frect.lefttop;
	ret.righttop = righttop - frect.righttop;
	ret.rightbottom = rightbottom - frect.rightbottom;
	ret.leftbottom = leftbottom - frect.leftbottom;

	return ret;
}

floatRect floatRect::offset(const int x, const int y)
{
	lefttop += floatPoint(x, y);
	righttop += floatPoint(x, y);
	rightbottom += floatPoint(x, y);
	leftbottom += floatPoint(x, y);
	return *this;
}

floatRect floatRect::rotate(double degree)
{
	lefttop.rotate(degree);
	righttop.rotate(degree);
	rightbottom.rotate(degree);
	leftbottom.rotate(degree);
	return *this;
}
