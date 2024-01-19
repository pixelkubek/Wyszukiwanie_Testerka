# Testerka do zadania wyszukiwanie
Program wykonuje domyślnie 10000 gier dla każdej możliwej kombinacji n, k oraz kl, gdzie kl oznacza sansę w %, że Alicja w danym momencie skłamie.

Wyniki wykonań programu dla kolejnych wartości będą zapisane w pliku log.txt. Można te pliki porównać z innymi osobami, by sprawdzić, czy strategia jest optymalna.

Dla danych parametrów g, n, k, kl będą tworzone takie same testy.

## Komenda do wywołania
Należy umieścić w folderze plik wys.cpp z kodem.
```bash
bash ./test.sh
```
Flagi
- -v użycie valgrinda (w przypadku błędu informacja pojawi się w pliku memcheck.log)
- -a wyswietlenie ilości pytań dla wszystkich gier
- -f wykonywanie dalszych testów po napotkaniu błędu
- -g zmiana ilości gier dla danych parametrów na podaną ilość

Inne parametry można ustawić w pliku test.sh