#include <iostream>

using namespace std;

#define PUBLIC_KEY      0xABCDEF
#define PUBLIC_KEY2     0xDECAFBAD
#define PRIVATE_KEY     0xDEFACED

#define PRIVATE_PARENT  0   /* 0: Parent class is a private class,
                               1: Parent class is a public class */

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

#if PRIVATE_PARENT
class PubPriVault : private PubVault {
#else 
class PubPriVault : public PubVault {
#endif
    uint64_t private_key;
    uint8_t private_id;
    string private_info;

    public:
        PubPriVault(uint64_t priv_key, uint8_t priv_id, string priv_info,
                    uint64_t pub_key, uint8_t pub_id, string pub_info) 
                    : PubVault(pub_key, pub_id, pub_info) { // inheritance from parent class
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

int main(void) {

    cout << "=== Example of Parent Class Only ===\n";
    PubVault vault(PUBLIC_KEY, (uint8_t)23, "public");
    vault.print_public_info();
    cout << endl;

    cout << "=== Example of Inheritance ===\n";
    PubPriVault vault2(PRIVATE_KEY, (uint8_t) 24, "private",
                       PUBLIC_KEY2, (uint8_t)66, "public2");

#if PRIVATE_PARENT
    vault2.print_all_info();
#else
    vault2.print_public_info();
    vault2.print_private_info();
#endif

    return EXIT_SUCCESS;
}