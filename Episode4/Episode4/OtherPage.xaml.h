#pragma once

#include "OtherPage.g.h"

namespace winrt::Episode4::implementation
{
    struct OtherPage : OtherPageT<OtherPage>
    {
        OtherPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }
    };
}

namespace winrt::Episode4::factory_implementation
{
    struct OtherPage : OtherPageT<OtherPage, implementation::OtherPage>
    {
    };
}
