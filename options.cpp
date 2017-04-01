//options.cpp
//
//Takes in command line arguments and parses them, also contains main
//Author:  Miles Thomas s3494949

//#include <boost/program_options.hpp>
#include <string>
#include <iostream>
#include "options.h"

namespace po = boost::program_options;

int main(int ac, char** av)
{
    
    options choice;
    choice.choose_option(ac, av);


    return 0;
}


bool options::choose_option(int ac, char** av)
{
    
    po::options_description desc("allowed options");
    desc.add_options()
    ("datastructure,s", po::value< std::string >(), "Select data structure to use")
    ("dictionary,d", po::value<std::string>(), "Select dictionary file")
    ("textfile,t", po::value<std::string>(), "Select text file")
    ("outputfile,o", po::value<std::string>(), "Choose output filename")
    ;
    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);


    if(vm.count("datastructure"))
    {
        if(vm["datastructure"].as< std::string>() == "custom_list")
        {
            user list_user;
            //ll user_list;
            std::cout << "confirming custom_list" << std::endl;
            list_user.open_dict(vm["dictionary"].as< std::string>());
            list_user.open_text(vm["textfile"].as< std::string>());
            //list_user.process_text();
            //COME BACK TO THIS!!!!
            return true;
        }
        if(vm["datastructure"].as< std::string>() == "custom_tree")
        {
            return true;
        }
        if(vm["datastructure"].as< std::string>() == "list")
        {
            return true;
        }
        if(vm["datastructure"].as< std::string>() == "vector")
        {
            return true;
        }
        if(vm["datastructure"].as< std::string>() == "set")
        {
            return true;
        }
    
    }
    else
    {
            return false;
    }   
    return true;   
}    
