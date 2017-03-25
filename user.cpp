#include "user.h"
#include <boost/tokenizer.hpp>
#include "intlist.h"
#include <string> //may take this out later test with compile
#include<iostream> //may also take this out with compile test

using ll=linked_list;

int main(int argc, char** argv)
{
    if(user::choose_option("list"))
    {
        user::open_dict(dict)
    }
}
    


bool user::choose_option(std::string option)
{
    if(true)
    {
        option = "list";
        return true;
    }
}
//dummies from here down
bool user::open_dict(user::dict dict_file)
{   
    //need to ingest and tokenise file
    //then need to insert each token into list dict
    return true;
}

bool user::open_text(text)
{
    return true;
}

bool user::output_to_file(count)
{
    //export contents of count map to file
    return true;
}

