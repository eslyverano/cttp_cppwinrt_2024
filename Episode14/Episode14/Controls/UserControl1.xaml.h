#pragma once

#include "UserControl1.g.h"

namespace winrt::Episode14::implementation
{
    struct UserControl1 : UserControl1T<UserControl1>
    {
        UserControl1()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::Episode14::factory_implementation
{
    struct UserControl1 : UserControl1T<UserControl1, implementation::UserControl1>
    {
    };
}
