#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int choice;
    int cat_choice;
    int veg_choice;
    
    // Show Home Page
    system("clear");  // Use "cls" on Windows
    printf("==============================\n");
    printf("🍟🍕🌭🥪🌮🌯🫔🥙🧆🥚🍳🥘🍲🍘🍙🍛\n");
    printf("       ==================     \n");
    printf("      |  THE RECIPE BOX  |     \n");
    printf("       ==================     \n");
    printf("🍟🍕🌭🥪🌮🌯🫔🥙🧆🥚🍳🥘🍲🍘🍙🍛\n");
    printf("==============================\n");
    printf("      Welcome to Home Page     \n");
    printf("==============================\n");

    // Show options to navigate
    printf("1. All Recipes\n");
    printf("2. Your Recipes\n");
    printf("3. Game Section\n");
    printf("4. Quit\n");

    // Prompt user to choose
    printf("Enter your choice: ");
    while (1) {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 4) {
            break;  // Valid choice
        }
        printf("Invalid choice. Please try again: ");
    }

    // Handle All Recipes selection
    if (choice == 1) {
        // All Recipes menu with categories
        while (1) {
            printf("\nSelect a Recipe Category:\n");
            printf("[1] Breakfast & Brunch\n");
            printf("[2] Lunch Specials\n");
            printf("[3] Dinner Delights\n");
            printf("[4] Desserts & Sweets\n");
            printf("[5] Vegetarian & Vegan\n");
            printf("[0] Go Back\n");
            printf("[Q] Quit\n");
            printf("Enter your choice: ");
            
            getchar();  // To capture the newline character
            char cat_choice_char = getchar();
            cat_choice_char = toupper(cat_choice_char); // Make choice uppercase

            if (cat_choice_char == 'Q') {
                printf("Goodbye!\n");
                return 0;
            }

            if (cat_choice_char == '0') {
                printf("Returning to the home page...\n");
                break;
            }

            // Handle category choices
            if (cat_choice_char == '1') {
                printf("You selected Breakfast & Brunch.\n");
            } else if (cat_choice_char == '2') {
                printf("You selected Lunch Specials.\n");
            } else if (cat_choice_char == '3') {
                printf("You selected Dinner Delights.\n");
            } else if (cat_choice_char == '4') {
                printf("You selected Desserts & Sweets.\n");
            } else if (cat_choice_char == '5') {
                // Handle Vegetarian & Vegan subcategories
                while (1) {
                    printf("\nVegetarian & Vegan Options:\n");
                    printf("[1] Vegetarian\n");
                    printf("[2] Vegan\n");
                    printf("[0] Go Back\n");
                    printf("[Q] Quit\n");
                    printf("Enter your choice: ");
                    getchar();  // To capture the newline character
                    char veg_choice_char = getchar();
                    veg_choice_char = toupper(veg_choice_char);  // Uppercase

                    if (veg_choice_char == 'Q') {
                        printf("Goodbye!\n");
                        return 0;
                    }

                    if (veg_choice_char == '0') {
                        printf("Returning to the previous level...\n");
                        break;
                    }

                    if (veg_choice_char == '1') {
                        printf("You selected Vegetarian Recipes.\n");
                    } else if (veg_choice_char == '2') {
                        printf("You selected Vegan Recipes.\n");
                    } else {
                        printf("Invalid choice. Try again.\n");
                    }
                }
            } else {
                printf("Invalid choice. Try again.\n");
            }
        }
    }

    // Handle Your Recipes selection
    if (choice == 2) {
        printf("\nYour Recipes Section:\n");
        printf("This is where you can manage your saved recipes.\n");
        printf("Press any key to go back to the home page.\n");
        getchar();  // To capture the enter key
        getchar();  // Wait for user to press a key to continue
    }

    // Handle Game Section selection
    if (choice == 3) {
        printf("\nGame Section:\n");
        printf("This is the game section! (You can add a game later)\n");
        printf("Press any key to go back to the home page.\n");
        getchar();  // To capture the enter key
        getchar();  // Wait for user to press a key to continue
    }

    // Quit the program
    if (choice == 4) {
        printf("Goodbye!\n");
        return 0;
    }

    return 0;
}
