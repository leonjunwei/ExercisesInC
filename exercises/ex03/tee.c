#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char * argv[]) {
    /*Only 2 supported syntaxes: tee -a [OUTPUT] or tee [OUTPUT]*/


   FILE *fp;
   int c;

    if (argc>3) { /*ls | ./tee -a output.txt is the maximum this implementation will support*/
        printf("Too many args. Try again, please.\n");
        return 0;
    }

    else if (argc<2) {
        printf("Too few args. Syntax: tee [-a] [-i] [File...]\n");
        return 0;
    }

    if (strcmp(argv[1],"-a") != 0){ /*tee [OUTPUT]*/
        fp = fopen(argv[1],"w");
    } else {
        fp = fopen(argv[2],"a"); /*tee -a [OUTPUT]. Documentation says this should work.*/
    }
   
   while(1) {
      c = fgetc(stdin);
      if( feof(stdin) ) { 
         break ;
      }
      printf("%c", c);
      fprintf(fp, "%c", c);
   }
   fclose(fp);
   
   return(0);
}



// #define BLOCK_SIZE 512


// main(int argc, char *argv[]){
//     // printf("argc: %i\n", argc);  /*number of args. The name of the binary file is apparently one.*/
//     // printf("%s\n", argv[0]); /* this is ./tee when I run it.*/
//     // printf("%s\n", argv[1]);

//     char * destination = "./test.txt";
//     FILE * fp;

//     if (argc>4) {
//         printf("Too many args. Try again, please.\n");
//         return 0;
//     }

//     else if (argc<3) {
//         printf("Too few args. Syntax: tee [-a] [-i] [File...]\n");
//         return 0;
//     }

//     else {
//         fp = fopen (destination,"w");
        
//         char buffer[BLOCK_SIZE+1];
//         for(;;) {
//             size_t bytes = fread(buffer,  sizeof(char),BLOCK_SIZE,stdin);
//             fwrite(buffer, sizeof(char), bytes, stdout);
//             fputs (buffer, fp);
//             fflush(stdout);
//             if (bytes < BLOCK_SIZE)
//                 if (feof(stdin)) {
//                     fflush(fp);
//                     fclose(fp);
//                     break;
//                 }

//             }

        
//     }

// }