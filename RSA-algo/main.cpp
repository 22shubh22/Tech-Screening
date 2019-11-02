// RSA applet
#include <iostream>
#include "rsa.h"

using namespace std;

// Returns gcd of a and b
int main()
{
    //message to encrypt
    RSA applet;
    double msg;
    cout << "Type a integer, message to encrypt :\n";
    cin >> msg;

    double cipher = applet.exponent(msg, applet.get_public_key(), applet.get_n());
    cout << "\nEncrypted Msg: " << cipher;

    double plain = applet.exponent(cipher, applet.get_private_key(), applet.get_n());
    cout << "\nDecrypt Msg: " << plain << '\n';
    return 0;
}