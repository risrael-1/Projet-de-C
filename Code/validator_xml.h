
typedef struct XMLTag{

    char* name;
    char* value;
    int isSimpleElement;
    int isEndOfSet;

}XMLTag;

FILE *openFile(char *fileName);

long countLine(FILE* file);

char** parseToArray(FILE* file, int* top);

char* substring(char* haystack, int start, int length);

int strpos(char* haystack, char* value);

XMLTag getXMLTag(char* line);

