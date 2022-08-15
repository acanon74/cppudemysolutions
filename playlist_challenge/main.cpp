#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include "Song.h"

using namespace std;


void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display
    // Playing: followed by the song that is playing
    cout << "Playing: " << song.get_name() << endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist
    // and then the current song playing.

    for(Song s: playlist) {
        cout << s.get_name() << endl;
        cout << s.get_artist() << endl;
        cout << s.get_rating() << endl;
    }
    cout << "===============================================" << endl;
    cout << "Current song Playing: " << current_song.get_name() << endl;
    cout << "===============================================" << endl;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}
    };

    std::list<Song>::iterator current_song = playlist.begin();

    char selection{'Q'};

    do {
        display_menu();
        cin >> selection;
        selection = toupper(selection);

        if(selection == 'F') {
            current_song = playlist.begin();
            play_current_song(*current_song);
        }

        if(selection == 'N') {

            if(*current_song == playlist.back()) {
                current_song = playlist.begin();
                play_current_song(*current_song);
            } else {
                current_song++;
                play_current_song(*current_song);
            }
        }

        if(selection == 'A') {

            string t_name;
            string t_author;
            int t_rating{0};

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Type the name for the new song:";
            getline(cin, t_name);

            cout << "Type the name of the author: ";
            getline(cin, t_author);

            cout << "Type the rating: ";
            cin >> t_rating;

            playlist.emplace(current_song, Song{t_name, t_author, t_rating});
        }

        if(selection == 'P') {

            if(current_song == playlist.begin()) {
                current_song = --(playlist.end());
                play_current_song(*current_song);
            }else {
                current_song--;
                play_current_song(*current_song);
            }


        }

        if(selection == 'L') {
            display_playlist(playlist, *current_song);
        }


    } while(selection != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}
