#pragma once
#include "Connection.h"
#include <vector>
#include "solveUTF8.h"
using namespace std;
namespace characterDAO {
	sql::ResultSet* get_character(string ID);
	int get_privilege(string characterID);
	vector<CString> get_all();
	vector<CString> get_all_privilege();
}