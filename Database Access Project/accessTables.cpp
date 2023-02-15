#include <iostream>
#include <sqlite3.h>
#include <vector>

using namespace std;

class User {
private:
	const string username;
	const string password;

public:
	User(string username, string password) : username(username), password(password) {
	}

	string getUser() {
		return this->username;
	}

	string getPassword() {
		return this->password;
	}
};

// Global variables for pulled data.

vector<string> usernames;
vector<string> objects;
vector<User> accounts;

class AccessDatabase {

private:
	string sql;
	// int argc;
	// char** argv;

public:

	AccessDatabase(string sql) : sql(sql) {
		sqlite3* db;
		int exit = 0;
		exit = sqlite3_open("testDB.db", &db);

		string data = ("CALLBACK FUNCTION");


		if (exit) {
			cerr << "Error opening DB" << sqlite3_errmsg(db) << endl;
		}
		else {
			cout << "OPENED DATABASE SUCCESSFULLY" << endl;
		}

		int rc = sqlite3_exec(db, sql.c_str(), accessAccounts, (void*)data.c_str(), NULL);

		if (rc != SQLITE_OK) {
			cerr << "Error SELECT" << endl;
		}
		else {
			cout << "Operation OK" << endl;
		}

		sqlite3_close(db);
	};

	static int accessAccounts(void* unused, int numCol, char** data, char** columns) {

		// fprintf(stderr, "%s: \n", (const char*)unused);

		for (int i = 0; i < numCol; i++) {
			// printf("%s = %s\n", columns[i], data[i] ? data[i] : "NULL");
			string currentUsername;
			string currentPassword;
			
			// cout << columns[i] << endl;
			
			if (string(columns[i]) == "Username") {
				usernames.push_back(data[i] ? data[i] : "NULL");
				currentUsername = data[i] ? data[i] : "NULL";
			}
			else {
				currentPassword = data[i] ? data[i] : "NULL";
			}		

			User user1 = User(currentUsername, currentPassword);

			//	cout << user1.getUser() << endl;
			//	cout << user1.getPassword() << endl;

			accounts.push_back(user1);
		}

		printf("\n");
		return 0;
	}

	static int accessObjects(void* unused, int numCol, char** data, char** columns) {

		fprintf(stderr, "%s: \n", (const char*)unused);

		for (int i = 0; i < numCol; i++) {
			NULL;
		}
	}
};

int main() {
	const string showAccounts = "SELECT * FROM Accounts";
	const string showObjects = "SELECT * FROM Objects";
	const string showTriangles = "SELECT * FROM Triangles";
	const string showVertices = "SELECT * FROM Vertices";

	AccessDatabase accessDb(showAccounts);

	cout << "Using accounts vector: \n";
	for (auto i : accounts) {
		cout << i.getUser();
		cout << i.getPassword() << endl;

	}

	return (0);
}