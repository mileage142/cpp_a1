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
#include <vector>
#include <list>
#include <set>
#include "ctree.h"

using ll=linked_list;

class user
{
    private:
    ll dict_clist;
    ll text_clist;
    char output;
    std::string option;
    std::map <std::string, int> count;

    public:
    user() : dict_clist(), text_clist(), count() {}
    user(std::string input_dict, std::string input_text) : dict_clist(), text_clist(), count() {}
    

    void get_list(ll);
    void start_list(void);
    ll open_clist_dict(std::string dict);
    std::vector<std::string> open_vector_dict(std::string dict);
    std::list<std::string> open_list_dict(std::string dict);
    std::set<std::string>  open_set_dict(std::string dict);
    ctree open_ctree_dict(std::string dict);
    
    ll open_clist_text(std::string text);
    std::vector<std::string> open_vector_text(std::string text);
    std::list<std::string> open_list_text(std::string text);
    std::set<std::string> open_set_text(std::string text);
    ctree open_ctree_text(std::string text);

    bool process_text(ll, ll);
    bool process_text(std::vector<std::string>, std::vector<std::string>);
    bool process_text(std::list<std::string>, std::list<std::string>);
    bool process_text(std::set<std::string>, std::set<std::string>);
    bool process_text(ctree, ctree);

    bool output_to_file(std::string);
    //std::map get_count(void);
};
