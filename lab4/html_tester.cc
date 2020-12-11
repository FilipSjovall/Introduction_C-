#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <memory>
#include <cctype>
#include "TagRemover.h"


int main(int charc, char* argv[]){
    std::ifstream myfile; 
    std::ifstream in{argv[1]}; // filen foo.html läses in vid anrop via : ./html_tester < "foo.html" 
    //myfile.open("test.html");
    TagRemover tr(std::cin);
    tr.print(std::cout);
    std::cout << " Ska antal rader i en <tag> bevaras? " << std::endl;
}