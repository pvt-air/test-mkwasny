//Generowanie liczb pseudolosowych
//Generator LFG - Lagged Fibonacci Generator
//Opóźniony Generator Fibonacci'ego
//www.algorytm.org (c) 2008 Tomasz Lubinski
 
#include "stdio.h"
 
// Definicje wspolczynnikow j, k oraz m 
#define J 24
#define K 55
#define M 0x100000000ul /* 2^32 */
 
 
// Definicja wspolczynnika a dla generatora LCG dla zainicjowania tablicy
#define A 69069
 
// Tablica x - rejestr cykliczny oraz jej aktualny wskaznik
unsigned long long x[K];
unsigned long i;
 
/* Zainicjuj tablice X - uzyj gneratora LCG o wspolczynnikach:
m = 2^32, a = 69069, c = 0.
dla takiego generatora wszystkie posrednie wyniki mieszcza sie w 49 bitach */
void initX(unsigned long long seed)
{
int j;
 
x[0] = seed;
for (j=1; j<K; j++)
x[j] = (A*x[j-1]) % M;
 
i = 0;
}
 
/* Generator ALFG */
unsigned long long genRandALFG()
{
unsigned long long result;
 
x[i] = (x[(K + i - J) % K] + x[i]) % M;
result = x[i];
i = (i + 1) % K;
 
return result;
}
 
/* Generator MLFG */
unsigned long long genRandMLFG()
{
unsigned long long result;
 
x[i] = (x[(K + i - J) % K] * x[i]) % M;
result = x[i];
i = (i + 1) % K;
 
return result;
}
 
/* Generator TGFSR */
unsigned long long genRandTGFSR()
{
unsigned long long result;
 
x[i] = (x[(K + i - J) % K] ^ x[i]) % M;
result = x[i];
i = (i + 1) % K;
 
return result;
}
 
int main()
{
int j, n, g;
unsigned long long seed;
 
printf("Podaj wartosc poczatkowa ziarna (seed)\n");
scanf("%Ld", &seed);
 
printf("Podaj ile liczb pseudolosowych wylosowac\n");
scanf("%d", &n);
 
printf("Podaj, ktory generator uzyc:\n");
printf("1-ALFG - Addytywny Opozniony Generator Fibonacciego\n");
printf("2-MLFG - Multiplikatywny Opozniony Generator Fibonacciego\n");
printf("3-TGFSR - Dwupunktowy uogolniony rejestr przesuwny ze sprzezeniem zwrotnym\n");
scanf("%d", &g);
 
initX(seed);
 
switch (g)
{
case 1:
for (j=0; j<n; j++)
printf("%Ld\n", genRandALFG());
break;
case 2:
for (j=0; j<n; j++)
printf("%Ld\n", genRandMLFG());
break;
case 3:
for (j=0; j<n; j++)
printf("%Ld\n", genRandTGFSR());
break;
}
 
return 0;
}