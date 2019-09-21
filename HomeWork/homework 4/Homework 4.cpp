// CS1300 Spring 2018
// Jonathan Phouminh
// Ionia Flemming
// Recitation 930am 
// https://ide.c9.io/joph0114/cs1300s18
// Homework 4, Problem 1
// February 11, 2018


#include <iostream> 
#include <string>
using namespace std;


/*  function will accept to string parameters and return a float value
        1. Define / re-define variables that are going to be used
        2. Initialize value for indexing counter
        3. Set conditional that chekcs to make sure string values are valid
        
        4. If values are valid execute function finding hamming distance
            intialize hamming distance / initialize indexing variable to 0
            set up while loop that will exececute up until the the indexing variable is not out of range of string variables 
                loop will compare the current index of each string 
                    if both are the same characters 
                        increase index count by one, and repeat process
                    else if characters in the same index are different, 
                        Add one to the hamming distance and then add another to the indexing count
                    
        5. repeat loop process until all characters are evaluated
            once total hamming distance is found, calculate the similarity score
        6. float similarity score is returned from the function. 
*/
float findSimilarityScore(string sequence1, string sequence2)       // accepting 2 string parameters
{
    string sequence_1 = sequence1;          // redefining variables / declaring new variables
    string sequence_2 = sequence2;
    float similarity_score;
    float hamming_distance;
    int i;
    
    if (sequence_1.length() < sequence_2.length() || sequence_2.length() < sequence_1.length() || sequence_1 == "" || sequence_2 == "")  // if given strings fall in these comparion paramaters then the function will return -1
    {
        return -1;
    }
    else            // otherwise the function will execute the normal function of finding hamming distance
    {
        hamming_distance = 0;           // initializing hamming distance
        i = 0;
        while (i < sequence_1.length() && i < sequence_2.length())      // i, is the index number for both strings, while loop will execute as long as indexing number doesnt surpass the boundaries of both strings
        {
            if(sequence_1[i] == sequence_2[i])  // if both characters match the indexing number will increase by one to move onto the next character
            {
                i = i + 1;
            }
            if(sequence_1[i] != sequence_2[i])  // if the characters are not equivalent then the conditional will add 1 to the hamming distance, then procedes by updating index number
            {
                hamming_distance = hamming_distance + 1 ;
                i = i + 1;
            }
        }
    }
    
    similarity_score = (sequence_1.length() - hamming_distance) / sequence_1.length();      // calculates similarity score with final hamming value
    return similarity_score;
}
/*
    function will return a float value and accept 2 string values
    1. redefine / define variables
    2. set up first 2 conditionals that will make sure both strings are not empty / make sure the genome length is shorter than the sequence length
    3. find the length of given sequence
        use that sequence length to obtain matching character length for genome string
    4. initialize index length / a current similarity score. 
        - set up a terminating while loop
            - loop will execute for as long as the genome substring doesn't suprass it's indexing boundaries
            - for every execution, the while loop will call the simmilarity score function and calculate the similarity score between current genome substring / sequence
            - after calculations, compare the highest similarity score with the previous score. if new score is > current score, update current score with new one
                - increase initial index by one
    5. After while loop has terminated, return float highest similarity score
*/
float findBestMatch(string gnme, string sqnc)    // acceting 2 string parameters
{
    string genome = gnme;           // redefining / defining new variables
    string sequence = sqnc;
    string genome_substring;
    float current_similarity_score;
    if (genome == "" || sequence == "")         // edge cases , checks empty strings
    {
        return -1;
    }
    if (sequence.length() > genome.length())        // edge cases , ensures string length of sequence is greater then genome length
    {
        return -2;
    }
    int initial_index = 0;               // initial indexer for sperating substrings in the genome                          
    int string_sequence_length = sequence.length();      // gives sequence length
    genome_substring = genome.substr(initial_index, string_sequence_length);        // gives substring for the sequence length of the genome_substring
    
   
    float highest_similarity_score = 0;     // initialize similarity score
    while (genome_substring != "\0")            // conditional loop that will run as long as the genome substring does not surpass its boundaries
    {
        genome_substring = genome.substr(initial_index, string_sequence_length);   // gives genome substring that matches amount of characters of current sequence
        current_similarity_score = findSimilarityScore(genome_substring, sequence); // calculates similarity score with current values
        
        if (current_similarity_score >= highest_similarity_score)       // conditional that only returns the highest similarity score
        {
            highest_similarity_score = current_similarity_score;
        }
        initial_index = initial_index + 1;      // updates index number so the genome_substring can contine onto the next characters
    }
    return highest_similarity_score;            // once highest similarity score is found, return that value
}
/*
    1. initialize variables for values that the unser will input
    2. ask user to input variables
        - user inputs variables
    3. after all values have been entered check to make sure that sequence length is greater than genome lengths
        - if not true, execute while loop that will run until the previous conditions are met
    
        - Repeat process again but this time making sure that no inputs are left blank
            - inform user that input is invalid
    4. after all variables have been declared valid, calculate similarity score for each different genome
    5. set up conditionals that determine which print statements are to be executed. 
*/
int main()
{
    string inputted_genome1;        // defining variables for user input 
    string inputted_genome2;
    string inputted_genome3;
    string inputted_sequence;
    
    cout << "Please enter genome 1:" << endl;       // input and output statements for the user
    cin >> inputted_genome1;
    cout << "Please enter genome 2:" << endl;
    cin >> inputted_genome2;
    cout << "Please enter genome 3:" << endl;
    cin >> inputted_genome3; 
    cout << "Please enter a sequence:" << endl;
    cin >> inputted_sequence;
    if (inputted_sequence.length() > inputted_genome1.length() || inputted_sequence.length() > inputted_genome2.length() || inputted_sequence.length() > inputted_genome3.length())             // terminating loop that makes sure user input is valid
    {
        
        while (inputted_sequence.length() > inputted_genome1.length() || inputted_sequence.length() > inputted_genome2.length() || inputted_sequence.length() > inputted_genome3.length())  // conditional while loop 
        {
            cout << "Sequence cannot be longer than genome." << endl;
            cout << "Please enter a sequence:" << endl;
            cin >> inputted_sequence;
        }
    }
    
   if (inputted_genome1 == "" || inputted_genome2 == "" || inputted_genome3 == "" || inputted_sequence == "") // Makes sure no inputted values are empty
   {
       cout << "Genome and sequence cannot be empty." << endl;
       return 0;
   }
   
   float genome_match1 = findBestMatch(inputted_genome1, inputted_sequence); // calculates all inputted genomes with given sequence
   float genome_match2 = findBestMatch(inputted_genome2, inputted_sequence);
   float genome_match3 = findBestMatch(inputted_genome3, inputted_sequence);
   
   if (genome_match3 == genome_match1 && genome_match3 == genome_match2 && genome_match1 == genome_match2 && genome_match1 == genome_match3 && genome_match2 == genome_match1 && genome_match2 == genome_match3) // the rest are conditions that determing what to print and when. 
   {
       cout << "Genome 1 is the best match." << endl;
       cout << "Genome 2 is the best match." << endl;
       cout << "Genome 3 is the best match." << endl;
   }
   
   else if (genome_match1 == genome_match2)
   {
       cout << "Genome 1 is the best match." << endl;
       cout << "Genome 2 is the best match." << endl;
   }
   
   else if (genome_match1 == genome_match3)
   {
       cout << "Genome 1 is the best match." << endl;
       cout << "Genome 3 is the best match." << endl;
   }
   else if (genome_match2 == genome_match3)
   {
       cout << "Genome 2 is the best match." << endl;
       cout << "Genome 3 is the best match." << endl;
   }
   else if (genome_match1 > genome_match2 && genome_match1 > genome_match3)
   {
       cout << "Genome 1 is the best match." << endl;
   }
   else if (genome_match2 > genome_match1 && genome_match2 > genome_match3)
   {
       cout << "Genome 2 is the best match." << endl;
   }
   else if (genome_match3 > genome_match1 && genome_match3 > genome_match2)
   {
       cout << "Genome 3 is the best match." << endl;
   }
    
    




}


/*  
    First similarity function attempt


    string sub_string_genome1 = genome.substr(0,3);         // break down the genome string into segments
    string sub_string_genome2 = genome.substr(1,3);
    string sub_string_genome3 = genome.substr(2,3);
    string sub_string_genome4 = genome.substr(3,3);
    
    similarity_score1 = findSimilarityScore(sub_string_genome1, sequence);          // calculating similarity score for all segments
    similarity_score2 = findSimilarityScore(sub_string_genome2, sequence);
    similarity_score3 = findSimilarityScore(sub_string_genome3, sequence);
    similarity_score4 = findSimilarityScore(sub_string_genome4, sequence);
    
    if (similarity_score1 > similarity_score2 && similarity_score1 > similarity_score3 && similarity_score1 > similarity_score4)
    {
        highest_similarity_score = similarity_score1;
        return highest_similarity_score;
    }
    if (similarity_score2 > similarity_score1 && similarity_score2 > similarity_score3 && similarity_score2 > similarity_score4)
    {
        highest_similarity_score = similarity_score2;
        return highest_similarity_score;
    }
    if (similarity_score3 > similarity_score1 && similarity_score3 > similarity_score2 && similarity_score3 > similarity_score4)
    {
        highest_similarity_score = similarity_score3;
        return highest_similarity_score;
    }
    if (similarity_score4 > similarity_score1 && similarity_score4 > similarity_score2 && similarity_score4 > similarity_score3)
    {
        highest_similarity_score = similarity_score4;
        return highest_similarity_score;
    }
}
*/