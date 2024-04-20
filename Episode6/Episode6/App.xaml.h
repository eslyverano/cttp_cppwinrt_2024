#pragma once

#include "App.xaml.g.h"
#include "DbHelper.h"

namespace winrt::Episode6::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);
        static DbHelper db;

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
