// Author: Janathan Phouminh
// Recitation: 930am
// Akriti Kapur
// Homework 2
// January 30, 2018


#include <iostream> 
using namespace std; 


/*
int US_Population accepts one parameter and returns new int value for the current population
    defining all of the variables that will be used
    taking the value of year and calculating the total amount of seconds in a year
    once seconds has been found find the amount of birth rates by dividing the total seconds by birth rate (8seconds)
    once that number has been found I updated the value of int population.
    Repeat the same process of dividing the total amount of seconds by the given rate
    Repeat the step for updating the current value of population
    Once finished with updating the variable population returned the final value of population
    cout statement at the bottom was just to verify my information. 
*/


int US_Population(int Current_Population)
{
    int population = Current_Population;
    int year = 365;
    int seconds;
    int birth_rate;
    int death_rate;
    int immigration_rate; 
    
    seconds = (year *24) *60 *60;
    
    birth_rate = seconds / 8.0; 
    population = population + birth_rate;
    death_rate = seconds / 12; 
    population = population - death_rate;
    immigration_rate = seconds / 33; 
    population = population + immigration_rate;
    cout << population << endl;
    return 0;
}
/* 
main function 
    defines the the given current population as integer value
    calls US_Population function and passes the parameter of Current_Population
    Second test case below calls US_Populaton again, just passes a different test case for the US_Population function 
*/
int main()
{
    int Current_Population = 325766246;
    US_Population(Current_Population);
    US_Population(2);
    
}