# Testerka do zadania wyszukiwanie
Program wykonuje domyślnie 10000 gier dla każdej możliwej kombinacji n, k oraz kl, gdzie kl oznacza sansę w %, że Alicja w danym momencie skłamie.

Wyniki wykonań programu dla kolejnych wartości będą zapisane w pliku log.txt. Można te pliki porównać z innymi osobami, by sprawdzić, czy strategia jest optymalna.

Dla danych parametrów n, k, kl będą tworzone takie same testy.

**Uwaga!** Dwa optymalne rozwiązania mogą tworzyć różne wyniki dla niedostatecznie dużych g, np. dla n = 3 i k = 0 pytania 2 i 3 są równoważne w ogólności, ale mają inne wyniki w zależności od odpowiedzi Ali, dlatego, aby wyniki były porównywalne warto wywyołać skrypt np. z "-g 1000000",
mimo że wykracza to poza specyfikację zadania.

Jeśli ktoś znajdzie bardziej optymalne wyniki i większe g nie zmiejszają różnicy, to proszę o wiadomość.

## Komenda do wywołania
Należy umieścić w folderze plik wys.cpp z kodem.
```bash
bash ./test.sh
```
Flagi
- -a wyswietlenie ilości pytań dla wszystkich gier
- -f wykonywanie dalszych testów po napotkaniu błędu
- -g zmiana ilości gier dla danych parametrów na podaną ilość

Inne parametry można ustawić w pliku test.sh

## Debugowanie konkretnego przypadku
Aby odtworzyć konkretny przypadek trzeba przekazać 6 argumentów na stdin
```
n k g kl a seed
```
Gdzie "kl" jest z zakresu [0; 100], a "a" jest z zakresu [0; 1] i oznacza, czy wyświetlać wyniki dla każdej gry.