#include <signal.h>

static void	handle_sigint(int sig)
{
	
}

static void	handle_sigquit(int sig)
{
	(void)sig;
	return ;
}

void	init_signals(void)
{
	signal(SIGQUIT, handle_sigquit);
}