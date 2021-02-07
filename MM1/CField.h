#pragma once
#include <vector>

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
	floatPoint& operator=(const CPoint &point);
	floatPoint operator+(const floatPoint point) const;
	floatPoint operator-(const floatPoint point) const;
	floatPoint& operator+=(const floatPoint &point);
	floatPoint& operator-=(const floatPoint &point);
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
	floatRect operator+(const floatRect frect) const;
	floatRect operator-(const floatRect frect) const;

	floatPoint lefttop;
	floatPoint rightbottom;
	floatPoint righttop(void) const { return lefttop + floatPoint(rightbottom.x, 0); };
	floatPoint leftbottom(void) const { return lefttop + floatPoint(0, rightbottom.y); };
	double width(void) const { return (rightbottom.x - lefttop.x); };
	double height(void) const { return (rightbottom.y - lefttop.y); };
	floatRect scale(double scale) const { return floatRect((lefttop * scale), (rightbottom * scale)); }
};

class CField
{
public:
	CField();
	CField(floatSize size, floatPoint center);
	~CField();
	floatPoint m_MapOrigin;
	floatSize m_MapSize;
	floatRect m_RelativeMap; /* 中心を0,0とする座標 マップ描画の移動回転に使う */
	floatRect m_AbsoluteMap; /* 左上を0,0とする座標　 */
};


