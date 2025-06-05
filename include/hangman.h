
#ifndef HANGMAN_H
# define HANGMAN_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

void	ft_play_hangman(void);
int		ft_random_nbr(int max);
char	*ft_select_word(char *word);
char	*ft_fill_str(char *word);
char	*ft_char_word(char *word, char *solution, char letter);
char	*ft_update_use(char *use, char letter, int *index);

const char *hangman_stages[] = {
	"  _______\n"
	" |/\n"
	" |\n"
	" |\n"
	" |\n"
	" |\n"
	"_|___\n",

	"  _______\n"
	" |/      |\n"
	" |\n"
	" |\n"
	" |\n"
	" |\n"
	"_|___\n",

	"  _______\n"
	" |/      |\n"
	" |      (_)\n"
	" |\n"
	" |\n"
	" |\n"
	"_|___\n",

	"  _______\n"
	" |/      |\n"
	" |      (_)\n"
	" |       |\n"
	" |\n"
	" |\n"
	"_|___\n",

	"  _______\n"
	" |/      |\n"
	" |      (_)\n"
	" |      \\|\n"
	" |\n"
	" |\n"
	"_|___\n",

	"  _______\n"
	" |/      |\n"
	" |      (_)\n"
	" |      \\|/\n"
	" |\n"
	" |\n"
	"_|___\n",

	"  _______\n"
	" |/      |\n"
	" |      (_)\n"
	" |      \\|/\n"
	" |       |\n"
	" |\n"
	"_|___\n",

	"  _______\n"
	" |/      |\n"
	" |      (_)\n"
	" |      \\|/\n"
	" |       |\n"
	" |      / \n"
	"_|___\n",

	"  _______\n"
	" |/      |\n"
	" |      (_)\n"
	" |      \\|/\n"
	" |       |\n"
	" |      / \\\n"
	"_|___\n"};

	char	*dictionary[] = {"camuflaje", "escuela", "ajedrez",
							"gaseoso", "lima", "zapote", "mango",
							"halcon", "cocodrilo", "eco", "corazon",
							"espuela", "dedos", "aspiradora", "luna",
							"gato", "perro", "torre", "flor", "estrella",
							"sol", "poema", "noche", "chutar", "polaco",
							"rojo", "libertad", "anarquia", "jaguar"
							};

#endif