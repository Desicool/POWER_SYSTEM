#pragma once
#include "Connection.h"
#include <stack>
#include <vector>
#include "solveUTF8.h"
using namespace std;
namespace userDAO{
	//��¼���
	string login_check(string username, string pwd);
	//��ȡuser��Ϣ
	sql::ResultSet* get_user_info(string ID);
	//ע��
	int regist(string _name,string _pwd,string _phone,string _address,string _email,string _identity);
	//��ȡ�����û���
	vector<CString> get_all();
	//�����û�Ȩ��
	bool update_user(string _name,int x);
}