#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>


#include <stack>
#include <queue>

std::string cleaner(const std::string &word);
template<typename T>
void display(std::stack<T>);

bool is_palindrome_queue(const std::string &s) {

    std::queue<char> que;

    for(char c: s) {
        que.push(c);
    }
    for(auto i{s.size()-1}; i > 0; i--) {

        if(que.front() != s.at(i)) {
            return false;
        }
        que.pop();
    }

    return true;
}

bool is_palindrome_stack(const std::string &s) {

    std::stack<char> sta;

    for(char c: s) {
        sta.push(c);
    }

    for(int i{0}; i < s.size(); i++) {

        if(sta.top() != s.at(i)) {
            return false;
        }
        sta.pop();
    }

    return true;
}


int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
                                           "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
                                           "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };



    std::vector<std::string> cleaned_str;

    for(const std::string &s: test_strings) {
        cleaned_str.push_back(cleaner(s));
    }

    for(const auto &s: cleaned_str) {
        std::cout << s << " / ";
        std::cout << is_palindrome_stack(s) << " | " << is_palindrome_queue(s) << std::endl;
    }

    /*
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;

    for(const auto& s : cleaned_str) {
        std::cout << std::setw(8) << std::left << is_palindrome_stack(s)  << s << std::endl;
    }
     */
    std::cout << std::endl;
    return 0;
}

std::string cleaner(const std::string &word) {

    std::string temp;

    for(char c: word) {

        if(std::isalpha(c))
            temp += toupper(c);
        else if(std::isspace(c) || std::ispunct(c))
            continue;
        else
            continue;
    }

    return temp;
}
template<typename T>
void display(std::stack<T> sta) {

    while(!sta.empty()) {
        std::cout << sta.top() << " ";
        sta.pop();
    }
}



