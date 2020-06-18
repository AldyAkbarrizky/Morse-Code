/* File    : bintree.c 					*/
/* Desk    : Body primitif Binary Tree secara rekursif 	*/
/* Oleh    : ANI RAHMANI / 23501007			*/
/* Tgl	   : 21 / 11 / 2001	  			*/

#ifndef BINTREE_C
#define BINTREE_C

#include <stdio.h>
#include "bintree.h"

/* ***** Manajemen Memory ******* */
address Alokasi(infotype X)
{  /* menghasilkan address hasil alokasi sebuah Node */
   /* Jika alokasi berhasil, maka address tidak Nil  */
   /* Info(P)=X, Left(P)=Nil,Right(P)=Nil; Count(P)=0 */	
   /* Jika alokasi gagal ; mengembalikan  Nil 	     */
   
  
   address P;
   P=(address) malloc(sizeof(ElmtNode));   
   if(P!=Nil)
   {
	 Info(P)=X;
         Left(P)=Nil;
	 Right(P)=Nil;	 
	 //Count(P)=0; 
   }
   return P;
}

boolean  IsEmpty(BinTree P)
{  /*  Mengembalikan true jika pohon kosong  */
	printf("Is  Empty \n");
	return (P==Nil);
}


infotype GetAkar(BinTree P)
{ /* Mengirimkan informasi yang tersimpan di Akar pohon biner P */
  /* tidak kosong */
   return Info(P);	
}

BinTree GetLeft(BinTree P)
{ /* Mengirimkan anak kiri dari pohon biner P yang tidak kosong */
    return Left(P); 	
}

BinTree GetRight(BinTree P)
{ /* Mengirimkan anak kanan dari pohon pohon biner P yang tidak kosong */
    return Right(P);
}

BinTree GetParent(BinTree P, BinTree search)
{
	if(Left(P) == Nil && Right(P) == Nil)
		return Nil;
	if(Info(Left(P)) == Info(search) || Info(Right(P)) == Info(search))
		return P;
	BinTree leftSearch = GetParent(Left(P), search);
	if(leftSearch != Nil)
		return leftSearch;
	return GetParent(Right(P), search);
}

/* ***************** KONSTRUKTOR ****************  */

BinTree Tree(infotype X, BinTree L, BinTree R)
{ /* Menghasilkan sebuah pohon Biner dari A, L, dan R jika Alokasi berhasil */
  /* Menghasilkan pohon kosong Nil, jika alokasi gagal 			  */
    	address P;
	P=Alokasi(X);
	if(P!=Nil)
	{   Info(P)=X;
	    Left(P)=L;
        Right(P)=R;	    
	}
	return (P);
}

void MakeTree(infotype X, BinTree L, BinTree R, BinTree *P)
{  /* I.S   : Sembarang 	*/
   /* F.S   : Menghasilkan sebuah pohon biner P dari A,L,dan R, jika alokasi */
   /*         berhasil; Menghasilkan pohon P yang kosong jika alokasi gagal  */
	 
	*P=Alokasi(X);
       	if(*P!=Nil)
	{  Info(*P)=X;
	   Left(*P)=L;
	   Right(*P)=R;	
	}
}

void BuildTree(BinTree *P)
{ /* Membentuk sebuah pohon biner P dari pita karakter yang dibaca 	*/
  /* I.S   : Pita berisi 'kostanta' pohon dalam bentuk prefiks, memory 	*/
  /*         pasti cukup, alokasi pasti berhasil 			*/
  /* F.S   : P dibentuk dari Ekspresi dalam Pita   			*/    	
	
}

/* ********* PREDIKAT PENTING  **************  */

boolean IsUnerLeft(BinTree P)
{  /* Mengirimkan True jika pohon biner tidak kosong; P adalah pohon  */
   /* unerleft : hanya mempunyai subpohon kiri 			      */
	
     return ((Right(P)==Nil)  && (Left(P) !=Nil ));
}

boolean IsUnerRight(BinTree P)
{  /* Mengirimkan True jika pohon biner tidak kosong; P adalah pohon  */
   /* unerright : hanya mempunyai subpohon kanan          	      */

     return ((Right(P)!=Nil)  && ( Left(P) ==Nil ));
}

boolean IsBiner(BinTree P)
{  /* Mengirimkan true jika pohon biner tidak kosong; P adalah pohon */
   /* biner : mempunyai subpohon kiri dan subpohon kanan 	     */
	return ((Left(P) != Nil) && (Right(P) !=Nil ));
}

/* ************* TRAVERSAL   ************* */

void Preorder(BinTree P)
{  /* I.S  : P terdefinisi   					       */
   /* F.S  : semua simpul P sudah diproses secara Preorder; akar, kiri */
   /*        kanan (dengan Proses (P)) 				       */
   /* Basis : pohon kosong  : tidak ada yang diproses		       */
   /* Rekurens : Prosees Akar(P); Proses secara Preorder(Left(P));     */	
   /*            Proses secara  Preorder(Right(P)); 		       */ 	
	if(P !=Nil)
	   {
		printf("%c",Info(P));   
		Preorder(Left(P));
		Preorder(Right(P));
	       }		   
}

void Inorder(BinTree P)
{  /* I.S  : P terdefinisi   					      */
   /* F.S  : semua simpul P sudah diproses secara Inorder; kiri, akar */
   /*        kanan (dengan Proses (P)) 				      */
	if(P!=Nil)
	{
	     Inorder(Left(P));	
	     printf("%c",Info(P));
	     Inorder(Right(P));
	}
}

void Postorder(BinTree P)
{  /* I.S  : P terdefinisi   					    */
   /* F.S  : semua simpul P sudah diproses secara Postorder; kiri,  */    
   /* 	     kanan, akar (dengan Proses (P)) 			    */
	if(P!=Nil)
	{
	    Postorder(Left(P));	
	    Postorder(Right(P));
	    printf("%c",Info(P));
	}
}

void PrintTree(BinTree P)
{   /* I.S  : P terdefinisi                          	*/
    /* F.S  : semua simpul P sudah ditulis / preorder	*/
	if(P==Nil)
	{
	  printf("");	
	} else  {
		    printf("%c",Info(P));
		    PrintTree(Left(P));
		    PrintTree(Right(P));
		}
}

/* *********** SEARCHING ELEMENT ************* */
boolean Search(BinTree P, infotype X)
{
	if (P==Nil) //Jika tree kosong, kembalikan nilai false
		return false;
	
	if (Info(P) == X) //Jika data info pada node P sama dengan X, kembalikan nilai true
		return true;
	
	boolean found = Search(Left(P), X); //Lanjutkan mencari kepada anak kiri
	
	if(found) //Jika sudah ketemu, maka hentikan pencarian (tidak perlu mencari ke anak kanan)
		return true;
		
	boolean found2 = Search(Right(P), X); //Lanjutkan pencarian ke anak kanan
	
	return found2; //Kembalikan false jika tidak ketemu pada anak kanan, atau kembalikan true jika ketemu pada anak kanan
}

BinTree SearchAdr(BinTree P, infotype X)
{
	if (P==Nil)
	{
		return Nil;
	}
	
	if (Info(P)==X) //Jika data info pada node P sama dengan X, kembalikan nilai true
	{
		return P;
	}
	
	BinTree Find = SearchAdr(Left(P), X); //Lanjutkan mencari kepada anak kiri
	
	if(Find!=Nil) //Jika sudah ketemu, maka hentikan pencarian (tidak perlu mencari ke anak kanan)
		return Find;
		
	BinTree Find2 = SearchAdr(Right(P), X); //Lanjutkan pencarian ke anak kanan
	
	return Find2; //Kembalikan false jika tidak ketemu pada anak kanan, atau kembalikan true jika ketemu pada anak kanan
}

/* *********** FUNGSI LAIN  *********** */
int NbElmt(BinTree P)
{
	int count = 1;
	if(P!=Nil)
	{
		count += NbElmt(Left(P));
		count += NbElmt(Right(P));
	} else
	{
		return 0;
	}
}

int NbDaun(BinTree P)
{
	if(P==Nil)
		return 0;
	else if(Left(P)==Nil && Right(P)==Nil)
		return 1;
	else
		return NbElmt(Left(P)) + NbElmt(Right(P));
}

int Level(BinTree P, infotype X)
{
	return GetLevel(P, X, 1); 
}

int GetLevel(BinTree P, infotype X, int level)
{
	int level_bawah;
	
	if(P==Nil)
		return 0;
	if(Info(P)==X)
		return level;
		
	level_bawah = GetLevel(Left(P), X, level+1);
	
	if(level_bawah!=0)
		return level_bawah;
		
	level_bawah = GetLevel(Right(P), X, level+1);
	
	return level_bawah;
		
}

/* *********** OPERASI LAIN  *********** */
void AddDaunTerkiri(BinTree *P, infotype X)
{
	address N;
	if(Left(*P)!=Nil)
	{
		AddDaunTerkiri(&(Left(*P)), X);
	} else
	{
		N = Alokasi(X);
		if(N!=Nil)
		{
			Left(*P) = N;
		}
	}
}

void AddDaun(BinTree *P, infotype X, boolean InputKiri)
{
	address N;
	if(InputKiri)
	{
		if(Left(*P)==Nil)
		{
			N = Alokasi(X);
			Left(*P) = N;
		} else
		{
			printf("Node ini sudah memiliki anak kiri\n");
		}
	} else
	{
		if(Right(*P)==Nil)
		{
			N = Alokasi(X);
			Right(*P) = N;
		} else
		{
			printf("Node ini suadh memiliki anak kanan\n");
		}
	}
}

/* *********** MEMBENTUK BALANCE TREE ************* */

BinTree BuildBalanceTree(int n)
{  /* Menghasilkan sebuah balance tree dengan n node, nilai setiap */
   /* node dibaca 						   */
	/* Kamus */
	address P;
	infotype X;
	int nL,nR;
	BinTree L,R;
	
	/* Algoritma */
	if(n==0)
	{  return Nil;	
	   }else
		{   printf("Masukkan data "); 
		    scanf("%c",&X);
		    
		    printf("Test  -  test !\n");
		    P=Alokasi(X);
		    printf("test 2\n");
		    if(P!=Nil)
		    { printf("di dalam if \n");
			nL = n / 2  ;
		        nR = n-nL-1;
			L=BuildBalanceTree(nL);
			R=BuildBalanceTree(nR);
			Left(P)=L;
			Right(P)=R;	
			printf("selesai if \n");
		    }
		}
	return  P;

}

void InsSearchTree(BinTree *P, infotype X)
{   /* Menambahkan sebuah node X, ke  pohon biner pencarian P */
    /* infotype terdiri dari key dan count. Key menunjukkan  */	
    /* nilai unik, dan Count berapa kali muncul  ; */	
    /* Basis :  pohon kosong */
    /* Rekurens  : jika pohon tidak kosong, insert  ke anak   */
    /*         	   kiri jika nilai  < info(P); insert ke anak */	
    /*             kanan jika nilai > info(Akar); 	      */
    /* Alokasi selalu berhasil 				      */	
     
     if(IsEmpty(*P))
         {  printf("test empty \n");
              MakeTree(X,Nil,Nil,P);	
         } else {
		  if(X==Info(*P)) {
		  } else { if(X<Info(*P)) {
		  	 	    InsSearchTree(&(Left(*P)),X);
		  		}
		  	   else { /* X > Info(P)  */
		  	   	    InsSearchTree(&(Right(*P)),X);
		  	         } 	
		  	}
          	}	
}


#endif
