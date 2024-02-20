#include <iostream>

#define NUM_SCOPES 3

using namespace std;

enum scope_t {
    NAMESPACE = 0,
    GLOBAL = 1,
    LOCAL = 2    
};

string scope_strs[NUM_SCOPES] = {"namespace", "global", "local"};

namespace top_level {
    enum scope_t val = NAMESPACE;     
    enum scope_t val2 = NAMESPACE;     
}

enum scope_t val = GLOBAL;
enum scope_t val2 = GLOBAL;

void identify_value(enum scope_t val, string var_name) {
    cout << var_name << " defined in " << scope_strs[val] << endl;
}

int main(void) {
    enum scope_t val = LOCAL;

    identify_value(val, "val");
    identify_value(val2, "val2");
    identify_value(top_level::val, "top_level::val");

    return EXIT_SUCCESS;
}