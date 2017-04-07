/*************************************************************
 * This file is converted from intlist.cpp which was an example
 * by Paul Mictreeer for the COSC2140 course at RMIT

*/
//list converted to use std::string (not int)
//#include <iostream> //just for testing purposes
#include "ctree.h"

void ctree::node::set_right(std::unique_ptr<ctree::node>&& newright)
{
    right = std::move(newright);
}
ctree::node * ctree::node::get_right(void)
{
    return right.get();
}
std::unique_ptr<ctree::node>& ctree::node::get_right_ptr(void)
{
    return right;
}

void ctree::node::set_left(std::unique_ptr<ctree::node>&& newleft)
{
    left = std::move(newleft);
}
ctree::node * ctree::node::get_left(void)
{
    return left.get();
}
std::unique_ptr<ctree::node>& ctree::node::get_left_ptr(void)
{
    return left;
}


std::string ctree::node::get_data(void)
{
    return data;
}

bool ctree::add(std::string data)
{
    node * current;
    node * prev = nullptr;
    std::unique_ptr<ctree::node> newnode = std::make_unique<ctree::node>(data);
    if(head == nullptr)
    {
        head = std::make_unique<node>(data);
        ctree->add_data(data);
        return true;
    }
}

bool ctree::add_data(std::string data)
{
    //get the pointer held by the unique_ptr
    node * current;
    node * prev = nullptr;
    
    current = head.get();
    
    //this is an alpha sort function    
    if(current && current->data < data)
    {
        if(current->left)
        {
            return current->left->add_data(data)
        } 
        else
        {
            newleft->set_left(std::move(head));
            if(current->left)
            {    
                return true;
            }
            return false;
        }

       // prev = current;
       // current = current->get_right();
    }
    
    else
    {
        if(current->right)
        {
            return current->right->add_data(data)
        } 
        else
        {
            newleft->set_right(std::move(head));
            if(current->right)
            {    
                return true;
            }
            return false;
        }

       // prev = current;
       // current = current->get_right();
    }
} 
 


bool ctree::search(std::string needle)
{
    node * current;
    current = head.get();
    //int word_count = 0;

    while(current != nullptr)
    {
        if(current->get_data() == needle)
        {    
            current = current->get_right();
            return true;      
        }
        else
        {
            current = current->get_right();
        }
    }
    //std::cout << "occurences of " << needle;
    //std::cout << ": " << word_count << std::endl;
    return false;
}

bool ctree::print_list()
{
     node * current;
     current = head.get();
     
     std::cout << "print_list" << std::endl;

     while(current != nullptr)
     {
        std::cout << current->get_data() << std::endl;
        current = current->get_right();
     }

     return true;
}


std::string ctree::get_line(int line_count)
//Terrible and slow implementation but works
//contains a lot of commented out debug strings
{
    node * current;
    std::string line;
    int i = line_count;
    //std::cout << "get_line" << i << std::endl;
    //std::map<std::string, int> count;
    current = head.get();
    
    while(i > 0)
    {
    // std::cout << current << std::endl;
    // std::cout << "i = " << i << std::endl;
        if(current == nullptr)
        {
            line = "ENDOFTEXT";
            return line;
        }
        else           
        {
            line = current->get_data();
            current = current->get_right();
            i--;
        }
        //std::cout << "if" << std::endl;
     } 
     //std::cout << "post i " << i << std::endl;
     return line; 
}

/*
bool ctree::list_start(void)
//DEPRECIATED - don't think this is needed anymore
{
    ctree::node * current;
    current = head.get();
    std::cout << current << std::endl;
    return true;
}
*/
/*
ctree::node* ctree::get_right_node(void)
{
   node * current; 
    return current->get_right;
}
*/
