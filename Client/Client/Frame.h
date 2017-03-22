#pragma once
#include "afxwin.h"
#include <string>

class Frame : public CFrameWnd
{
	DECLARE_DYNCREATE(Frame)
private:
	void SwitchToSelectionView(const std::string& id, const std::string& pin);
	bool IsIdPinCorrect();
protected:
	Frame() {};
	virtual ~Frame() {};
	DECLARE_MESSAGE_MAP()
public:
	BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg LRESULT OnLogin(WPARAM wParam, LPARAM lParam);
};

