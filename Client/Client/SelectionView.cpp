
#include "SelectionView.h"
#include "resource.h"

SelectionView::SelectionView(int id) : CFormView(IDD_SELECTIONVIEW), id(id)
{}

SelectionView::~SelectionView()
{}

BEGIN_MESSAGE_MAP(SelectionView, CFormView)
	ON_BN_CLICKED(IDC_CHECKBALANCEBUTTON, &SelectionView::OnCheckBalanceButtonClicked)
END_MESSAGE_MAP()

void SelectionView::OnCheckBalanceButtonClicked()
{
	uri_builder builder(U("http://localhost/atm/balance/id/"));
	builder.set_path(L"http://localhost/atm/balance/id/");
	builder.append_path(utility::conversions::to_string_t(to_string(id)));
	
	client = make_unique<http_client>(builder.path());

	int balance = 0;
	string error;
	CheckBalance(balance, error).wait();

	CString message, title;
	unsigned int buttons = MB_OK;
	if(error.empty())
	{
		message.Format(_T("%d"), balance);
		message += "$";
		title = "Balance";
	}
	else
	{
		message = error.c_str();
		title = "Error";
		buttons |= MB_ICONERROR;

	}
	MessageBox(message, title, buttons);
}

pplx::task<void> SelectionView::CheckBalance(int& balance, string& error)
{
	http_request request(methods::GET);
	request.headers().set_content_type(L"application/json");

	return client->request(request).then([](http_response response)
	{
		if (response.status_code() == status_codes::OK)
			return response.extract_json();
		else
			return pplx::task_from_result(json::value());
	}).then([&balance, &error](pplx::task<json::value> previousTask)
	{
		try
		{
			json::value const & value = previousTask.get();
			if (value.is_object())
			{
				auto v = value.as_object();
				if (v.size() == 1)
				{
					if (v.begin()->first == L"Balance")
						balance = v.begin()->second.as_integer();
				}
			}
		}
		catch (http_exception const & e)
		{
			error = e.what();
		}
	});
}
