#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int LOWERASCII(char ch)
{
    int tmp = (int)ch;
    if(65 <= tmp && tmp <= 90){
        return tmp + 32;
    }
    else{
        return tmp;
    }
}


int main()
{
    char arr[50];
    int size = 0;
    bool pl = true, dpl = true;
    printf("Enter word : ");
    scanf("%s",&arr);

    for(int i = 0 ; arr[i] != '\0' ; i++) size++;

    // printf("size = %d\n", size);

    //check Palindrome  if check == true == it is Palindrome
    for(int i = 0 ; i<(floor)(size/2) ; i++){
        if(LOWERASCII(arr[i]) != LOWERASCII(arr[size - i-1])){
            // printf("i = %d   %c != %d\n",i,LOWERASCII(arr[i]),LOWERASCII(arr[size-i-1]));
            printf("No");
            return -1;
        }
    }

    // printf("%d", check);

    int Median = (floor)(size/2);
    //check Double Palindrome   if check == true == it is Double Palindrome
    for(int i = 0 ; i<(floor)(size/2) ; i++){
        if(arr[i] != arr[Median - 1 - i]  &&  arr[Median + 1 + i] != arr[size - 1 + i])
            dpl == false;
    }



    if(dpl){
        printf("Double Palindrome");
    }
    else{
        printf("Palindrome");
    }
}