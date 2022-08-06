#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;
char get_char(fstream, int, bool);


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
    bool in_word;
    int word_counter;

    while(true) {

        if(file.peek() == EOF)
            break;

        if(c == word.at(0)) {

            match = true;

            for(int i{1}; i < word.length(); i++) {

                c = get_char(file, word_counter, in_word);

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

char get_char(fstream file, int n_words, bool whitespace) {

    char c;

    file.get(c);

    if(isalpha(c) && !whitespace) {
        whitespace = true;
    }

    if(isspace(c) && whitespace) {
        n_words++;
        whitespace = false;
    }

    return c;
}