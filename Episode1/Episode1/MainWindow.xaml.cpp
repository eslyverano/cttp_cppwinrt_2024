#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Episode1::implementation
{
    int32_t MainWindow::MyProperty()
    {
        return propertyValue;
    }

    void MainWindow::MyProperty(int32_t value)
    {
        propertyValue = value;
        this->Bindings->Update();       // It refreshes all the x:Bind in the XAML code
        OutputDebugString(L"Property value updated to: ");
        OutputDebugString(winrt::to_hstring(propertyValue).c_str());
        OutputDebugString(L"\r\n");
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        MyProperty(propertyValue+1);
    }
}
