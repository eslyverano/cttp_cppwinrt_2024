#include "pch.h"
#include "UserControl2.xaml.h"
#if __has_include("UserControl2.g.cpp")
#include "UserControl2.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Episode13::implementation
{
    int32_t UserControl2::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void UserControl2::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void UserControl2::ShowMessage() {
        messageBlock().Text(L"ShowMessage in UserControl2");
    }
}
