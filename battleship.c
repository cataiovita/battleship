#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Functie initializare mod ncurses;
void getNcursed(void)
{
	initscr();
	clear();
	noecho();
	cbreak();
	start_color();
}

// Functia de verificare integritate harti citite;
void readCheckFile(int argc, char **argv, FILE *gridfile)
{
	if (argc != 6)
	{
		printf("[Eroare]: Nu s-au dat numar argumente necesare de comanda.\n");
		printf("[Help]: Ruleaza cu %s <map1>...<map5>.\n", argv[0]);
		exit(1);
	}

	if (argv[1] == NULL)
	{
		printf("[Eroare]: Fisierul de configuratie nu poate fi citit.\n");
		exit(1);
	}
}

// Functie pentru culorile utilizate in interfata grafica;
void getColors(void)
{
	init_pair(1, COLOR_CYAN, COLOR_WHITE);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
}

// Logo Battleship fereastra initiala;
void logoBattleShip(void)
{
	int i;
	attron(A_BLINK | A_BOLD);

	mvprintw(4, 60," _____"); 
 	mvprintw(5, 60,"|  _  )");
 	mvprintw(6, 60,"| |_|_)   ");
 	mvprintw(7, 60,"|  __)   ");
 	mvprintw(8, 60,"| |_| )   ");
 	mvprintw(9, 60,"|_____)  ");  
 
	mvprintw(6, 70,"  __ _ ");
 	mvprintw(7, 70," / _` |");
 	mvprintw(8, 70,"| (_| |");
 	mvprintw(9, 70," \\__,_|");

	mvprintw(4, 80,"  _");
 	mvprintw(5, 80," | |");
 	mvprintw(6, 80,"|_ _|");
 	mvprintw(7, 80," | |");
 	mvprintw(8, 80," | |");
 	mvprintw(9, 80," |_|");

	mvprintw(4, 88,"  _");
 	mvprintw(5, 88," | |");
 	mvprintw(6, 88,"|_ _|");
 	mvprintw(7, 88," | |");
 	mvprintw(8, 88," | |");
 	mvprintw(9, 88," |_|");

	mvprintw(4, 96,"  _");
 	mvprintw(5, 96," | |");
 	mvprintw(6, 96," | | ");
 	mvprintw(7, 96," | |");
 	mvprintw(8, 96," | |");
 	mvprintw(9, 96," |_|");
 
 	mvprintw(6, 104,"  ___ ");
 	mvprintw(7, 104," / _ \\");
 	mvprintw(8, 104,"|  __/");
 	mvprintw(9, 104," \\___|");

 	mvprintw(4, 116, "   ____");
 	mvprintw(5, 116, "  /  __/  ");
 	mvprintw(6, 116, " |  |     ");
 	mvprintw(7, 116, "  \\ \\");
 	mvprintw(8, 116, "  __\\ \\");
 	mvprintw(9, 116,  "/_____/");

 	mvprintw(5, 126, "  _    ");
 	mvprintw(6, 126, " | |     ");
 	mvprintw(7, 126, " | |__   ");
 	mvprintw(8, 126, " | | ||   ");
 	mvprintw(9, 126, " |_| ||   ");

	mvprintw(4, 136, "  _ ");
 	mvprintw(5, 136, " (_)");
 	mvprintw(6, 136, "  _ ");
 	mvprintw(7, 136, " | | ");
 	mvprintw(8, 136, " | | ");
 	mvprintw(9, 136, " |_| ");

	mvprintw(4, 144, "    ");
 	mvprintw(5, 144, "  ___  ");
 	mvprintw(6, 144, " | _ ) ");
 	mvprintw(7, 144, " |  _)");
 	mvprintw(8, 144, " | |");
 	mvprintw(9, 144, " |_|");

 	attroff(A_BLINK | A_BOLD );

 	for (i = 50; i < 88; i++)
 	{
 		mvprintw(25, i, "~");
 	}

 	for (i = 26; i < 45; i++)
 	{
 		mvprintw(i, 50, "|");
 	}

 	for (i = 117; i < 155; i++)
 	{
 		mvprintw(25, i, "~");
 	}

 	for (i = 26; i < 45; i++)
 	{
 		mvprintw(i, 154, "|");
 	}

 	for (i = 50; i < 155; i++)
 	{
 		mvprintw(45, i, "~");
 	}

}

// Informatii legate de jocul Battleship, introduse in meniu - Info;
void getInfo(void)
{
	mvprintw(15, 45, "Battleship (also Battleships or Sea Battle)\
 is a strategy type guessing game for two players. It is played");
	mvprintw(16, 40, "on ruled grids (paper or board) on which each player's\
 fleet of ships (including battleships) are marked.");
	mvprintw(17, 40, "The locations of the fleets are concealed from the other\
player. Players alternate turns calling shots at the");
	mvprintw(18, 40, "other board game by Milton Bradley in 1967\
. The game has spawned electronic versions, video games, smart device apps and\
 a film. ");
	mvprintw(19, 45, "The game of Battleship is thought to have\
 its origins in the French game L'Attaque\
 played during World War I");
	mvprintw(20, 40, "although parallels have also been drawn to\
 E. I. Horsman's 1890 game Basilindaq and\
 the game is said to have been");
 	mvprintw(21, 40, "played by Russian officers before World War I.\
 The first commercial version of the game was Salvo, published in 1931");
  	mvprintw(22, 40, "in the United States by the Starex company.\
 Other versions of the game were printed in the 1930s and 1940s, including");
	mvprintw(23, 40, "the Strathmore Company's Combat: The Battleship Game\
 ,Milton Bradley's Broadsides: A Game of Naval Strategy and Maurice");
 	mvprintw(24, 40, "L. Freedman's Warfare Naval Combat. Strategy Games Co.\
  produced a version called Wings which pictured planes flying");
 	mvprintw(25, 40, "over the Los Angeles Coliseum. All of these early\
  editions of the game consisted of pre-printed pads of paper.");
	mvprintw(26, 45, "Battleship was one of the earliest games to be produced\
  as a computer game, with a version being released for the Z80");
  	mvprintw(27, 40, "Compucolor in 1979. Many computer editions of the game\
  have been produced since. In Clubhouse Games for the Nintendo DS");
  	mvprintw(28, 40, "Battleship is known as Grid Attack. It is played on an\
 	10x10 grid, and includes slight variations, such as 4-player");
 	mvprintw(29, 40,"gameplay, and various ship sizes and shapes.\
 Versions of Battleship appear as applications on numerous social networking.");
	attron(A_BOLD);
	mvprintw(7, 85, "Battleship - Game and history");
	mvprintw(44, 87, "Press any key to get back.");	
	attroff(A_BOLD);
}

// Functie atribute meniu si modificari aduse asupra stringurilor din
// interiorul box-ului de meniu;
void menuAtts(WINDOW *menu, char **menuopt, int lighted)
{
	int border, up;
	int i;

	border = 11;
	up = 2;
	
	char sign2[] = ">|";	
	char sign4[] = "|<";

	int sign = 172;
	char cleared = ' ';
	char c = '-';
	char l = '|';
	box(menu, l, c);

	for (i = 0; i < 4; i++)
	{
		up = up + 3;

		mvwprintw(menu, up, border - 4, "%c", sign);
		
		wrefresh(menu);

		if (lighted == i + 1)
		{
			mvwprintw(menu, up, border - 2, "%s", sign2);
			mvwprintw(menu, up, border + strlen(menuopt[i]), "%s", sign4);
			wattron(menu, A_BOLD | A_REVERSE);
			mvwprintw(menu, up, border, "%s", menuopt[i]);
			wattroff(menu, A_BOLD | A_REVERSE);
		}
		
		else
		{
			wattron(menu, A_BOLD);
			mvwprintw(menu, up, border, "%s", menuopt[i]);
			mvwprintw(menu, up, border - 1, "%c", cleared);
			mvwprintw(menu, up, border - 2, "%c", cleared);
			mvwprintw(menu, up, border + strlen(menuopt[i]), "%c", cleared);
			mvwprintw(menu, up, border + strlen(menuopt[i]) + 1, "%c", cleared);
			wattroff(menu, A_BOLD);
		}
	}
	
	wrefresh(menu);
}

// Functia prin care se poate naviga in interiorul meniului, impreuna cu toate
// cazurile de utilizare a butoanelor;
int menuControl(WINDOW *menu, char **menuopt, int selectch, int lighted,
									int goexit, int *getInfo, int *resume)
{	
	int res = 0;
	int f = 0;
	while (1)
	{
		selectch = wgetch(menu);
		switch(selectch)
		{
			case KEY_UP:
				if (lighted == 1)
				{
					lighted = 4;
				}
				
				else 
				{
					--lighted;
				}

				break;

			case KEY_DOWN:
				if (lighted == 4)
				{
					lighted = 1;
				}

				else
				{
					++lighted;
				}
				break;

			case 10:
				goexit = 1;
				break;

			default:
				attron(A_BOLD);
				mvprintw(14, 91, "You can select an option");
				mvprintw(15, 88, "pressing your keyboard's arrows.");
				attroff(A_BOLD);
				refresh();
				break;
		}
		
		menuAtts(menu, menuopt, lighted);

		if (lighted == 4 && goexit == 1)
		{
			return 1;
		}
		
		else if (lighted == 1 && goexit == 1)
		{
			break;
		}

		else if (lighted == 3 && goexit == 1)
		{		
			f = 1;
			break;
		}
	
		else if (lighted == 2 && goexit == 1)
		{
			res = 1;
			break;
		}
	}
	*resume = res;
	*getInfo = f;
}

// Functia pentru completare grid propriu din interiorul fisierului de intrare,
// configurat, si marcare pe fiecare pozitie la care se afla X o barca pe inter
// fata grafica;
void completeMyGrid(FILE *gridfile, char **argv, int gridch, char **ships)
{
	int i = 0, j = 0;
	time_t t;

	int x = 0;
	srand((unsigned) time(&t));

	while (x == 0)
	{
		x = rand() % 6;
	}

	gridfile = fopen(argv[x], "r");

	do {
		gridch = fgetc(gridfile);

        if (gridch == 'X' || gridch == ' ')
        {
        	ships[i][j] = gridch;      
        	j++;
        } 

        if (gridch == '\n')
        {
        	i++;
        	j = 0;
        }

    } while (gridch != EOF);

    fclose (gridfile);
 	
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
     	{
			if (ships[i][j] == 'X')
			{
				attron(A_BOLD);
				mvprintw(4 * i + 10, 6 * j + 134, ".|.");
				refresh();
				attroff(A_BOLD);
			}
		}
    }
}

// Creare scheletul primului grid in interiorul ferestrei, (gridul PC-ului);
void gridstMake(void)
{
	int i, j, n;

	for (i = 8; i < 49; i++)
	{
		for (n = 8; n < 78; n++)
		{
			if (n % 6 == 0)
			{
				mvaddch(i, n, '|');
			}
		}

		if (i % 4 == 0)
		{
			for (j = 12; j < 73; j++)
			{
				mvaddch(i, j, '-');
			}
		}
	}

	refresh();
}

// Creare a scheletului celui de-al doilea grid (grid personal);
void gridndMake(void)
{
	int i, j, n;

	for (i = 8; i < 49; i++)
	{
		for (n = 130; n < 194; n++)
		{
			if (n % 6 == 0)
			{
				mvaddch(i, n, '|');
			}
		}

		if (i % 4 == 0)
		{
			for (j = 132; j < n - 1 ; j++)
			{
				mvaddch(i, j, '-');
			}
		}
	}

	refresh();
}

// Functia de navigare prin gridul PC-ului.
char jumpThroughGrid(int gridch, char **opships, int *hitted, int hittedat,
												int *DIA, int *AUTO)
{
	int conter = 0;
	int y = 10;
	int x = 15;
	int pressEnter[100] = {0};
	int i = 0;
	int getExit = 0;
	int getDIA = 0;
	int getAUTO = 0;

	hittedat = 0;
	move(y, x);	

	keypad(stdscr, TRUE);

	while (1)
	{
		if (*hitted == 20)
		{
			break;
		}
		// Ia un caracter de la tastatura;
		gridch = getch();

			switch(gridch)
			{
				// Cazul enter;
				case 10:
					pressEnter[i]++;
					break;
				
				// Cazurile sagetilor de navigare;
				case KEY_UP:
					if (y == 14 || y == 18 || y == 22 || y == 26 || y == 30 
					    || y == 34 || y == 38 || y == 42 || y == 46)
					{
						move(y = y - 4, x);
					}
					break;

				case KEY_DOWN:
					if (y == 10 || y == 14 || y == 18 || y == 22 || y == 26
					    || y == 30 || y == 34 || y == 38 || y == 42)
					{
						move(y = y + 4, x);
					}
					break;

				case KEY_LEFT:
					if (x == 21 || x == 27 || x == 33 || x == 39
					   	|| x == 45 || x == 51 || x == 57 || x == 63 || x == 69)
					{
						move(y, x = x - 6);
					}
					break;

				case KEY_RIGHT:
					if (x == 15 || x == 21 || x == 27 || x == 33 || x == 39
						|| x == 45 || x == 51 || x == 57 || x == 63)
					{
						move(y, x = x + 6);
					}
					break;		
				
				// Cazul tastei q de break a functiei;
				case 113:
					getExit++;
					break;
				// Cazul de selectie a optiunii Destroy in Advance;
				case 100:
					getDIA = 1;
					break;
				// Cazul optiunii Randomize;
				case 114:
					break;
				case 97:
					getAUTO = 1;
					break;
		}

		// Verific la fiecare apasare a tastei Enter in interiorul gridului
		// daca locul in care apas este ocupat de vruen caracter (X), iar apoi
		// printez la pozitia aceea caracterul cu rosu;
		if (pressEnter[i] == 1 && mvinch(y, x - 1) == ' ')
		{
			attron(A_BOLD | COLOR_PAIR(4));
			
			mvprintw(y, x - 1, ".|.");
			
			refresh();

			attroff(A_BOLD | COLOR_PAIR(4));
			i++;
	
			attron(A_INVIS);		
			mvprintw(y - 1, x, "o");
			attroff(A_INVIS);

			break;
		}

		// In cazul in care se afla caracterul X in matrice, plasez barca cu
		// o culoare de verde;
		if (pressEnter[i] == 1 && mvinch(y, x - 1) != ' ' 
									&& mvinch(y - 1, x) == ' ')
		{
			
			conter++;
		
			attron(A_BOLD | COLOR_PAIR(5));
			
			mvprintw(y, x - 1, ".|.");
			
			refresh();
			

			attroff(A_BOLD | COLOR_PAIR(5));
			i++;

			attron(A_INVIS);		
			mvprintw(y - 1, x, "o");
			attroff(A_INVIS);
			
			move(y, x);	
			hittedat++;
		}

		// La fiecare iteratie, returnez la un pointer valoarea numarului de 
		// barci pe care le-am nimerit;
		if (*hitted + conter == 20)
		{
			break;
		}

		// Pun conditia ca o celula sa nu poata fi reapasata;
		if (pressEnter[i] == 1 && mvinch(y, x - 1) != ' '
									 && mvinch(y - 1, x) != ' ')
		{
			pressEnter[i] = 0;
			mvprintw(10, 90, "You should try another cell");
			
			move(y, x);
		}

		if (pressEnter[i] == 1 && mvinch(y, x - 1) != ' ' 
									 && mvinch(y - 1, x) == ' ')
		{
			pressEnter[i] = 0;
			mvprintw(10, 90, "You should try another cell");
			move(y, x);
		}

		// Returnez o conditie de oprire;
		if (getExit == 1)
		{
			return -2;
			break;
		}

		if (getAUTO == 1)
		{
			break;
		}
		// Salvez intr-o variabila precedata de conditia apasarii tastei R,
		// si plasez o optiune de break pentru a-mi opera Destroy in Advance;
		if (getDIA == 1)
		{			
			break;
		}
	}
	*hitted += hittedat;
	*DIA = getDIA;
}

// Functia de umplere cu spatii ' ' a matricei in care operez;
void getEmpty(char **opships)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			opships[i][j] = ' ';
		}
	}
}

// Functia principala pentru randomizare: bordez fiecare barca creata, in jurul
// ei cu caractere de 0, pentru a evita o suprapunere.
void getBordered(char **opships, int *count, int *dir, int *lenght, int k)
{
	time_t t;

	int x, y;
	int i;

	srand((unsigned) time(&t));

	// Randomizez doua numere ce reprezinta coordonatele de pe matrice;
	x = rand() % 10;
	y = rand() % 10;
	
	while (count[k] != 0)
	{
		// Randomizez o directie posibila: SUS, JOS, STANGA. DREAPTA;
		dir[k] = rand() % 4;
		// directia SUS = 0;
		if (opships[x][y] == ' ' && opships[x][y + lenght[k] - 1] == ' ')
		{
			if (dir[k] == 0 && x > lenght[k] - 2 && 
							opships[x - lenght[k]][y] == ' ')
			{
				for (i = 0; i < lenght[k]; i++)
				{
					opships[x - i][y] = 'X';
					count[k]--;

					opships[x - i][y + 1] = '0';
					opships[x - i][y - 1] = '0';
					
					opships[x - lenght[k]][y - 1] = '0';
					opships[x - lenght[k]][y + 1] = '0';
					
					opships[x - lenght[k]][y] = '0';
					opships[x + 1][y] = '0';
					
					opships[x + 1][y - 1] = '0';
					opships[x + 1][y + 1] = '0';
				}
			}
			// Directia JOS = 1;
			if (dir[k] == 1 && x < 11 - lenght[k] && 
							opships[x + lenght[k] - 1][y] == ' ')
			{
				for (i = 0; i < lenght[k]; i++)
				{
					opships[x + i][y] = 'X';
					count[k]--;

					opships[x + i][y - 1] = '0';
					opships[x + i][y + 1] = '0';
					
					opships[x + lenght[k]][y + 1] = '0';
					opships[x + lenght[k]][y - 1] = '0';
					
					opships[x + lenght[k]][y] = '0';
					opships[x - 1][y] = '0';
					
					opships[x - 1][y + 1] = '0';
					opships[x - 1][y - 1] = '0';
				}
			}

			// Directia STANGA = 2;
			if (dir[k] == 2 && y > lenght[k] - 1 &&
							opships[x][y - lenght[k] - 1] == ' ')
			{
				for (i = 0; i < lenght[k]; i++)
				{
					opships[x][y - i] = 'X';
					count[k]--;
					// jos si sus boarding;
					opships[x + 1][y - i] = '0';
					opships[x - 1][y - i] = '0';
					
					// colturi; 
					opships[x - 1][y - lenght[k]] = '0';
					opships[x + 1][y - lenght[k]] = '0';
					
					// laturi;
					opships[x][y - lenght[k]] = '0';
					opships[x][y + 1] = '0';
					
					// langa laturi;
					opships[x - 1][y + 1] = '0';
					opships[x + 1][y + 1] = '0';
				}
			}

		// Directia DREAPTA = 3;
			if (dir[k] == 3 && y < 11 - lenght[k] &&
							   opships[x][y + lenght[k] - 1] == ' ')
			{		
				for (i = 0; i < lenght[k]; i++)
				{
					opships[x][y + i] = 'X';
					count[k]--;
				
					opships[x + 1][y + i] = '0';
					opships[x - 1][y + i] = '0';
					
					opships[x - 1][y + lenght[k]] = '0';
					opships[x + 1][y + lenght[k]] = '0';
					
					opships[x][y + lenght[k]] = '0';
					opships[x][y - 1] = '0';
					
					opships[x - 1][y - 1] = '0';
					opships[x + 1][y - 1] = '0';
				}
			}
		
			else
			{
				x = rand() % 10;
				y = rand() % 10;
			}
		}
		
		else
		{
			x = rand() % 10;
			y = rand() % 10;
		}
	}
}

// Creez barcile oponentului in functie de bordare si numar barci + lungime;
void createOpShips(char **opships, int *count, int *dir, int *lenght, int k)
{
	int i;
	k = 0;
	lenght[k] = 4;

	for (i = 0; i < 4; i++)
	{
		dir[k] = rand() % 4;
		count[k] = 4;
		
		if (i == 1 || i == 2)
		{
			count[k] += 2;
		}

		getBordered(opships, count, dir, lenght, k);

		k++;
		lenght[k] = lenght[k - 1] - 1;
	}
}

// Printez pe grid, interfata grafica fiecare barca stabilita la o proportie de
// lungimi;
void printOpShip(char **opships)
{
	int i, j;

	for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
     	{
     		if (opships[i][j] == 'X')
     		{
				attron(A_BOLD | A_INVIS);
				mvprintw(4 * i + 10, 6 * j + 14, ".|.");
				attroff(A_BOLD | A_INVIS);
				refresh();
			}
    	}
	}
}	

// Printez castigatorul fiecarei runde;
void printWinMe(void)
{
	int i;
	clear();
	refresh();
	attron(A_BOLD);
	for (i = 78; i < 128; i++)
	{
		mvprintw(20, i, "~");
		mvprintw(30, i, "~");
	}

	for (i = 21; i < 30; i++)
	{
		mvprintw(i, 78, "|");
		mvprintw(i, 127, "|");
	}
	attroff(A_BOLD);

	attron(A_BOLD | A_BLINK);	
	mvprintw(25, 84, "Congratulations! You won this game. :)");
	attroff(A_BOLD | A_BLINK);
	attron(A_BOLD);
	mvprintw(46, 91, "Press any key to get back.");	
	attroff(A_BOLD);
	refresh();
}

// Cazul in care calculatorul este cel care castiga;
void printWinPC(void)
{
	int i;
	clear();
	refresh();

	attron(A_BOLD);
	for (i = 78; i < 128; i++)
	{
		mvprintw(20, i, "~");
		mvprintw(30, i, "~");
	}

	for (i = 21; i < 30; i++)
	{
		mvprintw(i, 78, "|");
		mvprintw(i, 127, "|");
	}
	attroff(A_BOLD);

	attron(A_BOLD | A_BLINK);	

	mvprintw(25, 88, "Sorry! You lost this game. :(");
	attroff(A_BOLD | A_BLINK);
	attron(A_BOLD);
	mvprintw(46, 91, "Press any key to get back.");	
	attroff(A_BOLD);
	refresh();
}	

// Cazul in care este egalitate, remiza;
void printWinDeuce(void)
{
	int i;
	clear();
	refresh();
	attron(A_BOLD);
	for (i = 78; i < 128; i++)
	{
		mvprintw(20, i, "~");
		mvprintw(30, i, "~");
	}

	for (i = 21; i < 30; i++)
	{
		mvprintw(i, 78, "|");
		mvprintw(i, 127, "|");
	}
	attroff(A_BOLD);
	attron(A_BOLD | A_BLINK);
	mvprintw(25, 87, "Oh! It looks like a drawn game!");	
	attroff(A_BOLD | A_BLINK);
	attron(A_BOLD);
	mvprintw(46, 91, "Press any key to get back.");	
	attroff(A_BOLD);
	refresh();
}

// Folosesc aceasta functie pentru a genera lovituri random de catre calculator
char randomHit(char **ships, char hittedCount)
{
	int x, y;

	// Generez doua numere random, coordonate de pe grid;
	x = rand() % 10;
	y = rand() % 10;

	while (1)
	{
		// Setez conditia de oprire, hittedCount reprezentand numarul de 
		// barci pe care calculatorul le-a lovit pe parcus;
		if (hittedCount == 20)
		{
			break;
			clear();
			printWinPC();
			refresh();
		}

		// Ma asigur in cele doua cazuri ca PC-ul loveste in locuri diferite,
		// plasand la anumite pozitii caractere de 0 pe care le-am mascat
		// cu ajutorul atributului A_INVIS;
		if (ships[x][y] == 'X' && mvinch(4 * x + 10, 6 * y + 133) == ' ')
		{

			attron(A_BOLD | COLOR_PAIR(5));
			mvprintw(4 * x + 10, 6 * y + 134, ".|.");
			refresh();
			attroff(A_BOLD | COLOR_PAIR(5));
		
			attron(A_BOLD | A_INVIS);
			mvprintw(4 * x + 10, 6 * y + 133, "0");
			attroff(A_BOLD | A_INVIS);
			hittedCount++;
		}
		
		// Ma asigur in cele doua cazuri ca PC-ul loveste in locuri diferite,
		// plasand la anumite pozitii caractere de 0 pe care le-am mascat
		// cu ajutorul atributului A_INVIS;

		if (ships[x][y] != 'X' && mvinch(4 * x + 10, 6 * y + 133) == ' ')
		{
			attron(A_BOLD | COLOR_PAIR(4));
			mvprintw(4 * x + 10, 6 * y + 134, ".|.");
			refresh();
			attroff(A_BOLD | COLOR_PAIR(4));

			attron(A_BOLD | A_INVIS);
			mvprintw(4 * x + 10, 6 * y + 133, "0");
			attroff(A_BOLD | A_INVIS);
			break;
		}

		else
		{
			x = rand() % 10;
			y = rand() % 10;
		}
	}

	// Returnez numarul de lovituri pe care PC-ul le are asupra grid-ului meu.
	return hittedCount;
}

// Functie necesara loviturilor Random personale (pentru Destroy in Advance)
// Functie asemanatoare celei de randomizare a loviturilor PC-ului
char advanceHit(char **opships, char hittedCount)
{
	char hittedPC = 0;
	int x, y;

	x = rand() % 10;
	y = rand() % 10;

	while (hittedPC == 0)
	{
		if (hittedCount == 20)
		{
			break;
		}
		
		if (opships[x][y] == 'X' && mvinch(4 * x + 10, 6 * y + 13) == ' ')
		{

			attron(A_BOLD | COLOR_PAIR(5));
			mvprintw(4 * x + 10, 6 * y + 14, ".|.");
			refresh();
			attroff(A_BOLD | COLOR_PAIR(5));
		
			attron(A_BOLD | A_INVIS);
			mvprintw(4 * x + 10, 6 * y + 13, "0");
			attroff(A_BOLD | A_INVIS);
			hittedCount++;
		}
		

		if (opships[x][y] != 'X' && mvinch(4 * x + 10, 6 * y + 13) == ' ')
		{
			attron(A_BOLD | COLOR_PAIR(4));
			mvprintw(4 * x + 10, 6 * y + 14, ".|.");
			refresh();
			attroff(A_BOLD | COLOR_PAIR(4));

			attron(A_BOLD | A_INVIS);
			mvprintw(4 * x + 10, 6 * y + 13, "0");
			attroff(A_BOLD | A_INVIS);
			hittedPC++;
		}

		else
		{
			x = rand() % 10;
			y = rand() % 10;
		}

	}
	return hittedCount;
}

// Functia de printare a textelor de pe fereastra fiecarui New Game
void youLogo(int hittedMe, char hittedPC)
{
	mvprintw(40, 94, " You hit   ships. ");
	mvprintw(43, 89, "Your opponent hit   ships.");
	attron(A_BOLD);
	
	mvprintw(6, 154, "Your Battleship:");
	mvprintw(40, 103, "%d", hittedMe);
	mvprintw(43, 107, "%d", hittedPC);
	mvprintw(6, 28, "Your opponent's Battleship:");
	
	attroff(A_BOLD);

	mvprintw(2, 7, "Choose a cell with your keyboard's arrows");
	mvprintw(3, 12, "and select it pressing");
	attron(COLOR_PAIR(4));
	mvprintw(3, 35,	"Enter.");
	mvprintw(18, 100, "Destroy In Advance");
	attroff(COLOR_PAIR(4));
	
	mvprintw(5, 76, "When you hit a ship, that will be coloured with");
	attron(COLOR_PAIR(5));
	mvprintw(40, 92, "~|");
	mvprintw(40, 112, "|~");
	mvprintw(5, 124, "Green.");
	mvprintw(22, 103, "Auto-Play");
	attroff(COLOR_PAIR(5));

	mvprintw(8, 87, "You can press Q to quit this game.");
	mvprintw(18, 82, "Press D to select");
	mvprintw(22, 85, "Press A to select");
	
	mvprintw(18, 119, "option");
	mvprintw(22, 113, "option");

	mvprintw(6, 88, "Otherwise, that will be");
	
	attron(COLOR_PAIR(4));
	mvprintw(6, 112, "Red.");
	mvprintw(43, 86, "~|");
	mvprintw(43, 116, "|~");
	attroff(COLOR_PAIR(4));

	attron(COLOR_PAIR(5) | A_BOLD);
	attroff(COLOR_PAIR(5) | A_BOLD);

	refresh();
}

// Functia de DestroyInAdvance;
void destroyInAdvance(char **ships, char **opships, int hittedMe, int hittedPC)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		// Apelez cele doua functii, folosindu-ma de variabilele hittedMe, 
		// numarul de lovituri pe care eu le efectuez si hittedPC, numarul
		// de lovituri pe care PC-ul le are asupra mea
		hittedMe = advanceHit(opships, hittedMe);
		hittedPC = randomHit(ships, hittedPC);	

		// Updatez de fiecare data numarul de lovituri al fiecarui adversar; 
		youLogo(hittedMe, hittedPC);
	
		// Daca cele doua sunt egale, inseamna ca are loc remiza;
		if (hittedMe == hittedPC)
		{
			printWinDeuce();
			getch();
			break;
		}

		// Printeaza castigatorul eu;
		if (hittedMe == 20)
		{
			printWinMe();
			getch();
			break;
		}

		// Printeaza castigatorul PC;
		if (hittedPC == 20)
		{
			printWinPC();
			getch();
			break;
		}
	}
}

void autoPlay(char **ships, char **opships, int hittedMe, int hittedPC)
{
	int i;

	for (i = 0; i < 100; i ++)
	{
		hittedMe = advanceHit(opships, hittedMe);
		sleep(1);
		hittedPC = randomHit(ships, hittedPC);	

		if (hittedMe == hittedPC)
		{
			printWinDeuce();
			getch();
			break;
		}

		if (hittedMe == 20)
		{
			printWinMe();
			getch();
			break;
		}

		if (hittedPC == 20)
		{
			printWinPC();
			getch();
			break;
		}
	}
}

// Functia prin care se stabileste castigatorul si are loc jocul in sine;
void setWinner(char **ships, char **opships, int hittedMe, char hittedPC,
				int gridch)
{
	int i;
	int need = 0;
	int DIA = 0;
	int RAN = 0;
	int AUTO = 0;

	// Cat timp nu este apasata tasta q;
	while (jumpThroughGrid(gridch, opships, &hittedMe, need, &DIA, &AUTO) != -2)
	{

		if (AUTO == 1)
		{
			for (i = 0; i < 100; i++)
			{
				hittedMe = advanceHit(opships, hittedMe);
				sleep(1);
				hittedPC = randomHit(ships, hittedPC);
				youLogo(hittedMe, hittedPC);

				if (hittedMe == 20 || hittedPC == 20)
				{
					break;
				}
			}
		}
		
		if (hittedPC != 20 && DIA != 1 && AUTO != 1 && hittedMe != 20)
		{
			sleep(3);
			hittedPC = randomHit(ships, hittedPC);
		}


		if (DIA == 1)
		{
			for (i = 0; i < 10; i++)
			{
				hittedMe = advanceHit(opships, hittedMe);
				hittedPC = randomHit(ships, hittedPC);
				youLogo(hittedMe, hittedPC);
			}
		}

		if (RAN == 1)
		{
			// functie randomizare;
		}

		youLogo(hittedMe, hittedPC);

		if (hittedMe == 20 && hittedPC == 20)
		{
			printWinDeuce();
			getch();
			break;
		}

		if (hittedPC == 20)
		{
			printWinPC();
			getch();
			break;
		}

		if (hittedMe == 20)
		{
			printWinMe();
			getch();
			break;
		}
	}
}

void freeMem(char **ships, char **opships)
{
	int i, j;

    for (i = 0; i < 10; i++)
    {
    	free(ships[i]);
    }	


	for (j = -1; j < 11; j++)
	{
		free(opships[j]);
	}

	free(opships);
	free(ships);
}

int main(int argc, char **argv)
{
	FILE *gridfile;

	// Puncte initiale fereastra meniu;
	int start_1 = 0, start_2 = 0;
	int height, width;

	// WINDOW options;
	WINDOW *menu;
	int goexit = 0;
	int lighted = 1;
	int selectch;

	// Initializare optiuni meniu si lungime/latime tabel optiuni;
	char *menuopt[] = {"New Game", "Resume Game", "Info", "Quit"};
	height = 20;
	width = 30;
	
	// Initializare variabile necesare randomizare grid PC;
	int i;
	int k = 0;
	int dir[5] = {0}, count[5] = {0}, lenght[4] = {0};

	// Atribute si optiuni meniu;
	int f = 0, res = 0;
	char c, hittedMe = 0, hittedPC = 0;
	int gridch;
	
	// Matrice barci proprii;
	char **ships;
	ships = (char **)malloc(10 * sizeof(char *));

    for (i = 0; i < 10; i++)
    {
    	ships[i] = (char *)malloc(10 * sizeof(char));
    }	

    // Matrice barci oponente;
	char **opships;
	opships = (char **)malloc(12 * sizeof(char *));

	for (i = -1; i < 11; i++)
	{
		opships[i] = (char *)malloc(12 * sizeof(char));
	}

	// CITIRE FISIER SI AFISARE ERORI POSIBILE;
	readCheckFile(argc, argv, gridfile);

	// INIT NCURSES;
	getNcursed();
	getColors();

	// Initializare dimensiuni centrale fereastra;

	start_1 = (LINES - height) / 2;
	start_2 = (COLS - width) / 2;

	// Creare fereastra meniu;
	menu = newwin(height, width, start_1, start_2);
	
	keypad(menu, TRUE);
	refresh();

	do 
	{	
		// Initializare grafica fereastra principala + meniu;
		logoBattleShip();
		refresh();
		menuAtts(menu, menuopt, lighted);
		c = menuControl(menu, menuopt, selectch, lighted, goexit, &f, &res);

		// Break principal meniu, optiune Quit;
		if (c == 1)
		{
			break;
		}		

		// Optiune Info menu;
		if (f == 1)
		{
			clear();
			refresh();
			getInfo();
			getch();
			clear();	
		}

		// Intrare New Game;
		else if (f != 1)
		{
			clear();
			refresh();	
			gridstMake();
			youLogo(hittedPC, hittedMe);
			gridndMake();
			refresh();
			completeMyGrid(gridfile, argv, gridch, ships);
			getEmpty(opships);	
			createOpShips(opships, count, dir, lenght, k);
			printOpShip(opships);
			setWinner(ships, opships, hittedMe, hittedPC, gridch);
			clear();
		}

	} while (c != 1);

	endwin();

	return 1;
}
		