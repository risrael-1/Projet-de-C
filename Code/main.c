#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validator_xml.h"



int main() {

    printf("--Program start\n");

    FILE* file1 = openFile("exemple.xml");
    FILE* file2 = openFile("test.dtd");

    int top = 0;
    int top2 = 0;
    char** document = parseToArray(file1,&top);
    char** document2 = parseToArray(file2,&top2);

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

    DTDTag dtd;
    for (int i = 0; i < top2; i++) {
        char eject[] = "<!DOCTYPE";
        char eject2[] = "]>";
        int pos = strpos(document2[i],eject);
        int pos2 = strpos(document2[i],eject2);

        if (!(pos>=0) && !(pos2>=0)){
            dtd = getDTDTag(document2[i]);
            printf("%s\n", document2[i]);

            printf("dtd.name : %s\n",dtd.name);
            printf("dtd.contentType : %s\n",dtd.contentType);
            printf("dtd.isSimpleElement : %d\n",dtd.isSimpleElement);

        }
    }

    printf("--Program end\n");


    return 0;
}
