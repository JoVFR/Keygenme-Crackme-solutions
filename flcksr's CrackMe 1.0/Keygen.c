#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>



#pragma clang diagnostic push

/*
 * (1) 4409 is the first four digits
(2) must contain 3 8s    x
(3) must not contain a 4 x
(4) 20 digits (will be formatted to (\d{4}-){4}\d{4} x
(5) 5 or more unique digits used                                    dont need to check this, most generated keys will work...
(6) after the 4409, no consecutive repeating digits x
(7) sum of all the digits must be 104 x
(8) contain 2+ digits from [2357] x
(9) last digit must be odd x
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */



int main(void) {
    srand(time(NULL));

    while (true) {


        int sum = 0;
        bool flag8 = false;
        bool flag2357 = false;

        short flagcount8 = 0;
        short flagcount2357 = 0;
        short generated;

        int string[20];
        string[0] = 4;
        string[1] = 4;
        string[2] = 0;
        string[3] = 9;

        for (int i = 4; i < 20; i++) {
            generated = rand() % 10;
            string[i] = generated;
            if (string[i] == 4) {
                i--;
                continue;
            }
            if (string[i] == 0) {
                i--;
                continue;
            }
            if (generated == string[i - 1]) {
                i--;
                continue;
            }
        }
        for (int i = 0; i < 20; i++) {
            sum = sum + string[i];

            if (string[i] == 8)
                flagcount8++;

            if (flagcount8 == 3)
                flag8 = true;

            if (string[i] == 2 || string[i] == 3 || string[i] == 5 || string[i] == 7)
                flagcount2357++;

            if (flagcount2357 >= 2)
                flag2357 = true;
        }
        if (sum != 104)
            continue;
        if (!flag8)
            continue;
        if (!flag2357)
            continue;
        if (string[19] % 2 == 0)
            continue;
        for (int i = 0; i < 20; i++) {
            printf("%d", string[i]);
        }

        printf("\n");
       sleep(15000);

    }


}


#pragma clang diagnostic pop