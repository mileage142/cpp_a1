//list converted to use std::string (not int)

#include <memory>


class linked_list
{
    class node
    {
        std::string data;
        std::unique_ptr<node> next;
        public:
        node(std::string newdata) : data(newdata), next(nullptr) {}

        void set_next(std::unique_ptr<node>&& newnext);
        node * get_next(void);
        std::string get_data(void);
        std::unique_ptr<node>& get_next_ptr(void);
        friend class linked_list;
        //firend class allows access to priv variables
    };

    std::unique_ptr<node>head;
    int size;
    public:
    linked_list(void) : head(nullptr), size(0) {}
    bool add(std::string);
    bool search(std::string);
    bool print_list(void);
};
