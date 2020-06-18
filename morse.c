#ifndef MORSE_C
#define MORSE_C

#include <stdio.h>
#include "morse.h"

void createMorseTree(BinTree *P)
{
	address travL, travR, temp;
	
	//Level ke 2
	AddDaun(&(*P), 'E', true);
	AddDaun(&(*P), 'T', false);
	
	//Level ke 3
	travL = Left(*P);
	AddDaun(&travL, 'I', true);
	AddDaun(&travL, 'A', false);
	travR = Right(*P);
	AddDaun(&travR, 'N', true);
	AddDaun(&travR, 'M', false);
	
	//Level ke 4
	travL = Left(Left(*P));
	AddDaun(&travL, 'S', true);
	AddDaun(&travL, 'U', false);
	travR = Right(Left(*P));
	AddDaun(&travR, 'R', true);
	AddDaun(&travR, 'W', false);
	travL = Left(Right(*P));
	AddDaun(&travL, 'D', true);
	AddDaun(&travL, 'K', false);
	travR = Right(Right(*P));
	AddDaun(&travR, 'G', true);
	AddDaun(&travR, 'O', false);
	
	//Level ke 5
	travL = Left(Left(Left(*P)));
	AddDaun(&travL, 'H', true);
	AddDaun(&travL, 'V', false);
	travR = Right(Left(Left(*P)));
	AddDaun(&travR, 'F', true);
	AddDaun(&travR, '|', false);
	travL = Left(Right(Left(*P)));
	AddDaun(&travL, 'L', true);
	AddDaun(&travL, '|', false);
	travR = Right(Right(Left(*P)));
	AddDaun(&travR, 'P', true);
	AddDaun(&travR, 'J', false);
	travL = Left(Left(Right(*P)));
	AddDaun(&travL, 'B', true);
	AddDaun(&travL, 'X', false);
	travR = Right(Left(Right(*P)));
	AddDaun(&travR, 'C', true);
	AddDaun(&travR, 'Y', false);
	travL = Left(Right(Right(*P)));
	AddDaun(&travL, 'Z', true);
	AddDaun(&travL, 'Q', false);
	travR = Right(Right(Right(*P)));
	AddDaun(&travR, '0', true);
	AddDaun(&travR, '|', false);
	
	//Level ke 6 (Angka)
	travL = Left(Left(Left(Left(*P))));
	AddDaun(&travL, '5', true);
	AddDaun(&travL, '4', false);
	travR = Right(Left(Left(Left(*P))));
	AddDaun(&travR, '|', true);
	AddDaun(&travR, '3', false);
	travL = Left(Right(Left(Left(*P))));
	AddDaun(&travL, '?', true);
	AddDaun(&travL, '-', false);
	travR = Right(Right(Left(Left(*P))));
	AddDaun(&travR, '.', true);
	AddDaun(&travR, '2', false);
	travL = Left(Left(Right(Left(*P))));
	AddDaun(&travL, ',', true);
	AddDaun(&travL, ':', false);
	travR = Right(Left(Right(Left(*P))));
	AddDaun(&travR, ' ', true);
	AddDaun(&travR, ';', false);
	travL = Left(Right(Right(Left(*P))));
	AddDaun(&travL, '*', true);
	AddDaun(&travL, '%', false);
	travR = Right(Right(Right(Left(*P))));
	AddDaun(&travR, '#', true);
	AddDaun(&travR, '1', false);
	travL = Left(Left(Left(Right(*P))));
	AddDaun(&travL, '6', true);
	AddDaun(&travL, '=', false);
	travR = Right(Left(Left(Right(*P))));
	AddDaun(&travR, '/', true);
	AddDaun(&travR, '|', false);
	travL = Left(Right(Left(Right(*P))));
	AddDaun(&travL, '|', true);
	AddDaun(&travL, '|', false);
	travR = Right(Right(Left(Right(*P))));
	AddDaun(&travR, '&', true);
	AddDaun(&travR, '|', false);
	travL = Left(Left(Right(Right(*P))));
	AddDaun(&travL, '7', true);
	AddDaun(&travL, '|', false);
	travR = Right(Left(Right(Right(*P))));
	AddDaun(&travR, '|', true);
	AddDaun(&travR, '|', false);
	travL = Left(Right(Right(Right(*P))));
	AddDaun(&travL, '8', true);
	AddDaun(&travL, '|', false);
	travR = Right(Right(Right(Right(*P))));
	AddDaun(&travR, '9', true);
	AddDaun(&travR, '|', false);
}

void EncodeMorse(BinTree P, char text[])
{
	printf("Kode morsenya adalah: \n");
	BinTree X, parent;
	int i, j, counter;
	char morse[6];
	for( i=0; i<strlen(text)-1; i++)
	{
		counter = 0;
		X = SearchAdr(P, text[i]);
		while(Info(X)!='\\')
		{
			parent = GetParent(P, X);
			if(Info(Left(parent))==Info(X))
			{
				morse[counter] = '.';
			} else
			{
				morse[counter] = '-';
			}
			X = parent;
			counter++;
		}
		for(j=counter-1; j>=0; j--)
			printf("%c", morse[j]);
		printf("  ");
	}
	printf("\n");
	getch();
}

void DecodeMorse(BinTree P, char morse[])
{
	printf("%s\n", morse);
	system("pause");
}

#endif
