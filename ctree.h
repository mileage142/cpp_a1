//list converted to use std::string (not int)

#include <memory>
#include <iostream>
#include<stack>
#include<string>

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
        bool add(std::string);
        bool find(std::string);
        std::string get_data(void);
        std::string get_line(void);
        void stack_line(void);
        std::unique_ptr<node>& get_right_ptr(void);
        std::unique_ptr<node>& get_left_ptr(void);
        friend class ctree;
        //friend class allows access to private variables
    };

    std::unique_ptr<node>root;
    int size;
    static std::stack<std::string> lines;
    //std::stack<std::string> lines();
    public:
    //static std::stack<std::string> lines;
    ctree(void) : root(nullptr), size(0) {}
    bool add(std::string);
    //bool add_data(std::string);
    bool search(std::string);
    bool find(std::string);
    void stack_line(void);
    std::string get_line(void);
};
