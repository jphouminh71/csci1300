// CS1300 Spring 2018
// Jonathan Phouminh
// Ionia Flemming
// Recitation 930am 
// https://ide.c9.io/joph0114/cs1300s18
// Recitation 5, Problem 1
// February 12, 2018
#include <iostream>
#include <string>
using namespace std;
/*
    function recives string parameter and will end up returning a integer value
        define / redefine variables
        set up first conditional that will evaluate if passed parameter is a empty string
            if true, return 0
        else
            intialize while loop that runs until hits last character in given string
            intialize word count to return later , set = to one because you know there will be at least one word
            intialize indexing variable
            while
                evaluate each index of the sequence 
                first conditional that checks if any space mark characters are matching the current index
                    if true, add 1 to word counter
                second conditional if current index is not a space
                    update indexing character
                    
            after while loop terminates return the value of word count
*/
int getWordCount(string sequence)   // accepts string returns int
{
    string sentence = sequence;         // define / redefine 
    int i;
    int word_count;
    if (sentence == "") // checks for empty string
    {
        return 0;
    }
    else
    {
        i = 0;                  // initialize variables , indexer
        word_count = 1; // word count
        
        while (i < sentence.length())           // defined conditional for while loop
        {
            if (sentence[i] != ' ')         // checks to see if character is not a space
            {
                i = i + 1;
            }
            else if (sentence[i] == ' ' or sentence[i] == '\0')     // if it is a space it will add 1 to the word count
            {
                word_count = word_count + 1;        // update word count
                i = i + 1;      // update indexer
            }
        }
        return word_count;      // returns value of word count
        
    }
    
}




int main()
{   
    cout << getWordCount("Hello World!") << endl;                   // test cases
    cout << getWordCount("hi hi hi hi hi hi hi") << endl;
    cout << getWordCount("hello hello hello hello hello") << endl;
}