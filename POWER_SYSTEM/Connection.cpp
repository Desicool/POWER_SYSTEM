#include "stdafx.h"
#include "Connection.h"



Connection::Connection()
{
	/* �������� */
	driver = get_driver_instance();
	con = driver->connect("localhost:3306", "root", "l1728L3sh+");
	//sql::mysql_options(&driver, MYSQL_SET_CHARSET_NAME, "gbk")
	/* ���� MySQL ���ݿ� mysystem  */
	con->setSchema("mysystem");
	//con->execute("set character_set_results = 'gbk';");
	//stmt = con->createStatement();
	//mySession = new Session(3306, "root", "l1728L3sh+");

	//myDb = &(mySession->getSchema("mysystem"));

}


Connection::~Connection()
{
	//delete stmt;
	//delete myDb;
	//delete mySession;
	delete con;
}

