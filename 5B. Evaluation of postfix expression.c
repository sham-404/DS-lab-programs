// Uncomment #include <conio.h>, getch() and clrscr() if you are using Turbo C

#include <stdio.h>
#include <string.h>
#include <ctype.h>
// #include <conio.h>

#define STACKSIZE 10

struct stack {
    int top;
    int item[STACKSIZE];
};

void push(struct stack *sptr, int data) {
    if (sptr->top == STACKSIZE - 1) {
        printf("\nStack overflow");
    } else {
        sptr->item[++sptr->top] = data;
    }
}

int pop(struct stack *sptr) {
    if (sptr->top == -1) {
        return -1; // underflow
    } else {
        return sptr->item[sptr->top--];
    }
}

int main(void) {
    struct stack s;
    char exp[50];
    int len, a, b, c, val, result;

    s.top = -1;

    // clrscr();

    printf("Enter the postfix expression: ");
    scanf("%s", exp);

    len = strlen(exp);
    printf("Length: %d\n", len);
    printf("Postfix expression: %s\n", exp);

    for (int i = 0; i < len; i++) {
        char ch = exp[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            a = pop(&s);
            b = pop(&s);

            switch (ch) {
                case '+': c = b + a; break;
                case '-': c = b - a; break;
                case '*': c = b * a; break;
                case '/': c = b / a; break;
            }

            push(&s, c);
            result = c;
        } else if (isalpha((unsigned char)ch)) {
            printf("Enter the value of %c = ", ch);
            scanf("%d", &val);
            push(&s, val);
        }
    }

    printf("Result = %d\n", result);

    // getch();

    return 0;
}
