//
// Created by karl-aleksander on 1/9/24.
//

#include "MusicFile.h"
#include <string>
#include <iostream>

using namespace std;

class MusicFile {
    int ID;
    string name;
    string artist;
    int amountPlayed;
    string filepath;

public:
    //Constructor
    MusicFile(string name, string artist, string filepath){
        ID = 0;
        this->name = name;
        this->artist = artist;
        this->amountPlayed = 0;
        this->filepath = filepath;
    }

    void ShowData(){
        std::cout << "Title: " << name << endl << "Artist: " << artist << endl;
    }

};

class SongBuilder{
public:
    SongBuilder setName(string name){
        this->name = name;
        return *this;
    }
    SongBuilder setArtist(string artist){
        this->artist = artist;
        return *this;
    }
    SongBuilder setFilepath(string filepath){
        this->filepath = filepath;
        return *this;
    }
    MusicFile build(){
        return {name, artist, filepath};
    }
private:
    string name;
    string artist;
    string filepath;
};