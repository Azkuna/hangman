/***************************************************************
 *  Nombre del archivo :    main.c
 *  Autor              :    Jhon Rios
 *  Fecha de creación  :    2025-05-31
 *  Última modificación:    2025-06-05
 * 
 *  Descripción:
 *      Funcion principal del juego hangman version 1.0
 *
 ***************************************************************/

#include <stdio.h>
#include <unistd.h>

void	ft_play_hangman(void);

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
