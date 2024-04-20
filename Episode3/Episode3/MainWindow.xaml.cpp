#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Episode3::implementation
{
	MainWindow::MainWindow() {
		InitializeComponent();	// This is required when creating a custom constructor.
		sourceList().ItemsSource(sourceArray);
	}

	void MainWindow::addManualItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		manualIndex++;
		manualList().Items().Append(box_value(hstring{ L"Item " + to_hstring(manualIndex) }));
		if (manualList().SelectedItem() == nullptr) manualList().SelectedIndex(0);
	}


	void MainWindow::addSourceItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		sourceIndex++;
		sourceArray.Append(hstring{ L"Item " + to_hstring(sourceIndex) });
		if (sourceList().SelectedItem() == nullptr) sourceList().SelectedIndex(0);
	}

	// Property 'getter'
	winrt::Windows::Foundation::Collections::IObservableVector<hstring> MainWindow::collection() {
		return boundArray;
	}

	void winrt::Episode3::implementation::MainWindow::addBoundItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		boundIndex++;
		boundArray.Append(hstring{ L"Item " + to_hstring(boundIndex) });		
		if (boundList().SelectedItem() == nullptr) boundList().SelectedIndex(0);
	}

}








