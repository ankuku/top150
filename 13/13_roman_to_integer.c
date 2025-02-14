#include <stdio.h>
#include <string.h>

int romanCharToInt(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0; // Return 0 for invalid characters
    }
}


int romanToInt(char* s) {
    int result = 0;
    int prev = 0;

    for (int i = strlen(s) - 1; i >= 0; i--) {
        int curr = romanCharToInt(s[i]);
        if (curr < prev) {
            result -= curr;
        } else {
            result += curr;
        }
        prev = curr;
    }
    return result;
}


int main() {
    char s[] = "MCMXCIV";
    int result = romanToInt(s);
    printf("%d\n", result);
    return 0;
}