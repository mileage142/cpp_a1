//list converted to use std::string (not int)

#include <memory>
#include <iostream>
#include<string>
//#include <string>

class ctree 
{
    class node
    {
        std::string data;
        std::unique_ptr<node> right;
        std::unique_ptr<node> left;
        public:
        node(std::string newdata) : data(newdata), right(nullptr),
        left(nullptr){}

        void set_right(std::unique_ptr<node>&& newright);
        void set_left(std::unique_ptr<node>&& newleft);
        node * get_right(void);
        node * get_left(void);
        std::string get_data(void);
        std::unique_ptr<node>& get_right_ptr(void);
        std::unique_ptr<node>& get_left_ptr(void);
        friend class ctree;
        //friend class allows access to private variables
    };

    std::unique_ptr<node>head;
    int size;
    public:
    ctree(void) : head(nullptr), size(0) {}
    bool add(std::string);
    bool add_data(std::string);
    bool search(std::string);
    bool print_list(void);
    std::string get_line(int);
    bool list_start(void);
};
