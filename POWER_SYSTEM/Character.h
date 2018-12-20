#pragma once
#include "characterDAO.h"
class Character
{
private:
	string character_name;
	string ID;
	int privilege;
public:
	Character();
	//根据userID获取系统角色
	void init(string userID);
	~Character();
};

