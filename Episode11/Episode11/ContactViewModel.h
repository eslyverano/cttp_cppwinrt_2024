#pragma once

#include "ContactViewModel.g.h"

namespace winrt::Episode11::implementation
{
    struct ContactViewModel : ContactViewModelT<ContactViewModel>
    {
    private:
        winrt::hstring name;
        winrt::hstring country;
    public:
        ContactViewModel() = default;

        winrt::hstring Name();
        winrt::hstring Country();
        void SetContactData(winrt::hstring, winrt::hstring);
    };
}

namespace winrt::Episode11::factory_implementation
{
    struct ContactViewModel : ContactViewModelT<ContactViewModel, implementation::ContactViewModel>
    {
    };
}
