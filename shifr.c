#include <stdio.h>
#include <string.h>

// Функція шифрування Цезаря
void caesarEncrypt(char *str, int key) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') { 
            str[i] = (str[i] - 'A' + key) % 26 + 'A'; 
        } else if (str[i] >= 'a' && str[i] <= 'z') { 
            str[i] = (str[i] - 'a' + key) % 26 + 'a'; 
        }
    }
}

// Функція частотного аналізу для зламу шифру
int breakCaesar(char *encryptedStr) {
    int freq[26] = {0}; 
    int maxFreq = 0; 
    int mostFrequentLetterIndex = 0; 

    // Підрахунок частоти літер
    for (int i = 0; encryptedStr[i] != '\0'; i++) {
        if (encryptedStr[i] >= 'A' && encryptedStr[i] <= 'Z') {
            int index = encryptedStr[i] - 'A';
            freq[index]++;
            if (freq[index] > maxFreq) {
                maxFreq = freq[index];
                mostFrequentLetterIndex = index;
            }
        } else if (encryptedStr[i] >= 'a' && encryptedStr[i] <= 'z') {
            int index = encryptedStr[i] - 'a'; 
            freq[index]++;
            if (freq[index] > maxFreq) {
                maxFreq = freq[index];
                mostFrequentLetterIndex = index; 
            }
        }
    }

    // Обчислюємо ключ на основі частоти
    int key = (mostFrequentLetterIndex - ('e' - 'a') + 26) % 26; 
    return key;
}

// Функція зламу шифру перебором всіх ключів
void breakCaesarBruteForce(char *encryptedStr) {
    char tempStr[100];
    for (int key = 1; key < 26; key++) { 
        strcpy(tempStr, encryptedStr); 
        caesarEncrypt(tempStr, 26 - key); 
        printf("Ключ %d: %s\n", key, tempStr); 
    }
}

int main() {
    char str[100];
    int key;

    // Введення рядка та ключа шифрування
    printf("Введіть рядок для шифрування (до 100 символів): ");
    fgets(str, 100, stdin);
    // Видаляємо символ нового рядка, якщо він є
    str[strcspn(str, "\n")] = '\0';

    printf("Введіть ключ шифрування: ");
    scanf("%d", &key);

    // Обмеження ключа до діапазону 0-25
    key = key % 26;

    // Шифрування рядка
    caesarEncrypt(str, key);
    printf("Зашифрований рядок: %s\n", str);

    // Злам шифру методом частотного аналізу
    int crackedKey = breakCaesar(str);
    printf("Зламаний ключ: %d\n", crackedKey);

    // Злам шифру методом грубої сили
    printf("Розшифрування за допомогою грубої сили:\n");
    breakCaesarBruteForce(str);

    return 0;
}
