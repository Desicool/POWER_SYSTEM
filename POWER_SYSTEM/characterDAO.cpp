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
		case 4:
			ret |= P_DISTRIBUTE_CHARACTER;
			break;
		case 5:
			ret |= P_ADD_CHARACTER;
			break;
		case 6:
			ret |= P_DISTRIBUTE_FUNC;
			break;
		}
	}
	delete pst;
	delete db;
	return ret;
}

vector<CString> characterDAO::get_all()
{
	Connection *db = new Connection();
	sql::PreparedStatement *pst = db->con->prepareStatement(sql::SQLString(
		"select characterName from `character`")
	);
	sql::ResultSet* rs = pst->executeQuery();
	vector<CString>ret;
	while (rs->next())
	{
		ret.push_back(UTF82WCS(rs->getString("characterName").c_str()));
	}
	delete pst;
	delete db;
	return ret;
}

vector<CString> characterDAO::get_all_privilege()
{
	Connection *db = new Connection();
	sql::PreparedStatement *pst = db->con->prepareStatement(sql::SQLString(
		"select functionName from function")
	);
	sql::ResultSet* rs = pst->executeQuery();
	vector<CString>ret;
	while (rs->next())
	{
		ret.push_back(UTF82WCS(rs->getString("functionName").c_str()));
	}
	delete pst;
	delete db;
	return ret;
}

bool characterDAO::d_character(string username, string cname)
{
	Connection* db = new Connection;
	try {
		sql::PreparedStatement *pst = db->con->prepareStatement((sql::SQLString)
			"delete from `user-character`\
		where userID IN(\
		select userID\
		from `user`\
		where username = ?)"
		);
		pst->setString(1, username.c_str());
		pst->executeUpdate();
		delete pst;
		sql::SQLString uID, cID;
		pst = db->con->prepareStatement((sql::SQLString)
			"select userID from `user` where username = ?"
		);
		pst->setString(1, username.c_str());
		sql::ResultSet* rs = pst->executeQuery();
		while (rs->next())
			uID = rs->getString("userID");
		delete rs;
		delete pst;
		pst = db->con->prepareStatement((sql::SQLString)
			"select characterID from `character` where characterName = ?"
		);
		pst->setString(1, cname.c_str());
		rs = pst->executeQuery();
		while (rs->next())
			cID = rs->getString("characterID");
		delete rs;
		delete pst;
		pst = db->con->prepareStatement((sql::SQLString)
			"insert into `user-character`\
			set userID = ?\
			, characterID = ?"
		);
		pst->setString(1, uID.c_str());
		pst->setString(2, cID.c_str());
		pst->executeUpdate();
		delete pst;
		pst = db->con->prepareStatement((sql::SQLString)
			"select characterName from `character` a,`user-character` b\
			where a.characterID = b.characterID and userID = ?"
		);
		pst->setString(1, uID.c_str());
		rs = pst->executeQuery();
		while (rs->next())
		{
			return UTF82WCS(rs->getString("characterName").c_str()) == UTF82WCS(cname.c_str());
		}
		return false;
	}
	catch (sql::SQLException e)
	{
		return false;
	}
}

bool characterDAO::d_function(string cname, string fname)
{
	Connection* db = new Connection;
	try {
		sql::PreparedStatement *pst = db->con->prepareStatement((sql::SQLString)
			"select count(*) from `character-f-o`\
		where characterID IN(\
			select characterID\
			from `character`\
			where characterName = ?)\
		and functionID IN(\
			select fID\
			from `function`\
			where functionName = ?)"
		);
		pst->setString(1, cname.c_str());
		pst->setString(2, fname.c_str());
		sql::ResultSet* rs = pst->executeQuery();
		while (rs->next())
			return true;
		delete rs;
		delete pst;
		sql::SQLString cID, fID;
		pst = db->con->prepareStatement((sql::SQLString)
			"select characterID from `character` where characterName = ?"
		);
		pst->setString(1, cname.c_str());
		rs = pst->executeQuery();
		while (rs->next())
			cID = rs->getString("characterID");
		delete rs;
		delete pst;
		pst = db->con->prepareStatement((sql::SQLString)
			"select fID from `function` where functionName = ?"
		);
		pst->setString(1, fname.c_str());
		rs = pst->executeQuery();
		while (rs->next())
			fID = rs->getString("fID");
		delete rs;
		delete pst;
		pst = db->con->prepareStatement((sql::SQLString)
			"insert into `character-f-o`\
			set characterID = ?\
			, functionID = ?"
		);
		pst->setString(1, cID.c_str());
		pst->setString(2, fID.c_str());
		pst->executeUpdate();
		delete pst;
		pst = db->con->prepareStatement((sql::SQLString)
			"select count(*) from `character-f-o`\
		where characterID = ?)\
		and functionID = ?"
		);
		pst->setString(1, cID.c_str());
		pst->setString(2, fID.c_str());
		rs = pst->executeQuery();
		while (rs->next())
		{
			return true;
		}
		return false;
	}
	catch (sql::SQLException e)
	{
		return false;
	}
}

bool characterDAO::add_character(string cname)
{
	Connection *db = new Connection();
	try {
		sql::PreparedStatement *pst = db->con->prepareStatement(sql::SQLString(
			"select count(*) from `character` where characterName = ?")
		);
		pst->setString(1, cname.c_str());
		sql::ResultSet* rs = pst->executeQuery();
		while (rs->next())
		{
			if(rs->getInt(1) > 0)
				return false;
		}
		delete rs;
		delete pst;
		pst = db->con->prepareStatement(sql::SQLString(
			"select count(*) a from `character`")
		);
		rs = pst->executeQuery();
		int num = 0;
		while (rs->next())
			num = rs->getInt("a");
		delete rs;
		delete pst;
		string xx = "C";
		xx += ++num / 100 % 10 + '0';
		xx += num / 10 % 10 + '0';
		xx += num % 10 + '0';
		pst = db->con->prepareStatement(sql::SQLString(
			"insert into `character` set characterID = ?,characterName = ?")
		);
		pst->setString(1, xx.c_str());
		pst->setString(2, cname.c_str());
		pst->executeUpdate();
		delete pst;
		delete db;
		return true;
		
	}
	catch (sql::SQLException e)
	{
		return false;
	}
}
