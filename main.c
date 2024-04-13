#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_NOMBRE 50
#define MAX_APELLIDO 50
#define MAX_CEDULA 20
#define MAX_PELICULA 100


/**se define de la estructura para almacenar los datos del boleto**/
typedef struct {
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    char cedula[MAX_CEDULA];
    int sala;
    char puesto[3];
    /**se utiliza para almacenar la letra y el numero del puesto**/
    char hora[10];
    char pelicula[MAX_PELICULA];
} Boleto;

int main() {
    /**se crea la estructura Boleto de cine para almacenar los datos**/
    Boleto boleto;

    printf("Ingrese el nombre: ");
    fgets(boleto.nombre, sizeof(boleto.nombre), stdin);
     /**se utiliza  fgets para leer cadenas de texto como (nombre, apellido, cedula, pelicula) y stdin para leer los datos ingresados**/
    boleto.nombre[strcspn(boleto.nombre, "\n")] = 0;
     /**se elimina el salto de linea y se utiliza el strcspn para eliminar el caracter de salto de linea (\n)**/

    /**lo que se hizo con el nombre se emplea a los datos restantes para colocarlos en el boleto**/
    printf("Ingrese el apellido: ");
    fgets(boleto.apellido, sizeof(boleto.apellido), stdin);
    boleto.apellido[strcspn(boleto.apellido, "\n")] = 0;

    printf("Ingrese el numero de cedula: ");
    fgets(boleto.cedula, sizeof(boleto.cedula), stdin);
    boleto.cedula[strcspn(boleto.cedula, "\n")] = 0;

    printf("Ingrese el numero de sala: ");
    scanf("%d", &boleto.sala);

    printf("Ingrese la letra del puesto (A-Z): ");
    scanf(" %c", &boleto.puesto[0]);
     /**se usa para leer la letra del respectivo puesto al igual que el numero del mismo**/

    printf("Ingrese el numero del puesto (1-99): ");
    scanf("%s", &boleto.puesto[1]);

    printf("Ingrese la hora de la funcion (HH:MM): ");
    /**se usa HH:MM para colocar la hora y los minutos**/
    scanf("%s", boleto.hora);

    printf("Ingrese el nombre de la pelicula: ");
    getchar();
     /**se limpia el buffer de entrada antes de leer la cadena**/
    fgets(boleto.pelicula, sizeof(boleto.pelicula), stdin);
    boleto.pelicula[strcspn(boleto.pelicula, "\n")] = 0;
    /**se elimina el salto de linea**/

    FILE *archivo_boleto;
    archivo_boleto = fopen("boleto_cine.txt", "w");
    /**se utiliza file y fopen para abrir un archivo de texto en modo escritura ("w")**/

    if (archivo_boleto != NULL) {
        /**se obtiene la fecha y hora actual usando time y localtime **/
        time_t ahora;
        time(&ahora);
        char fecha_hora[50];
        strftime(fecha_hora, sizeof(fecha_hora), "%Y-%m-%d %H:%M:%S", localtime(&ahora));
        /** Con "%Y-%m-%d %H:%M:%S" se representan los dias de 1 a 31,los meses de 1 a 12 y el año con 4 digitos, y las horas en formato de 24 con 2 digitos y por utlimos con un maximo de 59 minutos y segundos. Y luego usamos strftime para formatear una estructura de tiempo**/

        /** Escribimos todos los datos del boleto en el archivo**/
        fprintf(archivo_boleto, "---------------------------------\n"); /**Se usa fprintf para escribir los datos del boleto en el archivo de texto**/
        fprintf(archivo_boleto, "        Boleto de Cine\n");
        fprintf(archivo_boleto, "---------------------------------\n");
        fprintf(archivo_boleto, "Fecha y hora: %s\n", fecha_hora);
        fprintf(archivo_boleto, "Nombre: %s %s\n", boleto.nombre, boleto.apellido);
        fprintf(archivo_boleto, "Cedula: %s\n", boleto.cedula);
        fprintf(archivo_boleto, "Sala: %d\n", boleto.sala);
        fprintf(archivo_boleto, "Puesto: %c%s\n", boleto.puesto[0], boleto.puesto + 1); /**Imprimimos la letra y el numero del puesto**/
        fprintf(archivo_boleto, "Hora de la funcion: %s\n", boleto.hora);
        fprintf(archivo_boleto, "Pelicula: %s\n", boleto.pelicula);
        fprintf(archivo_boleto, "---------------------------------\n");

        printf("Boleto generado correctamente. Se ha creado el archivo 'boleto_cine.txt'.\n");

        fclose(archivo_boleto);
    } else {
        printf("Hubo un error al crear el archivo de boleto.\n"); /**Si los datos no estan bien colocados aparecera esto**/
    }

    return 0;
}

