
#ifndef HANGMAN_H
# define HANGMAN_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

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