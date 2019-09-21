#include <iostream> 
#include <string> 
#include <math.h> 
#include <fstream> 
#include <iomanip>
#include <sstream>
#include <cctype> 
using namespace std;
class User
{
public:
    User()       // empty constructor
    {
        
    }
    User(string inputted_name, string inputted_gender, double entered_height, double entered_weight, double bench_max, double squat_max, double dead_max)  // overloaded constructor, the one that will be used. 
    {
        username = inputted_name;
        gender = inputted_gender;
        heightFeet = entered_height;
        weightPounds = entered_weight;
        benchPressMax = bench_max;
        squatMax = squat_max;
        deadliftMax = dead_max;
    }
    
    string getUsername();       // getter and setter functions
    string getGender();
    double getHeight();
    double getWeight();
    double getBenchMax();
    double getSquatMax();
    double getDeadMax();
    
    void setUsername(string);
    void setGender(string);
    void setHeight(double);
    void setWeight(double);
    void setBenchMax(double);
    void setSquatMax(double);
    void setDeadMax(double);


private:

    string username;
    string gender;
    double heightFeet;
    double weightPounds;
    double benchPressMax;
    double squatMax;
    double deadliftMax;

};

string User::getUsername()
{
    return username;
}
string User::getGender()
{
    return gender;
}
double User::getHeight()
{
    return heightFeet;
}
double User::getWeight()
{
    return weightPounds;
}
double User::getBenchMax()
{
    return benchPressMax;
}
double User::getSquatMax()
{
    return squatMax;
}
double User::getDeadMax()
{
    return deadliftMax;
}
void User::setUsername(string new_name)
{
    username = new_name;
}
void User::setGender(string new_gender)
{
    gender = new_gender;
}
void User::setHeight(double new_height)
{
    heightFeet = new_height;
}
void User::setWeight(double new_weight)
{
    weightPounds = new_weight;
}
void User::setBenchMax(double new_BenchPresMax)
{
    benchPressMax = new_BenchPresMax;
}
void User::setSquatMax(double new_SquatMax)
{
    squatMax = new_SquatMax;
}
void User::setDeadMax(double new_deadLiftMax)
{
    deadliftMax = new_deadLiftMax;
}