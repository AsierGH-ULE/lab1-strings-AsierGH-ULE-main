# MUIC - DPS - Laboratorio 1

## ejemplo1.c

Para el desarrollo de esta práctica se han utilizado los estándares c99 y c2x de gcc y los estándares c++11 y c++23 de g++.

### Versiones
#### Sistema Operativo
Ubuntu 24.04
#### GCC
V. 13.2.0
#### G++
v. 13.2.0

### Explicaciones de los resultados obtenidos
Compilando `const char* s1 = R"foo( 
Hello
World
)foo";` con gcc, es decir, bajo el lenguaje C, salta un error, ya que `R"foo(...)foo"` pertenece a C++. Para que funcione, se ha sustituido por `const char* s1 = "Hello\nWorld\n"`

//

```bash
void gets_example_func(void) { 
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1;
  }
  buf[strlen(buf) - 1] = '\0';
```
Compilando con gcc la instrucción `return 1;` unicamente lo marca como warning, pero compilando con g++ la marca como error. Esto se debe a que el compilador de C es más permisivo que el de C++, que es bastante más restrictivo.

//

`slash = strrchr(pathname, '/');` Compilando con c++11 y c++23 indica qu ela conversión de 'const char*' a 'char' no se puede realizar. El puntero tendría que ser `const`

//

`gets(response);` 
Compilando con el estandar c99 advierte que 'gets' está deprecated. Además indica que es peligrosa y no debería utilizarse. Lo mismco ocurre compilando con c++11. Compilando con el estándar c2x sugiere cambiarla por fgets además, que como ocurre con c99 indica que es peligrosa y no debería utilizarse. c++23 nos sugiere getw, ya que argumenta que gets no está declarada

//

`char *ptr_char  = "new string literal";` c++11 y c++23 indican que la ISO C++ prohibe convertir una constante de string a 'char', debería ser const char... Ocurre con todos los estándates de C++

//

`int size_array1 = strlen("аналитик");` Compilando con el estandar c99 indica que la variable no se utiliza

//

`int size_array2 = 100;` Compilando con el estandar c99 indica que la variable no se utiliza

//

`char analitic3[100]="аналитик";` Compilando con el estandar c99 indica que la variable no se utiliza


## ejemplo2.c. Program Instrumentation

#### Sistema Operativo
Ubuntu 24.04
#### GCC
V. 13.2.0
#### G++
v. 13.2.0

### Explicación de los resultados obtenidos

`gcc -std=c11 ejemplo2.c -o ejemplo2 -fsanitize=address` & `gcc -std=c2x ejemplo2.c -o ejemplo2 -fsanitize=address`
La salida de los dos comandos es la misma:

```bash
ejemplo2.c: In function ‘optionFour’:
ejemplo2.c:35:5: warning: ‘__builtin_memcpy’ writing 19 bytes into a region of size 18 overflows the destination [-Wstringop-overflow=]
   35 |     strcpy(s,  "Welcome Sanitizer!"); //La cadena Wellcome Sanitizer! tiene un tamaño de 19 bits y lo está escribiendo en un puntero de 18 bits, con lo que se produce un overflow
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ejemplo2.c:34:24: note: destination object of size 18 allocated by ‘malloc’
   34 |     char *s = (char *) malloc(18);
      |                        ^~~~~~~~~~
```

`g++ -std=c++11 ejemplo2.c -o ejemplo2 -fsanitize=address` & `g++ -std=c++23 ejemplo2.c -o ejemplo2 -fsanitize=address`
Igual que en el caso anterior, la salida es igual a la obtenida compilando con gcc:

```bash
ejemplo2.c: In function ‘void optionFour()’:
ejemplo2.c:35:11: warning: ‘void* __builtin_memcpy(void*, const void*, long unsigned int)’ writing 19 bytes into a region of size 18 overflows the destination [-Wstringop-overflow=]
   35 |     strcpy(s,  "Welcome Sanitizer!"); //La cadena Wellcome Sanitizer! tiene un tamaño de 19 bits y lo está escribiendo en un puntero de 18 bits, con lo que se produce un overflow
      |     ~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~
ejemplo2.c:34:30: note: destination object of size 18 allocated by ‘malloc’
   34 |     char *s = (char *) malloc(18);
      |                        ~~~~~~^~~~
```