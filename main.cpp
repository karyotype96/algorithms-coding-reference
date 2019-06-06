#include <iostream>
#include <vector>

#include "utils.h"
#include "Compression/RunLengthEncoding.h"

using namespace std;

int main()
{
    string str = "yttttttttttttttttttttttttttttttttt";
    string str_encoded = RunLengthEncoding::encode(str);
    string str_decoded = RunLengthEncoding::decode(str_encoded);

    cout << "        String: " << str << endl;
    cout << "Encoded String: " << str_encoded << endl;
    cout << "Decoded String: " << str_decoded << endl;

    return 0;
}
