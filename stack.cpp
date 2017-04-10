/****************************************
*	Implementacja stosu		*	
*	www.algorytm.org		*
*	Opracował Michał Knasiecki	*
*****************************************/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string.h>
struct stos
	{
   char dane[10];
   stos *ref;
   };

   stos *pointer;
   stos *old;

void add_stack(char dodaj[10])
{
old=pointer;
pointer=new stos;
strcpy(pointer->dane,dodaj);
pointer->ref=old;
}

void delete_node(stos *node)
{
if (node!=NULL)
	{
	old=node->ref;
   printf("Usunieto: %s\n",node->dane);
	delete node;
	pointer=old;
   } else printf("Stos jest pusty\n");
}
void print_stack()
{
printf("Zawartosc stosu:\n");
old=pointer;
while (old!=NULL)
	{
	cout <<old->dane<<endl;
   old=old->ref;
   }
}
void delete_all(void)
{
old=pointer;
while (old!=NULL)	delete_node(old);
printf("\nStos oczyszczony. Dowolny klawisz...");
}
void main(void)
{
char dane[10];
pointer=NULL;
printf("Wprowadz dane na stos (do 10 znakow, bez spacji):\n");
printf("# - usun ostatni, $ - wypisz dane, & - usun wszystko i zakoncz\n");

do
	{
   printf("Dane: ");
	scanf("%s",dane);
   if (strcmp(dane,"&")!=0)
   if (strcmp(dane,"#")==0) delete_node(pointer); else
   if (strcmp(dane,"$")==0) print_stack(); else add_stack(dane);
	}
while (strcmp(dane,"&")!=0);
delete_all();
getch();
}