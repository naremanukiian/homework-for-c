#include <stdio.h>
#include <string.h>

// struct Time {
//     int hours;
//     int minutes;
//     int seconds;
// };

// struct Time addTimes(struct Time t1, struct Time t2) {
//     struct Time result;

//     result.seconds = t1.seconds + t2.seconds;
//     result.minutes = t1.minutes + t2.minutes + (result.seconds / 60);
//     result.seconds %= 60;
//     result.hours = t1.hours + t2.hours + (result.minutes / 60);
//     result.minutes %= 60;

//     return result;
// }

// int main() {
//     struct Time t1, t2, result;

//     printf("Enter first time (hours minutes seconds): ");
//     scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);

//     printf("Enter second time (hours minutes seconds): ");
//     scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

//     result = addTimes(t1, t2);

//     printf("Resultant Time: %02d:%02d:%02d\n", result.hours, result.minutes, result.seconds);

//     return 0;
// }


// struct Complex {
//     float real;
//     float imag;
// };

// struct Complex addComplex(struct Complex c1, struct Complex c2) {
//     struct Complex result;
//     result.real = c1.real + c2.real;
//     result.imag = c1.imag + c2.imag;
//     return result;
// }

// struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
//     struct Complex result;
//     result.real = c1.real * c2.real - c1.imag * c2.imag;
//     result.imag = c1.real * c2.imag + c1.imag * c2.real;
//     return result;
// }

// int main() {
//     struct Complex c1, c2, sum, product;

//     printf("Enter first complex number (real imaginary): ");
//     scanf("%f %f", &c1.real, &c1.imag);

//     printf("Enter second complex number (real imaginary): ");
//     scanf("%f %f", &c2.real, &c2.imag);

//     sum = addComplex(c1, c2);
//     product = multiplyComplex(c1, c2);

//     printf("Sum: %.2f + %.2fi\n", sum.real, sum.imag);
//     printf("Product: %.2f + %.2fi\n", product.real, product.imag);

//     return 0;
// }



// union SensorData {
//     int temperature;
//     float pressure;
//     float humidity;
// };

// int main() {
//     union SensorData data;
//     char sensorType[20];

//     printf("Enter sensor type (temperature, pressure, humidity): ");
//     scanf("%s", sensorType);

//     if (strcmp(sensorType, "temperature") == 0) {
//         printf("Enter temperature (integer): ");
//         scanf("%d", &data.temperature);
//         printf("Sensor Type: Temperature\nReading: %d°C\n", data.temperature);
//     } 
//     else if (strcmp(sensorType, "pressure") == 0) {
//         printf("Enter pressure (float): ");
//         scanf("%f", &data.pressure);
//         printf("Sensor Type: Pressure\nReading: %.2f Pa\n", data.pressure);
//     } 
//     else if (strcmp(sensorType, "humidity") == 0) {
//         printf("Enter humidity (float): ");
//         scanf("%f", &data.humidity);
//         printf("Sensor Type: Humidity\nReading: %.2f%%\n", data.humidity);
//     } 
//     else {
//         printf("Invalid sensor type!\n");
//     }

//     return 0;
// }


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