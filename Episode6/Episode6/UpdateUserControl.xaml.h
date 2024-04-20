#pragma once

#include "UpdateUserControl.g.h"

namespace winrt::Episode6::implementation
{
    struct UpdateUserControl : UpdateUserControlT<UpdateUserControl>
    {
    private:
        int32_t id;
        winrt::event<Windows::Foundation::EventHandler<int32_t>> userUpdatedEvent;  // The actual event object used internally
    public:
        UpdateUserControl()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }
        void LoadUserData(int32_t _id, hstring firstName, hstring lastName, hstring email);
        winrt::event_token UserUpdated(const Windows::Foundation::EventHandler<int32_t>& handler);  // Add an event handler and returns token
        void UserUpdated(const winrt::event_token& token);                                          // Use the token to remove event handler
        void saveButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::Episode6::factory_implementation
{
    struct UpdateUserControl : UpdateUserControlT<UpdateUserControl, implementation::UpdateUserControl>
    {
    };
}
