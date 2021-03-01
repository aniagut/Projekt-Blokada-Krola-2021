# Projekt-Blokada-Króla-2020
Projekt realizowany w ramach przedmiotu Algorytmy Grafowe na III semestrze Informatyki na AGH.

## Treść zadania
Świeżo koronowany Król Bitomruk po bardzo udanym dla niego turnieju szachów odkrył, że najlepszym sposobem na wzbudzenie szacunku wśród poddanych jest okresowe okazywanie swojej wyższości w grach planszowych. Nie zamierza jednak ryzykować przypadkowych potknięć i chce mieć pewność, że w każdej grze uda mu się zwyciężyć. W najbliższym czasie będzie grać w dziwnę grę o nazwie “Blokada”.

Każda rozgrywka toczy się na unikalnej planszy, która ma N pól połączonych M dwukierunkowymi ścieżkami. Dodatkowo, jeśli między dwoma polami można przejść pośrednio na więcej niż jeden sposób, to dla każdej pary różnych dróg prowadzących między tymi polami zachodzi zależność, że każde pole na jednej z dróg jest bezpośrednio połączone z jakimś polem z drugiej drogi (ta zależność zachodzi dla każdej pary pól i dla każdej pary dróg między tymi polami). Co więcej, wiadomo, że pól jest co najmniej 3 i z każdego pola można (pośrednio) przejść do każdego innego.

Gracze dysponują nierówną liczbą pionków, które rozkładają na planszy, a gra następuje w turach. W pierwszej turze gracz rozpoczynający rozstawia własne pionki na dowolnych polach, po czym drugi gracz rozkłada swoje. Następnie gracze wykonują ruchy na przemian. W każdym ruchu gracz może przesunąć dowolną liczbę pionków na inne pole, pod warunkiem że ruch odbywa się wzdłuż drogi na której nie stoi żaden z pionków przeciwnika (może jednak mijać pola, na których stoją jego własne pionki; co więccej, gracz może na danym polu ustawić kilka swoich pionków). W danym ruchu gracz musi przesunąć co najmniej jeden pionek. Przegrywa gracz, który nie może wykonać ruchu. Jeśli zwycięzca nie zostanie wyłoniony po M turach, gra kończy się remisem.

Król Bitomruk wydał dekret, że we wszystkich grach z jego udziałem jego przeciwnik dysponował będzie wyłącznie jednym pionkiem, natomiast sam król może rozstawić tak wiele pionków jak mu się podoba (dura lex, sed lex). Żeby gra była jednak odrobinę bardziej sprawiedliwa, to król zawsze będzie wykonywał swoje ruchy jako pierwszy. Dodatkowo, aby rozgrywka nie wyglądała zbyt podejrzanie, król nie chce nadużywać swojego przywileju i woli rozstawić najmniejszą możliwą liczbę pionków, która zagwarantuje mu wygraną.

## Format danych wejściowych
Plik wejściowy (który ma być wczytywany ze standardowego wejścia) w pierwszej linii zawiera liczbę T mówiącą ile jest zestawów danych (każdy pojedynczy zestaw opisuje jedną grę). W kolejnych linijkach znajdują się opisy gier w następującym formacie:

W pierwszej linii znajdują się dwie liczby naturalne N oraz M (N > 2 i M >= N-1) oznaczające kolejno liczbę pól na planszy oraz liczbę ścieżek między polami
Kolejne M linii zawiera opis każdej ze ścieżek. Ścieżka jest opisana przez parę liczb naturalnych a, b (1 <= a,b, <= N) oznaczających numery pól połączonych ścieżką. Każda z par pól na wejściu pojawia się co najwyżej raz. Mamy gwarancję że opisana w ten sposób plansza spełnia warunki z treści zadania.
### Przykład
Przykładowy plik wejściowy:

1
5 5
1 2
2 3
3 4
3 5
2 5

## Format wyjścia
Wynik działania programu należy wypisać na standardowe wyjście w następującym formacie: W każdej kolejnej linijce powinna znaleźć się jedna liczba naturalna opisująca minimalną liczbę pionków która zagwarantuje Królowi Bitomrukowi zwycięstwo w grze na danej planszy niezależnie od ruchów przeciwnika, zakładając że to król wykonuje swoje ruchy jako pierwszy.
### Przykład
Dla pliku wejściowego powyżej poprawnym wyjściem jest:

2

Mając do dyspozycji 2 pionki król ustawia je na polach 2 i 5, w zależności od ustawienia przeciwnika może wystąpić kilka wariantów:

Jeśli przeciwnik ustawi swój pionek na polu 1 lub na polu 4, to król przechodzi na pola 2 i 3 co blokuje możliwość wykonania ruchu (jedyny ruch z pozycji 1 można wykonać przechodząc przez pole 2 natomiast jedyny ruch z pola 4 można wykonać przechodząc przez pole 3)
Ostatnia możliwość przeciwnika to ustawienie pionka na polu 3. W tym przypadku król przechodzi na pola 1 i 2 i czeka na ruch przeciwnika. W takiej sytuacji przeciwnik może przejść na pole 4 lub pole 5. Następnie król przechodzi na pola 2 i 3 blokując możliwość ruchu przeciwnika zarówno gdyby był na polu 4 jak i na polu 5.

Źródło: https://faliszew.github.io/algograf/2020.project2
