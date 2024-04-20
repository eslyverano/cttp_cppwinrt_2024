#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Media;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Episode2::implementation
{
	
	void MainWindow::yellowButton_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		colorPanel().Background(SolidColorBrush{ Microsoft::UI::Colors::Yellow() });	//Microsoft::UI::Colors::Yellow() returns the 'Window::UI::Color' SolidColorBrush expects
	}


	void MainWindow::blueButton_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		colorPanel().Background(SolidColorBrush{ Microsoft::UI::Colors::Blue() });
	}


	void MainWindow::redButton_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		colorPanel().Background(SolidColorBrush{ Microsoft::UI::Colors::Red() });
	}

	void MainWindow::sayHiButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		if (nameBox().Text().empty()) {
			showMessage(L"Enter your name!");
			return;
		}
		showMessage(hstring{ L"Hi, " + nameBox().Text() });
	}
	winrt::fire_and_forget MainWindow::showMessage(hstring message)
	{
		Microsoft::UI::Xaml::Controls::ContentDialog dialog{};
		dialog.XamlRoot(this->Content().XamlRoot());		// This is required in WinUI 3.  In this case, 'XamlRoot' is inside the 'Content()' property.
		dialog.Title(box_value(L"Greetings"));
		dialog.Content(box_value(message));
		dialog.CloseButtonText(L"Close");
		co_await dialog.ShowAsync();
	}
}






