#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct XMLTag{

    char* name;
    char* value;
    int isSimpleElement;
    int isEndOfSet;

}XMLTag;

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
    fseek(file, 0 , SEEK_SET);

    return fileSize;
}

char** parseToArray(FILE* file, int* top){

    long count = countLine(file);

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

char* substring(char* haystack, int start, int length){

    char* result = malloc(sizeof(char)*(length));

    for (int i = start; i < start+length ; i++) {
        result[i-start] = haystack[i];
    }
    result[length] = '\0';

    return result;
}

int strpos(char* haystack, char* value){
    int result = -1;
    int compareIndex = 0;

    for (int i = 0; i < strlen(haystack); i++) {
        if (haystack[i]==value[compareIndex]){
            if (compareIndex==0){
                result = i;
            }
            compareIndex++;

            if (compareIndex == strlen(value)){
                return result;
            }
        } else {
            compareIndex = 0;
            result=-1;
        }
    }

    return -1;
}

/*
 * Return 0 for NO
 * Return 1 for <tag>
 * Return 2 for </tag>
 * Return 3 for <tag></tag>
 * */
int containAnXMLTag(char* line){
    int openStart = strpos(line, "<");
    int openEnd = strpos(line, "</");
    int closeStart = 0;
    int closeEnd = 0;

    int level = 0;

    if (openStart!=-1){
        closeStart = strpos(line, ">");
        if (closeStart>0){
            level++;
        }
    }

    if (openEnd!=-1){
        closeEnd = strpos(substring(line,closeStart,strlen(line)-closeStart), ">");
        if (closeEnd>0){
            level++;
            return  level+1;
        }
    }

    return level;


}

XMLTag getXMLTag(char line[]){

    int openStart = strpos(line, "<");
    int openEnd = -1;
    int closeStart = 0;
    int closeEnd = 0;
    XMLTag result;
    result.isEndOfSet = 0;


    if (openStart!=-1){
        closeStart = strpos(line, ">");
        if (closeStart>0){
            int lenghtName = (closeStart-openStart)-1;

            char* name = substring(line, openStart+1, lenghtName);

            result.name = malloc(sizeof(char)*lenghtName);

            int slash = strpos(name, "/");
            if (slash>=0){
                result.name = substring(line, openStart+2, lenghtName-1);
                result.isSimpleElement = 0;
                result.isEndOfSet = 1;
            }else{
                strcpy(result.name, name);
            }

        }

    }

    char* closeTag = malloc(sizeof(char)*(strlen(result.name)+3));
    sprintf(closeTag, "</%s>",result.name);


    openEnd = strpos(line, closeTag);

    if (openEnd>0){
        closeEnd = openEnd+strlen(closeTag);

        result.value = substring(line, closeStart+1,(openEnd-closeStart)-1);
        result.isSimpleElement = 1;

    }else{
        result.value = NULL;
        result.isSimpleElement = 0;
    }



    return result;
}
