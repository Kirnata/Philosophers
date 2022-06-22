/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:34:02 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/22 15:35:35 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	func(int i)
{
	if (i == 2)
		return (i);
	return (1);
}

int	main(int argc, char **argv)
{
	if (func(3) == 1)
		printf("hui\n");
	return (0);
}
