#include <iostream>

// provide namespace where variables, methods, and classes belong
using namespace std;

namespace test {
    class test_class {
        public:
            int var = 0;        /* default initialization */
    };
};

int main(void) {
    test::test_class test1;

    cout << "=== Default Value ===" << endl;
    cout << "test1.var = " << test1.var << endl;

    test1.var = 73;
    cout << "=== After Assigning 73 ===" << endl;
    cout << "test1.var = " << test1.var << endl;

    return EXIT_SUCCESS;
}