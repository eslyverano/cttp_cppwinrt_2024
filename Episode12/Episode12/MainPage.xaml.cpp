#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include <sstream>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Episode12::implementation
{
   
	/*
	* The hilarious url we are going to use:
	* https://official-joke-api.appspot.com/random_joke
	*/

	void MainPage::requestButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		callEndpoint();
	}

	Windows::Foundation::IAsyncAction MainPage::callEndpoint()
	{
		pRing().IsActive(true);
		Windows::Foundation::Uri url{ L"https://official-joke-api.appspot.com/random_joke" };
		// A filter is needed so the client doesn't cache the contents of the response.
		Windows::Web::Http::Filters::HttpBaseProtocolFilter filter{};
		filter.CacheControl().ReadBehavior(Windows::Web::Http::Filters::HttpCacheReadBehavior::MostRecent);
		Windows::Web::Http::HttpClient client{ filter };

		try {
			auto response{ co_await client.GetAsync(url) };
			if (response.IsSuccessStatusCode()) {
				winrt::hstring content = co_await response.Content().ReadAsStringAsync();
				parseJoke(content);
			}
		}
		catch (winrt::hresult_error& ex) {
			responseBlock().Text(ex.message().c_str());
		}
		client.Close();
		pRing().IsActive(false);
		co_return;	
	}

	void MainPage::parseJoke(winrt::hstring json)
	{
		Windows::Data::Json::JsonObject obj{ Windows::Data::Json::JsonObject::Parse(json) };
		std::wostringstream joke;		// Easy way to concatenate a string. Alternative for C#'s StringBuilder.
		joke << obj.GetNamedString(L"setup");
		joke << "\r\n\r\n";
		joke << obj.GetNamedString(L"punchline");
		responseBlock().Text(joke.str().c_str());
	}

}



