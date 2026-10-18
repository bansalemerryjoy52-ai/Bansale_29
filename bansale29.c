#include <ctype.h>l
#include <stdio.h>
#include <string.h>

#define CONSULTATION_FEE 500.0

int category_matches(const char *input, const char *category) {
    // Skip leading spaces
    while (isspace((unsigned char)*input)) {
        input++;
    }

    // Compare characters (case-insensitive)
    while (*input != '\0' && *category != '\0' &&
           tolower((unsigned char)*input) == tolower((unsigned char)*category)) {
        input++;
        category++;
    }

    // Skip trailing spaces
    while (isspace((unsigned char)*input)) {
        input++;
    }

    // Return true if both strings ended
    return *input == '\0' && *category == '\0';
}

int main(void) {
    char name[100];
    char category[50];
    int consultations;
    double discount_rate;
    double subtotal;
    double discount;
    double final_bill;

    // Get patient name
    printf("Enter patient's name: ");
    if (fgets(name, sizeof(name), stdin) == NULL) {
        printf("Error: unable to read patient's name.\n");
        return 1;
    }
    name[strcspn(name, "\n")] = '\0';

    // Get patient category
    printf("Enter patient category (senior citizen, student, or regular): ");
    if (fgets(category, sizeof(category), stdin) == NULL) {
        printf("Error: unable to read patient category.\n");
        return 1;
    }
    category[strcspn(category, "\n")] = '\0';

    // Get number of consultations
    printf("Enter number of consultations: ");
    if (scanf("%d", &consultations) != 1) {
        printf("Error: invalid number.\n");
        return 1;
    }

    // Determine discount rate
    if (category_matches(category, "senior citizen")) {
        discount_rate = 0.20;  // 20% discount
    } else if (category_matches(category, "student")) {
        discount_rate = 0.10;  // 10% discount
    } else {
        discount_rate = 0.00;  // Regular: no discount
    }

    // Calculate
    subtotal = CONSULTATION_FEE * consultations;
    discount = subtotal * discount_rate;
    final_bill = subtotal - discount;

    // Output results
    printf("\nPatient: %s\n", name);
    printf("Subtotal: %.2f\n", subtotal);
    printf("Discount: %.2f\n", discount);
    printf("Final bill: %.2f\n", final_bill);

    printf("\nProgram Finished.\n");
    return 0;
}
