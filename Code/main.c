#include <stdio.h>
#include <stdlib.h>

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

int main() {
    openFile("../exemple.xml");
    openFile("../test.dtd");
    printf("Hello, World!\n");
    return 0;
}



