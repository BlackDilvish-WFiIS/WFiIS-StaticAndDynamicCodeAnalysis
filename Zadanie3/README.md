# ANALIZA STATYCZNA NA PRZYKŁADZIE NARZĘDZIA cppcheck.

## Instalacja cppcheck
Jeśli narzędzie cppcheck nie jest dostępne na serwerze, należy pobrać repozytorium https://github.com/danmar/cppcheck i wykonać kroki kompilacji dla narzędzia cmake:
```
$ git clone https://github.com/danmar/cppcheck
$ cd cppcheck
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
```
Zbudowany plik binarny powinien być dostępny pod ścieżką <cppcheck_path>/build/bin/cppcheck.
Można zapisać go np w zmiennej:
```
$ export cppcheck=~/<cppcheck_path>/build/bin/cppcheck
```
Następnie odwołując się do zmiennej $cppcheck lub pełnej ścieżki można wykonać kolejne zadania.

## Przykład 1.
Proszę, korzystając z poradnika: https://linux.die.net/man/1/cppcheck oraz następującej konstrukcji:
```
$ cppcheck --enable=<OPTION> <FILE_NAME>
```

W poniższych przykładach proszę "pobawić" się plikiem main.cpp zakomentowując i odkomentowując wybrane linie.

a) Sprawdzić zachowanie programu cppcheck przy badaniu pliku main.cpp z różnymi opcjami. Proszę zwrócić uwagę na pojawiające się ostrzeżenia. Na razie prosze zignorować ewentualne informacje dotyczące niemożności znalezienia dołączanych plików.
b) Proszę odkomentować linię 15. i jeszcze raz uruchomić analize z dowolną opcją. Czy zgłoszenie takiego błędu w narzędziu do analizy statycznej stanowi pewne zaskoczenie?\
c) Proszę zastanowić się nad zasadnością otrzymanych ostrzeżeń w kontekście ogólnej wiedzy programistycznej i znajomości praktyk

d) Cppcheck posiada możliwość generowania raportu w formacie XML, proszę przetestować następującą komendę:

```
$ cppcheck --enable=all --xml main.cpp
```

e) Wracając do kwestii pojawiających się błędów dotyczących dołączeń biblioteki. Istnieje możliwość ignorowania wybranych naruszeń. Opcja ta w praktyce powinna być stosowana rzecz jasna z odpowiednią ostrożnością. Proszę spróbować zignorować mylące w naszym przypadku ostrzeżenie dotyczące includów poprzez:
```
$ cppcheck --enable=all --suppress=missingIncludeSystem
```

## Przykład 2.
W ramach tego zadania przedstawione zostanie rozszerzenie cppchecka do badania zgodności z wybranym standardem. Jako przykład posłuży stosowany w przemyśle samochodwym standard MISRA (_Motor Industry Software Reliability Association_). W tym celu należy pobrać skrypty pythona (misra_9, misra oraz cppcheckdata). Są to nieznacznie zmodyfikowane pliki projektu, którego repozytorium dostępne jest pod: https://github.com/danmar/cppcheck/tree/main/addons

a) Proszę wygenerować raport naruszeń standardu MISRA dla pliku main.cpp

```
$ cppcheck --dump main.cpp
$ python misra.py main.cpp.dump
```

UWAGA!!! Raport wskaże jedynie numery reguł MISR-y które zostały naruszone. Aby poznać dokładną treść reguł należy załadować odpowiedni plik konfiguracyjny. Standard ma jednak zamknięty charakter i sama treść reguł nie może być legalnie dystrybuowana bez ograniczeń (cppcheck posiada oficjalny dodatek do MISRy ale nie rozpowszechnia samej treści reguł, treść ta może zostać nabyta od twórców standardu wraz ze szczegółowym omówieniem).

b) Proszę spróbować bazując na własnym doświadczeniu, poprzednim zadaniu, kodzie skryptów .py i ogólnych kompetencjach wywnioskować, w jaki sposób można poprawić w kodzie zaistniałe naruszenia reguł i czego mogą dotyczyć nie znając ich dokładnej treści.

c) Po próbie poprawienia naruszeń, proszę zastanowić się nad zasadnością stosowania tych reguł biorąc pod uwagę zarówno programowanie aplikacji o zastosowaniu ogólnym, jak i tych przeznaczonych na systemy wbudowane.

d) Proszę wygenerować podobny raport dla standardu CERT C++:
```
$ cppcheck --dump main.cpp
$ python cert.py main.cpp.dump
```
e) Proszę poprawić kod, aby usunąć warningi generowane w raporcie.

# ANALIZA DYNAMICZNA

## Przykład 1. Memcheck
Proszę pobrać pliki z folderu memcheck_example. Znajduje się tam prosty przykład realizacji niektórych funkcjonalności listy jednokierunkowej. W pliku Node.c świadomie wprowadzono kilka wycieków pamięci. Proszę nie ingerując w plik main.c, korzystając z memchecka zlokalizować te błędy i wycieki i poprawić, aby poprawnie działały operacje dodawania do listy, czyszczenia pamięci przydzielonej dla jej elementów oraz wypisywania wszystkich elementów listy.

Pliki proszę kompilować z flagą -g dowolną techniką (z użyciem Makefile'a lub regexa) np.:
```
$ gcc -Wall -g *.c
```

Do śledzenia wycieków można np. użyć komendy:
```
  $ valgrind --tool=memcheck --leak-check=full ./a.out
```

## Przykład 2. Callgrind
W tym zadaniu proszę skorzystać z pliku main.c. Znajduje się tam implementacja algorytmów merge sort oraz bubble sort. W funkcji main następuje wywołanie tych algorytmów dla losowej tablicy 100 elementów.

a) Celem zadania jest prześledzenie raportu callgrinda dla poszczególnych funkcji.

Generowanie raportu:
1. Proszę (koniecznie) skompilować program z flagą -g.
2. Następnie proszę wygenerować raport:
```
$ valgrind --tool=callgrind ./a.out
```

Proszę zwrócić uwagę na numer procesu. Wygenerowany plik powinien zawierać go w nazwie, np. callgrind.out.214
3. I wyświetlić raport w formie, którą można przeanalizować:
```
$ callgrind_annotate callgrind.out.PID --inclusive=yes --tree=both
```

Podpowiedź: wygodnej informacji najlepiej poszukiwać w górnej części outputu.

Proszę zwrócić uwagę jak wiele instrukcji potrzebnych jest do wypisania tablicy!
Proszę zwrócić uwagę na różnicę pomiędzy sortowaniem bąbelkowym a szybszymi algorytmami.

b) Proszę spróbować napisać funkcję, która wywoływana dla trzech współczynników równania kwadratowego (A, B, C) postaci: Ax^2 + Bx + C, wypisze jego miejsca zerowe w formie: x1 = wartosc_1, x2 = wartosc_2, w taki sposób by po analizie callgrind uzyskać jak najmniej instrukcji. Niech program działa na liczbach zmiennoprzecinkowych.
Program można napisać w C lub C++, ale proszę zwrócić uwagę np. na koszt różnych sposobów wypisywania wyników itp.

## Przykład 3. Gcovr
Gcovr pozwala na zmierzenie pokrycia kodu:
- w kontekście pokrycia linii w trakcia uruchomienia programu
- w kontekście pokrycia kodu testami jednostkowymi

My zajmiemy się tym pierwszym przypadkiem. 

Jeżeli gcovr nie jest dostępny na Taurusie to proszę pobrać go w następujący sposób:

```
$ pip install gcovr
```

Wyświetli się ostrzeżenie ze ścieżką do pliku wykonywalnego gcovr. Należy posługiwać się tą ścieżką lub dodać w swoim katalogu domowym zmienną:

```
export gcovr=~/.local/bin/gcovr
```

Teraz pod komendą
```
$gcovr --help
```
powinien być widoczny program.

a) Proszę wygenerować w dowolnej formie raport z pokrycia dla pliku main.cpp.
Przykładowo dla wygenerowania raportu w HTML-u:
```
$ g++ -Wall -g -fprofile-arcs -ftest-coverage -fPIC main.cpp
$ ./a.out
$ $gcovr -r . --html --html-details -o nazwa_pliku.html
```
b) Proszę zwrócić uwagę na niepokryte branche i linie i dopisać w mainie wywołania funkcji tak by osiągnąć 100% w obu przypadkach.
Czy sygnalizacja niepokrycia branchy w niektórych miejscach jest zaskoczeniem?

Dziękujemy za uwagę :)
