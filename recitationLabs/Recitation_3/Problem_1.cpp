#include <iostream> 
using namespace std;


double getHours()                   //defining function, function takes no parameters
{
    double hours;           // defining variable for user input
    
    cout << "Please enter how many hours you worked this week:";
    cin >> hours;                           // user input put into hours variable
    cout << hours << endl;              // print statement, function does not return any value
}








int main()
{
    getHours();             // calling the function , no parameters need to be passed. 
}