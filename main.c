//3. Se citesc de la tastatura tastatura N numere intregi.Sa
//se verifice folosind DOAR stive daca numerele respective
//sunt palindroame, iar numere care sunt palindroame vor fi
//introduce intr - o stiva.La sfarsit se va afisa continutul stivei
//respective.Cerinta de implementare : Se va implementa o
//singura metoda de Push/Pop/Peek , se va stii pe care
//stiva se lucreaza transmitand parametrii prin referinta.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 100
int st[MAX_SIZE];
int vf = -1;    //n-am folosit asta :(

void push(int x, int v, int s[]) {
    printf("Pushing %d on stack\n", x);
    s[v] = x;
}

void pop(int v, int s[]) { //asta trebe schimbata, nu cred ca ii suficient sa zic vf = vf - 1, ci ar trebui facuta o copie a stackului in care ignori elementul care trebuie sters
//    vf = vf - 1;
}

int peek(int v, int s[]) {
    return s[v];
}

int main() {
    int aux, ok, n, nr, k = 0;
    int numere[MAX_SIZE]; //declar un array de 100 in care pun numerele citite
    printf("Numere citite: ");

    while (scanf("%d", &n) == 1){ //citesc numere pana cand intalneste un caracter != numar (ex pt input: 121 232 31 .) <- trebuie '.' la final sau orice litera
        numere[k++] = n;           // ca sa-l opresti din citit
    }

//    printf("%d\n",(int) sizeof(numere) / (int) sizeof(int));

    for(int i = 0; i < (int) sizeof(numere) / (int) sizeof(int); i++) { //loop prin toate elementele din numere[]
        if(numere[i] != 0) { //numere[] ii initializat cu size de 100. daca se citesc < 100 numere restul sunt 0 by default, deci le ignori
            push(numere[i], i, st); //le pun in alt stack ca sa nu imi dau batai de cap cu ultimul element care nu ii numar
//            printf("%d\n", numere[i]);
        }
        else {
            k -= 1; //k - 1 e ultimul element care e un numar
            break;
        }
    }

    for (int i = k; i >= 0; i--) { // da-i uncomment la asta daca vrei sa vezi cum arata stackul cu numerele tale
        printf("Hello %d\n", st[i]);
    }
    printf("%d\n", (int) sizeof(st) / (int) sizeof(int));
    for(int i = 0; i <= k; i++) { // loop prin st[]
        int x = peek(i, st); //elementul de la index i din st[]
//        printf("x = %d\n", x);
        if(x != 0) { //la fel ca numere[], st[] e initializat cu size de 100, deci elementele goale sunt 0 by default, deci le ignori
            int nr_cifre = 0;

            while (x > pow(10, nr_cifre)) { //aflu nr de cifre comparand cu 10^n pana cand x < 10^n
                nr_cifre++;
            }

//            printf("%d are %d cifre\n", x, nr_cifre);
            int digits[nr_cifre-1]; //initializez array unde pun fiecare cifra din X (numarul curent)
            int p = 0;

            while (x != 0) { //pun fiecare cifra pe un index din stack
                digits[p++] = x % 10;
                x /= 10; //asta ii echivalent cu x = x / 10
            }

//            for(int o = 0; o <= (int) sizeof(digits) / (int) sizeof(int); o++){ //da-i uncomment la asta daca vrei sa vezi numarul impartit in cifre
//                printf("digit %d, %d\n", digits[o], o);
//            }

            int palindrome = 1; // consider 0 = False si 1 = True

            for (int j = 0; j <= ((int) sizeof(digits) / (int) sizeof(int) -1 )/2 ; j++) { //
                if (peek(j, digits) != peek(nr_cifre-1 - j, digits)) { //compari primul cu ultimul element, al doilea cu (ultimul element- 1), etc.
                    palindrome = 0;
                    break;
                }
            }

            if (palindrome == 1) {
                printf("%d e palindrom\n", peek(i, st));
            } else {
                printf("%d nu e palindrom\n", peek(i, st));
            }
            //ce nu am facut ii sa sterg elementele care nu sunt palindroame din st[]
            //mai simplu decat sa le stergi ar fi sa creezi inca un stack si sa le pui pe toate acolo si ai terminat, dar atunci nu folosesti niciunde pop()
            //daca nu trebuie neaparat folosit pop() iti sugerez sa faci asa, altfel e putina bataie de cap
        }
    }

    return 0;
}