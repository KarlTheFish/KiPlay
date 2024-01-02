//
// Created by karl-aleksander on 12/21/23.
//

#include <string>
#include <ctime>
#include "songObject.h"

class SongObject{
    int ID;
    std::string name;
    std::string artist;
    tm duration;
    std::string album;

    public SongObject(int ID, std::string name, std::string artist, tm duration, std::string album){
        ID = this->ID;
        name = this->name;
        this->artist = artist;
        this->duration = duration;
        this->album = album;
    }
};