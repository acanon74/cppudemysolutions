#include <iostream>
#include <string>
#include <fstream>


int main() {

    std::fstream in_file;
    std::string in_filepath{"../romeoandjuliet.txt"};
    in_file.open(in_filepath, std::ios::in);


    std::ofstream ou_file;
    std::string ou_filepath{"../TEMP.txt"};
    ou_file.open(ou_filepath, std::ios::trunc);


    if(!ou_file.is_open())
        return -1;

    if(!in_file.is_open())
        return -1;

    std::string line;
    int index{0};

    while(in_file.peek() != EOF) {

        std::getline(in_file, line);

        ou_file << index << " | ";
        ou_file << line << std::endl;

        index++;
    }


    in_file.close();
    ou_file.close();
    return 0;
}
