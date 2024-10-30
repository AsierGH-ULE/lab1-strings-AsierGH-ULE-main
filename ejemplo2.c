#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

void optionOne(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

void optionTwo(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
}

void optionThree(){
    char *s = (char *) malloc(100);
    free(s);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
}
//gcc -std=c11 ejemplo2.c -o ejemplo2 -fsanitize=address
//gcc -std=c2x ejemplo2.c -o ejemplo2 -fsanitize=address
//La salida de los dos es la misma

//g++ -std=c++11 ejemplo2.c -o ejemplo2 -fsanitize=address
//g++ -std=c++23 ejemplo2.c -o ejemplo2 -fsanitize=address
//Igual que en el caso anterior, la salida es igual a la obtenida compilando con gcc
void optionFour(){
    char *s = (char *) malloc(18);
    strcpy(s,  "Welcome Sanitizer!"); //La cadena Wellcome Sanitizer! tiene un tamaño de 19 bits y lo está escribiendo en un puntero de 18 bits, con lo que se produce un overflow
    printf("string is: %s\n", s);
    free(s);
}

int main(int argc, const char *argv[]) {

    int expression;
    char* p;
    errno = 0; 
    
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <option>\n", argv[0]);
        exit(1);
    }

    long arg = strtol(argv[1], &p, 10);

    if (*p != '\0' || errno != 0) {
        return 1; 
    }

    if (arg < INT_MIN || arg > INT_MAX) {
        return 1;
    }

    expression = arg;
 

    switch (expression)
    {
        case 1:
            optionOne();
            break;
        case 2:
            optionTwo();
            break;
        case 3:
            optionThree();
            break;
        case 4:
            optionFour();
            break;
        default:
            printf("\n");
            break;
    }

    return 0;
}