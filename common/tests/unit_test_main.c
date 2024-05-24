/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:29:04 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/24 17:29:26 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	unit_tests_armand(int ac, char **av, char **envp);
void    unit_test_mehdi(int ac, char **av, char **envp);

int	main(int ac, char **av, char **envp)
{
	unit_tests_armand(ac, av, envp);
	unit_test_mehdi(ac, av, envp);
}
