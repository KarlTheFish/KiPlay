//
// Created by karl-aleksander on 1/9/24.
// Finds mp3 files in specified location and gives option to add them into the player library
//

#include "Finder.h"
#include <ftxui/dom/elements.hpp>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdio>
#include "MusicFile.cpp"
#include <sqlite3.h>
#include <cstring>

using namespace ftxui;
using namespace std;

class Finder{
public:
    string Path;

    vector<string> Search(){
        int foundFiles = 0;
        string command = "find " + Path + " -name \"*.mp3\" -printf \"%P\\n\"";
        FILE* pipe = popen(command.c_str(), "r");
        if(!pipe){
            std::cout << "Unexpected error occurred, exiting program." << std::endl;
            exit(1);
        }
        char buffer[512];
        string foundFile = "";
        vector<string> result;
        while(!feof(pipe)){
            if(fgets(buffer, 512, pipe) != NULL){
                    foundFiles++;
                    std::cout << foundFiles << ". " << buffer << std::endl;
                    result.emplace_back(buffer);
                    foundFile = "";
            }
        }
        pclose(pipe);
        std::cout << "Found " << foundFiles << " new files" << std::endl;
        return result;
    }
    void AddSongs(const vector<string>& results){
        string SongName;
        string ArtistName;
        string filePath;
        string userChoice;
        cout << "Enter the number in front of the song you'd like to add into your library. Enter '0' to finish adding songs." << endl;
        int userSongIndex = 0;
        cin >> userSongIndex;
        userChoice = results.at(userSongIndex - 1);
        cout << userChoice << endl;
        while(userSongIndex != 0){
            filePath = Path + userChoice;
            cout << "Enter song name(Default is filename):";
            std::getline(cin >> ws, SongName);
            if(SongName.empty()){
                //Set filename to whatever comes after the last / character
                stringstream SS(userChoice);
                string segment;
                while(getline(SS, segment, '/')){
                    SongName = segment;
                }
            }
            cout << endl << "Enter the artist(Default is Unknown):";
            std::getline(cin >> ws, ArtistName);
            if(ArtistName.empty()){
                ArtistName = "Unknown";
            }
            MusicFile musicFile = SongBuilder().setFilepath(filePath).setName(SongName).setArtist(ArtistName).build();
            musicFile.ShowData();
            cout << "Enter the number of the next song to add or '0' to finish adding songs" << endl;
            cin >> userSongIndex;
            userChoice = results.at(userSongIndex - 1);
            cout << userChoice << endl;
            if(userSongIndex == 0){
                return;
            }
        }
        if(userSongIndex == 0){
            return;
        }
    }
};