#pragma once
#include "Connection.h"
#include <stack>
#include <vector>
#include "solveUTF8.h"
using namespace std;
namespace userDAO{
	//登录检查
	string login_check(string username, string pwd);
	//获取user信息
	sql::ResultSet* get_user_info(string ID);
	//注册
	int regist(string _name,string _pwd,string _phone,string _address,string _email,string _identity);
	//获取所有用户名
	vector<CString> get_all();
	//更新用户权限
	bool update_user(string _name,int x);
}