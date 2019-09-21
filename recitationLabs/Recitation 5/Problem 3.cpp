// Ionia Flemming
// Recitation 930am 
// https://ide.c9.io/joph0114/cs1300s18
// Recitation 5, Problem 1
// February 12, 2018                                // cant figure out how to traverse or keep a counter going to compare the next substring set
#include <iostream>
#include <string>
using namespace std;
/* 
    set up function that accepts two string parameters and returns int value
        redefine parameters
        set up conditional that check to see if either string is empty
            if true. return -1
        set up conditional that checks to see if the substring is longer than the string
            if true, return -2
        
        else
            define new int variable that finds the length of given substring
            intialize a match counter
            initialize indexer variable
            set up while loop that terminates at end of string
                if substring is matching substring point of the string
                    update match count by one
                    i = i + 1  , this part changes the starting position of gathering the substring of the long string
                else
                    i = i + 1, if no matches are found the indexer will move on
                    
            after while loop has terminated, return match count. 
*/


int getMatchCount(string g_substring, string g_string)
{
    string given_substring = g_substring;
    string given_string = g_string;
    
    if (given_substring == "" || given_string == "")
    {
        return -1;
    }
    if (given_substring.length() > given_string.length())
    {
        return -2;
    }
    else
    {
        int given_substring_length = given_substring.length();  // gets length of given substring 
        int newStringStartingPosition = given_substring_length;
        //string substring_given_substring;       // variable of substring of given string
        // string substring_given_string = given_string.substr(0,given_substring_length);   // matches amount of characters of string to amount of char in given substring
    
        int match_count = 0;             // define variables
        int i = 0;   
        while (i < given_string.length())   // terminating while loop
        {
            
            if (given_substring == given_string.substr(i,given_substring_length))   // i is passed here because it changes the starting position of gathering the substring
            {
                match_count = match_count + 1;  // update matches
                i = i + 1;
                //substring_given_string == given_string.length(newStringStartingPosition, given_substring_length);
            }
            else 
            {
                i = i + 1;      // move indexer foward
            }
        
        
        
        }
        return match_count; // return 
       
    }
    
}
int main()
{
    cout << getMatchCount("si","si") << endl;               // test cases
    cout << getMatchCount("si","mississippi") << endl;
    cout << getMatchCount("o","lollipop") << endl;
    cout << getMatchCount("moo","moodle") << endl;
}