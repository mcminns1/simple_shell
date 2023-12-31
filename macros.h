#ifndef HELPERS_H
#define HELPERS_H

/* prompt to be printed */
#define PROMPT_MSG "$" /* needed to work with signal*/

/* resume from the unused attribute */
#define UNUSED __attribute__((unused))

/* buffer size for each read call in _getline */
#define BUFFER_SIZE 1024

/******** FORMATTED STRING FOR HELP BUILT IN *********/

#define HELP_CD_MSG "cd=\n"\
"cd:\tcd [dir]\n\n"\
"	Change the shell working directory.\n\n"\
"	If no argument is given to cd the command will be interpreted\n"\
"	as cd $HOME.\n"\
"	if the argument help is - (cd -), the command will be interpreted\n"\
"	as cd $OLDPWD.\n\n"

#define HELP_EXIT_MSG "exit=\n"\
"exit:\texit [STATUS]\n\n"\
"	Exit of the simple-shell.\n\n"\
"	Exits the shell with a status of N. If N is omitted, the exit status\n"\
"	is that of the last command executed.\n\n"

#define HELP_ENV_MSG "env=\n"\
"env:\tenv \n\n"\
"	print environment.\n\n"\
"	the env command will complete list of environment variables.\n\n"\

#define HELP_SETENV_MSG "setenv=\n"\
"setenv:\tsetenv VARIABLE VALUE\n\n"\
"	Change or add an environment variable.\n\n"\
"	initialize a new environment variable, or modify an existing one\n"\
"	when there are not correct numbers of arguments print error message.\n\n"

#define HELP_UNSETENV_MSG "unsetenv=\n"\
"unsetenv:\tunsetenv VARIABLE\n\n"\
"	the unsetenv function deletes one variable from the environment.\n\n"\
"	when there are not correct numbers of arguments print error message.\n\n"\

#define HELP_MSG "help=\n"\
"help:\thelp [BUILTIN_NAME]\n\n"\
"	display information about builtin commands.\n\n"\
"	displays brief summaries of builtin commands. If BUILTIN_NAME is\n"\
"	specified, gives detailed help on all commands matching BUILTIN_NAME,\n"\
"	otherwise the list of help topics is printed BUILTIN_NAME list.\n"\
"	arguments:\n\n"\
"	BUILTIN_NAME specifying a help topic.\n\n"\
"	cd\t[dir]\n"\
"	exit\t[status]\n"\
"	env\n"\
"	setenv\t[variable value]\n"\
"	unset\t[variable]\n"\
"	help\t[built_name]\n\n"\

#endif
