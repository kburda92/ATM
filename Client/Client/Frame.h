#pragma once
#include "afxwin.h"

class Frame : public CFrameWnd
{
	DECLARE_DYNCREATE(Frame)
private:
	void SwitchToSelectionView();
	bool IsIdPinCorrect();
protected:
	Frame();
	DECLARE_MESSAGE_MAP()
public:
	BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg LRESULT OnLogin(WPARAM wParam, LPARAM lParam);
};

