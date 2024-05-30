#include "minishell.h"

int    check_history_name(t_global *mini_s, char *history_name)
{
    int fd;

    fd = open(history_name, O_RDONLY);
    if (fd == -1)
        return (fd);
}

void    get_history(t_global *mini_s)
{
    char    *history_filename;
    char    *save_history;    
    int     fd;
    if (mini_s->env)
    {
        t_env_var *tmp;
        tmp = mini_s->env;
        while (tmp && ft_strncmp("HOME", tmp, 4))
            tmp = tmp->next;
        if (tmp && tmp->content)
            history_filename = tmp->content;
    }
    history_filename = ft_strjoin2(history_filename,"/.",HISTORY_NAME);
    if (!history_filename)
        return ;
    fd = open(history_filename, O_RDONLY);
    if (fd == -1)
        return ;
    free(history_filename);
    while (save_history = get_next_line(fd))
    {
        add_history(save_history);
        free(save_history);
    }
}