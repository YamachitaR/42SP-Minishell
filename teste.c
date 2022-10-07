
#include <stdio.h>
#include<stdlib.h>

// chdir function is declared
// inside this header
#include<unistd.h>

#include "libft/libft.h"
int main()
{
    char s[100];

    // printing current working directory
    printf("%s\n", getenv("PATH"));

    // using the command
    chdir("");

    // printing current working directory
    printf("%s\n", getcwd(s, 100));

    // after chdir is executed
    return 0;
}
