#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Wrong number of arguments!\n");
        return 1;
    }

    long long a, b;
    char op;
    char tail[2];

    int parsed = sscanf(argv[1], "%lld %c %lld %1s", &a, &op, &b, tail);

    if (parsed < 3) {
        // Проверяем, ввели ли правильные числа
        long long dummy_a, dummy_b;
        char dummy_op;
        if (sscanf(argv[1], "%*f %c %*f", &dummy_op) > 0 || sscanf(argv[1], "%lld", &dummy_a) == 1) {
            printf("Error: Wrong format!\n");
        } else {
            printf("Error: Operands should be integers!\n");
        }
        return 1;
    }

    if (parsed > 3) {
        printf("Error: Wrong format!\n");
        return 1;
    }

    switch (op) {
        case '+': printf("%lld\n", a + b); break;
        case '-': printf("%lld\n", a - b); break;
        case '*': printf("%lld\n", a * b); break;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            printf("%lld\n", a / b);
            break;
        case '%':
            if (b == 0) {
                printf("Error: Division by zero!\n");
                return 1;
            }
            printf("%lld\n", a % b);
            break;
        default:
            printf("Error: Invalid operator!\n");
            return 1;
    }

    return 0;
}