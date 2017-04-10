/*************************************************************
*ctree.cpp   COSC2140 Assingment 1     Miles Thomas  s3494949
*
*Implementation of a Binary Search Tree using unique pointers
*
* This file takes reference from intlist.cpp which was an example
* by Paul Miller for the COSC2140 course at RMIT
************************************************************************/

#include "ctree.h"

std::stack<std::string> ctree::lines;
bool ctree::node::found;

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

bool& ctree::node::get_found(void)
{
    return found;
}
/*

bool ctree::node::add(std::string data)
{
    //node * current;
    node * prev = nullptr;
    std::unique_ptr<ctree::node> newnode = std::make_unique<ctree::node>(data);
    if(head == nullptr)
    {
        head = std::make_unique<node>(data);
        this->add_data(data);
        return true;
    }
}
*/

bool ctree::node::add(std::string newdata)
{

    //this is an alpha sort function
    if(newdata < data)
    {

        if(left)
        {
            return left->add(newdata);
        }
        else
        {
            left = std::make_unique<ctree::node>(newdata);
            //std::cout << left->get_data() << std::endl;
            if(left)
            {
                return true;
            }
            return false;
        }
    }

    else
    {
        if(right)
        {
            return right->add(newdata);
        }
        else
        {
            right = std::make_unique<ctree::node>(newdata);
           // std::cout << right->get_data() << std::endl;
            if(right)
            {
                return true;
            }
            return false;
        }
    }
}

bool ctree::node::find(std::string needle)
{
	//HACK: Change Made Here
    //std::cout << data << std::endl;

	if (data == needle)
	{
		//this print function shows that things are working
		//if only it got to the other function
		//std::cout << "found! " << data << std::endl;

		return true;
	}
	else
	{
		if (needle < data)
		{
			//Go Left
			if (left != nullptr)
			{
				return left->find(needle);
			}
		}
		else
		{
			//Go Right
			if (right != nullptr)
			{
				return right->find(needle);
			}
		}
	}

    return false;
}

bool ctree::find(std::string needle)
{
	//HACK: Change Made Here
    return root->find(needle);

    //this accessor function always reads false
    //std::cout << "found: " << node::get_found() << std::endl;

    //if(root->find(needle) == "NOTAWORD")
    //as found always reads false, we never get here
    if(node::get_found())
    {
        //std::cout << node::get_found() << std::endl;
        return true;
    }/*
    if(found)
    {
        return true;
    }*/
    else
    {
        return false;
    }
}

void  ctree::node::stack_line(void)
{
    //std::stack<std::string> lines;
    if(left)
    {
        left->stack_line();
    }
    lines.push(data);
    if(right)
    {
        right->stack_line();
    }
}

void ctree::stack_line(void)
{
    root->stack_line();
}

std::string ctree::get_line(void)
{
    //std::string line;
    while(lines.empty() == false)
    {
        std::string line = lines.top();
        lines.pop();
        //std::cout << "lines?" << line << "???" << std::endl;
        return line;
    }
    return "ENDOFTEXT";
}

bool ctree::add(std::string data)
{
    if(root)
    {
        return root->add(data);
    }
    root = std::make_unique<ctree::node>(data);
    //std::cout << root->get_data() << std::endl;
    if(root)
    {
        return true;
    }
    return false;
}




//TO DO!!!
/*
bool ctree::search(std::string needle)
{
    node * current;
    current = root.get();
    //int word_count = 0;

    while(current != nullptr)
    {
        if(current->find(needle) == needle)
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
*/
/*bool ctree::find(std::string needle, bool )
{
    root->find(needle);
    std::cout << node::get_found() << std::endl;
    //if(root->find(needle) == "NOTAWORD")
    if(node::get_found())
    {
        std::cout << node::get_found() << std::endl;
        return true;
    }
    else
    {
        std::cout << "root"  << std::endl;
        return false;
    }
}

     *
    if(found)
    {
        std::cout << "found2" << std::endl;
        //return true;
    }
    else
    {
        std::cout << "else" << std::endl;
        return "NOTAWORD";
    } */


     //node * current;
     //current = root.get();


     /*
     while(current != nullptr)
     {
        std::cout << current->get_data() << std::endl;
        current = current->get_right();
     }

     return true;
     */


/*
std::string ctree::get_line(int line_count)
//Terrible and slow implementation but works
//contains a lot of commented out debug strings
{
    node * current;
    std::string line;
    int i = line_count;

    line = "ENDOFTEXT";
    //std::cout << "get_line" << i << std::endl;
    //std::map<std::string, int> count;
    current = root.get();

    while(i > 0)
    {
    // std::cout << current << std::endl;
    // std::cout << "i = " << i << std::endl;
        if(current == nullptr)
        {
            line = "ENDOFTEXT";
            return current->find();
        }
        else
        {
            line = current->get_data();
            current = find();
            i--;
        }

        //std::cout << "if" << std::endl;
     }
     //std::cout << "post i " << i << std::endl;
     return line;
}
*/
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
