//
// Created by karl-aleksander on 1/9/24.
//

#include "mainTUI.h"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

using namespace ftxui;

int mainTUI() {
    Element header = hbox({
                                  text("KiPlay") | border,
                                  text("Status") | border | flex,
                          });

    auto screen = Screen::Create(Dimension::Full(),
                                 Dimension::Fit(header));

    Render(screen, header);
    screen.Print();

    return EXIT_SUCCESS;
}
