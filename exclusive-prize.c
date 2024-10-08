#include <stdio.h>

int main() {
    int n;

    // Read the first integer which is the number of inputs
    scanf("%d", &n);

    // Create an array to store the input values
    int arr[n];

    // Loop to read the 'n' numbers in a single line
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the inputs to verify
    printf("You entered: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Example of processing: Loop over the array again
    printf("\nProcessing each number:\n");
    for (int i = 0; i < n; i++) {
        printf("Number %d: %d\n", i + 1, arr[i]);
    }

    return 0;
}
