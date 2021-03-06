//
//  main.c
//  istPrimzahl.c
//
//  Created by Tom Moritz on 19.01.21.
//

#include <stdio.h>
#include <stdlib.h>
// Methode 1
int istPrimzahl(int a){
    int i;
    
    if (a < 0)
            return -1;
    if(a == 0 || a == 1)
            return 0;
    
        for (i = 2; i < a; i++){
            if(a % i == 0){
                return 0;
            }
        }
        return 1;
}
void istPrimzahlAusgabe(int a){
    int i;
    
    if (a < 0)
        printf("Eingegebene Zahl kleiner 0\n");
    if(a == 0 || a == 1)
        printf("Eingegebene Zahl null oder eins\n");
    
        for (i = 2; i < a; i++){
            if(a % i == 0){
                printf("Die Eingegebene Zahl ist keine Primzahl.\n");
                return;
            }
        }
    printf("Die Eingegebene Zahl ist eine Primzahl.\n");
}

void listePrimzahlen(int n1, int n2){
    
    //test dann in größer kleiner Variablen
    int groesser = 0, kleiner = 0, i, c=1;
    
    printf("Primzahlen im Bereich %d bis %d:\n", n1, n2);
    
    if (n1<n2) {
        kleiner = n1;
        groesser = n2;
    }
    if (n1>n2) {
        kleiner = n2;
        groesser = n1;
    }
    
    //array aufstellen mit max inhalt von Größer minus kleiner
    int allePrimZahlen[groesser-kleiner];
    
    //zwischne n1 und n2
    //schleife istprimzahl Speichern in array
    for (i=kleiner; i<=groesser; i++) {
        if (istPrimzahl(i)) {
            allePrimZahlen[c] = i;
            c++;
        }
        
    }
    for (i=1; i < c; i++) {
        printf("%d : %d\n", i, allePrimZahlen[i]);
    }
}


int listePrimzahlzwillinge(unsigned int n1, unsigned int n2)
{
    printf("Primzahlzwilinge im Bereich %d bis %d:\n", n1, n2);
    for (unsigned int i = n1; i <= n2; i++)
        if (istPrimzahl(i) && istPrimzahl(i + 2))
            printf("%d & %d\n", i, i + 2);
    
    return 0;
}

void primFaktorZerlegung(int a){
    if (a>1) {
        while (a > 1) {
            
            if (a%2 == 0) {
                a /= 2;
                printf("2 ");
            }
            else if (a%3 == 0) {
                a /= 3;
                printf("3 ");
            }
            else if (a%5 == 0) {
                a /= 5;
                printf("5 ");
            }
            else if (a%7 == 0) {
                a /= 7;
                printf("7 ");
            }
            else if (a%11 == 0) {
                a /= 11;
                printf("11 ");
            }
            else if (a%13 == 0) {
                a /= 13;
                printf("13 ");
            }
            else if (a%17 == 0) {
                a /= 17;
                printf("17 ");
            }
            else if (a%19 == 0) {
                a /= 19;
                printf("19 ");
            }
            else if (istPrimzahl(a)) {
                printf("%d ", a);
                a /= a;
            }
        }
    }
}

int wahl(){
    char entscheidung;
    
    printf("[j][n]\n");
    scanf(" %c", &entscheidung);
    
    if (entscheidung == 'j') {
        return 1;
    }
    else {
        return 0;
    }
}



int main(){
    int choice, a = 0, b = 0, beenden = 1;
    
    do{
    printf("Welche der Folgenden Rechenoperationen wollen sie durchführen?\n[Geben sie die jeweilige Zahl ein und bestätigen sie mit Enter!]\n\nPrimzahlliste: 1\nPrimzahl Abfrage: 2\nZwillingsprimzahlliste: 3\nPrimfaktorzerlegung: 4\n\n");
    scanf(" %d", &choice);
    
    if (choice == 1) {
        printf("[Geben Sie die Grenzen, getrennt mit einem Leerzeichen, ein und bestätigen sie mit einem Enter]:\n");
        scanf("%d %d", &a, &b);
        listePrimzahlen(a, b);
    }
    else if (choice == 2) {
        printf("[Geben sie die jeweilige Zahl ein und bestätigen sie mit Enter]:\n");
        scanf("%d", &a);
        istPrimzahlAusgabe(a);
    }
    else if (choice == 3) {
        printf("[Geben Sie die Grenzen, getrennt mit einem Leerzeichen, ein und bestätigen sie mit einem Enter]:\n");
        scanf("%d %d", &a, &b);
        listePrimzahlzwillinge(a, b);
    }
        
    else if (choice == 4) {
        printf("[Geben sie die jeweilige Zahl ein und bestätigen sie mit Enter]:\n");
        scanf("%d", &a);
        primFaktorZerlegung(a);
    }
    else{
        printf("Die Eingabe war nicht zulässig!\n");
    }
        printf("\nWollen sie noch eine Rechenoperation durchführen?\n");
        if (wahl() == 0) beenden = 0;
                            
    }while (beenden != 0);
    return 0;
    
    printf("test");
    
    //listePrimzahlen(1, 100);
    //listePrimzahlzwillinge(1, 100);
    //primFaktorZerlegung(2046);
    //istPrimzahlAusgabe(341);
    //printf("Test");
    
}

    


