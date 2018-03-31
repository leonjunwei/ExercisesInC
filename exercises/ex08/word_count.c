#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <string.h>

/*
From https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings.

Uses two very unsafe functions.
*/
char* ReadFile(char *filename)
{
   char *buffer = NULL;
   int string_size, read_size;
   FILE *handler = fopen(filename, "r");

   if (handler)
   {
       // Seek the last byte of the file. Apparently very unsafe.
       fseek(handler, 0, SEEK_END);
       // Offset from the first to the last byte, or in other words, filesize. Apparently very unsafe.
       string_size = ftell(handler);
       // go back to the start of the file
       rewind(handler);

       // Allocate a string that can hold it all
       buffer = (char*) malloc(sizeof(char) * (string_size + 1) );

       // Read it all in one operation
       read_size = fread(buffer, sizeof(char), string_size, handler);

       // fread doesn't set it so put a \0 in the last position
       // and buffer is now officially a string
       buffer[string_size] = '\0';

       if (string_size != read_size)
       {
           // Something went wrong, throw away the memory and set
           // the buffer to NULL
           free(buffer);
           buffer = NULL;
       }

       // Always remember to close the file.
       fclose(handler);
    }

    return buffer;
}

void printTable(gpointer key, gpointer data, gpointer userdata) {
    printf("%s : %s\n", (char*) key, (char*) data);
}

int main(int argc, char** argv) {
    if (argc > 3) {
        printf("Too many args");
        return 0;
    }
    GHashTable* hashtable = g_hash_table_new(g_str_hash, g_str_equal);
    
    gchar * string = ReadFile(argv[1]);

    gchar ** string_array;

    if (string) {
        string_array = g_strsplit(string, " ",-1);
        int i = 0;

        while(string_array[i] != NULL) {
            printf("array %d is %s\n", i, string_array[i]);            

            char * wordcount = g_hash_table_lookup(hashtable, string_array[i]);
            if (wordcount == NULL) {
                g_hash_table_insert(hashtable, string_array[i],"1");
            } else {
                printf("wordcount: %s\n", wordcount);
                int count = atoi(wordcount) + 1;
                char str[1000];
                sprintf(str, "%d", count);
                g_hash_table_replace(hashtable, string_array[i], str);
            }
            i++;
        }

    } else {
        printf("No file found. Usage: ./word_count [TARGET_FILE] [optional: TARGET_WORD]");
    }

    /* used like so:

    ./word_count target_file target_word

    Finds out how many times that word appears.
    */
    if (argc == 3) {
        gchar* target = argv[2];
        char * result = g_hash_table_lookup(hashtable, target);
        if (result==NULL) {
            printf("nothing found\n");
        } else {
            printf("Number of occurences of word %s: %s\n", target, result);
        }
    }

    else {
        g_hash_table_foreach(hashtable, printTable, NULL); /*For some reason this segfaults. Running it with a target word is fine though.*/
    }

    g_strfreev(string_array);
    free(string);
    g_hash_table_destroy(hashtable);
    return 0;
}