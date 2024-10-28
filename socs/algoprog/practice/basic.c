#include <stdbool.h>
#include <stdio.h>

// Function to return a string
const char* getString(const char* str) {
    return str;
}

// Function to return an integer
int getInt(const int num) {
    return num;
}

// Function to return a boolean
bool getBool(const bool b) {
    return b;
}

// Function to return an array of strings
const char** getStringArr(const char* strArr[]) {
    return strArr;
}

struct MyStruct {
    int a;
    char b;
};

int main() {
    // Return string and print
    const char* str = getString("hi");
    printf("%s\n", str);

    // Return int and print
    const int num = getInt(10);
    printf("%d\n", num);

    // Return bool and print 0 = false, 1 = true
    const bool selection = getBool(false);
    printf("%d\n", selection);

    // Define an array of strings
    const char* strArr[] = {"hello", "world", "foo", "bar"};

    // Get the array of strings from the function
    const char** returnedStrArr = getStringArr(strArr);

    // Get the size of the array
    const int size = sizeof(strArr) / sizeof(strArr[0]);

    // Print each string in the array
    for (int i = 0; i < size; i++) {
        printf("%s\n", returnedStrArr[i]);
    }

    // bubble sort algorithm
    int intArr[] = {0, 5, 0, 10, 2, 4, 7 ,6, 6, 0};
    const int len = sizeof(intArr) / sizeof(intArr[0]);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (intArr[j] > intArr[j + 1]) {
                const int temp = intArr[j];
                intArr[j] = intArr[j + 1];
                intArr[j + 1] = temp;
            }
        }
    }
    int unique = 0;
    for (int i = 1; i < len; i++) {
        if (intArr[i] != intArr[unique]) {
            unique++;
            intArr[unique] = intArr[i];
        }
    }
    for (int i = unique + 1; i < len; i++) {
        intArr[i] = 0;
    }
    for (int i = 0; i < len; i++) {
        printf("%d\n", intArr[i]);
    }

    // int a, b;
    //
    // a = 11;
    // b = 10;
    //
    // int plus = a + b;
    // printf("hasil penjumlahan: %d\n", plus);
    // int minus = a - b;
    // printf("hasil pengurangan: %d\n", minus);
    // int times = a * b;
    // printf("hasil perkalian: %d\n", times);
    // int divide = a / b;
    // printf("hasil pembagian: %d\n", divide);
    // int modulo = a % b;
    // printf("hasil modulo: %d\n", modulo);
    // int increment = a++;
    // printf("hasil increment: %d\n", increment);
    // int decrement = --a;
    // printf("hasil decrement: %d\n", decrement);

    printf("program finished");
    return 0;
}
