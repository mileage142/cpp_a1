/**************************************************************************
*options.cpp COSC2140  Assingment 1   Miles Thomas s3494949
*
*Takes in command line arguments and parses them, also contains main
*
**************************************************************************/

//#include <string>
//#include <iostream>
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
    //setup options for command line
    po::options_description desc("allowed options");
    desc.add_options()
    ("datastructure,s", po::value< std::string >(),
    "Select data structure to use")
    ("dictionary,d", po::value<std::string>(), "Select dictionary file")
    ("textfile,t", po::value<std::string>(), "Select text file")
    ("outputfile,o", po::value<std::string>(), "Choose output filename")
    ;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);


    if(vm.count("datastructure"))
    {
        if(vm["datastructure"].as< std::string>() == "custom_list")
        {
            user list_user;
            //various implementations for all the data structures
            std::cout << "confirming custom_list" << std::endl;
            list_user.process_text(
            list_user.open_clist_dict(vm["dictionary"].
            as< std::string>()),
            list_user.open_clist_text(vm["textfile"].
            as< std::string>()));
            list_user.output_to_file(vm["outputfile"].
            as< std::string>());
            return true;
        }
        if(vm["datastructure"].as< std::string>() == "vector")
        {
            user vector_user;

            std::cout << "confirming vector" << std::endl;
            vector_user.process_text(
            vector_user.open_vector_dict(vm["dictionary"].
            as< std::string>()),
            vector_user.open_vector_text(vm["textfile"].
            as< std::string>()));
            vector_user.output_to_file(vm["outputfile"].
            as< std::string>());
            return true;
        }
        if(vm["datastructure"].as< std::string>() == "list")
        {
            user list_user;

            std::cout << "confirming list" << std::endl;
            list_user.process_text(
            list_user.open_list_dict(vm["dictionary"].
            as< std::string>()),
            list_user.open_list_text(vm["textfile"].
            as< std::string>()));
            list_user.output_to_file(vm["outputfile"].
            as< std::string>());
            return true;
        }
        if(vm["datastructure"].as< std::string>() == "set")
        {
            user set_user;

            std::cout << "confirming set" << std::endl;
            set_user.process_text(
            set_user.open_set_dict(vm["dictionary"].
            as< std::string>()),
            set_user.open_set_text(vm["textfile"].
            as< std::string>()));
            set_user.output_to_file(vm["outputfile"].
            as< std::string>());
            return true;
        }
        if(vm["datastructure"].as< std::string>() == "custom_tree")
        {
            user ctree_user;

            std::cout << "confirming ctree" << std::endl;

			ctree_user.process_text(
            ctree_user.open_ctree_dict(vm["dictionary"].
            as< std::string>()),
            ctree_user.open_ctree_text(vm["textfile"].
            as< std::string>()));

            ctree_user.output_to_file(vm["outputfile"].
            as< std::string>());

            return true;
        }
    }
    else
    {
            return false;
    }
    return true;
}
