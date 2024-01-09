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
    ftxui::Element FinderWindow(){
        Element finderWindow = hbox(text("Test"));
        return finderWindow;
    }
    string Search(string path){
        int foundFiles = 0;
        string command = "find " + path + " -name \"*.mp3\" -printf \"%P\\n\"";
        FILE* pipe = popen(command.c_str(), "r");
        if(!pipe) return "ERROR";
        char buffer[128];
        string result = "";
        while(!feof(pipe)){
            if(fgets(buffer, 128, pipe) != NULL){
                foundFiles++;
                //result = result + to_string(foundFiles) + ". ";
                result += buffer;
            }
        }
        pclose(pipe);
        std::cout << "Found " << foundFiles << " files" << std::endl;
        return result;
    }
};