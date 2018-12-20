#include "stdafx.h"
#include "User.h"


string User::getID()
{
	return ID;
}
void User::setID(string _ID)
{
	ID = _ID;
}
string User::getname()
{
	return name;
}
void User::setname(string _name)
{
	name = _name;
}
void User::setpassword(string _password)
{
	password = _password;
}
string User::getidentityNo()
{
	return identityNo;
}
void User::setidentityNo(string _identityNo)
{
	identityNo = _identityNo;
}
string User::getphoneNo()
{
	return phoneNo;
}
void User::setphoneNo(string _phoneNo)
{
	phoneNo = _phoneNo;
}
string User::getaddress()
{
	return address;
}
void User::setaddress(string _address)
{
	address = _address;
}
int User::getstatus()
{
	return status;
}
void User::setstatus(int _status)
{
	status = _status;
}
string User::getcreateDate()
{
	return createDate;
}
void User::setcreateDate(string _createDate)
{
	createDate = _createDate;
}
void User::setemail(string _email)
{
	email = _email;
}
string User::getemail()
{
	return email;
}
int User::login()
{
	if (status == LOGINED)return LOGINED;
	string _ID;
	if ((_ID = login_check(name, password)).length())
	{
		setID(_ID);
		status = LOGINED;
		sql::ResultSet* rs = get_user_info(_ID);
		while (rs->next())
		{
			/*
			string identityNo;
			string phoneNo;
			string address;
			string email;
			int status;
			string createDate;
			*/
			setidentityNo(rs->getString("identityNo").c_str());
			if (identityNo.length() == 0)
				identityNo = "δ��֤";
			setaddress(rs->getString("address").c_str());
			if (address.length() == 0)
				address = "δ����";
			setphoneNo(rs->getString("phoneNo").c_str());
			if (phoneNo.length() == 0)
				phoneNo = "δ����";
			setemail(rs->getString("email").c_str());
			if (email.length() == 0)
				email = "δ����";
			setcreateDate(rs->getString("createDate").c_str());
		}
		return OK;
	}
	return NOTFOUND;
}
User::User()
{
	status = 0;
}

User::User(string account, string pwd):name(account),password(pwd)
{
	User();
}


User::~User()
{
}

string User::regist()
{
	int tmp = userDAO::regist(name, password, phoneNo, address, email, identityNo);
	if (tmp == 0)
		return "��ӳɹ���";
	else if (tmp == 1)
		return "���û����Ѵ���";
	else
		return "����ʧ�ܣ�������������ݿ�";
	
}
