/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termination.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beddinao <beddinao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:20:49 by beddinao          #+#    #+#             */
/*   Updated: 2024/02/27 10:20:52 by beddinao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_en *env)
{
	int				a;

	a = 0;
	while (env->env__[a])
	{
		free(env->env__[a][0]);
		free(env->env__[a][1]);
		free(env->env__[a]);
		a += 1;
	}
	free(env->env__);
	free(env);
}

void	terminate(t_en *env, int status)
{
	if (env)
	{
		free_multible(env->__env);
		free_env(env);
	}
	exit(status);
}

void	free_multible(char **arr)
{
	int				a;

	a = 0;
	while (arr[a] != 0)
	{
		free(arr[a]);
		a += 1;
	}
	free(arr);
}

void	close_pipe(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}
