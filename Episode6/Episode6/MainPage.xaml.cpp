#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif
#include <winrt/Windows.Storage.h>
#include "App.xaml.h"
#include "UpdateUserControl.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Episode6::implementation
{	
	void MainPage::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		std::string path = winrt::to_string(Windows::Storage::ApplicationData::Current().LocalFolder().Path() + L"\\database.db");
		const char* dbFilename = path.c_str();
		App::db.openDatabase(dbFilename);
		loadAllUsers();
	}

	void MainPage::Page_Unloaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		closeDatabase();
	}	
	
	void MainPage::closeDatabase()
	{
		App::db.closeDatabase();
	}

	Windows::Foundation::Collections::IObservableVector<Episode6::UserViewModel> MainPage::userArray()
	{
		return _userArray;
	}

	void MainPage::loadAllUsers()
	{
		_userArray.Clear();
		App::db.getAllUsers(_userArray);
		itemCountBlock().Text(winrt::to_hstring(_userArray.Size()) + L" Users");
	}

	void MainPage::closeRightPanel()
	{
		rightPanel().Content(nullptr);
	}

	void MainPage::newUserButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		Episode6::UpdateUserControl update = winrt::make<Episode6::implementation::UpdateUserControl>();
		/* FIRST: [the access the handler will have - in this case 'this', meaning any method in this class can be invoked from inside the handler]
		*  SECOND: (Standard EventHandler parameters. IInspectable (mandatory) and int32_t defined in the UpdateUserControl.idl file)
		*/
		update.UserUpdated([this](const IInspectable&, int32_t) {
			/* We are not using the int32_t, but we could return the latest id inserted/updated */
			closeRightPanel();
			loadAllUsers();
			});
		rightPanel().Content(update);
	}

	void MainPage::editButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		/* The context menu opens up from the ListViewItem. Each ListViewItem contains a reference to UserViewModel inside the DataContext() property */
		/* Since the 'sender' (ListViewItem) is an IInspectable here, we convert first to FrameworkElement so we can have access to the DataContext() property */
		/* Then we convert to UserViewModel. */
		Episode6::UserViewModel user = sender.try_as<Microsoft::UI::Xaml::FrameworkElement>().DataContext().try_as<Episode6::UserViewModel>();
		Episode6::UpdateUserControl update = winrt::make<Episode6::implementation::UpdateUserControl>();
		update.LoadUserData(user.Id(), user.FirstName(), user.LastName(), user.Email());
		update.UserUpdated([this](const IInspectable&, int32_t) {
			closeRightPanel();
			loadAllUsers();
			});
		rightPanel().Content(update);

	}


	void MainPage::deleteButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
	{
		Episode6::UserViewModel user = sender.try_as<Microsoft::UI::Xaml::FrameworkElement>().DataContext().try_as<Episode6::UserViewModel>();
		if (App::db.deleteUser(user.Id())) {
			closeRightPanel();
			loadAllUsers();
		}
	}


}








