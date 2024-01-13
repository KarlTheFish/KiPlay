#include "Finder.h"
#include "Finder.cpp"
#include <iostream>

using namespace ftxui;

char action = ' ';

void actions();

int main() {
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
            std::cout << "Bye-bye!" << std::endl;
            exit(EXIT_SUCCESS);
            break;
        case 'f':
            Finder finder;
            finder.Main();
            action = ' ';
            break;
    }
}