#include "TagRemover.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <fstream>
#include <string>
#include <iostream> 
#include <memory>

TagRemover::TagRemover(std::istream& infile)  {
    // std::string text;

    std::stringstream strStream;
    strStream << infile.rdbuf();//read the file
    // text = strStream.str();
    text.append(strStream.str());
    remove_bit();  
    replace();          
    // clean_string.push_back(line);
}

void TagRemover::print(std::ostream& os) const
{
    os << text << std::endl; 
}

bool Contains_pair(std::string& s){   
     if (s.find_first_of('<')!=std::string::npos && s.find_first_of('>')!=std::string::npos)
     {
         return true;
     }
     else{
         return false;
     }
    //return true;
 }

bool TagRemover::Contains_special(){
    for(unsigned int i=0; i<specials.size(); i++){
        if(text.find(specials[i]) != std::string::npos){
            return true;
        }
    }
    return false;
}

void TagRemover::remove_bit(){
    while(Contains_pair(text) ){    
        if(text.find_first_of('<')!=std::string::npos && text.find_first_of('>')!=std::string::npos ){
                text.erase(text.find_first_of('<'),text.find_first_of('>')-text.find_first_of('<')+1);
        }
    }            
}

void TagRemover::replace(){
    while(Contains_special()){
        for(int i=0;i<specials.size();i++){
            if(text.find(specials[i]) != std::string::npos){
                text.replace(text.find(specials[i]),specials[i].length(),replacers[i]);
            }
        }
    } 
}





