// // ex. for hw1 and hw2

#include <stdio.h>

#define MAX_WORD_LENGTH 10

int main() {
    int c, word_length = 0;
    int word_lengths[MAX_WORD_LENGTH + 1] = {0};

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (word_length > 0) {
                if (word_length > MAX_WORD_LENGTH) {
                    word_lengths[MAX_WORD_LENGTH]++;
                } else {
                    word_lengths[word_length]++;
                }
                word_length = 0;  
            }
        } else {
            word_length++;
        }
    }

    // Count the last word if input does not end with whitespace
    if (word_length > 0) {
        if (word_length > MAX_WORD_LENGTH) {
            word_lengths[MAX_WORD_LENGTH]++;
        } else {
            word_lengths[word_length]++;
        }
    }

    printf("\nWord Length Histogram:\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {
        printf("%d: ", i);
        for (int j = 0; j < word_lengths[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    if (word_lengths[MAX_WORD_LENGTH] > 0) {
        printf("10+: ");
        for (int j = 0; j < word_lengths[MAX_WORD_LENGTH]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

#define MAXLINE 1000   

void reverse(char s[]); 
int get_line(char line[], int maxline); 

int main() { 
    char line[MAXLINE]; 

    while (get_line(line, MAXLINE) > 0) { 
        reverse(line);   
        printf("%s", line);   
    } 

    return 0; 
}

void reverse(char s[]) {
    int i = 0, j;
    char temp;

    while (s[i] != '\0' && s[i] != '\n') {
        i++;
    }

    j = i - 1;  

    for (int k = 0; k < (j + 1) / 2; k++, j--) {
        temp = s[k];
        s[k] = s[j];
        s[j] = temp;
    }
}

int get_line(char line[], int maxline) {
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';  
    return i;
}

#include <stdio.h>

void escape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\n') {         
            s[j++] = '\\';
            s[j++] = 'n';
        } else if (t[i] == '\t') {  
            s[j++] = '\\';
            s[j++] = 't';
        } else {                    
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';  
}

void unescape(char s[], char t[]) {
    int i = 0, j = 0;
    while (t[i] != '\0') {
        if (t[i] == '\\' && (t[i + 1] == 'n' || t[i + 1] == 't')) {
            s[j++] = (t[i + 1] == 'n') ? '\n' : '\t';
            i++;  // Skip next character
        } else {
            s[j++] = t[i];
        }
        i++;
    }
    s[j] = '\0';  
}

int main() {
    char s[100], t[100] = "Hello\nWorld\t!";
    escape(s, t);
    printf("Escaped: %s\n", s);

    char u[100];
    unescape(u, s);
    printf("Unescaped: %s\n", u);

    return 0;
}

#include <stdio.h>

void expand(char s1[], char s2[]) {
    int i = 0, j = 0;
    while (s1[i] != '\0') {
        if (s1[i + 1] == '-' && s1[i + 2] >= s1[i]) {  
            char start = s1[i];
            char end = s1[i + 2];
            for (char c = start; c <= end; c++) {
                s2[j++] = c;
            }
            i += 2;  
        } else {
            s2[j++] = s1[i];
        }
        i++;
    }
    s2[j] = '\0';  
}

int main() {
    char s1[] = "a-d0-3";
    char s2[100];
    expand(s1, s2);
    printf("Expanded: %s\n", s2);

    return 0;
}

#include <stdio.h>

void itob(int n, char s[], int b) {
    int i = 0;
    do {
        int digit = n % b;
        s[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';  
        n /= b;
    } while (n > 0);
    
    s[i] = '\0';

    int start = 0, end = i - 1;
    while (start < end) {
        char temp = s[start];
        s[start++] = s[end];
        s[end--] = temp;
    }
}

int main() {
    int n = 255;
    char s[100];
    itob(n, s, 16);
    printf("Hexadecimal: %s\n", s);

    itob(n, s, 2);
    printf("Binary: %s\n", s);

    return 0;
}
