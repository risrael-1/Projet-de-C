#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openFile(char *fileName) {
    FILE *f = fopen(fileName, "r");
    if(f != NULL) {
        //printf("ok");
        return f;
    } else {
        //printf("echec");
        return NULL;
       //
    }

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

int main() {
    FILE* file1 = openFile("../exemple.xml");
    openFile("../test.dtd");

    int top = 0;
    char** document = parseToArray(file1,&top);

    for (int i = 0; i < top; i++) {
        printf("%s", document[i]);
    }


    printf("Hello, World!\n");




    return 0;
}



