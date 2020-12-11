#ifndef TagRemover_H
#define TagRemover_H
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <fstream>

class TagRemover{

// std::istream _infile;

public:
    // TagRemover(); //
    TagRemover(std::istream& infile) ; // : _infile(std::move(infile)){} 
    bool Contains_special();
    void print(std::ostream&) const;
    void replace();
    void remove_bit();
    std::string text{};
private:
    std::vector<std::string> specials {"&lt;","&gt;","&nbsp;","&amp;"};
    std::vector<std::string> replacers{" < "," > ","   "," & "};
};

#endif