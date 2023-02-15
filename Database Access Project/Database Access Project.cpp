
#include <iostream>
#include <sqlite3.h>

/*
 * Arguments on the callback function:
 *
 *   unused - Ignored in this case, see the documentation for sqlite3_exec
 *    count - The number of columns in the result set
 *     data - The row's data
 *  columns - The column names
 */

using namespace std;
// using namespace System;
// using namespace System::Windows::Forms;



static int callback(void* unused, int numCol, char** data, char** columns) {
    int i;
    std::fprintf(stderr, "%s: ", (const char*)unused);

    for (i = 0; i < numCol; i++) {
        printf("%s = %s\n", columns[i], data[i] ? data[i] : "NULL");
    }

    printf("\n");
    return 0;
};

// string processData() {

// };

//int main(int argc, char** argv) {
//    sqlite3* db;
//    int exit = 0;
//    exit = sqlite3_open("testDB.db", &db);
//
//    string data = ("CALLBACK FUNCTION");
//
//    string sql = ("SELECT * FROM Accounts;");
//
//    if (exit) {
//        std::cerr << "Error opening DB" << sqlite3_errmsg(db) << std::endl;
//        return (-1);
//    }
//    else {
//        std::cout << "OPENED DATABASE SUCCESSFULLY" << std::endl;
//    }
//
//    int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data.c_str(), NULL);
//
//    if (rc != SQLITE_OK) {
//        cerr << "Error SELECT" << endl;
//    }
//    else {
//        cout << "Operation OK" << endl;
//    }
//
//    sqlite3_close(db);
//
//    return (0);
//}