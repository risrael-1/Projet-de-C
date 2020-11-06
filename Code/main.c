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


    XMLTag xmls[top];int summitXmls = 0;
    DTDTag dtds[top2];int summitDtds = 0;

    XMLTag tag;
    for (int i = 0; i < top; i++) {
        char eject[] = "<?xml";
        int pos = strpos(document[i],eject);
        if (!(pos>=0)){
            tag = getXMLTag(document[i]);
            xmls[summitXmls] = tag;
            summitXmls++;

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
            dtds[summitDtds] = dtd;
            summitDtds++;

            printf("dtd.name : %s\n",dtd.name);
            printf("dtd.contentType : %s\n",dtd.contentType);
            printf("dtd.isSimpleElement : %d\n",dtd.isSimpleElement);

        }

    }

    int result = compare(xmls, summitXmls, dtds, summitDtds);

    if (result==1){
        printf("XML is valid !\n");
    }else{
        printf("XML is not valid !\n");
    }

    printf("--Program end\n");

    fclose(file1);
    fclose(file2);


    return 0;
}
