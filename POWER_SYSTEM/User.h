#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include "userDAO.h"

using namespace std;
using namespace userDAO;
#define LOGINED		0x3f
#define NOTFOUND	1
#define OK			0
class User
{
private:
	//data
	string ID;
	string name;
	string password;
	string identityNo;
	string phoneNo;
	string address;
	string email;
	int status;
	string createDate;
	
public:
	//get set
	string getID();
	void setID(string _ID);
	string getname();
	void setname(string _name);
	void setpassword(string _password);
	string getidentityNo();
	void setidentityNo(string _identityNo);
	string getphoneNo();
	void setphoneNo(string _phoneNo);
	string getaddress();
	void setaddress(string _address);
	int getstatus();
	void setstatus(int _status);
	string getcreateDate();
	void setcreateDate(string _createDate);
	void setemail(string _email);
	string getemail();
	User();
	User(string account, string pwd);
	int login();
	~User();
	string regist();
	
};
#endif