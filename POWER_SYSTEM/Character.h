#pragma once
#include "characterDAO.h"
class Character
{
private:
	wstring character_name;
	string ID;
	int privilege;
public:
	Character();
	//根据userID获取系统角色
	void init(string userID);
	int getPrivilege() { return privilege; }
	wstring get_character_name() { return character_name; }
	vector<CString> get_all();
	vector<CString> get_all_privilege();
	bool d_character(string username, string cname);
	bool d_function(string cname, string fname);
	bool add_character(string cname);
	//TODO: 实时查询是否存在某operation权限
	~Character();
};

