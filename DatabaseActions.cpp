//
// Created by karl-aleksander on 14.01.24.
//

#include "DatabaseActions.h"
#include <sqlite3.h>
#include <string>
#include <iostream>

using namespace std;

class DBconnection{
public:
    sqlite3 *db;
    int Open(){
        char errorMsg = 0;
        int errorInt;

        errorInt = sqlite3_open("Kiplay.db", &db);
        if(errorInt){
            cout << "Can't open database, error: " << sqlite3_errmsg(db) << endl;
            return 1;
        }
        else {
            cout << "Opened database successfully" << endl;
            return 0;
        }
    }
    int Close(){
        sqlite3_close(db);
        return 0;
    }
};

class SearchDB{
public:
    string query;
    DBconnection connection;
    //Constructor
    SearchDB(string query){
        this->query = query;
    }

    bool Exists(){
        connection.Open();

        return true;
    }


};

class InitialDbTablecreation{
public:
    void SongTable(){ //If the table doesn't exist, create it
        connection.Open();
        statement = "CREATE TABLE IF NOT EXISTS Song("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "title VARCHAR(1000) NOT NULL,"
                    "artist VARCHAR(1000) NOT NULL,"
                    "amountPlayed INT NOT NULL DEFAULT(0),"
                    "filepath VARCHAR(1000) NOT NULL"
                    ");";

        char* errorMsg;
        errorInt = sqlite3_exec(connection.db, statement.c_str(), NULL, 0, reinterpret_cast<char **>(errorMsg));

        if(errorInt == SQLITE_OK){
            cout << "All good!" << endl;
            connection.Close();
        }
        else{
            cout << "Error: " << errorInt << endl;
        }
    }
private:
    DBconnection connection;
    int errorInt;
    string statement;
    //const char *statement;
};

