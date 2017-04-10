//Program szyfrujacy tekst znajdujacy sie w pliku za pomoca algorytmu Cezara
//Program pobrano ze strony www.algorytm.org
//Opracowal Krzysztof Mackowiak
//IMO kiepski szyfr
 
#include<stdio.h>
#include<iostream.h>
#include <math.h>
 
void main()
{
FILE *we, *wy;
char znak;                   //znak odczytany z pliku
//Przed uruchomieniem programu nalezy utworzyc 2 pliki - 1. z tekstem jawnym, 2. pusty na t.zaszyfrowany
char plik_jawny[20];         //nazwa pliku z tekstem jawnym
char plik_zaszyfrowany[20];  //nazwa pliku z tekstem zaszyfrownym
cout<<"Podaj nazwe pliku, ktorego tresc ma zostac zaszyfrowana: " ;
cin>>plik_jawny;             //pobranie nazwy pliku jawnego
cout<<"Podaj nazwe pliku wynikowego: ";
cin>>plik_zaszyfrowany;      //pobranie nazwy pliku zaszyfrowanego
if((we=fopen(plik_jawny,"rb"))!=NULL)    //otwieranie pliku 1. do odczytu - w przypadku gdy takiego pliku nie ma program nie wykona sie
{
if((wy=fopen(plik_zaszyfrowany,"wb"))!=NULL)  //otwieranie pliku 2. do zapisu  - w przypadku gdy takiego pliku nie ma program nie wykona sie
{
while((znak=getc(we))!=EOF)   //pobieranie znaku z pliku 1. tak dlugo az nie nastapi znak konca pliku
//Kazdy odczytywany znak wg kodow ASCII jest przydzielany do 3 grup duze litery, male litery, cyfry
{
if ((znak>=65)&&(znak<=90))
{
znak-=65;
znak+=3;
znak=fmod(znak,26);  //operacja ta potrzebna jest aby przykladowo litera z szyfrowana byla jako c a nie jako znaczek o nr o 3 wiekszym w tablicy ASCII
znak+=65;
putc(znak,wy);
}
else if ((znak>=97)&&(znak<=122))
{
znak-=97;
znak+=3;
znak=fmod(znak,26);  
znak+=97;
putc(znak,wy);
}
else if ((znak>=48)&&(znak<=57))
{
znak-=48;
znak+=3;
znak=fmod(znak,10);
znak+=48;
putc(znak,wy);
}
//Wszystkie inne znaki sa pomijane. Jezeli zalezy Ci aby nie pomijac niektorych znakow powinienes
//dodac w tym miejscu nastepujace linijki kodu:
//else if(znak==nr)   gdzie przez nr rozumiemy nr kodu ASCII danego znaku
//{znak+=3;
//putc(znak,wy);}
//W funkcji deszyfrujacej nalezy umiescic to samo zmieniajac + na -.
}
fclose(wy); //zamykanie pliku wyjsciowego
}
fclose(we);     //zamykanie pliku wejsciowego
}
cout<<"Szyfrowanie zostalo zakonczone";
return;
}

cezar_c/CEZAR_D.CPP:
//Program deszyfrujacy tekst z pliku za pomoca algorytmu Cezara
//Program pobrano ze strony www.algorytm.org
//Opracowal Krzysztof Mackowiak
 
#include<stdio.h>
#include<iostream.h>
#include <math.h>
 
void main()
{
FILE *we, *wy;
char znak;                   //znak odczytany z pliku
//Przed uruchomieniem programu nalezy utworzyc 2 pliki - 1. z tekstem zaszyfrowanym, 2. pusty na t.odszyfrowany
char plik_jawny[20];         //nazwa pliku z tekstem jawnym
char plik_zaszyfrowany[20];  //nazwa pliku z tekstem zaszyfrownym
cout<<"Podaj nazwe pliku zawierajacego tekst zaszyfrowany: ";
cin>>plik_zaszyfrowany;      //pobranie nazwy pliku zaszyfrowanego
cout<<"Podaj nazwe pliku,w ktorym zapisany ma byc tekst odszyfrowany: " ;
cin>>plik_jawny;             //pobranie nazwy pliku jawnego
 
if((we=fopen(plik_zaszyfrowany,"rb"))!=NULL)    //otwieranie pliku 1. do odczytu - plik musi istniec
{
if((wy=fopen(plik_jawny,"wb"))!=NULL)  //otwieranie pliku 2. do zapisu - plik musi istniec
{
while((znak=getc(we))!=EOF)   //pobieranie znaku z pliku 1. tak dlugo az nie nastapi znak konca pliku
//Kazdy odczytywany znak wg kodow ASCII jest przydzielany do 3 grup duze litery, male litery, cyfry
{
if ((znak>=65)&&(znak<=90))
{
znak-=65;
znak-=3;
if (znak<0)
znak=26-fabs(znak); //potrzebne jest obliczenie wartosci bezwzglednej, gdyz po odejmowaniu mozemy otrzymac wartosc ujemna
znak+=65;
putc(znak,wy);           //wypisanie znaku do pliku wyjsciowego
}
else if ((znak>=97)&&(znak<=122))
{
znak-=97;
znak-=3;
if (znak<0)
znak=26-fabs(znak);
znak+=97;
putc(znak,wy);
}
else if ((znak>=48)&&(znak<=57))
{
znak-=48;
znak-=3;
if (znak<0)
znak=10-fabs(znak);
znak+=48;
putc(znak,wy);
}
 
}
fclose(wy);     //zamkniecie pliku wyjsciowego
}
fclose(we);     //zamkniecie pliku wejsciowego
}
cout<<"Deszyfrowanie zostalo zakonczone";
return;
}