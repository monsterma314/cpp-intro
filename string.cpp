#include <iostream>
#include <cstring>

using namespace std;

string cpp_string = "Dynamically-allocated, mutable C++ string";
char c_string[] = "Statically-allocated, mutable C string";

int main() {

    // Both C++ and C style strings work! C++ strings are generally better
    cout << cpp_string << '\n';
    cout << c_string << "\n";
    
    // String indexing works in C++!
    cpp_string[3] = 'h';
    cout << cpp_string << '\n';

    string test = "Test";
    string test1 = "Test1";
    string test2 = "Test2";

    // string concatenation
    string test12 = test1 + test2;
    cout << test1 << " + " << test2 << "=" << test12 << '\n';

    // string length and size
    cout << "test1.length() = " << test1.length() << endl;
    cout << "test1.size() = " << test1.size() << endl;

    // test the push_back() method
    cout << "test1: " << test1 << endl;
    test1.push_back('z');
    cout << "test1.push_back('z'): " << test1 << endl;
    test1.pop_back();
    cout << "test1.pop_back(): " << test1 << endl;

    // test the resize method
    
    // test a c string method
    int tmp = std::strncmp(test1.c_str(), test.c_str(), test.size());
    cout << "std::strncmp(test1.c_str(), test.c_str(), test.size()): " << tmp << endl;
    tmp = std::strncmp(test1.c_str(), test.c_str(), test1.size());
    cout << "std::strncmp(test1.c_str(), test.c_str(), test1.size()): " << tmp << endl;
    tmp = std::strncmp(test.c_str(), test1.c_str(), test1.size());
    cout << "std::strncmp(test.c_str(), test1.c_str(), test1.size()): " << tmp << endl;
    
    size_t pos_found = test1.find(test);

    cout << "pos_found: " << std::hex << pos_found << endl;
    if(pos_found != SIZE_MAX) {
        test1.replace(test1.find(test), test.size(), "Replacement");
    }
    cout << test1 << endl;

    test = "new-string";
    test1 = "new-string1";
    test2 = "new-string2";

    // test the erase method
    cout << "test: " << test << endl;
    test.erase();   // deletes the string
    cout << "test.erase(): " << test << endl;

    cout << "test1: " << test1 << endl;
    test1.erase(3);  // deletes from the 3rd index to end
    cout << "test1.erase(3): " << test1 << endl;

    cout << "test2: " << test2 << endl;
    test2.erase(3, 4);  // deletes 4 characters from 3rd index on
    cout << "test2.erase(3, 4): " << test2 << endl;

    return EXIT_SUCCESS;
}