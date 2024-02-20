#include <iostream>

// using namespace std;

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
// Now don't need std::cout to use the cout method

int main() {
    cout << "cout << <Some Text Here>... works without std::cout!\n";
    
    // NOTE: Can only saying "using" <namespace> once!
    using namespace first_space;
    test();

    second_space::test();

    // always safe syntax used below
    std::cout << "Hello from std::cout!\n";
    first_space::test();
    second_space::test();
    top_name::nested_name::test();

    return EXIT_SUCCESS;
}