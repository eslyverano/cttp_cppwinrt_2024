#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include "winrt/Windows.UI.Xaml.Interop.h"


using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Episode4::implementation
{
    
    void MainPage::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        /* Initialise your stuff here! */
    }

    void MainPage::NavigationView_ItemInvoked(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewItemInvokedEventArgs const& args)
    {
        if (args.IsSettingsInvoked()) {
            openSettingsPage();
        }
        else {
            hstring tag = unbox_value<hstring>(args.InvokedItemContainer().Tag());
            if (tag == L"home")
                openHomePage();
            else if (tag == L"other")
                openOtherPage();
        }
    }
    void MainPage::openHomePage()
    {
        mainFrame().Navigate(xaml_typename<HomePage>());
    }
    void MainPage::openOtherPage()
    {
        mainFrame().Navigate(xaml_typename<OtherPage>());
    }
    void MainPage::openSettingsPage()
    {
        mainFrame().Navigate(xaml_typename<SettingsPage>());
    }

    void MainPage::mainFrame_Navigated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Navigation::NavigationEventArgs const& e)
    {
        nav().IsBackEnabled(mainFrame().CanGoBack());
    }

    void MainPage::nav_BackRequested(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewBackRequestedEventArgs const& args)
    {
        mainFrame().GoBack();
    }

}












