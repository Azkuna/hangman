/***************************************************************
 *  Nombre del archivo :    main.c
 *  Autor              :    Jhon Rios
 *  Fecha de creación  :    2025-06-05
 *  Última modificación:    2025-06-05
 * 
 *  Descripción:
 *      Logica principal del juego hangman version 1.0
 *
 ***************************************************************/

#include "hangman.h"

void	ft_play_hangman(void)
{
	char	*word = NULL;
	int		error = 0;
	char	*solution;
	char	letter;
	int		index = 0;
	char	alphat[25] = {0};

	word = ft_select_word(word);
	solution = ft_fill_str(word);
	while (1)
	{
		printf("\033[H\033[J");
		printf("\033[1;33m%s\033[0m", hangman_stages[error]);
		printf("\n\033[1;36m%s\033[0m		", solution);
		printf("\033[1;36m%s\033[0m\n", alphat);
		printf("\033[1;33mIntroduzca una letra: \033[0m");
		scanf(" %c", &letter);
		if (strchr(word, letter))
		{
			ft_char_word(word, solution, letter);
			ft_update_use(alphat, letter, &index);
			if (strcmp(word, solution) == 0)
			{
				printf("\033[H\033[J");
				printf("\033[1;33m%s\033[0m", hangman_stages[error]);
				printf("\n\033[1;36m%s\033[0m\n", solution);
				printf("\033[1;32mHas ganado!!\033[0m\n");
				break ;
			}
		}
		else
		{
			error++;
			ft_update_use(alphat, letter, &index);
		}
		if (error >= 8)
		{
			printf("\033[H\033[J");
			printf("\033[1;31mGAME OVER!!\033[0m\n");
			printf("\033[1;32mLa palabra era %s\033[0m\n", word);
			break ;
		}
	}
	while (letter != '\n' && letter != EOF)
		letter = getchar();
	free(solution);
}

char	*ft_select_word(char *word)
{
	int		index;

	index = ft_random_nbr(sizeof(dictionary)/sizeof(dictionary[0]));
	word = dictionary[index];
	return (word);
}

int	ft_random_nbr(int max)
{
	srand(time(NULL));
	return (rand() % (max + 1));
}

char	*ft_fill_str(char *word)
{
	char	*result;
	int		size;
	int		i;

	size = strlen(word);
	result = (char *) malloc(size * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		result[i] = '_';
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_char_word(char *word, char *solution, char letter)
{
	int	index;

	index = 0;
	while (word[index])
	{
		if (word[index] == letter)
			solution[index] = letter;
		index++;
	}
	return (solution);
}

char	*ft_update_use(char *use, char letter, int *index)
{
	if (!strchr(use, letter))
		use[(*index)++] = letter;
	return (use);
}
