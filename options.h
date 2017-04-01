#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include "user.h" //template for all datastructures

class options
{
    std::string dict;
    std::string text;
    public:
    options() : dict(), text() {}
    bool choose_option(int, char**);
};
