#include <iostream>
#include <sqlite3.h>
#include <vector>

// This file will be used to access Objects themselves.

using namespace std;

class Objects {
private:
	const int objectID;
	const string objectName;

	Objects(int ID, string name) : objectID(ID), objectName(name) {
	}
public:
	
	string getName() {
		return this->objectName;
	}
	
	int getID() {
		return this->objectID;
	}

};

vector<Objects> listOfObjects;