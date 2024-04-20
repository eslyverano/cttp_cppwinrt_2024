#pragma once
#include "db/sqlite3.h"
#include "UserViewModel.h"

namespace winrt::Episode6::implementation {
	class DbHelper
	{
	private:
		sqlite3* db;
		bool doesTableExist(std::string tableName);
		bool doesRecordExist(const char* sql);
		bool executeStatement(const char* sql);
		int getNextId();
		hstring convertToHString(const unsigned char*);

	public:
		void openDatabase(const char* path);
		void closeDatabase();

		void getAllUsers(Windows::Foundation::Collections::IObservableVector<Episode6::UserViewModel>& array);
		bool updateUser(int id, hstring firstName, hstring lastName, hstring email);
		bool deleteUser(int id);
	};

}

