#include "shell.h"

/**
 * free_recurrent_data - frerethe fileds needed each loop
 * @data: struct of the program's data
 * Return: Noting
 */
void free_recurrent_data(data_of_program *data)
{
	if (data->tokens)
		free_array_of_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_all_data - free al field of the data
 * @data: struct of the program's data
 * Return: Nothing
 */
void free_all_data(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->alias_list);
}

/**
<<<<<<< HEAD
 *free_array_of_pointers - frees each pointer of an array of pointers
 *and the array too
 *@array: array of pointers
 *Return: nothing
=======
 * free_array_of_pointers - frees each pointer of an
 * array of pointers and the array too
 * @array: array of pointers
 * Return: nothing
>>>>>>> 74b991a91edca32290dbea6f1161c4d1333a5bc9
 */
void free_array_of_pointers(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}
