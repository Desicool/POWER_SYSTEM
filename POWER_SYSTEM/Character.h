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
	//����userID��ȡϵͳ��ɫ
	void init(string userID);
	~Character();
};

