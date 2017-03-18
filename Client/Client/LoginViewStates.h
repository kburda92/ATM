#pragma once
#include <afx.h>

class LoginView;
class LoginViewState
{
protected:
	LoginView* view;
public:
	LoginViewState(LoginView* view) : view(view) {}
	virtual void Init();
	virtual int GetMaxChars() = 0;
	virtual CString& GetValue() = 0;
};

class IdState : public LoginViewState
{
public:
	IdState(LoginView* view) : LoginViewState(view) {}
	void Init();
	int GetMaxChars() { return 8; }
	CString& GetValue();
};

class PinState : public LoginViewState
{
public:
	PinState(LoginView* view) : LoginViewState(view) {}
	void Init();
	int GetMaxChars() { return 4; }
	CString& GetValue();
};