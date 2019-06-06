#ifndef RUNLENGTHENCODING_H
#define RUNLENGTHENCODING_H

#include <iostream>
#include <string>
/*
    A form of data compression where a string is shortened
    according to how many of each character there is in a row.
    In terms of decoding, I'm noticing I'm having a lot of
    trouble using regular expressions, so... for now I'll
    do it the hard way, but once I get C++'s regex functions
    down, I'll figure something out.
*/

class RunLengthEncoding
{
    public:
        static std::string encode(std::string to_encode){
            char current_symbol = to_encode[0];
            int enc_count = 1;

            std::string encoded = "";

            for (int i = 1; i < to_encode.length(); i++){
                if (to_encode[i] != current_symbol){
                    if (enc_count != 1) encoded += std::to_string(enc_count);
                    encoded += current_symbol;
                    current_symbol = to_encode[i];
                    enc_count = 1;
                } else {
                    enc_count++;
                }
            }

            if (enc_count != 1) encoded += std::to_string(enc_count);
            encoded += current_symbol;

            return encoded;
        }

        static std::string decode(std::string to_decode){
            int c_count;    // the number next to each character gets stored here
            char to_repeat; // the actual character to repeat

            int start_pos = 0;
            int end_pos = 0;

            std::string decoded = "";

            while (end_pos < to_decode.length()){
                if (std::isalpha(to_decode[end_pos])){
                    c_count = (start_pos < end_pos) ? std::stoi(to_decode.substr(start_pos, end_pos)) : 1;

                    for (int i = 0; i < c_count; i++){
                        decoded += to_decode[end_pos];
                    }

                    start_pos = end_pos + 1;
                }
                end_pos++;
            }

            return decoded;
        }
};

#endif // RUNLENGTHENCODING_H
