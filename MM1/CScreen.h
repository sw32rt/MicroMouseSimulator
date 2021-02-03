#pragma once
class CScreen
{
public:
	CScreen(CWnd *hwnd);
	~CScreen();

	void Update(void);
	void InitMaze(void);

private:
	CWnd* m_hWnd;



};

