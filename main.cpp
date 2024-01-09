#include "UI/mainTUI.h"
#include "Finder.cpp"
#include <iostream>

int main() {
    //mainTUI();
    Finder finder;
    std::cout << finder.Search("/home/karl-aleksander/Music/") << std::endl;
}