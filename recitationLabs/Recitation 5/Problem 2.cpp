// Ionia Flemming
// Recitation 930am 
// https://ide.c9.io/joph0114/cs1300s18
// Recitation 5, Problem 1
// February 12, 2018
#include <iostream>
#include <string>
using namespace std;
/*
    function accepts one string parameter and will return int value
        redefine / define variables
        define int values as strings 
        set up digit count variable that will be returned
        set up indexing variable
        while loop that terminates at the end of given string
            while loop will check the character being indexed and compare it to all digits
                if they match, increase digit count by 1
                add 1 to the indexing variable to move on to next character
        return digit count
*/
int getDigitCount(string sequence)  // accepts string para and will return int
{
    string sentence = sequence; // redefefine
    char zero = '0';
    char one = '1';
    char two = '2';     // defining int variables as characters
    char three = '3';
    char four = '4';
    char five = '5';
    char six = '6';
    char seven = '7';
    char eight = '8';
    char nine = '9';
    int i;
    int digit_count;
    
    
    digit_count = 0;            // initialize digit count
    i = 0;              // initialize index counter
    while (i < sentence.length())       // terminating while loop
    {
    
        if (sentence[i] == zero)            // comparison of current index with character 0, and so on until 9
        {
            digit_count = digit_count + 1;
           
        }
        if (sentence[i] == one)
        {
            digit_count = digit_count + 1;
           
        }
        if (sentence[i] == two)
        {
            digit_count = digit_count + 1;
           
        }
        if (sentence[i] == three)
        {
            digit_count = digit_count + 1;
            
        }
        if (sentence[i] == four)
        {
            digit_count = digit_count + 1;
            
        }
        if (sentence[i] == five)
        {
            digit_count = digit_count + 1;
          
        }
        if (sentence[i] == six)
        {
            digit_count = digit_count + 1;
           
        }
        if (sentence[i] == seven)
        {
            digit_count = digit_count + 1;
         
        }
        if (sentence[i] == eight)
        {
            digit_count = digit_count + 1;
           
        }
        if (sentence[i] == nine)
        {
            digit_count = digit_count + 1;
            
        }
        
        i = i + 1;      // increases digit counter after each conditional is evaluates
    }
    return digit_count;     // returns digit count


    
}


int main()
{
    cout << getDigitCount("as00012836759937df00000000") << endl;            // test cases
    cout << getDigitCount("jkdlkjnfbsfejk344") << endl;
    cout << getDigitCount("skljdflkjf1234") << endl;
}






/*if (sentence[i] != zero || sentence[i] != one || sentence[i] != two || sentence[i] != three || sentence[i] != four || sentence[i] != five || sentence[i] != six || sentence[i] != seven || sentence[i] != eight || sentence[i] != nine )
        {
            i = i;
        }*/