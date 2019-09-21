// Author: Janathan Phouminh
// Recitation: 930am
// Akriti Kapur
// Homework 2
// January 30, 2018


#include <iostream>
using namespace std; 
/*
    Initialized function howLong that accepts one parameter
        initialized new variables that the function will be used
        to find total days --> Divide total seconds by 86400 
        and to get the remainder of seconds divide the total seconds by 86400
        
        repeat the process for hours which would be dividing by 3600
        repeat the process for minutes which would be dividing the remainder seconds by 60
        
        print the output
        return 0
*/
int howLong(int seconds)
{
    int given_seconds = seconds;
    int Total_Seconds = seconds;
    int Total_Days;
    int Total_Hours;
    int Total_Minutes;
    int Days_Seconds_Count;
    int Minute_Count; 
    int Hour_Count;
    
    Total_Days = Total_Seconds / 86400 ; // Updates Total_Days variable
    Total_Seconds = Total_Seconds % 86400;// Updates remaining seconds 
    
    Total_Hours = Total_Seconds / 3600 ; 
    Total_Seconds = Total_Seconds % 3600;
    
    Total_Minutes = Total_Seconds / 60 ;
    Total_Seconds = Total_Seconds % 60;
 
    
    cout << given_seconds << " seconds is "<< Total_Days << " days, " << Total_Hours << " hours, " << Total_Minutes << " minutes, " << " and " <<
    Total_Seconds << " seconds." << endl;
    
    return 0;
}


/*
    Main function intialzes a int variable for secondsd
    calls the howLong function 3 times
    passess one parameter. 
*/
int main()
{
    int seconds = 86400;
    howLong(seconds);
    howLong(1000000);
    howLong(20000000000);
}