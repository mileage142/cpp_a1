//list converted to use std::string (not int)
#include <iostream> //just for testing purposes
#include "strlist.h"
using ll=linked_list;
//main inserted for compile reasons
/*int main(int argv, char** argc)
{
    ll mylist;
    mylist.add("thing");
    mylist.add("odata is spaced");
    mylist.add("thing");
    mylist.add("data3");
    mylist.print_list();
    mylist.search("thing");
    return 0;
}*/
void ll::node::set_next(std::unique_ptr<ll::node>&& newnext)
{
    next = std::move(newnext);
}

ll::node * ll::node::get_next(void)
{
    return next.get();
}

std::unique_ptr<ll::node>& ll::node::get_next_ptr(void)
{
    return next;
}

std::string ll::node::get_data(void)
{
    return data;
}

bool ll::add(std::string data)
{
    node * current;
    node * prev = nullptr;
    std::unique_ptr<ll::node> newnode = std::make_unique<ll::node>(data);
    if(head == nullptr)
    {
        head = std::make_unique<node>(data);
        ++size;
        return true;
    }

    //get the pointer held by the unique_ptr
    current = head.get();
    
    //this is an alpha sort function    
/*    while(current && current->data < data)
    {
        prev = current;
        current = current->get_next();
    }
*/    
    if(!prev)
    {
        newnode->set_next(std::move(head));
        head = std::move(newnode);
    }
    else if(!current)
    {
        prev->set_next(std::move(newnode));
    }
    else
    {
        newnode->set_next(std::move(prev->get_next_ptr()));
        prev->set_next(std::move(newnode));
    }
    ++size;
    return true;
}


bool ll::search(std::string needle)
{
    node * current;
    current = head.get();
    int word_count = 0;

    while(current != nullptr)
    {
        if(current->get_data() == needle)
        {    
            word_count++;
            current = current->get_next();
      
        }
        else
        {
            current = current->get_next();
        }
    }
    std::cout << "occurences of " << needle;
    std::cout << ": " << word_count << std::endl;
    return true;
}

bool ll::print_list()
{
     node * current;
     current = head.get();

     while(current != nullptr)
     {
        std::cout << current->get_data() << std::endl;
        current = current->get_next();
     }

     return true;
}
