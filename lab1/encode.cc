#include<iostream>
#include <iomanip>
#include<fstream>
using std::cout;
using std::endl;



int main(int argc, char* argv[])
{
    std::ofstream out("myfile.enc");
    std::ifstream in{argv[1]};
    char ch;
    while( in.get(ch)  ) {
        out << static_cast<char>(ch + 1); // utanför intervall - char? borde använt unsigned char
    }
    // out.close(); 
    return 0;
}




