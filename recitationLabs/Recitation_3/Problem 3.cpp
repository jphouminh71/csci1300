#include <iostream> 
using namespace std; 


double printPay( double x) // Function initialized to take one floating point parameter
{
    double pay = x ;        // Defining the passed parameter in the scope of this function
    
    cout << "Your pay is $" << pay << ".";      // Print
    
    return 0;   // Function does not return any real value
}




/*int main()              // First test case
{
    printPay(2.225);
}*/


int main()                  // Second test case
{
    cout << printPay(4.555) << endl;  // passing floating point variable
    cout << printPay(2.225) << endl;
}