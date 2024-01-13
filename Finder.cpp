//
// Created by karl-aleksander on 1/9/24.
// Finds mp3 files in specified location and gives option to add them into the player library
//

#include "Finder.h"
#include <ftxui/dom/elements.hpp>
#include <string>
#include <iostream>

using namespace ftxui;
using namespace std;

class Finder{
public:
    int Main(){
        string path;
        vector<string> results;

        std::cout << "Enter path to directory to be searched: ";
        std::cin >> path;
        results = Search(path);
        AddSongs(results);
    }
private:
    vector<string> Search(string path){
        int foundFiles = 0;
        string command = "find " + path + " -name \"*.mp3\" -printf \"%P\\n\"";
        FILE* pipe = popen(command.c_str(), "r");
        if(!pipe){
            std::cout << "Unexpected error occurred, exiting program." << std::endl;
            exit(1);
        }
        char buffer[128];
        string foundFile;
        vector<string> result;
        while(!feof(pipe)){
            if(fgets(buffer, 128, pipe) != NULL){
                foundFiles++;
                std::cout << foundFiles << ". " << buffer << std::endl;
                result.emplace_back(buffer);
            }
        }
        pclose(pipe);
        std::cout << "Found " << foundFiles << " files" << std::endl;
        return result;
    }
    void AddSongs(const vector<string>& results){
        cout << "Enter the number in front of the song you'd like to add into your library. Enter '0' to finish adding songs." << endl;
        int userSongIndex = 0;
        cin >> userSongIndex;
        while(userSongIndex != 0){
            cout << results.at(userSongIndex - 1) << endl;
            cout << "Enter the number of the next song to add or '0' to finish adding songs" << endl;
            cin >> userSongIndex;
        }
    }
};