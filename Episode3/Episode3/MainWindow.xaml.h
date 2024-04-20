#pragma once

#include "MainWindow.g.h"

namespace winrt::Episode3::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
    private:
        int32_t manualIndex = 0;
        int32_t sourceIndex = 0;
        int32_t boundIndex = 0;
        winrt::Windows::Foundation::Collections::IObservableVector<hstring> sourceArray{ winrt::single_threaded_observable_vector<hstring>() };
        winrt::Windows::Foundation::Collections::IObservableVector<hstring> boundArray{ winrt::single_threaded_observable_vector<hstring>() };
    public:
        MainWindow();   // Use a custom constructor only when strictly necessary.

        winrt::Windows::Foundation::Collections::IObservableVector<hstring> collection();
       
        void addManualItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void addSourceItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void addBoundItemButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::Episode3::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
