#pragma once

class CEdit;
class CStatic;
class LoginViewState
{
public:
	LoginViewState(CEdit& valueEdit, CStatic& enterValueStatic, int& maxChars);
protected:
	CEdit& valueEdit;
	CStatic& enterValueStatic;
	int& maxChars;
	virtual void SetValues();
};

class IdState : public LoginViewState
{
public:
	IdState(CEdit& valueEdit, CStatic& enterValueStatic, int& maxChars);
protected:
	void SetValues();
};

class PinState : public LoginViewState
{
public:
	PinState(CEdit& valueEdit, CStatic& enterValueStatic, int& maxChars);
protected:
	void SetValues();
};