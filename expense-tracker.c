#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESC_LEN 100

typedef struct {
    char description[DESC_LEN];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expenseCount = 0;
const char* filename = "expenses.txt";

void saveToFile() {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error saving file!\n");
        return;
    }
    
    for (int i = 0; i < expenseCount; i++) {
        fprintf(file, "%s|%.2f\n", expenses[i].description, expenses[i].amount);
    }
    fclose(file);
    printf("✓ Expenses saved!\n");
}

void loadFromFile() {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("No existing data found. Starting fresh.\n");
        return;
    }
    
    expenseCount = 0;
    while (fscanf(file, "%[^|]|%f\n", expenses[expenseCount].description, 
                  &expenses[expenseCount].amount) != EOF) {
        expenseCount++;
        if (expenseCount >= MAX_EXPENSES) break;
    }
    fclose(file);
    printf("✓ Loaded %d expenses\n", expenseCount);
}

void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached!\n");
        return;
    }
    
    printf("Enter description: ");
    getchar(); // Clear newline
    fgets(expenses[expenseCount].description, DESC_LEN, stdin);
    expenses[expenseCount].description[strcspn(expenses[expenseCount].description, "\n")] = 0;
    
    printf("Enter amount: ₹");
    scanf("%f", &expenses[expenseCount].amount);
    
    expenseCount++;
    saveToFile();
    printf("✓ Expense added!\n");
}

void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses yet.\n");
        return;
    }
    
    float total = 0;
    printf("\n📋 Your Expenses:\n");
    printf("--------------------------------\n");
    
    for (int i = 0; i < expenseCount; i++) {
        printf("%d. %s - ₹%.2f\n", i+1, expenses[i].description, expenses[i].amount);
        total += expenses[i].amount;
    }
    
    printf("--------------------------------\n");
    printf("💰 Total: ₹%.2f\n", total);
}

int main() {
    int choice;
    
    loadFromFile();
    
    do {
        printf("\n📊 EXPENSE TRACKER\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 3);
    
    return 0;
}
