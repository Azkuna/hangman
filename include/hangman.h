
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

	char	*dictionary[] = {"casa", "jirafa", "pan", "subir", "universo",
							"papel", "elefante", "puente", "sombra", "cantar",
							"valle", "destino", "dormir", "eco", "cuadro", "pez",
							"feliz", "luna", "raton", "sabio", "lago", "piedra",
							"reir", "muralla", "silla", "foca", "tijera", "flor",
							"tierra", "miedo", "sonar", "circulo", "abeja", "puerta",
							"reloj", "zorro", "salto", "globo", "bano", "murcielago",
							"trueno", "mapa", "castillo", "sueno", "desierto", "caminar",
							"puerto", "cueva", "fuego", "duda", "arbol", "fuerza", "azul",
							"amor", "techo", "mochila", "cielo", "gato", "verde", "nube",
							"paz", "luz", "idea", "mar", "hospital", "rio", "lenteja",
							"carro", "valor", "venado", "cantar", "eco", "oceano", "corazon",
							"lobo", "jugar", "pluma", "libro", "camion", "hormiga", "brujula",
							"espiritu", "zapato", "cuerda", "camisa", "lengua", "jardin",
							"otono", "balcon", "universidad", "pelota", "pintar", "limon",
							"abeja", "mariposa", "gritar", "llegar", "correr", "palabra",
							"bailar", "teatro", "parque", "silla", "marco", "espejo",
							"salado", "reino", "juguete", "castor", "amigo", "huevo",
							"tunel", "lavar", "angulo", "canon", "leon", "botella",
							"grillo", "ventana", "jirafa", "cuerda", "oveja", "plato",
							"taza", "hierro", "nieve", "huron", "raton", "agua", "pajaro",
							"fresa", "queso", "piano", "barco", "esfera", "cola", "globo",
							"tren", "museo", "rincon", "telarana", "numero", "letra",
							"pagina", "texto", "moneda", "arbol", "palacio", "trueno",
							"monje", "monstruo", "fantasma", "bruja", "piramide", "muneca",
							"poesia", "novela", "reptil", "lenguaje", "bandera",
							"dinosaurio", "flauta", "abejorro", "caballo", "cazador",
							"telefono", "tormenta", "guitarra", "bateria", "castillo",
							"tigre", "saxofon", "ganso", "jirafa", "pasto", "cabello",
							"cepillo", "monstruo", "cohete", "robot", "muralla", "reptil",
							"avion", "juguete", "espada", "brujo", "escoba", "trampa",
							"rayo", "viento", "torre", "reloj", "boton", "gafas", "armario",
							"tristeza", "felicidad", "ventilador", "bombilla", "escalera",
							"molino", "cerebro", "telescopio", "microscopio", "espacio",
							"cometa", "nave", "extraterrestre", "ovni", "galaxia", "planeta",
							"estacion", "estadio", "cementerio", "pirata", "tesoro", "ancla",
							"barco", "caverna", "diamante", "mineral", "volcan", "erupcion",
							"lava", "glaciar", "antartida", "tropico", "selva", "pradera",
							"sabana", "caravana", "espejismo", "alquimia", "quimica",
							"biologia", "atomo", "molecula", "energia", "solar", "electrico",
							"fisica", "mecanica", "motor", "plan", "codigo", "clave",
							"secreto", "origen", "meta", "viaje", "ruta", "guia", "mapa", 
							"brujula", "cofre", "piedra", "rayo", "sol", "nube", "lluvia",
							"tormenta", "granizo", "nevado", "cascada", "charco", "barro",
							"pantano", "jungla", "reptil", "mamifero", "anfibio", "insecto",
							"ave", "pez", "crustaceo", "molusco", "murcielago", "buho", "aguila",
							"halcon", "buitre", "tarantula", "escorpion", "ciempies", "tigre",
							"pantera", "jaguar", "gacela", "gnu", "hiena", "lemur", "canguro",
							"koala", "ornitorrinco", "nutria", "morsa", "ballena", "orca",
							"tiburon", "anemona", "estrella", "medusa", "coral", "plancton",
							"fosil", "cueva", "estalactita", "estalagmita", "cristal", "gema",
							"rubi", "esmeralda", "zafiro", "topacio", "ambar", "obsidiana",
							"granito", "marmol", "yeso", "arcilla", "tierra", "polvo",
							"arena", "roca", "acantilado", "cumbre", "pico", "llanura",
							"meseta", "globo", "atlas", "buho", "raton", "duende", "hada",
							"dragon", "hechizo", "pocion", "elixir", "magia", "conjuro",
							"encanto", "hechicero", "nube", "vortice", "huracan",
							"torbellino", "remolino", "espiral", "circulo", "curva",
							"angulo", "recta", "segmento", "poligono", "hexagono"
							};

#endif