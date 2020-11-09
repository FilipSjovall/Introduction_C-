#include<iostream>
#include <iomanip>
#include<fstream>
using std::cout;
using std::endl;


int main(int charc, char* argv[])
{
    std::ofstream out("filename.dec");
    std::ifstream in{argv[1]};
    char ch;
    while( in.get(ch)  ) {
        out << static_cast<char>(ch - 1);
    }
    out.close();
    return 0;
}




