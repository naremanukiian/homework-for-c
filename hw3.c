#include <stdio.h>

int main() {
    int arr1[25], i, n;
    printf("\n\n Pointer : Store and retrieve elements from an array :\n");
    printf("------------------------------------------------------------\n");

    printf(" Input the number of elements to store in the array :");
    scanf("%d", &n); 

    printf(" Input %d number of elements in the array :\n", n);
    for (i = 0; i < n; i++) {
        printf(" element - %d : ", i);
        scanf("%d", arr1 + i); 
    }

    printf(" The elements you entered are : \n");
    for (i = 0; i < n; i++) {
        printf(" element - %d : %d \n", i, *(arr1 + i)); 
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    float *element; 

    printf("\n\n Pointer : Find the largest element using Dynamic Memory Allocation :\n");
    printf("-------------------------------------------------------------------------\n");

   
    printf(" Input total number of elements (1 to 100): ");
    scanf("%d", &n);

    element = (float *)calloc(n, sizeof(float)); 

    if (element == NULL) {
        printf(" No memory is allocated."); 
        exit(0);
    }

    printf("\n");

    for (i = 0; i < n; ++i) {
        printf(" Number %d: ", i + 1);
        scanf("%f", element + i);
    }

    for (i = 1; i < n; ++i) {
        if (*element < *(element + i)) {
            *element = *(element + i); 
        }
    }

    printf(" The Largest element is :  %.2f \n\n", *element); 
    return 0;
}

#include <stdio.h>

int main() {
    int *a, i, j, tmp, n;
    printf("\n\n Pointer : Sort an array using pointer :\n");
    printf("--------------------------------------------\n");

    printf(" Input the number of elements to store in the array : ");
    scanf("%d", &n);

    printf(" Input %d number of elements in the array : \n", n);
    for (i = 0; i < n; i++) {
        printf(" element - %d : ", i + 1);
        scanf("%d", a + i);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (*(a + i) > *(a + j)) {
                tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }

    printf("\n The elements in the array after sorting : \n");
    for (i = 0; i < n; i++) {
        printf(" element - %d : %d \n", i + 1, *(a + i));
    }

    printf("\n");
}

#include <stdio.h>

int main() {
    
    char alph[27];  
    int x;
    char *ptr;  

    printf("\n\n Pointer : Print all the alphabets:\n");
    printf("----------------------------------------\n");

    ptr = alph; 

    for (x = 0; x < 26; x++) {
        *ptr = x + 'A'; 
        ptr++; 
    }

    ptr = alph; 

    printf(" The Alphabets are : \n");
    for (x = 0; x < 26; x++) {
        printf(" %c ", *ptr); 
        ptr++; 
    }
    printf("\n\n");
    return 0;
}

#include <stdio.h>

int main() {
    char str1[50];      
    char revstr[50];    
    char *stptr = str1; 
    char *rvptr = revstr; 
    int i = -1; 

    printf("\n\n Pointer : Print a string in reverse order :\n");
    printf("------------------------------------------------\n");

    printf(" Input a string : ");
    scanf("%s", str1); 

    while (*stptr) {
        stptr++; 
        i++;     
    }


    while (i >= 0) {
        stptr--;            
        *rvptr = *stptr;     
        rvptr++;             
        --i;                 
    }

    *rvptr = '\0'; 

    printf(" Reverse of the string is : %s\n\n", revstr);

    return 0;
}
