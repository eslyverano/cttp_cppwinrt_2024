#pragma once

#include "UserControl2.g.h"

namespace winrt::Episode13::implementation
{
    struct UserControl2 : UserControl2T<UserControl2>
    {
        UserControl2()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
        void ShowMessage();
    };
}

namespace winrt::Episode13::factory_implementation
{
    struct UserControl2 : UserControl2T<UserControl2, implementation::UserControl2>
    {
    };
}
