## Intro to C++ Concepts

❗ All of the code can be tested using the `Makefile` ... just run `make` for a help guide ❗

#### C++ Glossary
`namespace` - Declarative region that provides scope to the variable and function names used within (e.g. `from numpy import *`)
`scope` - The extent/sections of code where a variable is accessible
`manipulators` - Functions or objects that modify stream outputs (e.g. `std::cout`)
#### Object-Oriented Glossary
| Term              | Meaning                               |
| ----------------- | ------------------------------------- |
| `class`           | Classes are a collection of properties, methods, etc. |
| `object`          | An object is a specific instantiation of a class |
| `inheritance`     | Concept of a "child" class taking on the properties and methods of a "parent" class    |
| `constructor`     | Method in a class to allocate memory and run setup code for the object   |
| `overloading`     | Overwriting a default method in a class to change how operators (`+`, `==`, etc.) interact with the object |

## Syntax Examples

#### String Manipulation
`make test-string`
```cpp
string cpp_string = "Dynamically-allocated, mutable C++ string";
char c_string[] = "Statically-allocated, mutable C string";

int main() {
    // String indexing works in C++!
    cpp_string[3] = 'h';
    cout << cpp_string << '\n';

    // create exmaple strings
    string test = "Test";
    string test1 = "Test1";
    string test2 = "Test2";

    // string concatenation
    string test12 = test1 + test2;
    cout << test1 << " + " << test2 << "=" << test12 << '\n';

    // string length and size
    cout << "test1.length() = " << test1.length() << endl;
    cout << "test1.size() = " << test1.size() << endl;

    return EXIT_SUCCESS;
}
```

#### Namespace (Scoping)
`make test-scope`
```cpp
#include <iostream>
namespace first_space {
    void test(void) {
        std::cout << "Calling test() from: first_space\n";
    }
}
namespace second_space {
    void test(void) {
        std::cout << "Calling test() from: second_space\n";
    }
}
namespace top_name {
    namespace nested_name {
        void test(void) {
            std::cout << "Calling test() from: top_name::nested_name\n";
        }
    }
}

using namespace std;
// Don't need std::cout to use the cout method now!

int main() {
    cout << "cout << <Some Text Here>... works without std::cout!\n";
    
    // NOTE: Can only saying "using" <namespace> once!
    using namespace first_space;
    test();

    second_space::test();

    // always safe syntax
    std::cout << "Hello from std::cout!\n";
    first_space::test();
    second_space::test();
    top_name::nested_name::test();

    return EXIT_SUCCESS;
}
```

#### Printing
Restoring the settings

- Hexadecimal

- Floating Point

- Integer
- ...

#### File IO
`make test-fileio`
```cpp
#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ofstream fd; // output file stream
    fd.open("fileio-output.txt", ios::out);

    // treat fd like the std::cout stream
    fd << "Line 1\n";
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
```

## Object-Oriented Example

#### Classes and Objects
`make test-class`
```cpp
class PubVault {
    public:
        // public properties
        uint64_t public_key;
        uint8_t public_id;
        string public_info;

        // public method
        void print_public_info() {
            cout << "Public Key: 0x" << uppercase << hex << public_key << endl;
            cout << "Public Id: " << dec << +public_id << endl;
            cout << "Public Info: " << public_info << endl;
        }
        
        // public constructor (instantiator of class PubVault)
        PubVault(uint64_t pub_key, uint8_t pub_id, string pub_info) {
            public_key = pub_key;
            public_id = pub_id;
            public_info = pub_info;
        }
};
```

#### Public and Private Vault
```cpp
class PubPriVault : public PubVault {
    uint64_t private_key;
    uint8_t private_id;
    string private_info;

    public:
        // inheritance from parent class
        PubPriVault(uint64_t priv_key, uint8_t priv_id, string priv_info,
                    uint64_t pub_key, uint8_t pub_id, string pub_info) 
                    : PubVault(pub_key, pub_id, pub_info) {
            private_key = priv_key;
            private_id = priv_id;
            private_info = priv_info;
        }

        // public method
        void print_private_info() {
            cout << "Private Key: 0x" << uppercase << hex << private_key << endl;
            cout << "Private Id: " << dec << +private_id << endl;
            cout << "Private Info: " << private_info << endl;
        }

        void print_all_info() {
            print_public_info();
            cout << "Private Key: 0x" << uppercase << hex << private_key << endl;
            cout << "Private Id: " << dec << +private_id << endl;
            cout << "Private Info: " << private_info << endl;
        }
};
```

#### Memory Allocation (`new` and `delete`)
```cpp
class Test {
    int *val_ptr;

    public:
        Test *self_ptr;
        int val;
        string name;

        void print_info(void) { // print method
            cout << "name = " << name << endl;
            cout << "val = " << dec << val << endl;
            cout << "&val = " << hex << val_ptr << endl;
            cout << "&self = " << hex << self_ptr << endl;
        }
    
        // overloading the constructor (usually no printing)
        Test(int init_val, string init_name) {
            name = init_name;
            val = init_val;
            val_ptr = &val;
            
            cout << "Constructor called for " << init_name << endl;
        }
        // overloading the destructor (usually no printing)
        ~Test(void) {
            cout << "Destructor called for " << name << endl;
        }
};
```

And this code was called from `main()` as follow:
```cpp
int main(void) {
    // instantiate the object
    Test obj_a(1, "obj_a");
    obj_a.self_ptr = &obj_a;
    obj_a.print_info();
    cout << endl;

    // allocate memory for object using malloc()
    // will not call the constructor or destructor
    cout << "Creating obj_b with malloc()" << endl;
    
    Test *obj_b_ptr = (Test *) malloc(sizeof(Test));
    obj_b_ptr->name = "obj_b";
    obj_b_ptr->self_ptr = obj_b_ptr;
    
    obj_b_ptr->print_info();
    cout << endl;
    free(obj_b_ptr); // desctructor not called

    // allocate memory for object using new keyword
    Test *obj_c_ptr = new Test(3, "obj_c");
    obj_c_ptr->self_ptr = obj_c_ptr;
    obj_c_ptr->print_info();
    cout << endl;
    
    delete obj_c_ptr;   // calls the obj_c destructor

    return EXIT_SUCCESS; // runs the destructor for obj_a (out of scope)
}
```