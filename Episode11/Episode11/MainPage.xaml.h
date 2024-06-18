#pragma once

#include "MainPage.g.h"
#include "ContactViewModel.h"

namespace winrt::Episode11::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
    private:
        Windows::Foundation::Collections::IObservableVector<Episode11::ContactViewModel> contactArray{ winrt::single_threaded_observable_vector<Episode11::ContactViewModel>() };
        void prepareContactData();
        Microsoft::UI::Composition::SpringVector3NaturalMotionAnimation animation{ nullptr };
        void initSpringAnimation();
        void startAnimation(Microsoft::UI::Xaml::Controls::Grid grid, float scale);

    public:
        MainPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }      
        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void Grid_PointerEntered(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e);
        void Grid_PointerExited(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e);
    };
}

namespace winrt::Episode11::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
