#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ofstream fd; // output file stream
    fd.open("fileio-output.txt", ios::out);

    // treat fd like the std::cout stream
    fd << "Writing this line to a file\n";
    fd << "Line 2\n";
    fd << "Line 3\n";
    cout << "Writing this line to stdio\n";

    fd.close();

    ifstream fd2; // input file stream
    fd2.open("fileio-output.txt", ios::in);

    string line;
    while(std::getline(fd2, line)) { // keep reading lines
        cout << line << '\n';
    }

    return EXIT_SUCCESS;
}