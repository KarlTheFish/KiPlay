#include "Finder.h"
#include "Finder.cpp"
#include <iostream>
#include "Database.h"

using namespace ftxui;

char action = ' ';

void actions();

int main() {
    Database database;

    database.SongTable(); //Init

    database.exists("Allan Roosileht", "artist", "Song");

    Element WelcomeText = center(text("Welcome to KiPlay!") | border);

    auto screen = Screen::Create(Dimension::Full(),
                                 Dimension::Fit(WelcomeText));

    Render(screen, WelcomeText);

    screen.Print();
    while(action == ' '){
        actions();
    }

    return EXIT_SUCCESS;
}

//Don't know why it wants me to do this, but it won't work otherwise
void find(){
    vector<string> results;
    Finder finder;
    cout << "Enter path to directory to be searched: ";
    cin >> finder.Path;
    results = finder.Search();
    finder.AddSongs(results);
}

void exit(){
    std::cout << "Bye-bye!" << std::endl;
    exit(EXIT_SUCCESS);
}

void actions(){
    Element ActionMenu = vbox({
        center(text("What would you like to do?")),
        hbox({text("F - find songs") | border,
              text("Q - quit") | border})
    });
    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(ActionMenu));
    Render(screen, ActionMenu);
    screen.Print();
    std::cin >> action;
    action = tolower((int)action);
    switch(action){
        case 'q':
            exit();
            break;
        case 'f':
            find();
            action = ' ';
            break;
    }
}

