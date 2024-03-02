/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:20:49 by beddinao          #+#    #+#             */
/*   Updated: 2024/03/01 23:53:07 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_shell_exit_status(int err)
{
	if (err == 2)
		return (127);
	else if (err == 13)
		return (126);
	return (err);
}

int	count_digits_in_int(int num)
{
	int			a;

	a = 0;
	if (!num)
		return (1);
	while (num)
	{
		num /= 10;
		a++;
	}
	return (a);
}

void	free_environment_variables(t_env *env)
{
	int				a;

	a = 0;
	while (env->parsed_env[a])
	{
		free(env->parsed_env[a][0]);
		free(env->parsed_env[a][1]);
		free(env->parsed_env[a]);
		a += 1;
	}
	free(env->parsed_env);
	free(env);
}

void	cleanup_and_exit_shell(t_env *env, int status)
{
	if (env)
	{
		free_string_array(env->original_env);
		free_environment_variables(env);
	}
	exit(status);
}

void	close_pipe_ends(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
