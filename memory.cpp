#include <iostream>
#include <cstdlib>

using namespace std;

class Test {
    int *val_ptr;

    public:
        Test *self_ptr;
        int val;
        string name;

        // print method
        void print_info(void) {
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

int main(void) {
    // instantiate the object
    Test obj_a(1, "obj_a");
    obj_a.self_ptr = &obj_a;
    obj_a.print_info();
    cout << endl;

    // allocate memory for object using malloc()
    // will not call the constructor or destructor... dynamically allocated
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
    
    delete obj_c_ptr;   // calls the object destructor

    return EXIT_SUCCESS; // runs the destructor for obj_a
                         // because obj_a out of scope
}