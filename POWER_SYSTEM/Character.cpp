#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}


void Character::init(string userID)
{
	sql::ResultSet* rs = characterDAO::get_character(userID);
	while (rs->next())
	{
		ID = rs->getString(
			(sql::SQLString)"characterID").c_str();
		sql::SQLString tm = rs->getString(
			(sql::SQLString)"characterName");
		const char* tmp = tm.c_str();
		CString tt = UTF82WCS(tmp);
		character_name = tt;
	}
	delete rs;
	privilege = characterDAO::get_privilege(ID);
}