#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Program to Read Names and Print Duplicates
#define MAX_NAMES 100
#define NAME_LENGTH 50

int main() {
    char names[MAX_NAMES][NAME_LENGTH];
    int n, i, j;

    printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar(); 

    for (i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], NAME_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0'; 
    }

    printf("\nDuplicate names:\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                printf("%s\n", names[i]);
                break; 
            }
        }
    }

    return 0;
}


// Program to Print the Transpose of a Matrix
#define MAX_SIZE 10

int main() {
    int matrix[MAX_SIZE][MAX_SIZE], transpose[MAX_SIZE][MAX_SIZE];
    int rows, cols, i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose of the matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Program to Print the Last N Lines of Input (Tail)
#define MAX_LINES 1000

int main(int argc, char *argv[]) {
    char *lines[MAX_LINES];
    int n = 10; 
    int count = 0;

    if (argc > 1) {
        n = atoi(argv[1]);
        if (n <= 0) {
            printf("Please enter a positive number.\n");
            return 1;
        }
    }

    while (count < MAX_LINES && (lines[count] = malloc(256))) {
        if (fgets(lines[count], 256, stdin) == NULL) break;
        count++;
    }

    printf("\nLast %d lines:\n", n);
    for (int i = count - n; i < count; i++) {
        if (i >= 0) printf("%s", lines[i]);
    }

    for (int i = 0; i < count; i++) {
        free(lines[i]);
    }

    return 0;
}



// Program to Sort an Array of Strings Using a Callback Function
#define MAX_STRINGS 100
#define STRING_LENGTH 50

int compareAsc(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int compareDesc(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);
}

int main() {
    char *strings[MAX_STRINGS];
    int n;

    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar(); 

    printf("Enter %d strings:\n", n);
    for (int i = 0; i < n; i++) {
        strings[i] = malloc(STRING_LENGTH);
        printf("String %d: ", i + 1);
        fgets(strings[i], STRING_LENGTH, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0'; 
    }

    qsort(strings, n, sizeof(char *), compareAsc);
    printf("\nStrings sorted in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }

    return 0;
}
