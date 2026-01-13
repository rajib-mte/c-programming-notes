#include <stdio.h>
#include <stdlib.h> // for malloc() and free()

int main() {
    int n, i;
    float *marks;

    // User decides number of students at runtime
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Allocate memory for 'n' student marks
    marks = (float*) malloc(n * sizeof(float));

    // Check if memory allocation succeeded
    if (marks == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input marks
    printf("Enter marks for %d students:\n", n);
    for (i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &marks[i]);
    }

    // Display marks
    printf("\nStudent Marks:\n");
    for (i = 0; i < n; i++) {
        printf("Student %d: %.2f\n", i + 1, marks[i]);
    }

    // Free allocated memory
    free(marks);

    return 0;
}

