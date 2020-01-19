#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<conio.h>
int n; // ile rzedy

int * c = (int*)malloc(n * sizeof(int*)); // Tablica pomocnicza dla obliczen rekurencynych 2x2.
int determinanta(int **matrix, int n, int **tempdeta); // dekleracja naszej funkcji
int main()
{


	int i, j;
	printf("\n Podaj N dla NxN : ");
	scanf_s("%d", &n); // skanujemy rzedy
	printf("\n Podaj Elementy\n");
	int ** matrix; // nasza glowna matrix. Wskaznik na wskaznik
	matrix = (int**)malloc(n * sizeof(int*)); //Rezerwujemy sobie w pamieci nasz wskaznik z Elementami n razy
	int  **tempdeta; // Tablica na ktorej bedziemy liczyc  zeby nie zmieniac naszej glownej tablicy. Dynamiczna tak samo jak matrix
	tempdeta = (int**)malloc(n * sizeof(int*)); // tak samo jak matrix
	for (int i = 1; i <= n; i++) { // DO tej pory nasza tablica byla 1 wymiarowa z wskaznikami. Teraz Dla kazdego wskaznika ktory wskazuje na miejsce w pamieci jeszce jednego wskaznika=====>>> 2d  Tablica
		matrix[i] = (int*)malloc(n * sizeof(int));
		tempdeta[i] = (int*)malloc(n * sizeof(int*));
	}
	for (i = 1; i <= n; i++) // wczytujemy do naszej glownej matrix
	{
		for (j = 1; j <= n; j++)
		{
			printf("matrix[%d][%d] = ", i, j);
			scanf_s("%d, \t", &matrix[i][j]);
		}
	}
	printf("\n\n----------Matrix --------------\n"); // wyswietlamy nasza matrix
	for (i = 1; i <= n; i++)
	{
		printf("\n");
		for (j = 1; j <= n; j++)
		{
			printf("\t%d \t", matrix[i][j]);
		}
	}
	printf("\n \n");
	printf("\n Determinanta z podanej Matrix jest %d .", determinanta(matrix, n, tempdeta));
	_getch();

}

int determinanta(int **matrix, int n, int **tempdeta)
{

	int pr, j, p, q, t;
	int deta = 0;
	if (n == 2)
	{
		deta = 0;
		deta = (matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]); // Formuła dla przypadku 2x2 matrix
		return(deta);
	}
	else  // wiekesze niz 2. Moze byc dowolnie duza. nawet 100 x 100
	{
		for (j = 1; j <= n; j++)
		{
			int r = 1, s = 1;
			for (p = 1; p <= n; p++)
			{
				for (q = 1; q <= n; q++)
				{
					if (p != 1 && q != j)
					{
						tempdeta[r][s] = matrix[p][q]; // przepisanie w tablicy rachunkowej
						s++;
						if (s>n - 1)
						{
							r++;
							s = 1;
						}
					}
				}
			}
			for (t = 1, pr = 1; t <= (1 + j); t++)
				pr = (-1)*pr;
			c[j] = pr * determinanta(tempdeta, n - 1,NULL); // Wywołujemy rekurencynie naszą funkcję i obliczamy az do n=2. n10=>n9=>n8=>n7......n2(wtedy idziemy w pierwszy  case, obliczamy nasz 2x2 i tak dla calej matrix.) Zmniejszamy i liczimy i zwracamy
		}
		for (j = 1, deta = 0; j <= n; j++)
		{
			deta = deta + (matrix[1][j] * c[j]);  // ostatni krok dodanie wszystkich obliczonych wartosci z naszej pomocniczej tablicy rek c[] i mamy nasz wynik.
		}
		return(deta);
	}
}