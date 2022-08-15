#include <iostream>
#include <deque>
#include <string>
#include <cctype>
#include <vector>
#include <cctype>

using namespace std;

bool checker(string word) {

    for(int i{0}; i < word.size(); i++) {
        word.at(i) = tolower(word.at(i));
    }
    deque<char> temp = {word.begin(), word.end()};

    for(size_t i{0}; i < word.length(); i++) {

        int forward_index = i;
        int back_index = temp.size()-i-1;

        if(temp.at(forward_index) != temp.at(back_index))
            return false;
    }

    return true;
}


int main() {

    vector<string> test_strings = {"a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana", "avid diva", "Amore, Roma", "A Toyota's a Toyota"
    , "A Santa at NASA", "C++", "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome"};

    for(string t: test_strings) {
        cout << checker(t) << " | ";
        cout << t << endl;
    }

    return 0;
}
