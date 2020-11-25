#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validator_xml.h"



int main() {

    char test[20] = {0};
    printf("--Program start\n");

    printf("Veuillez verifier que les fichiers dtd et xml soient places dans le dossier de build\n");
    printf("Voulez vous lancer la comparaison ? (y/n)  ");
    scanf("%s", test);
    printf("--------------------------------------------\n\n");

    if(*test == 'y' || *test == 'Y') {

        FILE *file1 = openFile("exemple.xml");
        FILE *file2 = openFile("test.dtd");

        int top = 0;
        int top2 = 0;
        char **document = parseToArray(file1, &top);
        char **document2 = parseToArray(file2, &top2);


        XMLTag xmls[top];
        int summitXmls = 0;
        DTDTag dtds[top2];
        int summitDtds = 0;

        XMLTag tag;
        printf("\n- Extract XML\n\n");
        for (int i = 0; i < top; i++) {
            char eject[] = "<?xml";
            int pos = strpos(document[i], eject);
            if (!(pos >= 0)) {
                tag = getXMLTag(document[i]);
                xmls[summitXmls] = tag;
                summitXmls++;


                printf("tag.name : %s\n",tag.name);
                printf("tag.value : %s\n",tag.value);
                printf("tag.isSimpleElement : %d\n",tag.isSimpleElement);
                printf("tag.isEndOfSet : %d\n",tag.isEndOfSet);

                printf("tag.parametersSize : %d\n",tag.parametersSize);

                for (int j = 0; j < tag.parametersSize; j++){
                    printf("tag.dico : [%s, %s]\n",tag.parametersKeys[j], tag.parametersValues[j] );
                }

            }
        }

        printf("\n\n- Extract DTD\n\n");

        DTDTag dtd;
        for (int i = 0; i < top2; i++) {
            char eject[] = "<!DOCTYPE";
            char eject2[] = "]>";
            int pos = strpos(document2[i], eject);
            int pos2 = strpos(document2[i], eject2);

            if (!(pos >= 0) && !(pos2 >= 0)) {
                dtd = getDTDTag(document2[i]);
                dtds[summitDtds] = dtd;
                summitDtds++;

                printf("dtd.name : %s\n",dtd.name);
                printf("dtd.contentType : %s\n",dtd.contentType);
                printf("dtd.isSimpleElement : %d\n",dtd.isSimpleElement);
                printf("dtd.isElement : %d\n",dtd.isElement);
                printf("dtd.parametersList : %s\n",dtd.parametersList);


            }

        }

        int result = compare(xmls, summitXmls, dtds, summitDtds);
        printf("\n");
        for (int i = 0; i < 20; ++i) {
            printf("#");
        }
        if (result == 1) {
            printf("\nLe XML est valide !\n");
        } else {
            printf("\nLe XML n'est pas valide !\n");
        }
        for (int i = 0; i < 20; ++i) {
            printf("#");
        }

        printf("\n--Program end\n");

        fclose(file1);
        fclose(file2);

        free(document);
        free(document2);
        free(xmls);
        free(dtds);


        return 0;
    } else {
        printf("A bientot");

    }
}