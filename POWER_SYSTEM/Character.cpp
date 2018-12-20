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
		character_name = rs->getString(
			(sql::SQLString)"characterName").c_str();
	}
	delete rs;
	privilege = characterDAO::get_privilege(ID);
}