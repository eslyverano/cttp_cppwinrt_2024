#pragma once

#include "MainPage.g.h"

namespace winrt::Episode5::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
    private:
        winrt::fire_and_forget openImageFile();
    public:
        MainPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }        
        
        void selectImageFileButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::Episode5::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
