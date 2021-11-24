# Zadanie 2 - Dynamiczna analiza kodu

Celem zadania jest napisanie narzędzia, które wykona prostą dynamiczną analizę kodu źródłowego.
Proponowane jest wykorzystanie techniki instrumentacji, czyli modyfikacji kodu źródłowego.
Raport generowany przez narzędzie powinien zostać zapisany do pliku lub wypisany na standardowe wyjście.

Przykładowy raport:

```console
Wejscie do funkcji:     int main()
Stworzenie zmiennej:    float result; 
Wejscie do funkcji:     float processing()
Stworzenie zmiennej:    int i;
Stworzenie zmiennej:    float f = 0.5f;
Zmiana zmiennej:        f=0.5
Zmiana zmiennej:        f=1
Zmiana zmiennej:        f=2
Zmiana zmiennej:        f=3.5
Zmiana zmiennej:        f=5.5
Zmiana zmiennej:        f=16.5
Wyjscie z funkcji "float processing()". Stan zmiennych: i=5, f=16.5,
Zmiana zmiennej:        result=16.5
Zmiana zmiennej:        result=17.5
Wyjscie z funkcji "int main()". Stan zmiennych: result=17.5,
```

Narzędzie powinno generować raport z:

1. Tworzenia zmiennych
2. Modyfikacji zmiennych
3. Wejścia oraz opuszczenia funkcji
4. Stanu zmiennych lokalnych w momencie opuszczenia funkcji
5. Zadanie dodatkowe - zmierzyć czas wykonania funkcji 

Zadanie można zrealizować w dowolnym języku.
Strona do sprawdzania wyrażeń reguralnych https://regex101.com/