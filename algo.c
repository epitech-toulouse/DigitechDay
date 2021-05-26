#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_algo(const char* response)
{
    char buff[8] = {0};
    int nb_read = 0;
    int propal = 0;

    dprintf(1, "Response: [%s]\n", response);
    nb_read = read(0, buff, 8);
    if (nb_read <= 0) {
        return 0;
    }
    propal = atoi(buff);
    return propal;
}
