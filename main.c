#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "morse.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	BinTree P;
	int choice;
	boolean exit = false;
	char word[256];
	char fileteks[575];
	FILE *fp;
	
	printf("Membuat pohon morse...\n");
	Sleep(2000);
	MakeTree('\\', Nil, Nil, &P);
	createMorseTree(&P);
	printf("Pohon Morse telah berhasil dibuat...\n");
	printf("Pohon Morse dengan Inorder:\n");
	Inorder(P);
	printf("\n\nNOTE: Beberapa simbol karakter ditambahkan kepada pohon morsenya. Dan untuk node kosong kami ganti dengan karakter |. Juga untuk kode morse spasi, masih tidak sesuai dengan ketentuan\n\n");
	system("pause");
	do{
		system("cls");
		printf("=============================================\n");
		printf("MORSE ENCODE/DECODE\n");
		printf("=============================================\n");
		printf("1. Encode dari Kalimat menjadi Sandi Morse\n");
		printf("2. Decode dari Sandi Morse menjadi Kalimat\n");
		printf("3. Membuka file\n");
		printf("4. Keluar\n");
		printf("Pilihan anda? (1-4): ");scanf("%d", &choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:
				printf("Inputkan kalimat yang ingin diencode: ");
				fgets(word, sizeof(word), stdin);
				EncodeMorse(P, strupr(word));
				exit = true;
				break;
			case 2:
				printf("Inputkan sandi morse: ");
				fgets(word, sizeof(word), stdin);
				DecodeMorse(P, strupr(word));
				getch();
				break;
			case 3:
				printf("Membuka file");
				fp = fopen("input.txt", "r");
				if(fp!=Nil)
				{
					while(fgets(fileteks, 575, fp) != Nil)
					{
						EncodeMorseCodeToFile(P, fileteks);
					}
					fclose(fp);
				} else
				{
					printf("Gagal membuka file\n");
				}
			case 4:
				exit = true;
				break;
			default:
				break;
		}
	}while(!exit);
	
	
	
	return 0;
}
