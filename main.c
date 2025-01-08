#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char frase [50];
    int cont=0, cont1=0, cse=0, cont2=0, max=0, min=0, cont3=0;
    printf("escribe una frase de no mas de 50 caracteres\n");
    fflush(stdin);
    fgets(frase,50,stdin);
    int len = strlen(frase);
    
    for (int i = 0; i < len; i++)
    {
        cont2=cont2+1;
        cont3=cont3+1;
        //printf("%c\n", frase[i]);
        cont=cont+1;
        
        if (frase[i]== ' ' || frase[i] == '\n')
        {
            if (min==0)
            {
                min=cont3;
            }
            
            if (cont3<min)
            {
                min=cont3;
            }
            
            cont1=cont1+1;
            
            if (cont2>max)
            {
                max=cont2;
            }


            cont3=0;
            cont2=0;
        }
        
        
            
    }
    
    //cse=cont1;
    //cse=cont-cont1;
    cont=cont-cont1;
    max=max-1;
    min=min-1;
    printf("\n");
    printf("La palabra mas grande contiene: %i\n", max);
    //printf("La palabra ultima contiene: %i\n", cont2);
    //printf("Numero de caracteres es: %i\n", cont);
    printf("La frase contiuene: %i palabras\n" ,cont1);
    //printf("Numero de caracteres sin contar el espacio es: %i\n", cse);
    printf("La palbra mas pequena contiene: %i\n", min);
 

    return 0;
}