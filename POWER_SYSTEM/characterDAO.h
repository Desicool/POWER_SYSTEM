#pragma once
#include "Connection.h"
using namespace std;
namespace characterDAO {
	sql::ResultSet* get_character(string ID);
	int get_privilege(string characterID);
}