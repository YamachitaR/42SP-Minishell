
#include <stdio.h>
#include<stdlib.h>

# define EXIT_FAILURE 1
# define EXIT_SUCESS 0
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define SPECIAL "&\\()*;"

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

#include<unistd.h>

#include "libft/libft.h"

int main(void)
{
    int piper[2];
    int savefd;

    savefd = dup(STDOUT);
    pipe(piper);
    dup2(piper[1], 1);
    write (1, "C", 1);

    dup2(piper[0], STDIN);
    dup2(savefd, 1);
    close(piper[0]);
    close(piper[1]);

    pipe(piper);
    write (1, "A", 1);
    dup2(piper[0], STDIN);
    dup2(savefd, 1);
}











