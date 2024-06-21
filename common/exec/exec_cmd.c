#include <minishell.h>

static void exec_cmd(t_command *cmd, t_global *env)
{
    char    *path;

    path = get_cmd(cmd->tab[0], env->envp);
    if (!path)
    {
        if (cmd->tab[0])
            ft_putstr_fd(cmd->tab[0], STDERR_FILENO);
        ft_putstr_fd(": command not found\n", STDERR_FILENO);
    }
    else
    {
        if (execve(path, cmd->tab, env->envp) == -1)
        {
            perror(path);
            exit(EXIT_FAILURE);
        }
        exit(EXIT_FAILURE);
    }
}

void cmd_runtime(t_command *cmd, t_global *env)
{
    pid_t pid;

    int fd[2];
    if (cmd->in)
        dup2(cmd->in, STDIN_FILENO);
    if (pipe(fd) == -1)
    {
        perror("pipe");
        return ;
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        return ;
    }
    else if (pid == 0)
    {
        // if (cmd->in)
        //     dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        if (cmd->out)
            dup2(cmd->out, STDOUT_FILENO);
        exec_cmd(cmd, env);
    }
    else
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
    }
}   