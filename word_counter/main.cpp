#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

vector<string> word_divider(string &line);

int main() {

    fstream file;
    string filepath{"../words.txt"};

    file.open(filepath);

    if(!file.is_open()) {
        cerr << endl << "Problem opening the file!" << endl;
        return -1;
    }

    map<string, int> words;
    map<string, vector<int>> words_ind;

    string line;
    int counter{0};

    vector<string> temp;

    do {

        getline(file, line);
        counter++;
        temp = word_divider(line);
        for(auto i: temp) {
            if(words.find(i) == words.end()) {
                words.emplace(i, 1);
                words_ind.emplace(i, vector<int>{counter});
            }
            else {
                auto ind = words.find(i);
                (*ind).second++;
                auto ind2 = words_ind.find(i);
                ((*ind2).second).push_back(counter);
            }
        }
        temp.clear();

    } while(file.peek() != EOF);


    auto ind1 = words.begin();
    auto ind2 = words_ind.begin();

    for(size_t i{0}; i < words.size(); i++) {



        cout << "///" << (*ind1).first << " " << (*ind1).second << endl;
        cout << "/" << (*ind2).first << " | ";

        for(auto i: (*ind2).second) {
            cout << i << " ";
        }
        cout << endl;

        ind1++;
        ind2++;
    }



    file.close();
    return 0;
}

vector<string> word_divider(string &line) {

    vector<string> words;
    string word;

    for(int i{0}; i < line.length(); i++) {

        char c = line.at(i);

        if(i == line.length()-1) {
            word += c;
            words.push_back(word);
            word.clear();
            continue;
        }

        if(isalpha(c)) {
            word += c;
        }
        else if (isspace(c) && word.length() == 0) {
            continue;
        }
        else if (isspace(c) || ispunct(c)) {
            words.push_back(word);
            word.clear();
            continue;
        }
        else {
            cerr << "Broke at" << c;
        }
    }

    return words;
}