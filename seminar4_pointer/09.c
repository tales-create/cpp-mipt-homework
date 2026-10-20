#include <stdio.h>
#include <string.h>
#include <ctype.h>

void used_chars(const char* str, char* used) {
    int present[26] = {0};

    for (const char* p = str; *p != '\0'; ++p) {
        if (isalpha((unsigned char)*p)) {
            char lower_char = (char)tolower((unsigned char)*p);
            present[lower_char - 'a'] = 1;
        }
    }

    int idx = 0;
    for (int i = 0; i < 26; ++i) {
        if (present[i]) {
            used[idx++] = (char)('a' + i);
        }
    }
    used[idx] = '\0';
}

//int main(void) {
    char s[100] = "Sapere Aude";
    char u[30];

    used_chars(s, u);
    printf("%s\n", u); // Напечатает "adeprsu"

    strcpy(s, "123!$ ");
    used_chars(s, u);
    printf("%s\n", u); // Ничего не напечатает (только перенос строки)

    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u); // Напечатает "abcdefghijklmnopqrstuvwxyz"

    return 0;
}