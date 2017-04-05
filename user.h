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
    private:
    ll dict_list;
    ll text_list;
    char output;
    std::string option;
    std::map <std::string, int> count;

    public:
    user() : dict_list(), text_list(), count() {}
    user(std::string input_dict, std::string input_text) : dict_list(), text_list(), count() {}
    

    //bool choose_option(void);
    void get_list(ll);
    void start_list(void);
    ll open_dict(std::string);
    ll open_text(std::string);
    bool process_text(ll, ll);
    bool output_to_file(std::string);
    //std::map get_count(void);
};
