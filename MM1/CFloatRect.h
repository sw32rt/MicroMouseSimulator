#pragma once
class floatSize
{
public:
	floatSize();
	floatSize(double width, double yheight);
	~floatSize();

	double width = 0;
	double height = 0;
};

class floatPoint
{
public:
	floatPoint();
	floatPoint(double x, double y);
	~floatPoint();
	floatPoint& operator=(const CPoint& point);
	floatPoint operator+(const floatPoint point) const;
	floatPoint operator-(const floatPoint point) const;
	floatPoint& operator+=(const floatPoint& point);
	floatPoint& operator-=(const floatPoint& point);
	floatPoint operator*(const floatPoint point) const;
	floatPoint operator/(const floatPoint point) const;
	floatPoint operator*(const double multi) const;
	floatPoint operator/(const double division) const;
	operator POINT() const { return CPoint((int)x, (int)y); }
	operator CPoint() const { return CPoint((int)x, (int)y); }
	double x = 0;
	double y = 0;
};

class floatRect
{
public:
	floatRect();
	floatRect(floatPoint lefttop, floatPoint rightbottom);
	~floatRect();
	floatRect operator+(const floatPoint fpoint) const;
	floatRect operator-(const floatPoint fpoint) const;
	floatRect operator+(const floatRect frect) const;
	floatRect operator-(const floatRect frect) const;
	operator RECT() const { return CRect((POINT)lefttop, (POINT)rightbottom); }
	operator CRect() const { return CRect((POINT)lefttop, (POINT)rightbottom); }

	floatPoint lefttop;
	floatPoint rightbottom;
	floatPoint righttop(void) const { return lefttop + floatPoint(rightbottom.x, 0); };
	floatPoint leftbottom(void) const { return lefttop + floatPoint(0, rightbottom.y); };
	floatPoint center(void) const { return lefttop + ((rightbottom - lefttop) / 2.0); };
	double width(void) const { return (rightbottom.x - lefttop.x); };
	double height(void) const { return (rightbottom.y - lefttop.y); };
	floatRect scale(double scale) const { return floatRect((lefttop * scale), (rightbottom * scale)); }
	floatRect offset(const int x, const int y);
};