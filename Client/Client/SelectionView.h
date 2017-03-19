#pragma once
#include "afxext.h"
#include <memory>
#include <cpprest/http_client.h>
#include <cpprest/json.h>


using namespace std;
using namespace web;
using namespace web::http;
using namespace web::http::client;


class SelectionView : public CFormView
{
private:
	int id;
	std::unique_ptr<http_client> client;
	pplx::task<void> CheckBalance(int& balance, std::string& error);
protected:
	virtual ~SelectionView();
public:
	SelectionView(int id);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnCheckBalanceButtonClicked();
};

