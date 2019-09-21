// Ionia Flemming
// Recitation 930am 
// https://ide.c9.io/joph0114/cs1300s18
// Recitation 5, Problem 1                      // cant figure out how to specify what the function is going to do if the character is not in the sequence.
// February 12, 2018
#include <iostream>
#include <string>
#include <cstddef>
using namespace std;
/*
    set up function that recieves a character parameter and a string parameter and will return an integer value
        define / redefine variables
        set up first conditional that checksto see if the given string is empty
            if it is empty
                return 1
            else
                set up indexer variable
                set up variable that will be returned in the end, set = 2 because if no characters are found then it will return -2
                while loop that terminates at end of sequence length
                    conditional that checks if current index is matching character you are looking for
                        if found, store that value into the variable that will be returned in the end, the highest number should be returned
                    update indexer count to progress through the sequence
                return stored variable
*/
int getLastIndex(char c_parameter, string s_parameter)      // accepts char and string, returns int
{
    char character = c_parameter;
    string sequence = s_parameter;          // define / redfine
    
    if (sequence == "")     // checks string for empty string
    {
        return -1;
    }
   else
   {
       int i = 0;                   // initialize index count
       int stored_variable = -2;    // intialize variable that will be passed
       while (i < sequence.length())        // terminating while loop
       {
           if (sequence[i] == character)        // conditional that compares the current character to the constant character
           {
               stored_variable = i; // updates final variable to the highest conut of the wanted character
           }
           i = i + 1;   // keeps the sequence moving
          
       }
       return stored_variable;  // return
   }


}
int main()
{
    cout << getLastIndex('i',"misssissippi") << endl;
    cout << getLastIndex("h", "hello:") << endl;
    cout << getLastIndex("j","jajajjajjaajaj") << endl;
    cout << getLastIndex("h","hellohellohellohelloh:");endl
}