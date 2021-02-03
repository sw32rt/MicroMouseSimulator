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
	floatPoint operator+(floatPoint point);
	floatPoint operator-(floatPoint point);
	void offset_x(double offset);
	void offset_y(double offset);
	double x = 0;
	double y = 0;
};

class floatRect
{
public:
	floatRect();
	floatRect(floatPoint lefttop, floatPoint righttop, floatPoint rightbottom, floatPoint leftbottom);
	~floatRect();
	floatRect operator+(floatRect frect);
	floatRect operator-(floatRect frect);

	floatPoint lefttop;
	floatPoint righttop;
	floatPoint rightbottom;
	floatPoint leftbottom;
};

class CField
{
public:
	CField(floatSize size, floatPoint center);
	~CField();
	floatPoint m_MapOrigin;
	floatSize m_MapSize;
	floatRect m_RelativeMap; /* íÜêSÇ0,0Ç∆Ç∑ÇÈç¿ïW */
	floatRect m_AbsoluteMap; /* ç∂è„Ç0,0Ç∆Ç∑ÇÈç¿ïW */
	
};

