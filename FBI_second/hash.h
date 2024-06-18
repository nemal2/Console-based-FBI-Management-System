#include <iostream>
#include <openssl/sha.h>
#include <string>
#include <ctime>

using namespace std;
#pragma warning(disable : 4996)

class Hash {
public:

    static string addsalt(int len) {
        const string codec = "abcdefghijklmnopqrstuabcdefghijklmnopqrstuSFSADFSDFSDGSDGFKSDGSDNgnMASDFDSKGDNSAgmaefgSGMGKJWsgmSG3253245435634263425643572657632764712364712746712647hbcssahcbhjasbchbashbc";
        const int codec_size = codec.size();
        string Salt;
        int rand = 5234; //used a random constant to salting (Better if random variable like time can be used)

        for (int i = 0; i < len; i++) {
            Salt += codec[rand % codec_size];
        }
        return Salt;

    }


    static string hashcal(const string& password, const string& salt) {
        string saltedPassword = password + salt;

        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;

        if (SHA256_Init(&sha256) != 1) {
            cerr << "Err_initializing SHA-256" << endl;
            return "";
        }

        if (SHA256_Update(&sha256, saltedPassword.c_str(), saltedPassword.length()) != 1) {
            cerr << "Err_updating SHA-256" << endl;
            return " ";
        }

        if (SHA256_Final(hash, &sha256) != 1) {
            cerr << "Err_finalizing SHA-256" << endl;
            return " ";
        }

        char hex_hash[2 * SHA256_DIGEST_LENGTH + 1];
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            sprintf_s(hex_hash + 2 * i, 3, "%02x", hash[i]);
        }

        return hex_hash;
    }
};


