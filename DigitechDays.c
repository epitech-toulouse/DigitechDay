#include <stdlib.h>
#include <string.h>
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

/*int my_algo(const char* response)
{
    static int max = 300;
    static int min = 1;
    static int secret_number = 0;

    dprintf(2, "Response: [%s]\n", response);
    if (!response)
        return 0;
    if (strncmp("Above", response, strlen("Above")) == 0) {
        max = secret_number;
        secret_number -= (max - min) / 2;
    } else if ((strncmp("Below", response, strlen("Below")) == 0)) {
        min = secret_number;
        secret_number += (max - min) / 2;
    } else {
        secret_number = (max - min) / 2;
    }    
    dprintf(2, "Secret number: [%d]\n", secret_number);
    return secret_number;
}*/

int referee(int secret_number)
{
    char* response = ENTER;
    int propal = -1;

    while (propal != secret_number) {
        dprintf(1, ENTER);
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