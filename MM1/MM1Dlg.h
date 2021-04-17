
// MM1Dlg.h : ヘッダー ファイル
//

#pragma once
#include "CScreen.h"

#define ZOOMIN_RATE ((double)1.2)
#define ZOOMOUT_RATE ((double)0.8)

// CMM1Dlg ダイアログ
class CMM1Dlg : public CDialogEx
{
// コンストラクション
public:
	CMM1Dlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MM1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

/* ユーザー実装 */
/* メンバ変数 */
public:
	UINT m_TickTimerID;
	const UINT m_TickTimerInterval = 1;
	const float m_TickHz = m_TickTimerInterval / 1000;
	CScreen m_Screen;
	bool m_IsMouseLButtonDown = false;
	CPoint m_MouseMoveStart;
	CPoint m_MeasureStartPoint;

	CPoint m_SCreenDisplayPreOffset;

	CBitmap m_bmpCursorModeHandOn;
	CBitmap m_bmpCursorModeHandOff;

	enum E_CursorMode_t
	{
		E_CursorMode_Hand    = 0,
		E_CursorMode_Measure    ,
		E_CursorMode_Cursor     ,
	};

	E_CursorMode_t m_CursorMode = E_CursorMode_Hand;

	bool m_MeasureStart = false;
	void OnCursorModeRadioClick(int mode);

// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcLButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcMButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcRButtonDown(UINT nHitTest, CPoint point);
	afx_msg void OnNcRButtonUp(UINT nHitTest, CPoint point);
	afx_msg void OnNcMouseLeave();
	int m_rotateSlider;
	afx_msg void OnTRBNThumbPosChangingSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	CSliderCtrl m_rotateSliderCtrl;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedRadioCursormodeHand();
	afx_msg void OnBnClickedRadioCursormodeMeasure();
	afx_msg void OnBnClickedRadioCursormodeCursor();
	CButton m_ddx_CursorModeHandRdioCtrl;
	CButton m_ddx_CursorModeMeasureRdioCtrl;
	CButton m_ddx_CursorModeCursorRdioCtrl;
	virtual void OnCancel();
	afx_msg void OnBnClickedButton1();
};
