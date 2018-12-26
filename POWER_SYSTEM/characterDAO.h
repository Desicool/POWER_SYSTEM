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
	bool d_character(string username, string cname);
	bool d_function(string cname, string fname);
	bool add_character(string cname);
}