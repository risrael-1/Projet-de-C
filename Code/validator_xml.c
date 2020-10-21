#include <stdio.h>
#include <stdlib.h>
#include <string.h>


FILE *openFile(char *fileName) {
    FILE *f = fopen(fileName, "r");
    if(f != NULL) {
        return f;
    }
    return NULL;

}

long countLine(FILE* file){
    fseek(file, 0 , SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0 , SEEK_SET);// needed for next read from beginning of file

    return fileSize;
}

char** parseToArray(FILE* file, int* top){

    long count = countLine(file);

    fseek(file,0,SEEK_SET);

    char** document = malloc(sizeof(char)*count);

    char* line = malloc(sizeof(char)*100);
    while ( fgets( line, 100, file ) != NULL )
    {
        document[(*top)] =  malloc(sizeof(char)*100);
        strcpy(document[(*top)], line);

        *top +=1;
    }

    return document;
}
