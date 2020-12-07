#include <iostream>
#include <string.h>
#define MAXSIZE 255

char* get_word(char* string, int start, int end){
    char * word = (char *) malloc(sizeof(char) * MAXSIZE);
    memmove(word, string+start, end - start + 1);
    return word;
}

int check_(char s){
    char symbol[4] = {'.', ',', '!', '?'};
    for(int i = 0; i < 4; ++i){
        if(symbol[i] == s) return 1;
    }
    return 0;
}

void problem3(){
    printf("Введите строку для преобразования:\n");
    char *str = (char *) malloc(sizeof(char) * MAXSIZE);
    fgets(str, MAXSIZE, stdin);

    int size = strlen(str) - 2;

    int i = size;
    int start, end;
    int flag = 0;
    while(i >= 0){
        if(flag == 0 && str[i] != ' ' && !check_(str[i])){ end = i; flag = 1;}
        else if(flag == 1 && (str[i] == ' ' || check_(str[i]))){start = i + 1; break;}
        i--;
    }

    char *word = (char *) malloc(sizeof(char) * MAXSIZE);
    word = get_word(str, start, end);

    i = 0;
    flag = 0;
    int end1 = start;
    start = 0; end = 0;
    while(i <= end1){
        if(!flag && str[i] != ' '){
            flag = 1;
            start = i;
        }
        else if(flag && (str[i] == ' ' || check_(str[i]))){
            flag = 0;
            end = i - 1;
            char *check_word = (char *) malloc(sizeof(char) * MAXSIZE);
            check_word = get_word(str, start, end);
            if(strcmp(word, check_word) != 0) {
                fputs(check_word, stdout);
                printf(" ");
            }
        }
        i++;
    }
}



int main() {
    printf("TASK10.3\n");
    problem3();
    return 0;
}
