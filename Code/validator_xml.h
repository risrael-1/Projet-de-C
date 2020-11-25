typedef struct XMLTag{
    char* name;
    char* value;
    int isSimpleElement;
    int isEndOfSet;
    char** parametersKeys;
    char** parametersValues;

}XMLTag;

typedef struct DTDTag{
    char* name;
    char* contentType;
    int isSimpleElement;
}DTDTag;

FILE *openFile(char *fileName);

long countLine(FILE* file);

char** parseToArray(FILE* file, int* top);

char* substring(char* haystack, int start, int length);

int strpos(char* haystack, char* value);

XMLTag getXMLTag(char* line);

DTDTag getDTDTag(char line[]);

int compare(XMLTag xml[], int xml_size, DTDTag dtd[], int dtd_size);
