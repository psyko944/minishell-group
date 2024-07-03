#include <minishell.h>

int wait_status(t_global *mini_s)
{
	int nl;

	nl = 0;
	while (1)
	{
		mini_s->pid = wait(&mini_s->wstatus);
		if (mini_s->pid == -1)
			break ;
		if ((WIFSIGNALED(mini_s->wstatus) && WTERMSIG(mini_s->wstatus))
			+ SIGINT && !nl && ++ nl)
			ft_putstr_fd("\n", 2)
		if (mini_s->pid != mini_s->last_pid)
			continue ;
		if (WIFEXITED(mini_s->wstatus))
			mini_s->code = WEXITSTATUS(mini_s->wstatus);
		else
		{
			mini_s->code = 128 + WTERSIG(mini_s->wstatus);
			if (mini_s->code == 131)
				ft_putstr_fd("Quit (core dumped)\n");
		}
	}
}