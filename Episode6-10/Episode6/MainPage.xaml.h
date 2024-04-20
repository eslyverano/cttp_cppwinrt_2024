#pragma once

#include "MainPage.g.h"
#include "UserViewModel.h"

namespace winrt::Episode6::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
    private:
        void closeDatabase();
        Windows::Foundation::Collections::IObservableVector<Episode6::UserViewModel> _userArray{ winrt::single_threaded_observable_vector<Episode6::UserViewModel>() };
        void loadAllUsers();
        void closeRightPanel();

    public:
        MainPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }
        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void Page_Unloaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);        
        Windows::Foundation::Collections::IObservableVector<Episode6::UserViewModel> userArray();
        void newUserButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void editButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void deleteButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::Episode6::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
