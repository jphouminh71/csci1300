#include <iostream> 
#include <string> 
#include <math.h> 
#include <fstream> 
#include <iomanip>
#include <sstream>
#include <cctype> 
using namespace std;

class Music
{
public:
    Music(){
    
    }
    Music(string given_songTitle, string given_artist)  // constructor that is used if the user wants to add music to playlist of reccomended music, which is the array
    {
        songTitle = given_songTitle;
        songArtist = given_artist;
    }
    
    string getSongTitle();          // getter and setter functions 
    string getSongArtist();
    void setSongTitle(int, string);
    void setSongArist(int, string);
    
private:
    string songTitle;
    string songArtist;
    string arrayOfSongs[200];
    string arrayOfArtist[200];
    
};

string Music::getSongTitle()
{
    return songTitle;
}
string Music::getSongArtist()
{
    return songArtist;
}
void Music::setSongArist(int index, string given_artist)
{
    arrayOfArtist[index] = given_artist;
}
void Music::setSongTitle(int index, string given_title)
{
    arrayOfSongs[index] = given_title;
}