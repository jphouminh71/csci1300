// Author: Janathan Phouminh
// Recitation: 930am
// Akriti Kapur
// Homework 2
// January 30, 2018




#include <iostream> 
using namespace std;
/*
    carnot function accepts the two integer values that were passed to it 
    redifines integer values into float values
    takes two float values and calculates them into another float value for the variable carnot_efficiency
    returns float but used cout just for testing purposes
*/
float carnot(int tempurature_1 , int tempurature_2)
{
    float temp_1 = tempurature_1;
    float temp_2 = tempurature_2;
    float carnot_efficiency;
    
    carnot_efficiency = 1 - (temp_1 / temp_2);
    
    cout << carnot_efficiency;
    return 0;
}
/*
    main function includes calling the carnot function multiple times for different test cases, passes two integer values
    
*/
int main()
{
    cout << carnot(160, 1100) << endl;
    cout << carnot(260, 673) << endl;
    cout << carnot(294, 1089) << endl;
}