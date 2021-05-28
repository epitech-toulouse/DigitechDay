#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ENTER "Please enter number between 1 and 300"
#define PROBLEM "Oh ! It's seem had a problem ..."
#define ABOVE "Above, try again !"
#define BELOW "Below, try again !"
#define CONGRAT "Congrate, it\'s the right number !"

int my_algo(const char* response);

int init_rand_number()
{
    int nb = 0;

    srand(time(NULL));
    nb = rand() % 300 + 1;
    return nb;
}

int referee(int secret_number)
{
    char* response = ENTER;
    int propal = -1;

    dprintf(1, "%s\n", ENTER);
    while (propal != secret_number) {        
        propal = my_algo(response);
        if (propal > secret_number) {
            response = ABOVE;
        } else if (propal < secret_number) {
            response = BELOW;
        }
    }
    dprintf(1, CONGRAT);
    return 0;
}

int main()
{
    int secret_number = 0;

    secret_number = init_rand_number();
    referee(secret_number);
    return 0;
}