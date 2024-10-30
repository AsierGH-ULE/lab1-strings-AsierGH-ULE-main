/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the 
 *     previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++ ), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two. You can also try clang.
 * At the end the source code  should compile without warnings to the variant 
 *     selected (you can remove/change instructions).
 */

 //En ese ejercicio se ha compilado con los estándares c99 y c23 (c2x)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };
 
/*const char* s1 = R"foo( 
Hello
World
)foo";  */

//utilizando gcc da error ya que R\"foo... pertenece a C++ y no a C
// propuesta de cambio para compilar con gcc: const char* s1 = "Hello\nWorld\n";

const char* s1 = "Hello\nWorld\n";

const char* s2 = "\nHello\nWorld\n";

void gets_example_func(void) { 
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1; //Compilando con gcc unicamente lo marca como warning, pero compilando con g++ lo marca como error
  }
  buf[strlen(buf) - 1] = '\0';
}

const char *get_dirname(const char *pathname) {
  char *slash;
  slash = strrchr(pathname, '/'); //compilando con c++11 y c++23 indica qu ela conversión de 'const char*' a 'char' no se puede realizar. el puntero tendría que ser const
  if (slash) {
    *slash = '\0'; /* Undefined behavior */
  }
  return pathname;
}
 

void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");  
	gets(response); // compilando con el estandar c99 advierte que 'gets' está deprecated. Además indica que es peligrosa y no debería utilizarse. Lo mismco ocurre compilando con c++11
  //Compilando con el estándar c2x sugiere cambiarla por fgets además, que como ocurre con c99 indica que es peligrosa y no debería utilizarse
  //c++23 nos sugiere getw, ya que argumenta que gets no está declarada
	if (response[0] == 'n') 
		exit(0);  

	return;
}

 
int main(int argc, char *argv[])
{
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char *ptr_char  = "new string literal"; //c++11 y c++23 indican que la ISO C++ prohibe convertir una constante de string a 'char', debería ser const char... Ocurre con todos los estándates de C++
    int size_array1 = strlen("аналитик"); //compilando con el estandar c99 indica que la variable no se utiliza
    int size_array2 = 100; //compilando con el estandar c99 indica que la variable no se utiliza
    
   // char analitic1[size_array1]="аналитик";
   // char analitic2[size_array2]="аналитик";
    char analitic3[100]="аналитик"; //compilando con el estandar c99 indica que la variable no se utiliza

    puts(get_dirname(__FILE__));

        
    strcpy(key, argv[1]);  
    strcat(key, " = ");  
    strcat(key, argv[2]);


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}