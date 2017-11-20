//  project2.cpp
//
//  Created by Tara Kreft
//

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int maxChar = 20;

//struct song model
struct song {
    char   songTitle[maxChar];
    char   artistName[maxChar];
    char   songMins[4];
    char   songSecs[4];
    char   albumTitle[maxChar];
    int    index;
};

//add a song to the library
void addSong(song& addedSong, song songList[], int& songListSize){
    int tempIndex = songListSize;
    strncpy(songList[songListSize].songTitle, addedSong.songTitle, maxChar);
    strncpy(songList[songListSize].artistName, addedSong.artistName, maxChar);
    strncpy(songList[songListSize].songMins, addedSong.songMins, 4);
    strncpy(songList[songListSize].songSecs, addedSong.songSecs, 4);
    strncpy(songList[songListSize].albumTitle, addedSong.albumTitle, maxChar);
    addedSong.index = tempIndex;
}

//read the song library file
void readLibrary(char fileName[], song songList[], int& songListSize){
    
    ifstream infile;
    char     songTitle[maxChar];
    char     artistName[maxChar];
    char     songMins[4];
    char     songSecs[4];
    char     albumTitle[maxChar];
    int      index;
    song     addedSong;
    
    infile.open(fileName);
    
    if(!infile){
        infile.clear();
        cout << "Could not open songs.txt at this time." << endl;
        exit(1);
    }
    
    while(!infile.eof()){
        infile.get(songTitle, maxChar, ';');
        infile.get();
        infile.get(artistName, maxChar, ';');
        infile.get();
        infile.get(songMins, 4, ';');
        infile.get();
        infile.get(songSecs, 4, ';');
        infile.get();
        infile.get(albumTitle, maxChar, ';');
//        infile.ignore(100, ';');
        infile.ignore(100, '\n');
        
        strncpy(addedSong.songTitle, songTitle, maxChar);
        strncpy(addedSong.artistName, artistName, maxChar);
        strncpy(addedSong.songMins, songMins, 4);
        strncpy(addedSong.songSecs, songSecs, 4);
        strncpy(addedSong.albumTitle, albumTitle, maxChar);
        addedSong.index = songListSize;
        addSong(addedSong, songList, songListSize);
        songListSize++;
    }
    songListSize--;
    infile.close();
}

//display all songs
void displaySongs(song songList[], int& songListSize){
    
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    for(int i = 0; i < songListSize; i++){
        cout << left << setw(maxChar) << songList[i].songTitle << setw(maxChar) << songList[i].artistName << setw(7) << songList[i].songMins << setw(1) << " " << setw(7) << songList[i].songSecs << setw(maxChar) << songList[i].albumTitle << setw(5) << i << endl;
    }
}


// add songs
// remove songs by index
// search for songs by artist
//search for songs by album
//quit

int displayChoices(){
    int usersChoice;
    cout << "\n" << "\n" << "What would you like to do? Please enter a number from the following key:" << endl;
    cout << "1 - view library" << endl;
    cout << "2 - remove song by index" << endl;
    cout << "3 - search for a song by artist" << endl;
    cout << "4 - search for a song by album" << endl;
    cout << "5 - enter a new song to the library" << endl;
    cout << "6 - quit this program" << endl;
    
    cin >> usersChoice;
    cin.clear();
    cin.ignore(100, '\n');
    
    return usersChoice;
}

void runUserChoice(int programChoice, char fileName[], song songList[100], int& songListSize){
    switch(programChoice){
        case 1:
            cout << "you have chosen option 1:" << endl;
            displaySongs(songList, songListSize);
            break;
        case 2:
            cout << "you have chosen option 2:" << endl;
            break;
        case 3:
            cout << "you have chosen option 3:" << endl;
            break;
        case 4:
            cout << "you have chosen option 4:" << endl;
            break;
        case 5:
            cout << "you have chosen option 5:" << endl;
            break;
        case 6:
            cout << endl;
            break;
        default:
            cout <<programChoice << " is an Invalid entry! Try again" << endl;
    }
}

int main()
{
    int  programChoice;
    char fileName[] = "songs.txt";
    song songList[100];
    int  songListSize = 0;
    
    readLibrary(fileName, songList, songListSize);
    
    cout << "Welcome to the music library interface!" << endl;
    
    programChoice = displayChoices();
    
    while(programChoice != 6){
        runUserChoice(programChoice, fileName, songList, songListSize);
        programChoice = displayChoices();
    }
    
    return 0;
}










