#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}


vector<CString> Character::get_all()
{
	return characterDAO::get_all();
}

vector<CString> Character::get_all_privilege()
{
	return characterDAO::get_all_privilege();
}

bool Character::d_character(string username, string cname)
{
	return characterDAO::d_character(username, cname);
}

bool Character::d_function(string cname, string fname)
{
	return characterDAO::d_function(cname, fname);
}

bool Character::add_character(string cname)
{
	return characterDAO::add_character(cname);
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