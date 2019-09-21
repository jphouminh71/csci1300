// Author: Janathan Phouminh
// Recitation: 930am
// Akriti Kapur
// Homework 3 problem 2
// February 7th, 2018
#include <iostream>
#include <cmath>    // allows for power function 
using namespace std; 


/*
    Function accepts two parameters as double values and also returns a double value when called
        before calculations are made the function makes sure that wind speed is greater than 0 
            if true the parameters are used to calculate wind whill
        if wind speed < 0 the function will print, informing the user that there input is invalid
*/
float windChillCalculator(float air_temp,float wnd_speed)           // accepting both parameters
{
    float air_tempurature = air_temp;           // redefining variables
    float wind_speed = wnd_speed;
    float wind_chill;       // declaring new variable that is used in the cout statement
    if (wind_speed >= 0)        // as long as wind speed greater than 0 this conditional statement will evaluate. 
    {
        wind_chill = 0.0;
        float wind_chill = 35.74 + (0.6215*air_tempurature)-(35.75*(pow(wind_speed, 0.16)))+(0.4275*air_tempurature)*(pow(wind_speed, 0.16));
        return wind_chill;
    }
    
    else if (wind_speed < 0)        // conditional will only evaluate if wind speed < 0, notifying that the user has invalid input
    {
        cout << "Not Applicable" << endl;
    }
    
    return 0;
}


/*   imported math library  to use power function


    function accepts 4 parameters from main function
    variable definitions are created all in doubles
    created a comparison statement that checks variable inputs to see if they are valid or not before continuing to execute
    once they are passed
        a for loop is executed to obtain information with 4 different wind speeds
        while the for loop is being executed the windChill function is called and is passed 2 paramters
        the function calculates the windChill and returns that variable abck to print_wind_chill. 
*/


float printWindChill(float T, float Low_Wnd_Speed, float High_wnd_Speed, float Wnd_Speed_Step)      // accepting 4 parameters
{
    float air_temperature = T;
    float low_wind_speed = Low_Wnd_Speed;           // redefining variables that will be used. 
    float high_wind_speed = High_wnd_Speed;
    float wind_speed_step = Wnd_Speed_Step; 
    float wind_chill;
 
    if (low_wind_speed > high_wind_speed || wind_speed_step < 0)        // conditional only passes if negative values are inputted, informing the user. 
    {
        cout << "Invalid Input" << endl;
        return 0;
    }
    
    else                    // if values are not negative then the program will execute its calculations 
    {
        wind_chill =  0.0;                              // initialize wind chill to 0
        while (low_wind_speed <= high_wind_speed)           //  conditional that ensures the right amount of loops will occur
        {
            float wind_chill = windChillCalculator(air_temperature, low_wind_speed);    //setting vari wind chill = to value for the first loop
            //low_wind_speed = low_wind_speed + wind_speed_step;
            cout << "The wind chill is " << wind_chill << " degrees F for an air temperature of " << air_temperature <<     // console out 
            " degrees F and a wind speed of " << low_wind_speed << " mph." << endl;
            low_wind_speed = low_wind_speed + wind_speed_step;      //updating low wind speed so the next calculation in the sequence can be made
        }
        //cout << "The wind chill is " << wind_chill << " degrees F for an air temperature of " << air_temperature <<
        //" degrees F and a wind speed of " << low_wind_speed << " mph." << endl;
    }
}




int main()
{
    printWindChill(30.0, 10.0, 20.0, 1.0);      // Test Cases
    //printWindChill(30.0, 5.0, 8.0, 1);
    //printWindChill(0.0,0.0,0,3);
    //printWindChill(0,-1,-1,0)
}