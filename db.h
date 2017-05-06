#include<stdio.h>
#include<stdlib.h>
#include<string.h>
TESTANDO MODIFICAÇÃO
void setRecordInt(char *fileName, char *key, int val, int append){

    FILE *file;

    if(append == 1){
        file = fopen(fileName, "a");
    }
    else{
        file = fopen(fileName, "w");
    }

    fprintf(file, "%s %d\n", key, val);

    fclose(file);

}

void setRecordFloat(char *fileName, char *key, float val, int append){

    FILE *file;

    if(append == 1){
        file = fopen(fileName, "a");
    }
    else{
        file = fopen(fileName, "w");
    }

    fprintf(file, "%s %f\n", key, val);

    fclose(file);

}

void setRecordString(char *fileName, char *key, char *val, int append){

    FILE *file;

    if(append == 1){
        file = fopen(fileName, "a");
    }
    else{
        file = fopen(fileName, "w");
    }

    fprintf(file, "%s %s\n", key, val);

    fclose(file);

}

int getRecordInt(char *fileName, char *key){

    FILE *file = fopen(fileName, "r");

    do{

        char *in_key = malloc(sizeof(char));
        fscanf(file, "%s", in_key);

        if(strncmp(in_key, key, 1) == 0){
            int val;
            fscanf(file, "%d", &val);
            rewind(file);
            fclose(file);
            return val;
        }

    }while(!feof(file));

    fclose(file);
    return -1;

}

float getRecordFloat(char *fileName, char *key){

    FILE *file = fopen(fileName, "r");

    do{

        char *in_key = malloc(sizeof(char));
        fscanf(file, "%s", in_key);

        if(strncmp(in_key, key, 1) == 0){
            float val;
            fscanf(file, "%f", &val);
            rewind(file);
            fclose(file);
            return val;
        }

    }while(!feof(file));

    fclose(file);
    return -1.0;

}

char * getRecordString(char *fileName, char *key){

    FILE *file = fopen(fileName, "r");

    do{

        char *in_key = malloc(sizeof(char));
        fscanf(file, "%s", in_key);

        if(strncmp(in_key, key, 1) == 0){
            char *val = malloc(sizeof(char));
            fscanf(file, "%s", &val);
            rewind(file);
            fclose(file);
            return val;
        }

    }while(!feof(file));

    fclose(file);
    return "";

}
