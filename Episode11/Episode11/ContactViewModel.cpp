#include "pch.h"
#include "ContactViewModel.h"
#if __has_include("ContactViewModel.g.cpp")
#include "ContactViewModel.g.cpp"
#endif

namespace winrt::Episode11::implementation
{
	winrt::hstring ContactViewModel::Name()
	{
		return name;
	}
	winrt::hstring ContactViewModel::Country()
	{
		return country;
	}
	void ContactViewModel::SetContactData(winrt::hstring _name, winrt::hstring _country)
	{
		name = _name;
		country = _country;
	}
}
