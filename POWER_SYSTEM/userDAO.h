#pragma once
#include "Connection.h"
#include <stack>
using namespace std;
namespace userDAO{
	string login_check(string username, string pwd);
	sql::ResultSet* get_user_info(string ID);
	int regist(string _name,string _pwd,string _phone,string _address,string _email,string _identity);
}