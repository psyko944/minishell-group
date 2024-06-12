#include "builtins.h"

static bool check_option(char *cmd)
{
    int i;

    if (*cmd != '-')
        return (false);
    i = 1;
    while (cmd[i] == 'n')
        i++;
    if (!cmd[i])
        return (true);
    return (false);
}

void mini_echo(int ac, char **av)
{
    int i;
    bool n_line;

    n_line = true;
    i = 1;
    while (av[i] && check_option(av[i]))
    {
        n_line = false;
        i++;
    }
    while (av[i])
    {
        printf("%s", av[i++]);
        if (i < ac)
            printf(" ");
    }
    if (n_line)
        printf("\n");
}