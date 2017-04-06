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
    int line_count = 1;
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
