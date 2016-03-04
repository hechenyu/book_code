/* main.c */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD	100
#define NKEYS	37

struct key {
	char *word;
	int count;
} keytab[NKEYS] = {
	{"auto", 0}, 
	{"break", 0}, 
	{"case", 0}, {"char", 0}, {"const", 0}, {"continue", 0},
	{"default", 0}, {"do", 0}, {"double", 0},
	{"else", 0}, {"enum", 0}, {"extern", 0},
	{"float", 0}, {"for", 0},
	{"goto", 0},
	{"if", 0}, {"inline", 0}, {"int", 0}, 
	{"long", 0},
	{"restrict", 0}, {"return", 0},
	{"short", 0}, {"signed", 0}, {"sizeof", 0}, {"static", 0}, {"struct", 0}, {"switch", 0},
	{"typedef", 0},
	{"union", 0}, {"unsigned", 0},
	{"void", 0}, {"volatile", 0},
	{"while", 0},
	{"_Bool", 0}, {"_Complex", 0}, {"_Imaginary", 0}
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* ͳ��������C���Թؼ��ֵĳ��ִ��� */
int main()
{
	int n;
	char word[MAXWORD];
	
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
				if ((n = binsearch(word, keytab, NKEYS)) >= 0)
					keytab[n].count++;
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0)
			printf("%4d %s\n",
				keytab[n].count, keytab[n].word);
	return 0;
}

/* binsearch��������tab[0]��tab[n-1]�в��ҵ��� */
int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else 
			return mid;
	}
	return -1;
}
