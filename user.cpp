#include "user.h"
//#include <boost/tokenizer.hpp>
//#include "strlist.h"
//#include <string> //may take this out later test with compile
//#include<iostream> //may also take this out with compile test
#include<fstream> //for ifstream to read files
using ll=linked_list;

    


ll user::open_clist_dict(std::string dict)
{   
    ll dict_clist;
    std::string word;
    std::cout << "test open_clist_dict" << std::endl;
    std::ifstream dict_file;
    dict_file.open (dict);
    if(dict_file.is_open())
    {
        while(getline(dict_file, word))
        {
            dict_clist.add(word);
        }
        dict_file.close();
        //funtion to test dict ingestion
        //dict_clist.print_list();
    }
    else
    {    
        std::cout << "Unable to open" << dict << std::endl;
    }
    return dict_clist;
}

std::vector<std::string> user::open_vector_dict(std::string dict)
{   
    std::vector<std::string> dict_vector;
    std::string word;
    std::cout << "test open_vector_dict" << std::endl;
    std::ifstream dict_file;
    dict_file.open (dict);
    if(dict_file.is_open())
    {
        while(getline(dict_file, word))
        {
            dict_vector.push_back(word);
        }
        dict_file.close();
        //funtion to test dict ingestion
        //dict_clist.print_list();
    }
    else
    {    
        std::cout << "Unable to open" << dict << std::endl;
    }
    return dict_vector;
}


std::list<std::string> user::open_list_dict(std::string dict)
{   
    std::list<std::string> dict_list;
    std::string word;
    std::cout << "test open_list_dict" << std::endl;
    std::ifstream dict_file;
    dict_file.open (dict);
    if(dict_file.is_open())
    {
        while(getline(dict_file, word))
        {
            dict_list.push_back(word);
        }
        dict_file.close();
        //funtion to test dict ingestion
        //dict_clist.print_list();
    }
    else
    {    
        std::cout << "Unable to open" << dict << std::endl;
    }
    return dict_list;
}

std::set<std::string> user::open_set_dict(std::string dict)
{   
    std::set<std::string> dict_set;
    std::string word;
    std::cout << "test open_set_dict" << std::endl;
    std::ifstream dict_file;
    dict_file.open (dict);
    if(dict_file.is_open())
    {
        while(getline(dict_file, word))
        {
            dict_set.insert(word);
        }
        dict_file.close();
        //funtion to test dict ingestion
        //dict_cset.print_set();
    }
    else
    {    
        std::cout << "Unable to open" << dict << std::endl;
    }
    return dict_set;
}

ctree user::open_ctree_dict(std::string dict)
{   
    ctree dict_ctree;
    std::string word;
    std::cout << "test open_ctree_dict" << std::endl;
    std::ifstream dict_file;
    dict_file.open (dict);
    if(dict_file.is_open())
    {
        //int word_count = 0;
        while(getline(dict_file, word))
        {
           //word = sorted_array[word_count]
           //++word_count
            dict_ctree.add(word);
        }
        dict_file.close();
        //funtion to test dict ingestion

    }
    else
    {    
        std::cout << "Unable to open" << dict << std::endl;
    }
    std::cout << "dict done" << std::endl;
    return dict_ctree;
}

ll user::open_clist_text(std::string text)
{
    ll text_clist;
    std::string line;
    std::cout << "test open_clist_text" << std::endl;
    std::ifstream text_file;
    text_file.open(text);
    if(text_file.is_open())
    {
        while(getline(text_file, line))
        {
            text_clist.add(line);
        }
        text_file.close();
        //function to test text ingestion
      //  text_clist.print_list();
    }
    else
    {    
        std::cout << "Unable to open" << text << std::endl;
    }
   return text_clist;
}

std::vector<std::string> user::open_vector_text(std::string text)
{
    std::vector<std::string> text_vector;
    std::string line;
    std::cout << "test open_vector_text" << std::endl;
    std::ifstream text_file;
    text_file.open(text);
    if(text_file.is_open())
    {
        while(getline(text_file, line))
        {
            text_vector.push_back(line);
        }
        text_file.close();
        //function to test text ingestion
      //  text_clist.print_list();
    }
    else
    {    
        std::cout << "Unable to open" << text << std::endl;
    }
   return text_vector;
}

std::list<std::string> user::open_list_text(std::string text)
{
    std::list<std::string> text_list;
    std::string line;
    std::cout << "test open_list_text" << std::endl;
    std::ifstream text_file;
    text_file.open(text);
    if(text_file.is_open())
    {
        while(getline(text_file, line))
        {
            text_list.push_back(line);
        }
        text_file.close();
        //function to test text ingestion
      //  text_clist.print_list();
    }
    else
    {    
        std::cout << "Unable to open" << text << std::endl;
    }
   return text_list;
}

std::set<std::string> user::open_set_text(std::string text)
{
    std::set<std::string> text_set;
    std::string line;
    std::cout << "test open_set_text" << std::endl;
    std::ifstream text_file;
    text_file.open(text);
    if(text_file.is_open())
    {
        while(getline(text_file, line))
        {
            text_set.insert(line);
        }
        text_file.close();
        //function to test text ingestion
      //  text_cset.print_set();
    }
    else
    {    
        std::cout << "Unable to open" << text << std::endl;
    }
   return text_set;
}

ctree user::open_ctree_text(std::string text)
{
    ctree text_ctree;
    std::string line;
    std::cout << "test open_ctree_text" << std::endl;
    std::ifstream text_file;
    text_file.open(text);
    if(text_file.is_open())
    {
        while(getline(text_file, line))
        {
            text_ctree.add(line);
        }
        text_file.close();
        //function to test text ingestion
       // text_ctree.print();

    }
    else
    {    
        std::cout << "Unable to open" << text << std::endl;
    }
    std::cout << "text opened" << std::endl;
    return text_ctree;
}

bool user::process_text(ll dict_clist, ll text_clist)
{
    int line_count = 1;
    //std::cout << "process text!!!" << std::endl;
    std::map <std::string, int> word_count;
    //text_clist.print_list();
    //text_clist.list_start();
    while(text_clist.get_line(line_count) != "ENDOFTEXT")
    {
        boost::tokenizer<> tok(text_clist.get_line(line_count));
        for(boost::tokenizer<>::iterator beg=tok.begin();
        beg!=tok.end();++beg)
        {
            if(dict_clist.search(*beg))
            {
                // std::cout << *beg << std::endl;
                if(word_count[*beg])
                {
                    word_count[*beg]++;
                }
                else
                {
                    word_count[*beg] = 1;
                }    
            }
        }
        line_count++;
    }    
    this->count = word_count;
    return true;
}

bool user::process_text(std::vector<std::string> dict_vector,
std::vector<std::string> text_vector)
{
    unsigned int line_count = 1;
    std::cout << "process text!!!" << std::endl;
    std::map <std::string, int> word_count;
    //text_clist.print_list();
    //text_clist.list_start();
    //while(text_vector[line_count] < text_vector[text_vector.size()])
    while(line_count < text_vector.size())
    {
        //std::cout << "at line count: " << line_count << std::endl;
        boost::tokenizer<> tok(text_vector[line_count]);
        for(boost::tokenizer<>::iterator beg=tok.begin();
        beg!=tok.end();++beg)
        {
            for(std::vector<std::string>::iterator it = 
                dict_vector.begin(); it != dict_vector.end(); ++it)
            {    
                if(*it ==  *beg)
                {
                    // std::cout << *beg << std::endl;
                    if(word_count[*beg])
                    {
                        word_count[*beg]++;
                    }
                    else
                    {
                        word_count[*beg] = 1;
                    }    
                }
             } 
        }
        line_count++;
    }    
    this->count = word_count;
    return true;
}

//This function processes 2 std::lists
//take each line from text_list in order, tokenizes it
//and compares it with the entire dict_list, scores word 
//counts and stores them in a std::map
bool user::process_text(std::list<std::string> dict_list,
std::list<std::string> text_list)
{
    unsigned int line_count = 1;
    std::cout << "process text!!!" << std::endl;
    std::map <std::string, int> word_count;
    //text_clist.print_list();
    //text_clist.list_start();
    //while(text_list[line_count] < text_list[text_list.size()])
    while(line_count < text_list.size())
    {
        //The two loops following are a convoluted and expensive way
        //to extract the poistion of the line in the list
        unsigned int line_num = 1;
        for(std::list<std::string>::iterator ln =
        text_list.begin(); ln != text_list.end(); ++ln, ++line_num)
        {
            if(line_num == line_count)
            {
                std::string line = *ln;
                boost::tokenizer<> tok(line);
                for(boost::tokenizer<>::iterator beg=tok.begin();
                beg!=tok.end();++beg)
                {       
                    for(std::list<std::string>::iterator it = 
                    dict_list.begin(); it != dict_list.end(); ++it)
                    {    
                        if(*it ==  *beg)
                        {
                            if(word_count[*beg])
                            {
                                word_count[*beg]++;
                            }
                            else
                            {
                                word_count[*beg] = 1;
                            }    
                        }
                    }   
                }
             }
        }     
        line_count++;
    }    
    this->count = word_count;
    return true;
}

//This function processes 2 std::sets
//take each line from text_set in order, tokenizes it
//and compares it with the entire dict_set, scores word 
//counts and stores them in a std::map
bool user::process_text(std::set<std::string> dict_set,
std::set<std::string> text_set)
{
    unsigned int line_count = 1;
    std::cout << "process text!!!" << std::endl;
    std::map <std::string, int> word_count;
    //text_cset.print_set();
    //text_cset.set_start();
    //while(text_set[line_count] < text_set[text_set.size()])
    while(line_count < text_set.size())
    {
        unsigned int line_num = 1;
        for(std::set<std::string>::iterator ln =
        text_set.begin(); ln != text_set.end(); ++ln, ++line_num)
        {
           if(line_num == line_count)
           {
                std::string line = *ln;
                boost::tokenizer<> tok(line);
                for(boost::tokenizer<>::iterator beg=tok.begin();
                beg!=tok.end();++beg)
                {     
                    for(std::set<std::string>::iterator it = 
                    dict_set.begin(); it != dict_set.end(); ++it)
                    {    
                        if(*it ==  *beg)
                        {
            //                std::cout << *beg << std::endl;
                            if(word_count[*beg])
                            {
                                word_count[*beg]++;
                            }
                            else
                            {
                                word_count[*beg] = 1;
                            }    
                        }
                    }   
                }
            }
        }     
        line_count++;
    }   
    this->count = word_count;
    return true;
}

bool user::process_text(ctree dict_ctree, ctree text_ctree)
{
    std::string line = "line";
    std::map <std::string, int> word_count;
    text_ctree.stack_line();
    while(line != "ENDOFTEXT")
    {    
        line = text_ctree.get_line();
        boost::tokenizer<> tok(line);
        for(boost::tokenizer<>::iterator beg=tok.begin();
        beg!=tok.end();++beg)
        {
            //std::cout << "still working1?" << *beg << std::endl;
            if(dict_ctree.find(*beg))
            {
                std::cout << *beg << std::endl;
                if(word_count[*beg])
                {
                    word_count[*beg]++;
                }
                else
                {
                    word_count[*beg] = 1;
                }    
               // std::cout << line << std::endl;
            }
        }
    }    
    //std::cout << "still working?" << std::endl;
    this->count = word_count;
    return true;
}


bool user::output_to_file(std::string output_file)
{
    //export contents of count map to file
    std::ofstream output;
    output.open (output_file);
    if(output.is_open())
    {
        for(std::map<std::string, int>::iterator it=this->count.begin(); 
        it!=this->count.end(); ++it)
        {
            output << it->first << " : " << it->second << std::endl;

        }
   
       
       output.close();
        
    }
    else
    {    
        std::cout << "Unable to open" << output_file << std::endl;
    }
    return true;

}
/*
std::map get_count(void)
{
    return count;
}
*/
