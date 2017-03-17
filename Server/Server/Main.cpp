#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <algorithm>
#include <vector>
#include <thread>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

#define LOG(message)	wcout << message
typedef map<const http::method, const std::function<void(http_request)>> method_map;

void checkBalance(http_request request)
{
	LOG(L"\nChecking account balance\n");
	request.reply(status_codes::OK);
}

void withdrawMoney(http_request request)
{
	LOG(L"\nWithdrawing money\n");

	status_code status;

	request
		.extract_json()
		.then([&status](pplx::task<json::value> task) {
		try
		{
			auto & jvalue = task.get();

			if (!jvalue.is_null())
				status = status_codes::OK;
			else
				status = status_codes::BadRequest;
		}
		catch (http_exception const & e)
		{
			wcout << e.what() << endl;
		}
	})
		.wait();

	request.reply(status);
}
int main()
{
	vector<thread> listenerThreads;
	map<shared_ptr<http_listener>, method_map> listeners
	{
		{ make_shared<http_listener>(http_listener{ L"http://localhost/ATM/balance" }),{ { methods::GET, checkBalance } } },
		{ make_shared<http_listener>(http_listener{ L"http://localhost/ATM/withdraw" }),{ { methods::PUT, withdrawMoney } } }
	};

	for (auto& listener : listeners)
	{
		//Before we run listening, we must add methods and handlers we declared earlier
		for (auto& supported_m : listener.second)
		{
			const auto& method = supported_m.first;
			const auto& handler = supported_m.second;
			listener.first->support(method, handler);
		}

		//Start thread for every listener
		listenerThreads.push_back(thread([httpListener = listener.first]()
		{
			httpListener->open()
				.then([&httpListener]() {std::wcout << "Listening at " << httpListener->uri().to_string() << '\n'; })
				.wait();
			while (1);
		}));
	}

	for (auto& thread : listenerThreads)
	{
		thread.join();
	}

	return 0;
}