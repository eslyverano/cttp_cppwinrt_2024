#include "pch.h"
#include "UserViewModel.h"
#if __has_include("UserViewModel.g.cpp")
#include "UserViewModel.g.cpp"
#endif

namespace winrt::Episode6::implementation
{
	void UserViewModel::SetUserData(int32_t _id, hstring _firstName, hstring _lastName, hstring _email)
	{
		id = _id;
		firstName = _firstName;
		lastName = _lastName;
		email = _email;
	}
	hstring UserViewModel::FirstName()
	{
		return firstName;
	}
	hstring UserViewModel::LastName()
	{
		return lastName;
	}
	hstring UserViewModel::Email()
	{
		return email;
	}
	int32_t UserViewModel::Id()
	{
		return id;
	}
}
