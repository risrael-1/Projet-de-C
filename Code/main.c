#include <stdio.h>
#include <stdlib.h>
#include "validator_xml.h"



int main() {

    FILE* file1 = openFile("exemple.xml");

    int top = 0;
    char** document = parseToArray(file1,&top);

    for (int i = 0; i < top; i++) {
        printf("%s", document[i]);
    }


    printf("Hello, World!\n");


    return 0;
}
