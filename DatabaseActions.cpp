//
// Created by karl-aleksander on 14.01.24.
//

#include "DatabaseActions.h"
#include <sqlite3.h>
#include <string>
#include <iostream>

using namespace std;

class DBconnection{
    sqlite3 *db;
public:
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
    //Constructor
    SearchDB(string query){
        this->query = query;
    }

    bool Exists(){
        OpenDB();
        return true;
    }

private:
    void OpenDB(){
        DBconnection connection;
        connection.Open();
    }

};

