#pragma once
#include "afxwin.h"

class Frame : public CFrameWnd
{
	DECLARE_DYNCREATE(Frame)
private:
	void SwitchToSelectionView(int id);
	bool IsIdPinCorrect();
protected:
	Frame();
	DECLARE_MESSAGE_MAP()
public:
	BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg LRESULT OnLogin(WPARAM wParam, LPARAM lParam);
};

