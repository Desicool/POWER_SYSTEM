#include "stdafx.h"
#include "characterDAO.h"

sql::ResultSet * characterDAO::get_character(string ID)
{
	Connection* db = new Connection;
	sql::PreparedStatement *pst = db->con->prepareStatement((sql::SQLString)
		"select a.characterID,characterName from `character` a, `user-character` b\
		 where a.characterID = b.characterID and b.userID = ?"
	);
	pst->setString(1, ID.c_str());
	return pst->executeQuery();
}

int characterDAO::get_privilege(string characterID)
{
	Connection* db = new Connection();
	sql::PreparedStatement *pst = db->con->prepareStatement((sql::SQLString)
		"select DISTINCT functionID from `character-f-o`\
		 where characterID = ?"
	);
	pst->setString(1, characterID.c_str());
	int ret = 0;
	sql::ResultSet* rs = pst->executeQuery();
	while (rs->next())
	{
		string x = rs->getString((sql::SQLString)"functionID").c_str();
		int tmp = 0;
		for (int i = 1;i < x.length();i++)
			tmp += x[i] - '0';
		switch (tmp)
		{
		case 1:
			ret |= P_QUERY;
			break;
		case 2:
			ret |= P_ADD_USER;
			break;
		case 3:
			ret |= P_UPDATE;
			break;
		}
	}
	delete pst;
	delete db;
	return ret;
}
