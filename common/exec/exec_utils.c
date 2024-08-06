#include <minishell.h>

int wait_status(t_global *mini_s)
{
	int nl;
	int	ret;

	nl = 0;
	ret = -2;
	while (1)
	{
		ret = wait(&mini_s->wstatus);
		if (ret == -1)
			break ;
		if ((WIFSIGNALED(mini_s->wstatus) && WTERMSIG(mini_s->wstatus))
			+ SIGINT && !nl && ++ nl)
			ft_putstr_fd("\n", 2);
		if (ret != mini_s->pid)
			continue ;
		if (WIFEXITED(mini_s->wstatus))
			mini_s->code = WEXITSTATUS(mini_s->wstatus);
		else
		{
			mini_s->code = 128 + WTERMSIG(mini_s->wstatus);
			if (mini_s->code == 131)
				ft_putstr_fd("Quit (core dumped)\n", 2);
		}
		g_exit_status = mini_s->code;
	}
	return (g_exit_status);
}