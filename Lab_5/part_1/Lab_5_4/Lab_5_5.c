#include <stdio.h>
#include <string.h>

int main() {
    int d;
    int num;
    char roman[99] = "";

    scanf("%d", &d);

    int count[5] = {0};

    int values[] =   {100, 90,  50, 40,  10, 9,   5, 4,  1};
    char *symbols[] ={"C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for(int n = 1; n <= d; n++){
        num = n;
        roman[0] = '\0';
        
        for(int i = 0; i < 9; i++){
            while(num >= values[i]){
                strcat(roman, symbols[i]);
                num -= values[i];
            }
        }

        
        for(int i = 0; roman[i] != '\0'; i++){
            switch (roman[i]) {
                case 'I': count[0]++; break;
                case 'V': count[1]++; break;
                case 'X': count[2]++; break;
                case 'L': count[3]++; break;
                case 'C': count[4]++; break;
            }
        }
    }






    for(int i=0 ; i<5 ; i++){
        printf("%d ",count[i]);
    }
}
