#include "pch.h"
#include "DbHelper.h"


namespace winrt::Episode6::implementation {
	void DbHelper::openDatabase(const char* path)
	{
		int result = sqlite3_open(path, &db);
		if (result == SQLITE_OK)
		{
			OutputDebugString(L"Amazing!. It actually worked!\r\n");
			if (!doesTableExist("users")) {
				executeStatement(std::string{ "create table users (id int primary key, first_name text, last_name text, email text);" }.c_str());
				OutputDebugString(L"Table 'users' created!\r\n");
			}
		}
		else {
			OutputDebugString(L"ERROR: Cannot open db");
		}

	}
	bool DbHelper::doesTableExist(std::string tableName)
	{
		return doesRecordExist(std::string{ "select 1 from sqlite_master where type='table' and name='" + tableName + "'" }.c_str());
	}
	bool DbHelper::doesRecordExist(const char* sql)
	{
		bool exists = false;
		sqlite3_stmt* st;
		if (sqlite3_prepare_v2(db, sql, -1, &st, NULL) == SQLITE_OK) {
			exists = sqlite3_step(st) == SQLITE_ROW;
		}
		sqlite3_finalize(st);
		return exists;
	}
	bool DbHelper::executeStatement(const char* sql)
	{
		return sqlite3_exec(db, sql, NULL, NULL, NULL) == SQLITE_OK;
	}

	void DbHelper::closeDatabase()
	{
		sqlite3_close(db);
	}


	int DbHelper::getNextId()
	{
		int nextId = 0;
		sqlite3_stmt* st;
		if (sqlite3_prepare_v2(db, "select max(id) from users", -1, &st, NULL) == SQLITE_OK) {
			if (sqlite3_step(st) == SQLITE_ROW)
				nextId = sqlite3_column_int(st, 0);
		}
		sqlite3_finalize(st);
		return ++nextId;
	}

	/* Here we receive a reference of the collection. In this case the IObservableVector coming from MainPage */
	void DbHelper::getAllUsers(Windows::Foundation::Collections::IObservableVector<Episode6::UserViewModel>& array)	{
		sqlite3_stmt* st;
		if (sqlite3_prepare_v2(db, "select id, first_name, last_name, email from users order by first_name", -1, &st, NULL) == SQLITE_OK) {
			while (sqlite3_step(st) == SQLITE_ROW) {
				Episode6::UserViewModel u = winrt::make<Episode6::implementation::UserViewModel>();
				u.SetUserData(sqlite3_column_int(st, 0), convertToHString(sqlite3_column_text(st, 1)), convertToHString(sqlite3_column_text(st, 2)), convertToHString(sqlite3_column_text(st, 3)));
				array.Append(u);
			}
		}
		sqlite3_finalize(st);
	}

	bool DbHelper::updateUser(int id, hstring firstName, hstring lastName, hstring email)
	{
		bool updated = false;
		int finalId = id == 0 ? getNextId() : id;
		const char* sql;
		/* Notice we left the field "id" at the end, so both INSERT and UPDATE have the same "bind" field order */
		if (id == 0) {
			sql = "insert into users (first_name, last_name, email, id) values (?, ?, ?, ?);";
		}
		else {
			sql = "update users set first_name=?, last_name=?, email=? where id=?;";
		}
		sqlite3_stmt* st;
		if (sqlite3_prepare_v2(db, sql, -1, &st, NULL) == SQLITE_OK) {
			sqlite3_bind_text(st, 1, winrt::to_string(firstName).c_str(), -1, SQLITE_TRANSIENT);
			sqlite3_bind_text(st, 2, winrt::to_string(lastName).c_str(), -1, SQLITE_TRANSIENT);
			sqlite3_bind_text(st, 3, winrt::to_string(email).c_str(), -1, SQLITE_TRANSIENT);
			sqlite3_bind_int(st, 4, finalId);
			updated = sqlite3_step(st) == SQLITE_DONE;
		}
		sqlite3_finalize(st);

		return updated;
	}

	bool DbHelper::deleteUser(int id)
	{
		bool deleted = false;
		sqlite3_stmt* st;
		if (sqlite3_prepare_v2(db, "delete from users where id=?", -1, &st, NULL) == SQLITE_OK) {
			sqlite3_bind_int(st, 1, id);
			deleted = sqlite3_step(st) == SQLITE_DONE;
		}
		sqlite3_finalize(st);
		return deleted;
	}


	hstring DbHelper::convertToHString(const unsigned char* value)
	{
		return winrt::to_hstring(std::string{ reinterpret_cast<char const*>(value) });
	}

}