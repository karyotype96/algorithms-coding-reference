#ifndef CIPHERS_H_INCLUDED
#define CIPHERS_H_INCLUDED

#include <iostream>
#include <string>
#include <cmath>

std::string baconian[] = { "AAAAA", "AAAAB", "AAABA", "AAABB",
                            "AABAA", "AABAB", "AABBA", "AABBB",
                            "ABAAA", "ABAAB", "ABABA", "ABABB",
                            "ABBAA", "ABBAB", "ABBBA", "ABBBB",
                            "BAAAA", "BAAAB", "BAABA", "BAABB",
                            "BABAA", "BABAB", "BABBA", "BABBB",
                            "BBAAA", "BBAAB" };

std::string b64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

class Ciphers
{
    public:

        // The Caesar cipher is one of the simplest ciphers, as well as one of the
        // earliest. Encoding some text is simple: choose a number to "rotate" each
        // letter by, and do that with every letter. For instance, if the rotation
        // count is 5, A becomes E, B becomes F, and so on. If we count past Z, we
        // start from A again, so W becomes A, X becomes B, and so on.
        static std::string CaesarCipher(std::string msg, unsigned int rotCount){
            std::string new_msg = "";
            for (int i = 0; i < msg.length(); i++){
                if (isupper(msg[i])){
                    new_msg += (((msg[i] - 'A') + rotCount) % 26) + 'A';
                } else if (islower(msg[i])){
                    new_msg += (((msg[i] - 'a') + rotCount) % 26) + 'a';
                } else {
                    new_msg += msg[i];
                }
            }

            return new_msg;
        }

        // Rail-fence is a simple cipher. First, we zig-zag each letter through a "fence"
        // of the size we choose, where the size of the fence is the key. If we encode the
        // message "attackatdawn" using a fence of size 3, we visualize it like this:

        //  a . . . c . . . d . . .
        //  . t . a . k . t . a . n
        //  . . t . . . a . . . w .

        // With that, we read the fence, line by line, into the output string, so the
        // message "attackatdawn" with a fence size of 3 turns into "acdtaktantaw".
        static std::string RailFenceEncode(std::string msg, unsigned int key){
            std::string fence[key];
            std::string new_msg = "";
            bool move_back = false;
            unsigned int current_row = 0;

            for (int i = 0; i < msg.length(); i++){
                if (move_back && current_row == 0)
                    move_back = false;
                if (!move_back && current_row == key-1)
                    move_back = true;

                fence[current_row] += msg[i];

                if (move_back) current_row--;
                else current_row++;
            }

            for (int i = 0; i < key; i++){
                new_msg += fence[i];
            }

            return new_msg;
        }

        // Atbash is a ridiculously simple encoding. The idea is that A is replaced
        // by Z, B is replaced by Y, and so on. Basically, it maps each letter from
        // A-Z to Z-A.
        static std::string AtbashEncode(std::string msg){
            std::string new_msg = "";

            for (int i = 0; i < msg.length(); i++){
                if (isupper(msg[i])) new_msg += (char)('Z' - (msg[i] - 'A'));
                else if (islower(msg[i])) new_msg += (char)('z' - (msg[i] - 'a'));
                else new_msg += msg[i];
            }

            return new_msg;
        }

        static std::string BaconianEncode(std::string msg){
            std::string new_msg = "";

            for (int i = 0; i < msg.length(); i++){
                if (toupper(msg[i]) < 'A' || toupper(msg[i]) > 'Z'){
                    new_msg += msg[i];
                    continue;
                }
                new_msg += baconian[toupper(msg[i]) - 'A'];
            }

            return new_msg;
        }

        static std::string Base64Encode(std::string msg){
            std::string new_msg = "";
            int block_count = (int)ceil(msg.length() / 3.0);
            int overwrite = (msg.length() % 3 == 0) ? 0 :
                            (msg.length() % 3 == 1) ? 2 : 1;
            char byte_buffer[3];
            char block_buffer[4];

            for (unsigned int i = 0; i < block_count; i++){
                byte_buffer[0] = msg[i * 3];
                if (i * 3 + 1 >= msg.length())
                    byte_buffer[1] = 0;
                else
                    byte_buffer[1] = msg[i * 3 + 1];

                if (i * 3 + 2 >= msg.length())
                    byte_buffer[2] = 0;
                else
                    byte_buffer[2] = msg[i * 3 + 2];

                block_buffer[0] = BLOCK1(byte_buffer);
                block_buffer[1] = BLOCK2(byte_buffer);
                block_buffer[2] = BLOCK3(byte_buffer);
                block_buffer[3] = BLOCK4(byte_buffer);

                for (int b = 0; b < 4; b++){
                    new_msg += b64chars[block_buffer[b]];
                }
            }

            if (overwrite == 1){
                new_msg[new_msg.length() - 1] = '=';
            } else if (overwrite == 2){
                new_msg[new_msg.length() - 1] = '=';
                new_msg[new_msg.length() - 2] = '=';
            }

            return new_msg;
        }

    private:
        // get the first 6 bits of the block
        static char BLOCK1(char block[]){
            return (block[0] >> 2) & 0b111111;
        }

        static char BLOCK2(char block[]){
            return ((block[0] & 0b11) << 4) | ((block[1] >> 4) & 0b1111);
        }

        static char BLOCK3(char block[]){
            return ((block[1] & 0b1111) << 2) | ((block[2] >> 6) & 0b11);
        }

        static char BLOCK4(char block[]){
            return ((block[2] & 0b111111));
        }
};

#endif // CIPHERS_H_INCLUDED
