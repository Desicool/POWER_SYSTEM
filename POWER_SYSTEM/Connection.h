#pragma once
#ifndef CONNECTION_H
#define CONNECTION_H
#include "Connection.h"
#include <jdbc\mysql_connection.h>
#include <jdbc\cppconn/driver.h>
#include <jdbc\cppconn/exception.h>
#include <jdbc\cppconn/resultset.h>
#include <jdbc\cppconn/statement.h>
#include <jdbc\cppconn/prepared_statement.h>
#include <mysqlx\common\op_if.h>
class Connection
{
	sql::Driver *driver;
	//sql::Statement *stmt;
	//sql::PreparedStatement *pst;
public:
	sql::Connection *con;
	Connection();
	~Connection();
};

#endif