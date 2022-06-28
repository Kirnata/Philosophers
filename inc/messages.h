/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptopping <ptopping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:41:20 by ptopping          #+#    #+#             */
/*   Updated: 2022/06/28 20:52:06 by ptopping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

/*
error_messages
*/
# define ERROR_ARGS_NUM      "ERROR: Wrong number of arguments\n"
# define ERROR_VALID_ARGS    "ERROR: Invalid arguments: only positive integers\n"
# define ERROR_CREATE_THREAD "ERROR: Can not create thread\n"
# define ERROR_MX_INIT       "ERROR: mutex init has failed\n"
# define FOR_HELP            "Enter help for more information\n"

/*
help_messages
*/
# define HELP_MSG "The number of argument must be 4 or 6:\n\
1 arg - number_of_philosophers\n\
2 arg - time_to_die\n\
3 arg - time_to_eat\n\
4 arg - time_to_sleep\n\
5 arg - number_of_times_each_philosopher_must_eat (optional)\n"

/*
life_circle_messages
 */
# define EAT_MSG   "is eating 🥣\n"
# define SLEEP_MSG "is sleeping\n"
# define THINK_MSG "is thinking\n"
# define TAKE_L_F  "has taken a right fork\n"
# define TAKE_R_F  "has taken a left fork\n"
# define DEAD      "IS DEAD 💀\n"
#endif