#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;


int main() {

    fstream file;
    string filepath{"../romeoandjuliet.txt"};
    file.open(filepath);

    string word;

    cout << "Type the word to look for:";
    cin >> word;

    int counter{0};

    char c;
    bool match{false};

    while(file.peek() != EOF) {

        c = file.get();

        if(c == word.at(0)) {

            match = true;

            for(int i{1}; i < word.length(); i++) {

                c = file.get();

                if(c != word.at(i)) {
                    match = false;
                    break;
                }
            }

            if(match) {
                counter++;
                match = false;
            }

        }
    }
    cout << counter;

    return 0;
}