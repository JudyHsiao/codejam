#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <ostream>
class Screen {
friend std::ostream& print(std::ostream& , Screen&);
public:
typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c):height(ht), width(wd), contents(ht*wd,c){}
private:
    pos cursor = 0;
    pos height =0, width = 0;
    std::string contents;
};

std::ostream& print(std::ostream& , Screen&);
#endif