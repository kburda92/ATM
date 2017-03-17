#pragma once
#include "afxwin.h"

class Frame : public CFrameWnd
{
	DECLARE_DYNCREATE(Frame)
protected:
	Frame();
public:
	void SwitchToView(int);
};

