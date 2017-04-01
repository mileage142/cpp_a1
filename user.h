//user.h
//
//header for user_list class
//Author: Miles Thomas s3494949
//
#include <iostream>
#include <string>
#include <map>
#include "strlist.h"
#include <boost/tokenizer.hpp>


using ll=linked_list;

class user
{
//private:
    ll dict;
    ll text;
    char output;
    std::string option;
    std::map <char, int> count;

    public:
    user() : dict(), text(), count() {}
    user(std::string input_dict, std::string input_text) : dict(), text(), count() {}
    

    //bool choose_option(void);
    void get_list(ll);
    void start_list(void);
    bool open_dict(std::string);
    bool open_text(std::string);
    bool process_text(void);
    bool output_to_file(void);
    //std::map get_count(void);
};
