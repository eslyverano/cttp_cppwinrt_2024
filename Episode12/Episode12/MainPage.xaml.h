#pragma once

#include "MainPage.g.h"

namespace winrt::Episode12::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }
      
        void requestButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
   
    private:
        Windows::Foundation::IAsyncAction callEndpoint();
        void parseJoke(winrt::hstring json);

    };
}

namespace winrt::Episode12::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
