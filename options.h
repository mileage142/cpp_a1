#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include "user.h" //template for all datastructures

namespace po = boost::program_options;

class options
{
    std::string dict;
    std::string text;
    public:
    options() : dict(), text() {}
 
    po::variables_map vm;

    bool choose_option(int, char**);
};
