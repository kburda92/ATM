#pragma once
#include "afxwin.h"

class Frame : public CFrameWnd
{
	DECLARE_DYNCREATE(Frame)
protected:
	Frame();
	DECLARE_MESSAGE_MAP()
public:
	void SwitchToView(int viewId);
	BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg LRESULT OnLogin(WPARAM wParam, LPARAM lParam);
};

