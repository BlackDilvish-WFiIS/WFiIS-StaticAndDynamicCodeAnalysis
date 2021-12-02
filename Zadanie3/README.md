# ANALIZA STATYCZNA NA PRZYKŁADZIE NARZĘDZIA cppcheck.

## Przykład 1.
Proszę, korzystając z poradnika: https://linux.die.net/man/1/cppcheck oraz następującej konstrukcji:
```
$ cppcheck --enable=<OPTION> <FILE_NAME>
```

W poniższych przykładach proszę "pobawić" się plikiem main.cpp zakomentowując i odkomentowując wybrane linie.

a) Sprawdzić zachowanie programu cppcheck przy badaniu pliku main.cpp z różnymi opcjami. Proszę zwrócić uwagę na pojawiające się ostrzeżenia. Na razie prosze zignorować ewentualne informacje dotyczące niemożności znalezienia dołączanych plików.\
b) Proszę odkomentować linię 15. i jeszcze raz uruchomić analize z dowolną opcją. Czy zgłoszenie takiego błędu w narzędziu do analizy statycznej stanowi pewne zaskoczenie?\
c) Proszę zastanowić się nad zasadnością otrzymanych ostrzeżeń w kontekście ogólnej wiedzy programistycznej i znajomości praktyk\

d) Cppcheck posiada możliwość generowania raportu w formacie XML, proszę przetestować następującą komendę:\

```
$ cppcheck --enable=all --xml main.cpp
```

e) Wracając do kwestii pojawiających się błędów dotyczących dołączeń biblioteki. Istnieje możliwość ignorowania wybranych naruszeń. Opcja ta w praktyce powinna być stosowana rzecz jasna z odpowiednią ostrożnością. Proszę spróbować zignorować mylące w naszym przypadku ostrzeżenie dotyczące includów poprzez:\
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

UWAGA!!! Raport wskaże jedynie numery reguł MISR-y które zostały naruszone. Aby poznać dokładną treść reguł należy załadować odpowiedni plik konfiguracyjny. Standard ma jednak zamknięty charakter i sama treść reguł nie może być legalnie dystrybuowana bez ograniczeń (cppcheck posiada oficjalny dodatek do MISRy ale nie rozpowszechnia samej treści reguł, treść ta może zostać nabyta od twórców standardu wraz ze szczegółowym omówieniem).\

b) Proszę spróbować bazując na własnym doświadczeniu, poprzednim zadaniu, kodzie skryptów .py i ogólnych kompetencjach wywnioskować, w jaki sposób można poprawić w kodzie zaistniałe naruszenia reguł i czego mogą dotyczyć nie znając ich dokładnej treści.\

c) Po próbie poprawienia naruszeń, proszę zastanowić się nad zasadnością stosowania tych reguł biorąc pod uwagę zarówno programowania aplikacji o zastosowaniu ogólnym, jak i tych przeznaczonych na systemy wbudowane.

# ANALIZA DYNAMICZNA

## Przykład 1. Memcheck
Proszę pobrać pliki z folderu memcheck. Znajduje się tam prosty przykład realizacji niektórych funkcjonalności listy jednokierunkowej. W pliku Node.c świadomie wprowadzono kilka wycieków pamięci. Proszę nie ingerując w plik main.c, korzystając z memchecka zlokalizować te błędy i wycieki i poprawić, aby poprawnie działały operacje dodawania do listy, czyszczenia pamięci przydzielonej dla jej elementów oraz wypisywania wszystkich elementów listy.
## Przykład 2. Callgrind
## Przykład 3. Gcovr
