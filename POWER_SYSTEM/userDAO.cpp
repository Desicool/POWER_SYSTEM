#include "stdafx.h"
#include "userDAO.h"
using namespace std;
string userDAO::login_check(string username, string pwd)
{
	Connection *db = new Connection();
	sql::PreparedStatement *pst = db->con->prepareStatement(sql::SQLString(
		"select userID from user where username = ? and password = ? and status != -1")
	);
	
	pst->setString(1, username.c_str());
	pst->setString(2, pwd.c_str());
	sql::ResultSet* rs = pst->executeQuery();
	while (rs->next())
	{
		return string(rs->getString("userID").c_str());
	}
	delete rs;
	delete pst;
	delete db;
	return string();
}
sql::ResultSet* userDAO::get_user_info(string userID)
{
	Connection *db = new Connection();
	sql::PreparedStatement *pst = db->con->prepareStatement(sql::SQLString(
		"select * from user where userID = ?")
	);
	pst->setString(1, userID.c_str());
	sql::ResultSet* rs = pst->executeQuery();
	delete pst;
	delete db;
	return rs;
}


#define USER_EXISTS 1
#define INSERT_FAIL 2
int userDAO::regist(string _name, string _pwd, string _phone, string _address, string _email, string _identity)
{
	Connection *db = new Connection();
	//检测用户是否已存在
	sql::PreparedStatement *pst = db->con->prepareStatement(sql::SQLString(
		"select userID from user where username = ?")
	);
	sql::SQLString str = _name.c_str();
	pst->setString(1, _name.c_str());
	sql::ResultSet* rs = pst->executeQuery();
	delete pst;
	pst = nullptr;
	while (rs->next())
		return USER_EXISTS;
	try {
		//自动生成ID
		pst = db->con->prepareStatement((sql::SQLString)
			"select count(DISTINCT username) from user"
		);
		sql::ResultSet* tmp = pst->executeQuery();
		int num = 0;
		while (tmp->next())
			num = tmp->getInt(1);
		num++;
		delete tmp, pst;
		pst = nullptr;
		string ID = "U";
		stack<char>Q;
		for (int i = 0;i < 5;i++)
		{
			Q.push(num % 10 + '0');
			num /= 10;
		}
		while (!Q.empty())
		{
			ID += Q.top();
			Q.pop();
		}
		pst = db->con->prepareStatement((sql::SQLString)
			"insert into user set userID = ?,username = ?,password = ?,identityNo = ?,phoneNo = ?,address = ?,email = ?,status = 0,createDate = curtime()"
		);
		pst->setString(1, ID.c_str());
		if (_name.length())
			pst->setString(2, _name.c_str());
		else
			pst->setNull(2, 0);
		if (_pwd.length())
			pst->setString(3, _pwd.c_str());
		else
			pst->setNull(3, 0);
		if (_identity.length())
			pst->setString(4, _identity.c_str());
		else
			pst->setNull(4, 0);
		if (_phone.length())
			pst->setString(5, _phone.c_str());
		else
			pst->setNull(5, 0);
		if (_address.length())
			pst->setString(6, _address.c_str());
		else
			pst->setNull(6, 0);
		if (_email.length())
			pst->setString(7, _email.c_str());
		else
			pst->setNull(7, 0);
		pst->executeUpdate();
		delete pst;
		pst = db->con->prepareStatement((sql::SQLString)
			"insert into `user-character` set userID = ?,characterID = 'C002'"
		);
		pst->setString(1, ID.c_str());
		pst->executeUpdate();
	}
	catch (sql::SQLException e)
	{
		cerr << e.what();
		return 2;
	}
	return 0;
}

#undef USER_EXISTS
#undef INSERT_FAIL
vector<CString> userDAO::get_all()
{
	Connection *db = new Connection();
	sql::PreparedStatement *pst = db->con->prepareStatement(sql::SQLString(
		"select username from user")
	);
	sql::ResultSet* rs = pst->executeQuery();
	vector<CString>ret;
	while (rs->next())
	{
		ret.push_back(UTF82WCS(rs->getString("username").c_str()));
	}
	delete pst;
	delete db;
	return ret;
}

bool userDAO::ban_user(string _name)
{
	Connection *db = new Connection();
	sql::PreparedStatement *pst = db->con->prepareStatement(sql::SQLString(
		"update user set status = -1 where username = ?")
	);
	pst->setString(1, _name.c_str());
	return pst->executeUpdate();
}
