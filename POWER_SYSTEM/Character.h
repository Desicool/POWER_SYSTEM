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
	//����userID��ȡϵͳ��ɫ
	void init(string userID);
	int getPrivilege() { return privilege; }
	wstring get_character_name() { return character_name; }
	~Character();
};

