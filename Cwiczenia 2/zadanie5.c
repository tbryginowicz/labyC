/*
### **Zadanie 5: Implementacja prostej książki adresowej**

---

- Zdefiniuj strukturę **`Contact`**, która zawiera imię, nazwisko (jako tablice znaków) oraz numer telefonu (jako tablicę znaków).
- Utwórz tablicę struktur **`Contact`** i zainicjuj ją przykładowymi danymi.
- Napisz funkcje do:
    - Dodawania nowego kontaktu do książki adresowej.
    - Wyszukiwania kontaktu po nazwisku.
    - Usuwania kontaktu po nazwisku.
    - Wypisywania wszystkich kontaktów w książce adresowej.
- Aby ułatwić zarządzanie tablicą kontaktów, możesz założyć stały maksymalny rozmiar tablicy i śledzić aktualną liczbę kontaktów.
- W funkcji **`main`**, zaimplementuj prosty interfejs użytkownika pozwalający na wykonanie powyższych operacji
    (dodaj, znajdź, usuń, wyświetl wszystkie). ( po prostu użyj funkcji `scanf`,
    pytając co użytkownik chce zrobić, lub wykorzystaj [parsowanie argumentów wejściowych]
    (https://stackoverflow.com/questions/9642732/parsing-command-line-arguments-in-c))
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char imie[30];
    char nazwisko[30];
    char numer[13];
} Contact;

void add(Contact *contacts, char *imie, char *nazwisko, char *numer, int *len);

int find(Contact *contacts, char *nazwisko, int *len, int doPrint);

void removeFromContacts(Contact *contacts, char *nazwisko, int *len);

void allContacts(Contact *contacts, int *len);

int main() {
    Contact contacts[999] = {{"Jan", "Kowalski", "+48123456789"}, 
    {"Mariusz", "Pudzianowski", "+48100000000"}, 
    {"Adam", "Mickiewicz", "+4810"},
    {"Robert", "Kubica", "+48101010101"},
    {"Jan", "Nowak", "+48999999999"}};
    int len = 5;
    int *plen = &len;
    int going = 1;
    while (going == 1){
        printf("Mozliwe polecenia: dodaj, znajdz, usun, wyswietl. Wpisz polecenie");
        char *polecenie;
        scanf("%s", &polecenie);
        if (strcomp(polecenie, "dodaj") == 0){
            char *imie, *nazwisko, *numer;
            printf("Podaj imie:");
            scanf("%s", imie);
            printf("Podaj nazwisko:");
            scanf("%s", nazwisko);
            printf("Podaj numer telefonu:");
            scanf("%s", numer);
            
            add(contacts, imie, nazwisko, numer, plen);
        }
        if (strcomp(polecenie, "usun") == 0){

        }
        if (strcomp(polecenie, "znajdz") == 0){

        }
        if (strcomp(polecenie, "wyswietl") == 0){
            allContacts(contacts, plen);
        }
    }
    /*
    add(contacts, "Marcin", "Nazwiskowy", "+48222", plen);
    
    allContacts(contacts, plen);
    removeFromContacts(contacts, "Kubica", plen);
    printf("\n\n");
    allContacts(contacts, plen);
    */
    return 0;
}

void add(Contact *contacts, char *imie, char *nazwisko, char *numer, int *len){
    strcpy(contacts[*len].imie, imie);
    strcpy(contacts[*len].nazwisko, nazwisko);
    strcpy(contacts[*len].numer, numer);
    (*len)++;
}

int find(Contact *contacts, char *nazwisko, int *len, int doPrint){
    for (int i = 0; i < *len; i++){
        if (strcmp(contacts[i].nazwisko, nazwisko) == 0){
            if (doPrint == 1){
                printf("%s %s: %s\n", contacts[i].imie, contacts[i].nazwisko, contacts[i].numer);
            }
            return i;
        }
    }
    return -1; // Zwróć -1, jeśli kontakt nie został znaleziony
}

void removeFromContacts(Contact *contacts, char *nazwisko, int *len){
    int index = find(contacts, nazwisko, len, 0);
    if (index != -1) {
        for (int i = index; i < *len - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*len)--;
    } else {
        printf("Nie znaleziono kontaktu o nazwisku %s\n", nazwisko);
    }
}

void allContacts(Contact *contacts, int *len){
    for (int i = 0; i < *len; i ++){
        printf("%s %s: %s\n", contacts[i].imie, contacts[i].nazwisko, contacts[i].numer);
    }
}
