#include <stdio.h>

int checkBalance(char input[]){
    size_t length = strlen(input);
    int esq =0, dir =0;
    for(int i=0; i<length; i++){
        if(input[i]=='('){
            esq++;
        }
        else if(input[i]==')'){
            dir++;
        }
    }
    return esq==dir?1:0;
}

int main(){
    char input_1[] = "(hello (world))";
    char input_2[] = "((hello (world))";
    char input_3[] = "hello world";
    printf("Exemplo de entrada 1, (hello (world)), quando executado retorna o valor: %d \n", checkBalance(input_1));
    printf("Exemplo de entrada 2, ((hello (world)), quando executado retorna o valor: %d \n", checkBalance(input_2));
    printf("Exemplo de entrada 3, hello world, quando executado retorna o valor: %d \n", checkBalance(input_3));
}