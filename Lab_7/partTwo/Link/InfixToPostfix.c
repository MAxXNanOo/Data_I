#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};

struct node *Top, *ansTop, *ans;

void push(char data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = Top;
    Top = new_node;
    // printf("push %c    ",Top->data);
}

void anspush(char data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = ansTop;
    ansTop = new_node;
}

void makeans(char data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = ans;
    ans = new_node;
}

char pop()
{
    if(Top){
        char tmp = Top->data;
        Top = Top->next;
        return tmp;
    }
    else{
        return 'e';
    }
}

char anspop()
{
    if(ansTop){
        char tmp = ansTop->data;
        ansTop = ansTop->next;
        return tmp;
    }
    else{
        return 'e';
    }
}

char peek(struct node *ptr)
{
    if(ptr){
        return ptr->data;
    }
    else{
        return 'e';
    }
}



int main()
{
    char input[1000];
    
    scanf("%s", &input);

    for(int i=0 ; input[i] != '\0' ; i++ ){
        switch(input[i]){
            case '(':
            case '[':
            case '{':
                push(input[i]);
            break;

            case '^':
                push('^');
            break;

            case '*':
            case '/':
                while(peek(Top) == '^' || peek(Top) == '*' || peek(Top) == '/'){
                    anspush(pop());
                }

                push(input[i]);
                // char tmp;
                // if(input[i] == '^' || input[i] == '*' || input[i] == '/'){

                // }
            break;

            case '+':
            case '-':
                while(peek(Top) == '^' || peek(Top) == '*' || peek(Top) == '/' || peek(Top) == '+' || peek(Top) == '-'){
                    anspush(pop());
                }

                push(input[i]);
            break;

            case ')':
            case ']':
            case '}':
                while(1){
                    if(input[i] == ')' && peek(Top) == '('){
                        // printf("stop");
                        pop();
                        break;
                    }
                    else if(input[i] == ']' && peek(Top) == '['){
                        pop();
                        break;
                    }
                    else if(input[i] == '}' && peek(Top) == '{'){
                        pop();
                        break;
                    }
                    else{
                        // pop();
                        // printf("stop");
                        anspush(pop());
                        // anspush('!');
                    }
                }
                break;

            default:
                anspush(input[i]);
        }
    }

    while(Top){
        anspush(pop());
    }

    while(ansTop){
        makeans(anspop());
    }

    while(ans){
        printf("%c",ans->data);
        ans = ans->next;
    }
}