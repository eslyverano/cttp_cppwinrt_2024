#pragma once

#include "MainWindow.g.h"

namespace winrt::Episode6::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
    public:
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

    };
}

namespace winrt::Episode6::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
