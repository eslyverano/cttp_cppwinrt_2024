#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include "winrt/Windows.Storage.Pickers.h"
#include "App.xaml.h"
#include <shobjidl.h>


using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Episode5::implementation
{
	
	void MainPage::selectImageFileButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		openImageFile();
	}
	winrt::fire_and_forget MainPage::openImageFile()
	{
		Windows::Storage::Pickers::FileOpenPicker picker{};
		HWND hwnd = App::getMainWindow();
		picker.as<IInitializeWithWindow>()->Initialize(hwnd);
		picker.SuggestedStartLocation(Windows::Storage::Pickers::PickerLocationId::PicturesLibrary);
		picker.FileTypeFilter().Append(L".jpg");
		Windows::Storage::StorageFile file = co_await picker.PickSingleFileAsync();
		if (file != nullptr) {
			bmp().SetSource(co_await file.OpenAsync(Windows::Storage::FileAccessMode::Read));
		}
	}
}


