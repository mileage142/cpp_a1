#include <iostream>
#include <string>
#include <map>
class user
{
//private:
    static std::string dict;
    int text;
    char output;
    std::string option;
    std::map <char, int> count;
    //there is a chance that this will require extern keyword.:w

    public:
    user(std::string dict) : count(0) {}
    

    bool choose_option(std::string);
    bool open_dict(std::string);
    bool open_text(std::string);
    bool output_to_file(std::string);

};
