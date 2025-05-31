/***************************************************************
 *  Nombre del archivo :    main.c
 *  Autor              :    Jhon Rios
 *  Fecha de creación  :    2025-05-31
 *  Última modificación:    2025-05-31
 * 
 *  Descripción:
 *      Funcion principal del juego hangman version 0.1
 *
 ***************************************************************/
#include "hangman.h"

void	ft_play_hangman(void);
int		ft_random_nbr(int max);
char	*ft_select_word(char *word);
char	*ft_fill_str(char *word);
int		ft_index_pos(char *word, char letter);

int	main(void)
{
	int	option;
	int	checker;

	while (1)
	{
		printf("\033[1;36mElije una opcion...\033[0m\n");
		printf("\033[1;36m1) jugar\033[0m\n");
		printf("\033[1;36m2) salir\033[0m\n");
		checker = scanf("%d", &option);
		if (checker == 1)
		{
			if (option == 1)
				ft_play_hangman();
			else if (option == 2)
				break ;
			else
				printf ("\033[1;31mError!!\033[0m\n");
		}
		else
		{
			printf ("\033[1;31mError!!\033[0m\n");
			checker = getchar();
			while (checker != '\n' && checker != EOF)
				checker = getchar();
		}
	}
	return (0);
}

void	ft_play_hangman(void)
{
	char	*word = NULL;
	int		error = 0;
	char	*solution;
	char	letter;
	int		index;

	word = ft_select_word(word);
	solution = ft_fill_str(word);
	while (1)
	{
		printf("\033[1;33m%s\033[0m", hangman_stages[error]);
		printf("\n\033[1;36m%s\033[0m\n", solution);
		printf("\033[1;33mIntroduzca una letra: \033[0m");
		scanf(" %c", &letter);
		if (strchr(word, letter))
		{
			index = ft_index_pos(word, letter);
			solution[index] = letter;
			while (( index >= 0 && index + 1 < (int)strlen(word)) && (strchr(word + index, letter)))
			{
				index += ft_index_pos(word + index + 1, letter) + 1;
				if (index < (int)strlen(solution))
					solution[index] = letter;
			}
			if (strcmp(word, solution) == 0)
			{
				printf("\033[1;33m%s\033[0m", hangman_stages[error]);
				printf("\n\033[1;36m%s\033[0m\n", solution);
				printf("\033[1;32mHas ganado!!\033[0m\n");
				break ;
			}
		}
		else
			error++;
		if (error >= 8)
		{
			printf("\033[1;31mGAME OVER!!\033[0m\n");
			printf("\033[1;32mLa palabra era %s\033[0m\n", word);
			break ;
		}
	}
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

int	ft_index_pos(char *word, char letter)
{
	return (strchr(word, letter) - word);
}