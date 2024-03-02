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
        printf("\nMozliwe polecenia: dodaj, znajdz, usun, wyswietl, wyjdz. Wpisz polecenie:\n");
        char polecenie[10];
        scanf("%s", polecenie);
        if (strcmp(polecenie, "dodaj") == 0){
            char imie[30], nazwisko[30], numer[13];
            printf("Podaj imie:\n");
            scanf("%s", imie);
            printf("Podaj nazwisko:\n");
            scanf("%s", nazwisko);
            printf("Podaj numer telefonu:\n");
            scanf("%s", numer);
            add(contacts, imie, nazwisko, numer, plen);
        }
        else if (strcmp(polecenie, "usun") == 0){
            char nazwisko[30];
            printf("Podaj nazwisko usuwanej osoby, lub wpisz anuluj:\n");
            scanf("%s", nazwisko);
            if (!(strcmp(nazwisko, "anuluj") == 0)){
                removeFromContacts(contacts, nazwisko, plen);
            }
        }
        else if (strcmp(polecenie, "znajdz") == 0){
            char nazwisko[30];
            printf("Podaj nazwisko osoby do wyszukania:\n");
            scanf("%s", nazwisko);
            if (find(contacts, nazwisko, plen, 0) != -1){
                find(contacts, nazwisko, plen, 1);
            }
            else{
                printf("Nie ma takiego kontaktu!");
            }
        }
        else if (strcmp(polecenie, "wyswietl") == 0){
            allContacts(contacts, plen);
        }
        else if (strcmp(polecenie, "wyjdz") == 0){
            going = 0;
        }
        else{
            printf("Zle polecenie.");
        }
    }
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
        printf("\n%s %s: %s\n", contacts[i].imie, contacts[i].nazwisko, contacts[i].numer);
    }
}
