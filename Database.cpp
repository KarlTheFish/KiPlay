//
// Created by karl-aleksander on 1/15/24.
//

#include "Database.h"
#include <sqlite3.h>
#include <iostream>

using namespace std;

sqlite3 *db;

vector<string> Database::DBresults;


int Database::Open() {
    char errorMsg = 0;
    int errorInt;

    errorInt = sqlite3_open("Kiplay.db", &db);
    if(errorInt){
        std::cout << "Can't open database, error: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }
    else {
        std::cout << "Opened database successfully" << std::endl;
        return 0;
    }
}

int Database::Close() {
    sqlite3_close(db);
    return 0;
}

void Database::SongTable() {//If the table doesn't exist, create it
    Open();
    statement = "CREATE TABLE IF NOT EXISTS Song("
                "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                "title VARCHAR(1000) NOT NULL,"
                "artist VARCHAR(1000) NOT NULL,"
                "amountPlayed INT NOT NULL DEFAULT(0),"
                "filepath VARCHAR(1000) NOT NULL"
                ");";

    errorInt = sqlite3_exec(db, statement.c_str(), NULL, 0, reinterpret_cast<char **>(errorMsg));

    if(errorInt == SQLITE_OK){
        cout << "All good!" << endl;
        Close();
    }
    else{
        cout << "Error: " << errorInt << endl;
    }

}

bool Database::exists(std::string rowName, std::string columnName, std::string inTable) {
    Open();
    statement = "SELECT EXISTS(SELECT 1 FROM " + inTable + " WHERE " + columnName + "='" + rowName + "');";

    errorInt = sqlite3_exec(db, statement.c_str(), callback, nullptr, errorMsg);
    if(errorInt != SQLITE_OK){
        cerr << "Unexpected error: " << errorInt << endl;
    }
    else{
        cout << "Check exist OK" << endl;
    }
    if(!DBresults.empty()){
        if(DBresults.at(0) == "0"){
            cout << "Exists" << endl;
            return true;
        }
        else{
            cout << "Does not exist" << endl;
            return false;
        }
    }
    else{
        cout << "Results empty" << endl;
        return false;
    }

}

int Database::callback(void *data, int argc, char **argv, char **colNames) {
    int i;
    string result;
    for (i = 0; i < argc; i++) {
        //printf("%s = %s\n", colNames[i], argv[i] ? argv[i] : "NULL");
        //push back result to results vector
        result;
        cout << result << endl;
        DBresults.emplace_back(result);
        //Praying to god this works
    }
    return 0;
}

void Database::AddSong(std::string Title, std::string Artist, std::string Filepath) {
    Open();
    statement = "INSERT INTO Song (title, artist, filepath) VALUES ('" + Title + "', '" + Artist + "', '" + Filepath + "');";
    errorInt = sqlite3_exec(db, statement.c_str(), NULL, 0, reinterpret_cast<char **>(errorMsg));

    if(errorInt == SQLITE_OK){
        cout << "Song inserted successfully!" << endl;
        Close();
    }
    else{
        cout << "Error: " << errorInt << endl;
    }
    Close();
}