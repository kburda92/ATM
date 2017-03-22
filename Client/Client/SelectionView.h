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
	DECLARE_MESSAGE_MAP()
private:
	utility::string_t id, pin;
	std::unique_ptr<http_client> client;
	std::unique_ptr<http_client_config> config = std::make_unique<http_client_config>();
	pplx::task<void> CheckBalance(int& balance, std::string& error);
protected:
	virtual ~SelectionView() {};
public:
	SelectionView(const string& id, const string& pin);
	void OnInitialUpdate();
	afx_msg void OnCheckBalanceButtonClicked();
};

