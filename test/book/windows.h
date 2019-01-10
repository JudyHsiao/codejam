#ifndef WINDOWS_H
#define WINDOWS_H
#include <iostream>
#include <vector>
#include "screen.h"

class Windows{
friend std::ostream& print(std::ostream& , Windows&);

public:
    Windows& newScreen(const Screen& s) {
        screens.push_back(s);
        return *this;
    };

private:
    std::vector<Screen> screens {Screen(24,80, ' ')};
};

std::ostream& print(std::ostream& , Windows&);
#endif