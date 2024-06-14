#include <minishell.h>

static char *check_history_name(t_global *mini_s)
{
    t_env_var *tmp;
    tmp = mini_s->env;
    if (!tmp)
        return (NULL);
    while (tmp && ft_strncmp("HOME", tmp->key, 4))
        tmp = tmp->next;
    if (tmp && tmp->content)
        return (tmp->content);
    return (NULL);
}

void get_history(t_global *mini_s)
{
    char *history_filename;
    char *save_history;
    int fd;
    if (mini_s->env)
    {
        history_filename = check_history_name(mini_s);
        if (!history_filename)
            return;
    }
    history_filename = ft_strjoin3(history_filename, "/.", HISTORY_NAME);
    if (!history_filename)
        return;
    fd = open(history_filename, O_RDONLY);
    if (fd == -1)
        return (free(history_filename));
    close(fd);
    while ((save_history = get_next_line(fd)))
    {
        add_history(save_history);
        free(save_history);
    }
}