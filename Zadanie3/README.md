# ANALIZA STATYCZNA NA PRZYKŁADZIE NARZĘDZIA cppcheck.

## Przykład 1.
Proszę, korzystając z następującej konstrukcji:

a) Sprawdzić zachowanie programu cppcheck przy badaniu pliku main.cpp. Proszę zwrócić uwagę na pojawiające się ostrzeżenia
b) Proszę odkomentować linię
c) Proszę zastanowić się nad zasadnością otrzymanych ostrzeżeń w kontekście ogólnej wiedzy programistycznej i poczucia estetyki

d) Cppcheck posiada możliwość generowania raportu w formacie XML, proszę przetestować następującą komendę:

e) Wracając do kwestii pojawiających się błędów dotyczących dołączeń biblioteki. Istnieje możliwość ignorowania wybranych naruszeń. Opcja ta w praktyce powinna być stosowana rzecz jasna z odpowiednią ostrożnością. Proszę spróbować zignorować ostrzeżenie dotyczące poprzez:

## Przykład 2.
W ramach tego zadania przedstawione zostanie rozszerzenie cppchecka do badania zgodności z wybranym standardem. Jako przykład posłuży stosowany w przemyśle samochodwym standard MISRA (_Motor Industry Software Reliability Association_). W tym celu należy pobrać skrypty pythona (misra_9, misra oraz cppcheckdata). Są to nieznacznie zmodyfikowane pliki projektu, którego repozytorium dostępne jest pod: https://github.com/danmar/cppcheck/tree/main/addons

a) Proszę wygenerować raport naruszeń standardu MISRA dla pliku main.cpp

UWAGA!!! Raport wskaże jedynie numery reguł MISR-y które zostały naruszone. Aby poznać dokładną treść reguł należy załadować odpowiedni plik konfiguracyjny. Standard ma jednak zamknięty charakter i sama treść reguł nie powinna być legalnie dystrybuowana (cppcheck posiada oficjalny dodatek do MISRy ale nie rozpowszechnia samej treści reguł).

b) Proszę spróbować bazując na własnym doświadczeniu, poprzednim zadaniu, kodzie skryptów .py i ogólnych kompetencjach wywnioskować, w jaki sposób można poprawić w kodzie zaistniałe naruszenia reguł i czego mogą dotyczyć nie znając ich dokładnej treści.
c) Po poprawieniu naruszeń, proszę zastanowić się nad zasadnością stosowania tych reguł biorąc pod uwagę zarówno programowania aplikacji o zastosowaniu ogólnym, jak i tych przeznaczonych na systemy wbudowane.

# ANALIZA DYNAMICZNA

## Przykład 1. Memcheck
## Przykład 2. Callgrind
## Przykład 3. Gcovr
