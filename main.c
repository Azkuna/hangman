/*
un menu que le de la opcion al usuario de jugar o salir
al jugar se elije una palabra del diccionario de manera 'aleatoria'
pedirle al usuario que introduzca un caracter o resuelva
veririficar si la opcion introducida por el usuario es correcta
si es correcta ponerla en la solucion y si no dibujar el ahorcado
si hay mas de 6 errores el juego termina game over
*/

#include "hangman.h"

void	ft_play_hangman(void);
int		ft_random_nbr(int max);
char	*ft_select_word(char *word);
char	*ft_fill_str(char *word);
int	ft_index_pos(char *word, char letter);

int	main(void)
{
	int	option;

	while (1)
	{
		printf("Elije una opcion...\n");
		printf("1) jugar\n");
		printf("2) salir\n");
		scanf("%d", &option);
		if (option == 1)
			ft_play_hangman();
		else if (option == 2)
			break ;
		else
			printf ("Error!!\n");
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
		printf("%s", hangman_stages[error]);
		printf("\n%s\n", solution);
		printf("Introduzca una letra: ");
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
				printf("%s", hangman_stages[error]);
				printf("\n%s\n", solution);
				printf("Has ganado!!\n");
				break ;
			}
		}
		else
			error++;
		if (error >= 8)
			break ;
	}
	free(solution);
}

char	*ft_select_word(char *word)
{
	int		index;
	char	*dictionary[] = {"Camuflaje", "Escuela", "Ajedrez",
							"Gaseoso", "Lima", "Zapote", "Mango",
							"Halcon", "Cocodrilo", "Eco", "Corazon",
							"Escuela", "Dedos", "Aspiradora", "Luna"
							};
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