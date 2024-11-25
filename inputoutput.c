#include <stdio.h>
#include <string.h>

// int main() {
//     FILE *f1, *f2;
//     char line1[256], line2[256];
//     int line = 1;

//     f1 = fopen("file1.txt", "r");
//     f2 = fopen("file2.txt", "r");

//     if (!f1 || !f2) {
//         printf("Error opening files.\n");
//         return 1;
//     }

//     while (fgets(line1, sizeof(line1), f1) && fgets(line2, sizeof(line2), f2)) {
//         if (strcmp(line1, line2) != 0) {
//             printf("Difference at line %d:\nFile1: %sFile2: %s", line, line1, line2);
//             fclose(f1);
//             fclose(f2);
//             return 0;
//         }
//         line++;
//     }

//     printf("Files are identical or one ends early.\n");
//     fclose(f1);
//     fclose(f2);
//     return 0;
// }


// int main() {
//     FILE *file;
//     char line[256], *pattern = "search";
//     int lineNumber = 1;

//     file = fopen("file.txt", "r");
//     if (!file) {
//         printf("Error opening file.\n");
//         return 1;
//     }

//     while (fgets(line, sizeof(line), file)) {
//         if (strstr(line, pattern)) {
//             printf("Line %d: %s", lineNumber, line);
//         }
//         lineNumber++;
//     }

//     fclose(file);
//     return 0;
// }