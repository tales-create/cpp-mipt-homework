#include <stdio.h>

void alice(int n);
void bob(int n);

void alice(int n)
{
    int result = n * 3 + 1;
    printf("Alice: %d\n", result);
    bob(result);
}

void bob(int n)
{
    int result = n / 2;
    printf("Bob: %d\n", result);

    if (result == 1)
    {
        return;
    }

    if (result % 2 != 0)
    {
        alice(result);
    }
    else
    {
        bob(result);
    }
}

int main()
{
    alice(13);
    return 0;
}