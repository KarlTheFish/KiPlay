//
// Created by karl-aleksander on 1/15/24.
//

#ifndef KIPLAY_DATABASE_H
#define KIPLAY_DATABASE_H


#include <string>
#include <vector>

class Database {
public:
    //Init
    void SongTable();

    //Does item exist?
    bool exists(std::string rowName, std::string columnName, std::string inTable);

    //Add song to database
    void AddSong(std::string Title, std::string Artist, std::string Filepath);

private:
    int errorInt;
    char **errorMsg{};
    std::string statement;
    static std::vector<std::string> DBresults;

    int Open();
    int Close();

    //Searching callback
    static int callback(void* data, int argc, char** argv, char** colNames);

};


#endif //KIPLAY_DATABASE_H
