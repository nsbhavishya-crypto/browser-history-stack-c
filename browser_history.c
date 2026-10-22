#include <stdio.h>

#define MAX 5  // Maximum capacity for history stack

// Global variables
int history[MAX];  // Array to hold webpage ID numbers
int top = -1;      // Stack pointer starts at -1 (empty)

// Function to visit a new webpage (PUSH operation)
void visitPage() {
    // Check for Stack Overflow
    if (top == MAX - 1) {
        printf("\n[Error] History stack is full! Can't store more pages.\n");
    } else {
        int pageID;
        printf("Enter webpage ID (e.g., 101, 102): ");
        scanf("%d", &pageID);

        top++;                  // Move top up
        history[top] = pageID;  // Store the page ID in the stack
        printf("Successfully visited Page %d\n", history[top]);
    }
}

// Function to click the Back button (POP operation)
void goBack() {
    // Check for Stack Underflow
    if (top == -1) {
        printf("\n[Error] No previous history! You are at the start.\n");
    } else {
        printf("\nGoing back from Page %d\n", history[top]);
        top--;  // Remove the top page by moving top down

        if (top >= 0) {
            printf("Current page is now: Page %d\n", history[top]);
        } else {
            printf("History is now empty.\n");
        }
    }
}

// Function to display the history stack
void displayHistory() {
    if (top == -1) {
        printf("\nYour browser history is empty.\n");
    } else {
        printf("\n--- Browser History (Top to Bottom) ---\n");
        for (int i = top; i >= 0; i--) {
            printf("-> Page %d\n", history[i]);
        }
        printf("---------------------------------------\n");
    }
}

// Main function with menu loop
int main() {
    int choice;

    do {
        printf("\n=== WEB BROWSER HISTORY MENU ===\n");
        printf("1. Visit New Page (Push)\n");
        printf("2. Click Back Button (Pop)\n");
        printf("3. Show History Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                visitPage();
                break;
            case 2:
                goBack();
                break;
            case 3:
                displayHistory();
                break;
            case 4:
                printf("\nClosing browser...\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a number from 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}
