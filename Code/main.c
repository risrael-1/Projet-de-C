#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validator_xml.h"



int main() {

    printf("--Program start\n");

    FILE* file1 = openFile("exemple.xml");

    int top = 0;
    char** document = parseToArray(file1,&top);

    XMLTag tag;
    for (int i = 0; i < top; i++) {
        char eject[] = "<?xml";
        int pos = strpos(document[i],eject);
        if (!(pos>=0)){
            tag = getXMLTag(document[i]);

            printf("tag.name : %s\n",tag.name);
            printf("tag.value : %s\n",tag.value);
            printf("tag.isSimpleElement : %d\n",tag.isSimpleElement);
            printf("tag.isEndOfSet : %d\n\n",tag.isEndOfSet);
        }
    }

    printf("--Program end\n");


    return 0;
}
