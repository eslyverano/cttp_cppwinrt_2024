#pragma once

#include "App.xaml.g.h"

namespace winrt::Episode5::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);    
        static HWND getMainWindow();

    private:
        static winrt::Microsoft::UI::Xaml::Window window;
        
    };
}
