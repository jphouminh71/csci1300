
/*sources:
1.
https://stackoverflow.com/questions/9622163/save-plot-to-image-file-instead-of
-displaying-it-using-matplotlib
#used to find examples for how to save a plots vs showing a plots
2. http://www.cplusplus.com/forum/beginner/6397/
    used to figure out how to display date and time 
*/
#include "Music.h"
#include "User.h"
#include <ctime>
#include <chrono>
#include <cstdlib>
using namespace std;
class fitness
{
public:

    string getFitnessFactAt(int);       // defining all the public member functions that i use
    string getFitnessQuoteAt(int);

    void setFitnessFactAt(int, string);
    void setFitnessQuoteAt(int, string);
    // void 


    void loadFacts();
    void loadFitnessMembers();
    void loadWorkoutSongs();
    void setNewNumbers();

    void displayDate();
    void login();
    void menu();
    void foodFactGenerator();

    void viewInformation();
    void bmiCalculator(double, double);
    void factGenerator();              // gonna take a random integer and use it to pull from the getFitnessFactAt() member function
    void quoteGenerator();             // same thing but pull from getFitnessQuoteAt() member function 
    void songGenerator();
   
    int SignOut();


private:
          
    int factIndex = 0;
    int quoteIndex = 0;
    int foodIndex = 0;
    string arrayOfFitnessFacts[100];
    string arrayOfFitnessQuotes[100];
    string arrayOfFoodFacts[100];
    

    int indexOfCurrentUser;         // index for the current user being evaluated
    int currentUserCount;           // count of how many users are in the system
    User arrayOfFitnessMembers[100];        // array of user objects

    
    int currentSongIndexCount = 0;  // index for for how many songs are in the array of music objects
    int indexOfCurrentSong = 0;     // index for the song that is being pulled from the music array 
    Music arrayOfMusic[200];    // array of song objects

};

void fitness::setFitnessQuoteAt(int index, string given_quote)
{
    arrayOfFitnessQuotes[index] = given_quote;
}
void fitness::setFitnessFactAt(int index, string given_fact)
{
    arrayOfFitnessFacts[index] = given_fact;
}
string fitness::getFitnessQuoteAt(int index)
{
    return arrayOfFitnessQuotes[index];
}
string fitness::getFitnessFactAt(int index)
{
    return arrayOfFitnessFacts[index];
}
int Split(string sequence1, char seperator_character, string myArray[], int size)
{
    string sequence =  sequence1 + seperator_character;     // concatonate the seperator character
    string current_word;    // represents the substring that will be placed in the array that was taken from the string
    int last_index = 0; // represents the last index of the last substring taken
    int word_count = 0; // value that will end up being returned
    int i = 0;  // g and i are counters
    int g = 0;

    if ( sequence1 == "" )      // edge case
    {
        return 0;
    }
    
    while ( i <= sequence.length())
    {

        if ( sequence[i] != seperator_character)        // part of the while loop that evaluetes if the current character is a seperator character or not
        {
            i = i + 1;
        }
        else if ( sequence[i] == seperator_character || sequence[i] == '\0')    // conditional that sees if the current index is the seperator character
        {
            //word_count = word_count + 1;
            current_word = sequence.substr(last_index, i - last_index); // takes the substring from the current index -1 from the last known index

            myArray[g] = current_word;  // places the substring into the empty array

            //cout << current_word << endl;
            last_index = i + 1; // saves the last index of the seperator character one character forward
            //cout << current_word << endl;
            i = i + 1;  // keeps while loop running
            g = g + 1;  // counting the amount of words that were being added.
        }
    }

    word_count = g;
    return word_count;      // returning the final word count

}
/*
    set up system for setting up a live clock
    display the current time of login and sign out
*/
void fitness::displayDate()
{
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
 
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << std::ctime(&end_time);
	
}
/*
    ask the user for all the information required for the user object again 
    use that information to update the private members of the user class for the current user being evaluated
*/
void fitness::setNewNumbers()
{
        string gender_input, lowered_genderInput;
        cout << "Are you male or female or , other?" << endl;
        cin >> gender_input;
        for (int i = 0; i < gender_input.length(); i++)
        {
            char c = gender_input[i];
            char lower_c = tolower(c);
            lowered_genderInput = lowered_genderInput + lower_c;
        }

        bool valid_input = false;
        while (valid_input == false)
        {   
            if(lowered_genderInput == "male" || lowered_genderInput == "female" || lowered_genderInput == "other" )
            {
                valid_input = true;
                break;
            }
            else if (lowered_genderInput != "male" || lowered_genderInput != "female" || lowered_genderInput != "other")
            {
                cout << "Enter a valid input!" << endl;
                cout << "Enter your gender again" << endl;
                string gender_input, lowered_genderInput;
                cin >> gender_input;
                for (int i = 0; i < gender_input.length(); i++)
                {
                    char c = gender_input[i];
                    char lower_c = tolower(c);
                    lowered_genderInput = lowered_genderInput + lower_c;
                }
                
                if (lowered_genderInput == "male" || lowered_genderInput == "female" || lowered_genderInput == "other" )
                {
                    valid_input = true;
                    break;
                }
                else{
                    valid_input = false;
                }
            }
           
        }                                                                   // getting the gender of the new user being created, lowered_genderInput
        arrayOfFitnessMembers[indexOfCurrentUser].setGender(lowered_genderInput);    // setting the new inputted gender from the current object
        
        double inputtedHeight;
        cout << "Next," << endl << "Enter your height!(ft)" << endl;
        cin >> inputtedHeight;
        bool valid_height = false;
        while(valid_height == false)
        {
            if (inputtedHeight > 0)
            {
                valid_height = true;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter in your height (ft)" << endl;
                cin >> inputtedHeight;
                {
                    if (inputtedHeight > 0)
                    {
                        valid_height = true;
                    }
                    else{
                        valid_height = false;
                    }
                }
            }                                                                   // getting the height of the new user, inputted height
        }
        int inputtedInches;
        cout << "Enter inches: " << endl;
        cin >> inputtedInches;
        bool valid_inches = false;
        while(valid_inches == false)
        {
            if (inputtedInches > 0)
            {
                valid_inches = true;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter inches: " << endl;
                cin >> inputtedHeight;
                {
                    if (inputtedInches > 0)
                    {
                        valid_inches = true;
                    }
                    else{
                        valid_inches = false;
                    }
                }
            }                                                                   // getting the height of the new user, inputted height
        }
        
        float inchConversion = inputtedInches*0.083;
        float height = float(inputtedHeight) + inchConversion;
        
        arrayOfFitnessMembers[indexOfCurrentUser].setHeight(height); 
        
        double inputtedWeight;
        cout << "Next," << endl << "Enter your weight!(lbs)" << endl;
        cin >> inputtedWeight;
        bool validWeight = false;
        while (validWeight == false)
        {
            if (inputtedWeight > 0)
            {
                validWeight = true;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter in your weight! (lbs)" << endl;
                cin >> inputtedWeight;
                if (inputtedWeight > 0)
                {
                    validWeight = true;
                }
                else{
                    validWeight = false;
                }
            }
        }                                                                       // getting the weight of the new user, inputtedWeight
        arrayOfFitnessMembers[indexOfCurrentUser].setWeight(inputtedWeight); 
        
        double inputtedBenchPress;
        cout << "Ok," << endl << "Enter in your max BenchPress(lbs)" << endl;
        cin >> inputtedBenchPress;
        bool valid_int = false;
        while (valid_int == false)
        {
            if (inputtedBenchPress > 0)
            {
                valid_int = true;
                break;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter in your max BenchPress(lbs)" << endl;
                cin >> inputtedBenchPress;
                if (inputtedBenchPress > 0)
                {
                    valid_int = true;
                }
                else{
                    valid_int = false;
                }
            }
        }                                                                       // getting the value of their current max bench press   , inputtedBenchPress
        arrayOfFitnessMembers[indexOfCurrentUser].setBenchMax(inputtedBenchPress); 
        
        double inputtedSquatMax;
        cout << "Almost there!" << endl << "Enter in your max Squat(lbs)" << endl;
        cin >> inputtedSquatMax;
        bool valid_squat = false;
        while (valid_squat == false)
        {
            if (inputtedSquatMax > 0)
            {
                valid_squat = true;
                break;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter in your max Squat(lbs)" << endl;
                cin >> inputtedSquatMax;
                if (inputtedSquatMax > 0)
                {
                    valid_int = true;
                }
                else{
                    valid_int = false;
                }
            }
        }                                                                       // getting the value for the new users max Squat
        arrayOfFitnessMembers[indexOfCurrentUser].setSquatMax(inputtedSquatMax); 
        
        double inputtedDeadlift;
        cout << "Last one!" << endl << "Enter in your max DeadLift(lbs)" << endl;
        cin >> inputtedDeadlift;
        bool valid_dead = false;
        while (valid_dead == false)
        {
            if (inputtedDeadlift > 0)
            {
                valid_dead = true;
                break;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter in your max DeadLift(lbs)" << endl;
                cin >> inputtedDeadlift;
                if (inputtedDeadlift > 0)
                {
                    valid_int = true;
                }
                else{
                    valid_int = false;
                }
            }
        }
        arrayOfFitnessMembers[indexOfCurrentUser].setDeadMax(inputtedDeadlift); 
}
/*
    access the user private member values for the current user and dispaly all the information
    ask the user if they would like to update
        if so call the update function
    if not return them to the menu
*/
void fitness::viewInformation()
{
    cout << "Here are is your current information: " << endl;
    cout << "Username: " << arrayOfFitnessMembers[indexOfCurrentUser].getUsername() << endl;
    cout << "Gender: " << arrayOfFitnessMembers[indexOfCurrentUser].getGender() << endl;
    cout << "Height: " << arrayOfFitnessMembers[indexOfCurrentUser].getHeight() << endl;
    cout << "Weight: " << arrayOfFitnessMembers[indexOfCurrentUser].getWeight() << endl;
    cout << "Bench Press Max: " << arrayOfFitnessMembers[indexOfCurrentUser].getBenchMax() << endl;
    cout << "Squat Max: " << arrayOfFitnessMembers[indexOfCurrentUser].getSquatMax() << endl;
    cout << "DeadLift Max: " << arrayOfFitnessMembers[indexOfCurrentUser].getDeadMax() << endl;
                            // everything above is just for displaying the current information on the current user
    bool choice = false;
    char input;
    while(choice == false)
    {
        cout << "Would you like to update your information?(Y/N)" << endl;
        cin >> input;
        if (input == 'n' || input == 'N')
        {
            break;
        }
        else if(input == 'y' || input == 'Y')
        {
            setNewNumbers();
            cout << "Here are is your new information! " << endl;
            cout << "Username: " << arrayOfFitnessMembers[indexOfCurrentUser].getUsername() << endl;
            cout << "Gender: " << arrayOfFitnessMembers[indexOfCurrentUser].getGender() << endl;
            cout << "Height: " << arrayOfFitnessMembers[indexOfCurrentUser].getHeight() << endl;
            cout << "Weight: " << arrayOfFitnessMembers[indexOfCurrentUser].getWeight() << endl;
            cout << "Bench Press Max: " << arrayOfFitnessMembers[indexOfCurrentUser].getBenchMax() << endl;
            cout << "Squat Max: " << arrayOfFitnessMembers[indexOfCurrentUser].getSquatMax() << endl;
            cout << "DeadLift Max: " << arrayOfFitnessMembers[indexOfCurrentUser].getDeadMax() << endl;
            break;
        }
    }
    
    foodFactGenerator();
    menu();
}
/*
    convert inputted height and weight into meters and kg
    to calculate:
        1. BMI = (your weight in pounds x 703) ÷ (your height in inches x your height in inches)
        2. Underweight: BMI is less than 18.5
           Normal weight: BMI is 18.5 to 24.9
           Overweight: BMI is 25 to 29.9
           Obese: BMI is 30 or more
*/
void fitness::bmiCalculator(double weight_pounds, double height_feet)
{
    double BMI, inches;
    inches = height_feet * 12;
    BMI = (weight_pounds * 703) / (pow(inches,2));
    if (arrayOfFitnessMembers[indexOfCurrentUser].getGender() == "male")
    {
        if (BMI < 18.5)
        {
            cout << "Your body mass index is: " << BMI << endl << "You are underweight, time to start eating!!!" << endl;
            foodFactGenerator();
            menu();
        }
        else if (BMI >= 18.5 && BMI <= 24.9)
        {
            cout << "Your body mass index is: " << BMI << endl << "You weight is relatively normal, start eating and get ripped" << endl;
            foodFactGenerator();
            menu();
        }
        else if (BMI > 24.9)
        {
            cout << "Your body mass index is: " << BMI << endl << "You are overweight, time to stop lifting the fork and start lifting some weights." << endl;
            foodFactGenerator();
            menu();
        }
    }
    
    if (arrayOfFitnessMembers[indexOfCurrentUser].getGender() == "female" || arrayOfFitnessMembers[indexOfCurrentUser].getGender() == "other")
    {
        if (BMI < 17.5)
        {
            cout << "Your body mass index is: " << BMI << endl << "You are underweight, treat yo'self." << endl;
            foodFactGenerator();
            menu();
        }
        else if (BMI >= 17.5 && BMI <= 23.9)
        {
            cout << "Your body mass index is: " << BMI << endl << "You weight is relatively normal, keep it up!" << endl;
            foodFactGenerator();
            menu();
        }
        else if (BMI > 23.9)
        {
            cout << "Your body mass index is: " << BMI << endl << "You are overweight, time to get a gym membership!" << endl;
            foodFactGenerator();
            menu();
        }
    }
}
/*
    delcare a value to store the random number
    generate a rondom number 
    use that random number to pull from the array and display that element
    call the menu function to return the user back to the menu
*/
void fitness::foodFactGenerator()
{
    int randomNumber;
    srand(time(0));
    randomNumber = rand()%foodIndex+0;
    cout << "Did you know , " << arrayOfFoodFacts[randomNumber] << endl;
    //menu();
}
/*
    delcare a value to store the random number
    generate a rondom number 
    use that random number to pull from the array and display that element
    call the menu function to return the user back to the menu
*/
void fitness::factGenerator()
{
    int randomNumber;
    srand(time(0));
    randomNumber = rand()%factIndex+0;
    cout << arrayOfFitnessFacts[randomNumber] << endl;
    menu();
}
void fitness::quoteGenerator()
{
    int randomNumber;
    srand(time(0));
    randomNumber = rand()%quoteIndex+0;
    cout << arrayOfFitnessQuotes[randomNumber] << endl;
    menu();
}
/*
    delcare a value to store the random number
    generate a rondom number 
    use that random number to pull from the array and display that element
    call the menu function to return the user back to the menu
*/
void fitness::songGenerator()
{
    int randomNumber;
    int previous_number;  
    srand(time(0));
    randomNumber = rand()%currentSongIndexCount+0;
    if (previous_number == randomNumber)
    {
        randomNumber = rand()%currentSongIndexCount+0;
        if (previous_number = randomNumber)
        {
            randomNumber = rand()%currentSongIndexCount+0;
        }
    }
   
    cout << "Try listening to '" << arrayOfMusic[randomNumber].getSongTitle() << "' by " << arrayOfMusic[randomNumber].getSongArtist() << "!" << endl;
    menu();
}

/*
    display information informing the user whats going on
    open an outstream file
    write to the outstream file all the information of every user object that is currently in the way
    close the file
    tell the user bye
    return 0; this should end the entire program
*/
int fitness::SignOut()         // this function will write out a report of 
{
    cout << "Saving information" << endl;
    cout << "Have a good day!" << endl;
    ofstream outfile;
    outfile.open("fitnessmembers.txt");
    if (outfile.fail())
    {
        cout << "File failed to open" << endl;
        exit(1);
    }
    for (int i = 0; i < currentUserCount; i++)
    {
        outfile << arrayOfFitnessMembers[i].getUsername() << ',' << arrayOfFitnessMembers[i].getGender() << ',' << arrayOfFitnessMembers[i].getHeight() << ' ' << arrayOfFitnessMembers[i].getWeight()<< ' ' << arrayOfFitnessMembers[i].getBenchMax() << 
        ' ' << arrayOfFitnessMembers[i].getSquatMax() << ' ' << arrayOfFitnessMembers[i].getDeadMax() << endl;
    }
    
    outfile.close();
    cout << "Goodbye!" << endl;
    
    return 0;
}
/*
    open instream file for the text file that has all the music
    check if the file opens
    parse the text file line by line
        while parsing the information use the text information and create music objects and put them into the music object array
*/

void fitness::loadWorkoutSongs()
{
    ifstream infile;
    infile.open("workoutsongs.txt");
    if (infile.fail())
    {
        cout << "Music file failed to open" << endl;
        exit(1);
    }
    
    string songTitle;
    string songArtist;
    string arrayOfSongsFromFile[3];
    string line;
    while(getline(infile, line))
    {
        Split(line,',', arrayOfSongsFromFile,3);
        //cout << arrayOfSongsFromFile[0] << endl << arrayOfSongsFromFile[1] << endl;
        Music newSong = Music(arrayOfSongsFromFile[0], arrayOfSongsFromFile[1]);
        arrayOfMusic[currentSongIndexCount] = newSong;
        currentSongIndexCount++;
    }
}
/*
    open instream file for the text file that has all the facts
    check if the file opens
    take the facts in line by  line and put it into the array of facts
    update counters
*/
void fitness::loadFacts()
{
    ifstream infile, infile1, infile2;
    infile.open("fitnessfacts.txt");
    infile1.open("fitnessquotes.txt");
    infile2.open("foodFacts.txt");

    if (infile.fail() || infile1.fail() || infile2.fail())
    {
        cout << "One or more file failed to open. . ." << endl;
        exit(1);
    }


    string line;
    while(getline(infile,line))                 // loads in all facts
    {
        arrayOfFitnessFacts[factIndex] = line;
        factIndex++;
    }

    string line1;
    while(getline(infile1, line1))
    {
        arrayOfFitnessQuotes[quoteIndex] = line1;
        quoteIndex++;
    }
    
    string line2;
    while(getline(infile2,line2))
    {
        arrayOfFoodFacts[foodIndex] = line2;
        foodIndex++;
    }

    infile.close();
    infile1.close();
    infile2.close();
}
/*
    open instream file for the text file that has all the fitness member data
    check if the file opens
    parse the data
        use the parsed data and make user objects and put htem into the array of users
    update counters
*/
void fitness::loadFitnessMembers()
{
    ifstream infile;
    infile.open("fitnessmembers.txt");
    if(infile.fail())
    {
        cout << "failed to open file. . ." << endl;
        exit(1);
    }
    string arrayForCreatingFitnessMemberObjects[3];
    float arrayOfUserNumbers[6];        // this array will be used for creating user object, object form

    string database_name;           // database name will be used when we enter the login screen
    string database_gender;         // this will be used for the bmi part, everything should be working in lowercase
    string line;
    while(getline(infile,line))
    {
        database_name = "";
        database_gender = "";
        Split(line, ',', arrayForCreatingFitnessMemberObjects, 2);
        //cout << arrayForCreatingFitnessMemberObjects[0] << ' ' << arrayForCreatingFitnessMemberObjects[1] << endl;
        for (int i = 0; i < arrayForCreatingFitnessMemberObjects[0].length(); i++)
        {
            char c = arrayForCreatingFitnessMemberObjects[0][i];
            char upper_c = tolower(c);
            database_name = database_name + upper_c;
        }                                           // convert the username to lowercase
        for (int i = 0; i < arrayForCreatingFitnessMemberObjects[1].length(); i++)
        {
            char c = arrayForCreatingFitnessMemberObjects[1][i];
            char upper_c = tolower(c);
            database_gender = database_gender + upper_c;
        }                                                   // from here the username and the gender are ready to be used for creating user objects
        // convert the number values from the file from txt to float

        string arrayForBodyNumbersThatWillBeConverted[6];  // array that contains the fitness numbers for the current users in string form
        Split(arrayForCreatingFitnessMemberObjects[2], ' ', arrayForBodyNumbersThatWillBeConverted, 6);
        for (int i = 0; i < 5; i++)
        {
            float value = stof(arrayForBodyNumbersThatWillBeConverted[i]);
            arrayOfUserNumbers[i] = value;
        }

        User currentUser = User(database_name, database_gender, arrayOfUserNumbers[0],arrayOfUserNumbers[1], arrayOfUserNumbers[2], arrayOfUserNumbers[3],arrayOfUserNumbers[4]);    // creating the User object for the current User
        //cout << currentUser.getUsername() << endl;
        arrayOfFitnessMembers[currentUserCount] = currentUser;
        currentUserCount++; // updating the count for the user
        //cout << "Data for fitness members loaded!" << endl;     // data from "fitnessmembers.txt" should all be loaded, theres a small error , refer to top
        //cout << arrayOfFitnessMembers[0].getUsername() << endl;
    }
}
/*
    greet user and ask for input
    take in the input and go through user information to see if they are an existing member
    if they are then take them to the menu
    if they are not then ask them to create an account 
        ask for inforamtion for object information 
        create object and update object array
    take them into the menu once all of that is done
*/
void fitness::login()
{
    string input, loweredInput;
    cout << "--------------------------" << endl << "Hello! Welcome to FitnessBuddy!" << endl <<  "Are you an existing member?" << endl <<  "If so, type 'yes' OR type 'Create' to begin a new account." << endl;
    getline(cin, input);
    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];
        char lower_c = tolower(c);
        loweredInput = loweredInput + lower_c;
    }
    if (loweredInput == "yes")
    {
        string entered_name, lowered_name;
        cout << "Enter your name!" << endl;
        getline(cin, entered_name);
        for (int i = 0; i < entered_name.length(); i++)
        {
            char c = entered_name[i];
            char lower_c = tolower(c);
            lowered_name = lowered_name + lower_c;
        }                                               // converted the inputted member name to all lowercase
        
        bool foundUserOrNot = false;
        for (int i = 0; i < currentUserCount; i++)
        {
            if ( lowered_name == arrayOfFitnessMembers[i].getUsername())
            {
                indexOfCurrentUser = i;
                foundUserOrNot = true;
                break;
            }
        }
        if (foundUserOrNot == true)
        {
            cout << "Welcome back, "<< entered_name<< "!" << endl;
            menu();
        }
        else if (foundUserOrNot == false)
        {
            cout << "Sorry there is not an existing member in our records named: " << entered_name << " . Goodbye!" << endl;
            login();
        }
        
    }
    else if (loweredInput == "create")
    {
        string entered_username,lowered_username;
        cout << "Enter your first and last name: " << endl;
        getline(cin, entered_username);
        for (int i = 0; i < entered_username.length(); i++)
        {
            char c = entered_username[i];
            char lower_c = tolower(c);
            lowered_username = lowered_username + lower_c;
        }                                                               // entering in the username,        lowered_username
        
        string gender_input, lowered_genderInput;
        cout << "Are you male or female or , other?" << endl;
        cin >> gender_input;
        for (int i = 0; i < gender_input.length(); i++)
        {
            char c = gender_input[i];
            char lower_c = tolower(c);
            lowered_genderInput = lowered_genderInput + lower_c;
        }

        bool valid_input = false;
        while (valid_input == false)
        {   
            if(lowered_genderInput == "male" || lowered_genderInput == "female" || lowered_genderInput == "other" )
            {
                valid_input = true;
                break;
            }
            else if (lowered_genderInput != "male" || lowered_genderInput != "female" || lowered_genderInput != "other")
            {
                cout << "Enter a valid input!" << endl;
                cout << "Enter your gender again" << endl;
                string gender_input, lowered_genderInput;
                cin >> gender_input;
                for (int i = 0; i < gender_input.length(); i++)
                {
                    char c = gender_input[i];
                    char lower_c = tolower(c);
                    lowered_genderInput = lowered_genderInput + lower_c;
                }
                
                if (lowered_genderInput == "male" || lowered_genderInput == "female" || lowered_genderInput == "other" )
                {
                    valid_input = true;
                    break;
                }
                else{
                    valid_input = false;
                }
            }
           
        }                                                                   // getting the gender of the new user being created, lowered_genderInput
        
        double inputtedHeight;
        cout << "Next," << endl << "Enter your height!(ft), enter inches as part of feet in decimal form. Ex) 6ft 1in should be entered as 6.038." << endl;
        cin >> inputtedHeight;
        bool valid_height = false;
        while(valid_height == false)
        {
            if (inputtedHeight > 0)
            {
                valid_height = true;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter in your height (ft)" << endl;
                cin >> inputtedHeight;
                {
                    if (inputtedHeight > 0)
                    {
                        valid_height = true;
                    }
                    else{
                        valid_height = false;
                    }
                }
            }                                                                   // getting the height of the new user, inputted height
        }
        double inputtedWeight;
        cout << "Next," << endl << "Enter your weight!(lbs)" << endl;
        cin >> inputtedWeight;
        bool validWeight = false;
        while (validWeight == false)
        {
            if (inputtedWeight > 0)
            {
                validWeight = true;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter in your weight! (lbs)" << endl;
                cin >> inputtedWeight;
                if (inputtedWeight > 0)
                {
                    validWeight = true;
                }
                else{
                    validWeight = false;
                }
            }
        }                                                                       // getting the weight of the new user, inputtedWeight
        
        double inputtedBenchPress;
        cout << "Ok," << endl << "Enter in your max BenchPress(lbs)" << endl;
        cin >> inputtedBenchPress;
        bool valid_int = false;
        while (valid_int == false)
        {
            if (inputtedBenchPress > 0)
            {
                valid_int = true;
                break;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter in your max BenchPress(lbs)" << endl;
                cin >> inputtedBenchPress;
                if (inputtedBenchPress > 0)
                {
                    valid_int = true;
                }
                else{
                    valid_int = false;
                }
            }
        }                                                                       // getting the value of their current max bench press   , inputtedBenchPress
        
        double inputtedSquatMax;
        cout << "Almost there!" << endl << "Enter in your max Squat(lbs)" << endl;
        cin >> inputtedSquatMax;
        bool valid_squat = false;
        while (valid_squat == false)
        {
            if (inputtedSquatMax > 0)
            {
                valid_squat = true;
                break;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter in your max Squat(lbs)" << endl;
                cin >> inputtedSquatMax;
                if (inputtedSquatMax > 0)
                {
                    valid_int = true;
                }
                else{
                    valid_int = false;
                }
            }
        }                                                                       // getting the value for the new users max Squat
        
        double inputtedDeadlift;
        cout << "Last one!" << endl << "Enter in your max DeadLift(lbs)" << endl;
        cin >> inputtedDeadlift;
        bool valid_dead = false;
        while (valid_dead == false)
        {
            if (inputtedDeadlift > 0)
            {
                valid_dead = true;
                break;
            }
            else{
                cout << "Value must be greater than 0!" << endl;
                cout << "Enter in your max DeadLift(lbs)" << endl;
                cin >> inputtedDeadlift;
                if (inputtedDeadlift > 0)
                {
                    valid_int = true;
                }
                else{
                    valid_int = false;
                }
            }
        }                                                               // getting the value for the users deadlift max
        
        User newUser = User(lowered_username, lowered_genderInput, inputtedHeight, inputtedWeight, inputtedBenchPress, inputtedSquatMax, inputtedDeadlift);
        arrayOfFitnessMembers[currentUserCount] = newUser;
        indexOfCurrentUser = currentUserCount;
        currentUserCount++;
        menu();
   
    }                                                                                                                              
    else if (loweredInput != "create" || loweredInput != "yes")
    {
        cout << "Enter a valid input" << endl;
        login();
    }
        
}
/*
    display information
    ask for user input
    based on user input call different member functions
    
*/
void fitness::menu()
{
    char choice;
    bool valid_choice = false;
    cout << "------------------------------------------" << endl << "Would you like to (c)alcuate your BMI, get fun (f)itness facts, get (m)otivational quotes, (g)et workout song reccomendations, (v)iew and update your body information / lifting totals or (s)ign out?" << endl;
    cin >> choice;
    while (valid_choice == false)
    {
        if (choice == 'c' || choice == 'C')
        {
            valid_choice = true;    
            bmiCalculator(arrayOfFitnessMembers[indexOfCurrentUser].getWeight(), arrayOfFitnessMembers[indexOfCurrentUser].getHeight());
        }
        else if (choice == 'f' || choice == 'F')
        {
            valid_choice = true;
            factGenerator();
        }
        else if (choice == 'm' || choice == 'M')
        {
            valid_choice = true;
            quoteGenerator();
        }
        else if(choice == 'g' || choice == 'G')     // SAVE THIS FUNCTION CALL FOR THE LAST 
        {
            valid_choice = true;
            songGenerator();
        }
        else if(choice == 's' || choice == 'S')
        {
            valid_choice = true;
            SignOut();
        }
        else if(choice == 'v' || choice == 'V')
        {
            valid_choice = true;
            viewInformation();
        }
        else if(choice != 'q' && choice != 'Q' && choice != 'g' && choice != 'G' && choice != 'r' && choice != 'R' && choice != 'v' && choice != 'V')
        {
            cout << "Please input a valid choice " << endl;
            valid_choice = true;
            menu();
        }
        
    }
}

