#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Функція для перевірки, чи підрядок знайдено (ігноруючи регістр)
int findSubstringIgnoreCase(char *str, char *substr) {
    int lenStr = strlen(str);
    int lenSubstr = strlen(substr);

    for (int i = 0; i <= lenStr - lenSubstr; i++) {
        int j;
        for (j = 0; j < lenSubstr; j++) {
            if (tolower(str[i + j]) != tolower(substr[j])) {
                break; 
            }
        }
        if (j == lenSubstr) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    char str[100], substr[100];

    // Введення рядка та підрядка
    printf("Введіть оригінальний рядок: ");
    fgets(str, 100, stdin);
    printf("Введіть підрядок: ");
    fgets(substr, 100, stdin);

    // Видаляємо символи нового рядка (newline)
    str[strcspn(str, "\n")] = '\0';
    substr[strcspn(substr, "\n")] = '\0';

    // Пошук підрядка
    int index = findSubstringIgnoreCase(str, substr);
    if (index != -1) {
        printf("Підрядок знайдено на індексі: %d\n", index);
    } else {
        printf("Підрядок не знайдено\n");
    }

    return 0;
}
