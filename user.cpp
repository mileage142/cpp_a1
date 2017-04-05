#include "user.h"
//#include <boost/tokenizer.hpp>
//#include "strlist.h"
//#include <string> //may take this out later test with compile
//#include<iostream> //may also take this out with compile test
#include<fstream> //for ifstream to read files
using ll=linked_list;

    


ll user::open_dict(std::string dict)
{   
    ll dict_list;
    std::string word;
    std::cout << "test open_dict" << std::endl;
    std::ifstream dict_file;
    dict_file.open (dict);
    if(dict_file.is_open())
    {
        while(getline(dict_file, word))
        {
            dict_list.add(word);
        }
        dict_file.close();
        //funtion to test dict ingestion
        //dict_list.print_list();
    }
    else
    {    
        std::cout << "Unable to open" << dict << std::endl;
    }
    return dict_list;
}


ll user::open_text(std::string text)
{
    ll text_list;
    std::string line;
    std::cout << "test open_text" << std::endl;
    std::ifstream text_file;
    text_file.open (text);
    if(text_file.is_open())
    {
        while(getline(text_file, line))
        {
            text_list.add(line);
        }
        text_file.close();
        //function to test text ingestion
      //  text_list.print_list();
    }
    else
    {    
       // std::cout << "Unable to open" << dict << std::endl;
    }
   return text_list;
}

bool user::process_text(ll dict_list, ll text_list)
{
    int line_count = 1;
    //std::cout << "process text!!!" << std::endl;
    std::map <std::string, int> word_count;
    //text_list.print_list();
    //text_list.list_start();
    while(text_list.get_line(line_count) != "ENDOFTEXT")
    {
        boost::tokenizer<> tok(text_list.get_line(line_count));
        for(boost::tokenizer<>::iterator beg=tok.begin();
        beg!=tok.end();++beg)
        {
            if(dict_list.search(*beg))
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
