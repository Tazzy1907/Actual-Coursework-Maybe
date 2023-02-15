#include <iostream>;
#include <sqlite3.h>;

using namespace std;

static int createAccountsTable(const char* fileName) {

	sqlite3* db;

	string sql = "CREATE TABLE IF NOT EXISTS Accounts("
		"Username TEXT NOT NULL, "
		"Password TEXT NOT NULL, "
		"CONSTRAINT Accounts_PK PRIMARY KEY (Username) );";

	try {
		int exit;
		exit = sqlite3_open(fileName, &db); // Links the actual file to the db name.

		char* messageError;
		exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK) {
			cerr << "Error creating Accounts table" << endl;
			sqlite3_free(messageError);
		}
		else {
			cout << "Accounts table has been created." << endl;
		}
	}
	catch (const exception & e) {
		cerr << e.what();
	};

};

static int createObjectsTable(const char* fileName) {
	sqlite3* db;

	string sql = "CREATE TABLE IF NOT EXISTS Objects("
		"ObjectID INTEGER NOT NULL, "
		"Username TEXT NOT NULL, "
		"ObjectName TEXT NOT NULL, "
		"DateAccessed DATE NOT NULL, "
		"CONSTRAINT Objects_PK PRIMARY KEY (ObjectID AUTOINCREMENT), "
		"CONSTRAINT Objects_FK FOREIGN KEY (Username) REFERENCES Accounts(Username) );";

	try {
		int exit;
		exit = sqlite3_open(fileName, &db); // Links the actual file to the db name.

		char* messageError;
		exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK) {
			cerr << "Error creating Objects table" << endl;
			sqlite3_free(messageError);
		}
		else {
			cout << "Objects table has been created." << endl;
		}
	}
	catch (const exception& e) {
		cerr << e.what();
	};

}

static int createTrianglesTable(const char* fileName) {
	sqlite3* db;

	string sql = "CREATE TABLE IF NOT EXISTS Triangles("
		"TriangleID INTEGER NOT NULL, "
		"ObjectID INTEGER NOT NULL, "
		"Vertex1ID INTEGER NOT NULL, "
		"Vertex2ID INTEGER NOT NULL, "
		"Vertex3ID INTEGER NOT NULL, "
		"CONSTRAINT Triangles_PK PRIMARY KEY (TriangleID AUTOINCREMENT) ON UPDATE CASCADE ON DELETE CASCADE, "
		"CONSTRAINT TRIANGLES_FK FOREIGN KEY (Vertex1ID) REFERENCES Vertices(VertexID) ON UPDATE CASCADE ON DELETE CASCADE, "
		"CONSTRAINT TRIANGLES_FK FOREIGN KEY (Vertex2ID) REFERENCES Vertices(VertexID) ON UPDATE CASCADE ON DELETE CASCADE, "
		"CONSTRAINT TRIANGLES_FK FOREIGN KEY (Vertex3ID) REFERENCES Vertices(VertexID) ON UPDATE CASCADE ON DELETE CASCADE );";

	try {
		int exit;
		exit = sqlite3_open(fileName, &db); // Links the actual file to the db name.

		char* messageError;
		exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK) {
			cerr << "Error creating Triangles table" << endl;
			sqlite3_free(messageError);
		}
		else {
			cout << "Triangles table has been created." << endl;
		}
	}
	catch (const exception& e) {
		cerr << e.what();
	};

}

static int createVerticesTable(const char* fileName) {
	sqlite3* db;

	string sql = "CREATE TABLE IF NOT EXISTS Vertices("
		"VertexID INTEGER NOT NULL, "
		"x REAL, "
		"y REAL, "
		"z REAL, "
		"CONSTRAINT Vertices_PK PRIMARY KEY (VertexID AUTOINCREMENT) );";

	try {
		int exit;
		exit = sqlite3_open(fileName, &db); // Links the actual file to the db name.

		char* messageError;
		exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK) {
			cerr << "Error creating Vertices table" << endl;
			sqlite3_free(messageError);
		}
		else {
			cout << "Vertices table has been created." << endl;
		}
	}
	catch (const exception& e) {
		cerr << e.what();
	};

}



