#include <iostream> 
using namespace std;


double calcPay( double x, double y)     // Function initialized and accepts two floating point parameters
{
    double pay;                     // Defining a new floating parameter in this function only
    double hours_worked = x;    // Redefining the passed varibles into this functiosn scope
    double hourly_pay_rate = y;
    
    pay = hours_worked * hourly_pay_rate;           // calculation
    
    return pay;         // returning the value of pay
    
}




/*main()                        First test
{
    calcPay(2.5, 2.5);
}  */ 


int main()
{
    cout << calcPay (8.8, 9.9) << endl;  // passing 2 floating point variables
    cout << calcPay(2.5, 2.5) << endl;
}