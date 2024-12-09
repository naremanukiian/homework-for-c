#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
// Ex2: String Operations
int main() {
    char str1[101], str2[101], copy[101];
    
    printf("Enter the first string (max 100 characters): ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; 
    
    printf("Enter the second string (max 100 characters): ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; 
    
    char concatenated[202];
    snprintf(concatenated, sizeof(concatenated), "%s%s", str1, str2);
    printf("Concatenated String: %s\n", concatenated);
    
    if (strcmp(str1, str2) == 0)
        printf("Strings are the same.\n");
    else
        printf("Strings are different.\n");
    
    printf("Length of first string: %lu\n", strlen(str1));
    printf("Length of second string: %lu\n", strlen(str2));
    
    strcpy(copy, str1);
    printf("Copy of first string: %s\n", copy);

    return 0;
}
// Ex2: Date and Time Display
int main() {
    time_t t;
    struct tm *current;

    t = time(NULL);
    current = localtime(&t);

    printf("Current Date: %04d-%02d-%02d\n", current->tm_year + 1900, current->tm_mon + 1, current->tm_mday);

    printf("Current Time: %02d:%02d:%02d\n", current->tm_hour, current->tm_min, current->tm_sec);

    return 0;
}
// Ex3: Floating-Point Calculations
int main() {
    double num, sqrt_result, sine_result;
    int rounded;

    printf("Enter a floating-point number: ");
    scanf("%lf", &num);

    sqrt_result = sqrt(num);
    printf("Square root: %.2lf\n", sqrt_result);

    rounded = round(num);
    printf("Rounded: %d\n", rounded);

    sine_result = sin(num);
    printf("Sine (radians): %.2lf\n", sine_result);

    return 0;
}