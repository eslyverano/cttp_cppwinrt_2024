#pragma once

#include "UserViewModel.g.h"

namespace winrt::Episode6::implementation
{
    struct UserViewModel : UserViewModelT<UserViewModel>
    {
    private :
        int32_t id;
        hstring firstName;
        hstring lastName;
        hstring email;
    public:
        UserViewModel() = default;
        void SetUserData(int32_t _id, hstring _firstName, hstring _lastName, hstring _email);
        hstring FirstName();
        hstring LastName();
        hstring Email();
        int32_t Id();
    };
}

namespace winrt::Episode6::factory_implementation
{
    struct UserViewModel : UserViewModelT<UserViewModel, implementation::UserViewModel>
    {
    };
}
