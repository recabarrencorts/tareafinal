#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
  FILE *fp; 
  fp = fopen("entrada.txt", "r");
  const char EndOfLine[] = "\n";

  int a = pow(2,2);

  char linea[5000];

  while ( fgets (linea, 1000, fp) != NULL ) { // Lee el archivo linea por linea
    linea[strcspn(linea, "\r\n")] = 0; // elimina el salto de linea de la palabra
    
    char delim[] = " "; // define como delimitador el espacio para separar cada palabra
    char *palabra = strtok(linea, delim); // separa linea por delimitador (palabra por palabra) una vez
    while(palabra != NULL){   // recorre palabra a palabra
      /*
      En este punto, usted puede acceder a palabra
      */
     // printf("'%s'\n", palabra); // ELIMINAR. Imprime la palabra.
     for (int i=0;  i<strlen(palabra); i++){
       int elvalordelcaracter = (int)palabra[i];
       printf("%i-", elvalordelcaracter);

     }
    printf("/n@@/n");

     palabra = strtok(NULL, delim); // vuelve a separar palabra a palabra. Si usted elimina esta linea el programa no se detiene
     
   
   
    }
  
  
  fclose(fp); // cierra el archivo de entrada 

FILE *fp_lectura;
fp_lectura= fopen("salida.txt", "w");
//fwrite(palabra, sizeof(char), sizeof(palabra), fp_lectura );
for( int idx = 0; idx < ( sizeof(palabra) / sizeof( palabra[1] ) ); ++idx ) {
    fwrite(palabra[idx], sizeof( char ), sizeof( palabra[0] ), fp_lectura );
    fwrite( EndOfLine, sizeof( EndOfLine ) - 1 , 1, fp_lectura );
  }


/*FILE *fichero;
fichero = fopen("salida.txt","w+");
fwrite(i, sizeof(char), sizeof(i), fichero);
fclose(fichero);*/

fclose(fp_lectura);

  return 0;
}
}