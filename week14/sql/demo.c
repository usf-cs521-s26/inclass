#include <sqlite3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DOG_STR_LEN 32
struct dog_t {
    int id;
    char name[DOG_STR_LEN];
    char breed[DOG_STR_LEN];
};

void fatal(const char *msg) {
    printf("%s\n", msg);
    exit(-1);
}

void fatal_db(sqlite3 *db) {
    fatal(sqlite3_errmsg(db));
}

void db_create_table(sqlite3 *db) {
    char *sql = "CREATE TABLE dogs(" \
        "id INTEGER PRIMARY KEY,"    \
        "name TEXT, breed TEXT);";
    char *msg;

    if (SQLITE_OK != sqlite3_exec(db, sql, NULL, NULL, &msg)) {
        fatal(msg);
    }
}

void db_insert(sqlite3 *db, struct dog_t *dogs, int len) {
    sqlite3_stmt *stmt;
    char *sql = "INSERT INTO dogs(id, name, breed) VALUES(?, ?, ?);";
    if (SQLITE_OK != sqlite3_prepare_v2(db, sql, -1, &stmt, NULL)) {
        fatal_db(db);
    }
    for (int d = 0; d < len; d++) {
        if (SQLITE_OK != sqlite3_bind_int(stmt, 1, dogs[d].id))
            fatal_db(db);
        if (SQLITE_OK != sqlite3_bind_text(stmt, 2, dogs[d].name, -1, NULL))
            fatal_db(db);
        if (SQLITE_OK != sqlite3_bind_text(stmt, 3, dogs[d].breed, -1, NULL))
            fatal_db(db);
        if (SQLITE_DONE != sqlite3_step(stmt))
            fatal_db(db);
        sqlite3_reset(stmt);
    }
    
}

int main(int argc, char **argv) {
    sqlite3 *db;
    if (SQLITE_OK != sqlite3_open("demo.db", &db)) {
        fatal(sqlite3_errmsg(db));
    }

    struct dog_t dogs[2];
    memset(dogs, 0, sizeof(dogs));
    dogs[0].id = 1;
    strncpy(dogs[0].name, "Ghost", DOG_STR_LEN - 1);
    strncpy(dogs[0].breed, "Husky", DOG_STR_LEN - 1);
    dogs[1].id = 2;
    strncpy(dogs[1].name, "Odi", DOG_STR_LEN - 1);
    strncpy(dogs[1].breed,"Jack Russell", DOG_STR_LEN - 1);

    db_create_table(db);
    db_insert(db, dogs, sizeof(dogs) / sizeof(struct dog_t));
    
}
