#include "pch.h"
#include "UpdateUserControl.xaml.h"
#if __has_include("UpdateUserControl.g.cpp")
#include "UpdateUserControl.g.cpp"
#endif
#include "App.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Episode6::implementation
{
	void UpdateUserControl::LoadUserData(int32_t _id, hstring firstName, hstring lastName, hstring email)
	{
		id = _id;
		firstNameBox().Text(firstName);
		lastNameBox().Text(lastName);
		emailBox().Text(email);
	}
	winrt::event_token UpdateUserControl::UserUpdated(const Windows::Foundation::EventHandler<int32_t>& handler)
	{
		/* Add a new event handler (or listener) */
		return userUpdatedEvent.add(handler);
	}
	void UpdateUserControl::UserUpdated(const winrt::event_token& token)
	{
		/* Remove the event handler (or listener) */
		userUpdatedEvent.remove(token);
	}
	void UpdateUserControl::saveButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		/* First we check all fields have data */
		if (firstNameBox().Text().empty()) {
			firstNameBox().Focus(Microsoft::UI::Xaml::FocusState::Keyboard);
			return;
		}
		if (lastNameBox().Text().empty()) {
			lastNameBox().Focus(Microsoft::UI::Xaml::FocusState::Keyboard);
			return;
		}
		if (emailBox().Text().empty()) {
			emailBox().Focus(Microsoft::UI::Xaml::FocusState::Keyboard);
			return;
		}
		bool saved = App::db.updateUser(id, firstNameBox().Text(), lastNameBox().Text(), emailBox().Text());
		if (saved) {
			OutputDebugString(L"Saved!");
			firstNameBox().Text(L"");
			lastNameBox().Text(L"");
			emailBox().Text(L"");
			firstNameBox().Focus(Microsoft::UI::Xaml::FocusState::Keyboard);
		}
		userUpdatedEvent(*this, 0);
	}
}



