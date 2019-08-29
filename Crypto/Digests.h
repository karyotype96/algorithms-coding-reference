#ifndef DIGESTS_H_INCLUDED
#define DIGESTS_H_INCLUDED

/*
    A collection of hashing algorithms, all in one class space.

    A hash function is one that takes data from a source of
    variable size (like a string) and converts it to data
    of a finite size. This is done through a lot of math and
    bit twiddling, generally.
*/

union MDBuffer {
    int MDInts[4];
    char MDChars[16];
};

union Long2Chars {
    long long int MDLong;
    char MDChars[8];
};

class Digests
{
    public:

        /*
            Created by Dan Bernstein, this one updates
            the hash by running through the list, and for
            each character, the hash is multiplied by 33
            and has the value of the character added to it.
        */
        static unsigned long DJB2(std::string msg){
            unsigned long hash = 5381;

            for (int i = 0; i < msg.length(); i++){
                hash = hash * 33 + msg[i];
            }

            return hash;
        }

        /*
            Created for the SDBM database library, it does
            very well for a simple hashing algo. Much like
            above, it updates the hash for each character by
            multiplying the hash by 65599 and then adding the
            character's value.
        */
        static unsigned long SDBM(std::string msg){
            unsigned long hash = 0;

            for (int i = 0; i < msg.length(); i++){
                hash = hash * 65599 + msg[i];
            }

            return hash;
        }

        /*
            This first appeared in K&R 1st edition. It's a
            really terrible hashing algorithm, but it's
            simple and easy to implement.
        */
        static unsigned long LoseLose(std::string msg){
            unsigned int hash = 0;

            for (int i = 0; i < msg.length(); i++){
                hash += msg[i];
            }

            return hash;
        }

        /*
            One of the most famous hashing algorithms out there.
            Though it's cryptographically broken, MD5 is an
            interesting study into the nature of how a hashing
            algorithm ought to be.
        */
        static void MD5(std::string msg){
            MDBuffer buf;
            buf.MDInts[0] = 0x01234567;
            buf.MDInts[1] = 0x89abcdef;
            buf.MDInts[2] = 0xfedcba98;
            buf.MDInts[3] = 0x76543210;

            Long2Chars l2c = {msg.length()};

            std::cout << l2c.MDLong << std::endl;

            msg += (char)0x80;
            while (msg.length() % 64 != 56){
                msg += (char)0x00;
            }

            for (int i = 0; i < 8; i++){
                msg += l2c.MDChars[i];
            }

            std::cout << msg.length() << std::endl;

        }

    private:
};

#endif // DIGESTS_H_INCLUDED
