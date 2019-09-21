// CS1300 Spring 2018
// Author: Janathan Phouminh
// Recitation: 930am
// Akriti Kapur
// Homework 3 problem 1
// February 7th, 2018


#include <iostream>
using namespace std;
/*
    menu function is called from the main and defines varibles which the user will input to decide which function will be called
    the user input will be compared to 4 different choice options and once a boolean is true 
        another function will be called
        if user inputs anything other than the choices the function will output a error message. 
        menu takes no parameters
*/
void menu()
{
    void End_Game();        // initializing variables
    void story1();  
    void story2();
    void story3();
    
    string User_Choice;
    
    string Choice_1 = "1";          //initializing choice inputs
    string Choice_2 = "2";
    string Choice_3 = "3";
    string Choice_4 = "q";
    
    cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: " << endl;
    cin >> User_Choice;
    
    if (User_Choice == Choice_1)        // comparison statements
    {
        story1();
    }
    if (User_Choice == Choice_2)
    {
        story2();
    }
    if (User_Choice == Choice_3)
    {
        story3();
    }
    if (User_Choice == Choice_4)
    {
        cout << "good bye" << endl;
        End_Game();                     //call to endgame function
    }
    if (User_Choice != Choice_1 && User_Choice != Choice_2 && User_Choice != Choice_3 && User_Choice != Choice_4)   // last comparison statement that 
                                                                                                    // is evaluated if all other comparisons fail. 
    {
        cout << "Valid choice not selected. " << endl;
        menu();         // forces the function to return to the beginning of the menu
    }
}


//Purpose of endgame function is to return 0 so that the whole program will terminate


int End_Game()
{
    return 0;           //terminates program
}       


/*
    All 3 story functions work the same way
        They do not accept any parameters and they work if they are called from the menu function
        each story function defines their own respevtive variables where the user can enter information they desire
        the output is displayed at the end with the user inputted variables. 
            once the function displays output, each function will return to the menu function by calling it once again
*/
void story1()
{
    string plural_noun;         //declarations
    string occupation;
    string animal_name;
    string place;
    void menu();
    
    cout << "Enter a plural noun:" << endl;         //cinn statements for user input
    cin >> plural_noun;
    
    cout << "Enter an occupation:" << endl;
    cin >> occupation;
    
    cout << "Enter an animal name:" << endl;
    cin >> animal_name;
    
    cout << "Enter a place:" << endl;
    cin >> place;
    
    cout << "In the book War of the " << plural_noun << ", the main character is an anonymous " << occupation << 
    " who records the arrival of the " << animal_name << "s in " << place << "." << endl;           //console out
    
    menu();     //returns to menu
}


void story2()
{
    string Name;
    string State_Country;           // declarations
    void menu();
    
    cout << "Enter a name: " << endl;
    cin >> Name;                            //cin statements
    
    cout << "Enter a state/country:" << endl;
    cin >> State_Country;
    
    cout << Name << ", I've got a feeling we're not in " << State_Country << " anymore." << endl;           //console out
    
    menu();     // call to main function
}


void story3()
{
    string first_name;              // declarations
    string relative;
    string verb;
    void menu();
    
    cout << "Enter a first name: " << endl;         // console inputs / outputs
    cin >> first_name;
    
    cout << "Enter a relative: " << endl;
    cin >> relative;
    
    cout << "Enter a verb: " << endl;
    cin >> verb;
    
    cout << "Hello. My name is " << first_name << ". You killed my " << relative << ". Prepare to " << verb
    << "." << endl;         // console out
    
    menu();     // call to menu function
    
}


int main()
{
    menu();         //test cases
    //story1();
    //story2();
    //story3();
}