#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define BUFSIZE 100     // Buffer size for ungetch
#define MAXOP 100       // Max size of operator/operand
#define MAXVAL 100      // Max depth of value stack
#define NUMBER 0        // Token indicating a number

int getop(char[]);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);

int sp = 0;             // Stack pointer
double val[MAXVAL];     // Value stack
char buf[BUFSIZE];      // Buffer for ungetch
int bufp = 0;           // Buffer pointer

int main() {
    int type;
    double op2;
    char s[MAXOP];

    // Main loop for processing input
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s)); // Convert string to double and push onto stack
                break;
            case '+':
                push(pop() + pop()); // Pop and add two values, then push the result
                break;
            case '*':
                push(pop() * pop()); // Pop and multiply two values, then push the result
                break;
            case '-':
                op2 = pop(); // Pop the second operand
                push(pop() - op2); // Pop the first operand, subtract op2, and push the result
                break;
            case '/':
                op2 = pop(); // Pop the second operand
                if (op2 != 0.0)
                    push(pop() / op2); // Pop the first operand, divide by op2, and push the result
                else
                    printf("err: Cannot Divide by 0\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop()); // Print the result of the expression
                break;
            default:
                printf("err: Unknown Command\n");
                break;
        }
    }

    return 0;
}

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f; // Push f onto the stack
    else
        printf("err: Stack Full, Cannot Push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp]; // Pop the top value from the stack
    else {
        printf("err: Stack Empty\n");
        return 0.0;
    }
}

int getop(char s[]) {
    int i, c;

    // Skip white spaces
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    // If not a digit or decimal point, return it as a character token
    if (!isdigit(c) && c != '.')
        return c;

    i = 0;

    // Read digits before and after decimal point
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER; // Return token indicating a number
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar(); // Get a character from the buffer or standard input
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("err -ungetch: Too Many Characters\n");
    else
        buf[bufp++] = c; // Put a character back into the buffer
}