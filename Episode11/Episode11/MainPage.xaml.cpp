#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include "App.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Episode11::implementation
{

	void MainPage::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		list().ItemsSource(contactArray);
		prepareContactData();
		initSpringAnimation();
	}

	void MainPage::prepareContactData() {
		Episode11::ContactViewModel contact = winrt::make<Episode11::implementation::ContactViewModel>();
		contact.SetContactData(L"John Smith", L"Australia");
		contactArray.Append(contact);
		contact = winrt::make<Episode11::implementation::ContactViewModel>();
		contact.SetContactData(L"Jane Doe", L"England");
		contactArray.Append(contact);
		contact = winrt::make<Episode11::implementation::ContactViewModel>();
		contact.SetContactData(L"Charles Donahoe", L"United States");
		contactArray.Append(contact);
		contact = winrt::make<Episode11::implementation::ContactViewModel>();
		contact.SetContactData(L"Hans Grueber", L"Deutschland");
		contactArray.Append(contact);
		contact = winrt::make<Episode11::implementation::ContactViewModel>();
		contact.SetContactData(L"Gunter Holzhacker", L"Der Schweiß");
		contactArray.Append(contact);
		contact = winrt::make<Episode11::implementation::ContactViewModel>();
		contact.SetContactData(L"Ricardo Verano", L"España");
		contactArray.Append(contact);
		contact = winrt::make<Episode11::implementation::ContactViewModel>();
		contact.SetContactData(L"Marcos D'Muzio", L"Italia");
		contactArray.Append(contact);
	}

	void MainPage::initSpringAnimation() {
		animation = App::window.Compositor().CreateSpringVector3Animation();
		animation.Target(L"Scale");
	}

	void MainPage::startAnimation(Microsoft::UI::Xaml::Controls::Grid grid, float scale) {
		animation.FinalValue(Windows::Foundation::Numerics::float3{ scale });		
		grid.CenterPoint(Windows::Foundation::Numerics::float3{ (grid.ActualSize().x / 2.f), (grid.ActualSize().y / 2.f), 1.f });
		grid.StartAnimation(animation);
	}

	void MainPage::Grid_PointerEntered(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e)
	{
		startAnimation(sender.try_as<Microsoft::UI::Xaml::Controls::Grid>(), 1.1f);
	}


	void MainPage::Grid_PointerExited(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e)
	{
		startAnimation(sender.try_as<Microsoft::UI::Xaml::Controls::Grid>(), 1.0f);
	}

}


