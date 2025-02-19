#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leonel Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(messi));
           
        
           
           
           printf("Direccion de memoria de messi.name: %p \n"
           "Direccion de memoria de messi.age   : %p \n"
           "Direccion de memoria de messi.height: %p \n", (void *) &messi.name, (void *) &messi.age, (void *) &messi.height
           );

    return EXIT_SUCCESS;
}

/*La suma de los valores por separado no coincide con el total*/
/*El tamaño de name no depende de la cantidad de caracteres en este caso*/

/*Las direcciones de memoria tienen los primeros 12 lugares iguales*/









