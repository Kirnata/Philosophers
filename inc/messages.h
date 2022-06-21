#ifndef MESSAGES_H
# define MESSAGES_H

/*
error_messages
*/
# define ERROR_ARGS_NUM "ERROR: Wrong number of arguments\n"
# define ERROR_VALID_ARGS "ERROR: Invalid argument: only positive integers\n"
# define ERROR_CREATE_THREAD "ERROR: Can not create thread\n"

/*
help_messages
*/
# define HELP "The number of argument must be 4 or 6:\n\
1 arg - number_of_philosophers\n\
2 arg - time_to_die\n\
3 arg - time_to_eat\n\
4 arg - time_to_sleep\n\
5 arg - number_of_times_each_philosopher_must_eat (optional)\n"

#endif