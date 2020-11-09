#include <iostream>

using std::cout; /* bring in the name std from the namespace (of standard) */
                 /* i.e. the namespace is now locally cout */

void printfun()
{
    cout << "This function works!" << std::endl;
}
int main() 
{
   /** std::cout << "Hello World! \n" ;
   /*  std::cout << "Hello World! \n" << std::endl ; */
    cout << "Hello World! \n" ;
    /* All rows above do the same thing,  */
    printfun();
}