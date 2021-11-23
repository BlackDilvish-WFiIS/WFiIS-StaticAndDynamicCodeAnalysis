# Zadanie 1 - Statyczna analiza kodu

Celem zadania jest napisanie programu, który sprawdzi poprawność semantyczną pliku main.c i wypisze do konsoli informacje o błędach. 

Przykładowy wynik działania programu:

```console
Running static analysis tool...
Line 23: missing semicolon
Line 25: missing semicolon
Line: 10: typing error, got 'integer' instead of 'int'
Line: 11: typing error, got 'dobul' instead of 'double'
Line: 12: typing error, got 'chara' instead of 'char'
Found loose brackets - {[)
Found 6 errors
```

Zakładamy, że program nie ma skomplikowanej konstrukcji. Każda deklaracja jest przeprowadzana w osobnej linijce a zakres pętli rozpoczyna się w tej samej linii.

Program powinien sprawdzić:

1. Czy na końcu odpowiednich linii znajduje się średnik

2. Czy deklaracje typów są poprawne. W programie będą znajdować się typy:
    - *int*
    - *double*
    - *char*

3. Czy wszystkie nawiasy zostały zamknięte

4. Zadanie dodatkowe - rozwinąć poprzednie zadanie o sprecyzowanie lini, w której znajduje się niezamknięty nawias. 

Zadanie można zrealizować w dowolnym języku. \
Strona do sprawdzania wyrażeń reguralnych https://regex101.com/