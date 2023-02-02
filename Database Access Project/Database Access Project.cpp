
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



static int callback(void* unused, int numCol, char** data, char** columns) {
    int i;
    std::fprintf(stderr, "%s: ", (const char*)unused);

    for (i = 0; i < numCol; i++) {
        printf("%s = %s\n", columns[i], data[i] ? data[i] : "NULL");
    }

    printf("\n");
    return 0;
}

/*
int main(int argc, char** argv)
{
    sqlite3* DB;

    sqlite3_stmt* stmt;
    const char* sql = "SELECT ID, Name FROM User";
    int rc = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        printf("error: ", sqlite3_errmsg(DB));
        return;
    }
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = sqlite3_column_text(stmt, 1);
        // ...
    }
    if (rc != SQLITE_DONE) {
        printf("error: ", sqlite3_errmsg(DB));
    }
    sqlite3_finalize(stmt);
}
*/