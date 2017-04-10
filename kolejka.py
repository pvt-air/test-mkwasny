#kolejka
#www.algorytm.org
 
#!/usr/bin/python
# -*- coding: utf-8 -*-
 
 
class KolejkaElement: #klasa elementu kolejki
def __init__(self, val=0, poprzedni=None): #konstruktor musi zawierać
# referencję do poprzedniego elementu
# w kolejce
self.v=val
self.nastepny=None
if poprzedni!=None: #je?li istnieje poprzedni:
poprzedni.nastepny=self #ustawia, że następujący po nim jest
# aktualny
class Kolejka: #klasa Kolejki
def __init__(self):
self.poczatek=None #ustawia że nie ma elementu na początku, ani na końcu
self.koniec=None
def dodaj(self, val): #metoda dodaje do kolejki
el=KolejkaElement(val, self.koniec) #tworzy element
self.koniec=el #ustawia go na koniec
if self.poczatek==None: #i jeżli początek jest pusty
self.poczatek=self.koniec #ustawia go na koniec
def usun(self): #usuwa element z początku
if self.poczatek!=None: #żeby nie odwoływać się do None
self.poczatek=self.poczatek.nastepny
if self.poczatek==None: #jeżli okazało się, że już nie ma elementów
self.koniec=None # usuwa element z końca kolejki
def pobierz(self): #zwraca pierwszy element z kolejki
if self.poczatek!=None:
return self.poczatek.v
return None
def jestPusta(self): #sprawdza, czy jest pusta
if self.poczatek!=None:
return False
return True
 
s=Kolejka()
print("Dodaj 1")
s.dodaj(1)
print("Dodaj 2")
s.dodaj(2)
print("Dodaj 3")
s.dodaj(3)
print("")
print(s.pobierz())
s.usun()
print(s.pobierz())
s.usun()
print(s.pobierz())
print("Jest pusty: "+str(s.jestPusta()))
print("usuń")
s.usun()
print(s.pobierz())
print("Jest pusty: "+str(s.jestPusta()))