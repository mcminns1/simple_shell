#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

/************** MACROS **************/

#include "macros.h"

/********** STRUCTURES **********/

/**
 * struct info - struct for the program date
 * @program_name: the name of the executable
 * @input_line: pointer to the input read for _getline
 * @command_name: pointer to the first command typed by the user
 * @exec_counter: number of executed commands
 * @file_descriptor: file descriptor to the input of commands
 * @tokens: pointer to array of tokenized input
 * @env: copy of the environ
 * @alias_list: array of pointers with aliases
 */

typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

/**
 * struct builtins - struct for the builtins
 * @builtin: the name of the builtin
 * @function: the associated function to be called for each builtin
 */

typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
}builtins;

/********* MAIN FUNCTIONS *********/

/*======= shell.c ======*/

/* inicialize the struct with the info of the program */
void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);

/* makes the infinite loop that shows the prompt */
void sisifo(char *prompt, data_of_program *data);

/* print the prompt in a new line */
void handle_ctrl_c(int opr UNUSED);

/*====== _getline.c =======*/

/* read one line of the standard input */
int _getline(data_of_program *data);

/* split the each line for the logical operators if it exist */
int check_logic_ops(char *array_commands[], int i, char array_operators[]);

/*======= expansions.c =======*/

/* expand variables */
void expand_variables(data_of_program *data);

/* expand aliases */
void expand_alias(data_of_program *data);

/* append the string to the end of the buffer */
int buffer_add(char *buffer, char *str_to_add);

/*========= str_tok.c =========*/

/* separate the string in tokens using a designed delimiter */
void tokenize(data_of_program *data);

/* creates a pointer to a part of a string */
char *_strtok(char *line, char *delim);

/*===== execute.c =====*/

/* execute a command with its entire path */
int execute(data_of_program *data);

/*====== builtins_list.c =======*/

/* if match a builtin, executes it */
int builtins_list(data_of_program *data);

/*===== find_in_path.c =====*/

/* creates an array of the path directories */
char **tokenize_path(data_of_program *data);

/* search for program in path */
int find_program(data_of_program *data);

/*********** HELPERS FOR MEMORY MANAGEMENT **********/

/*======== helpers_free.c =========*/

/* frees the memory for directories */
void free_array_of_pointers(char **directories);

/* free the fields needed each loop */
void free_recurrent_data(data_of_program *data);

/* free all field of the data */
void free_all_data(data_of_program *data);

/************ BUILTINS *************/

/*======== builtins_more.c =========*/

/* close the shell */
int builtin_exit(data_of_program *data);

/* change the current directory */
int builtin_cd(data_of_program *data);

/* set the work directory */
int set_work_directory(data_of_program *data, char *new_dir);

/* show help information */
int builtin_help(data_of_program *data);

/* set, unset and show alias */
int builtin_alias(data_of_program *data);

/* ========== builtins_env.c ========= */

/* shows the environment where the shell runs */
int builtin_env(data_of_program *data);

/* create of override a variable of environment */
int builtin_set_env(data_of_program *data);

/* delete a variable of envronment */
int builtin_unset_env(data_of_program *data);

/************ HELPERS FOR ENVIRONMENT VARIABLES MANAGEMENT ***********/

/*======= env_management.c =======*/

/* gets the value of an environment variable */
char *env_get_key(char *name, data_of_program *data);

/* overwrite the value of the environment variable */
int env_set_key(char *key, char *value, data_of_program *data);

/* remove a key from the environment */
int env_remove_key(char *key, data_of_program *data);

/* print the current environ */
void print_environ(data_of_program *data);

/********** HELPERS FOR PRINTING **********/

/*======== helpers_print.c ========*/

/* prints a string in the standard output */
int _print(char *string);

/* prints a string in the standard error */
int _printe(char *string);

/* prints a string in the standard error */
int _print_error(int errorcode, data_of_program *data);

/******** HELPERS FOR STRINGS MANAGEMENT ********/

/*====== helpers_string.c =======*/

/* counts the number of characters of a striing */
int str_length(char *string);

/* duplicates a string */
char *str_duplicate(char *string);

/* compares two strings */
int str_compare(char *string1, char *string2, int number);

/* concatenates two strings */
char *str_concat(char *string1, char string2);

/* reverse a string */
void str_reverse(char *string);

/*======== helpers_numbers.c ========*/

/* cast from int to string */
void long_to_string(long number, char *string, int base);

/* convert a string into a number */
int _atoi(char *s);

/* count the coincidences of character in string */
int count_characters(char *string, char *character);

/*======== alias_management.c ========*/

/* print the list of alias */
int print_alias(data_of_program *data, char *alias);

/* get the alias name */
char *get_alias(data_of_program *data, char *alias);

/* set the alias name */
int set_alias(char *alias_string, data_of_program *data);


#endif
