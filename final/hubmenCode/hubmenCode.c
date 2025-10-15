#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct heapNode
{
    char ch;
    int count;
};

char myString[512];

char stringSet[512];
int nStringSet[512];
int iCount = 0;

char *stringCount(char *str)
{
    if (*str == '\0')
    {
        stringSet[iCount] = '\0';
        return 0;
    }
    int count = 1;
    char charcount = str[0];
    // printf("Counting %c\n",charcount);
    char newStr[512];
    char *newStrPtr = newStr;
    str++;
    while (*str != '\0')
    {
        if (*str == charcount)
        {
            count++;
        }
        else
        {
            *newStrPtr = *str;
            newStrPtr++;
        }
        str++;
    }
    stringSet[iCount] = charcount;
    nStringSet[iCount] = count;
    iCount++;
    *newStrPtr = '\0';
    // printf("new Str is %s\n",newStr);
    stringCount(newStr);
}

int main(int argc, char const *argv[])
{

    scanf("%[^\n]", myString);
    char *tmp = myString;
    int Ccount, iCount = 0;
    ;
    stringCount(tmp);

    char *tmpstrSet = stringSet;
    int *tmpNStringSet = nStringSet;
    printf("\n1. Frequency table of %ld characters\n", strlen(stringSet));
    while (*tmpstrSet != '\0')
    {
        printf("'%c' = %d ", *tmpstrSet, *tmpNStringSet);
        tmpstrSet++;
        tmpNStringSet++;
    }
    printf("\n");

    // 2.Build Huffman tree
    tmpstrSet = stringSet;
    tmpNStringSet = nStringSet;

    struct heapNode arrHeap[512];

    
    struct heapNode tmpHeapNode;
    int index, par;
    for(int i=0 ; i<strlen(tmpstrSet) ; i++){
        arrHeap[i].ch = *(tmpstrSet+i);
        arrHeap[i].count = *(tmpNStringSet+i);

        index = i;
        while(index>=0){
            par = (index-1)/2;
            if(arrHeap[index].count < arrHeap[par].count){
                tmpHeapNode = arrHeap[index];
                arrHeap[index] = arrHeap[par];
                arrHeap[par] = tmpHeapNode;
            }
            else{
                index--;
            }
        }
    }

    printf("\n2. A Min-Heap (the less frequency, the higher priority)\n");
    for(int i=0 ; i<strlen(tmpstrSet) ; i++){
        printf("'%c' = %d ", arrHeap[i].ch, arrHeap[i].count);
    }
    printf("\n");



    //2.2 A Huffman tree
    
    

    return 0;
}
