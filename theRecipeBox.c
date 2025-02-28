#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "recipe.h"

#define RECIPES_SIZE 25
#define ING_AMT 10  // Define max ingredient amount for recipes user adds

int main() {
    int choice;
    int cat_choice;
    int veg_choice;
    struct Recipe recipes[RECIPES_SIZE];
    int recipeCount = 0;
    int ingNum;

    while (1) {  // Program loop to allow navigation back

        // Home page
        system("clear");
        printf("==============================\n");
        printf("🍟🍕🌭🥪🌮🌯🫔🥙🧆🥚🍳🥘🍲🍘🍙🍛\n");
        printf("       ==================     \n");
        printf("      |  THE RECIPE BOX  |     \n");
        printf("       ==================     \n");
        printf("🍟🍕🌭🥪🌮🌯🫔🥙🧆🥚🍳🥘🍲🍘🍙🍛\n");
        printf("==============================\n");
        printf("      Welcome to Home Page     \n");
        printf("==============================\n");

        printf("1. All Recipes\n");
        printf("2. Your Recipes\n");
        printf("3. Game Section\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            return 1;
        }
        

        switch (choice) {

            case 1: // All Recipes
            

                    printf("\nSelect a Recipe Category:\n");
                    printf("[1] Breakfast & Brunch\n");
                    printf("[2] Lunch Specials\n");
                    printf("[3] Dinner Delights\n");
                    printf("[4] Desserts & Sweets\n");
                    printf("[5] Vegetarian & Vegan\n");
                    printf("[0] Go Back\n");
                    printf("Enter your choice: ");
                    

                    scanf("%d\n", &cat_choice);
                    
                    switch (cat_choice)
                    {
                    case 0:

                        break;
                    // this is where we need to add the recipes !!IMPORTANT

                    case 1: //breakfast and brunch

                        break;

                    case 2: //lunch specials

                        break;

                    case 3: //dinner delights

                        break;

                    case 4: //desserts & sweets

                        printf("Goodbye!\n");
                        exit(0);

                        break;

                    case 5: //vegetarian & vegan

                            if (veg_choice == 1) {

                            } else if (veg_choice == 2) {

                            } else {

                            }
                        break;

                    default:
                        printf("Invalid input. Try again.\n");
                        continue;

                        break;
                    }

                   
                
            break;

            case 2: // Your Recipes
                while (1) {
                    printf("\n1. Add Recipe\n");
                    printf("2. View Recipes\n");
                    printf("3. Go Back\n");
                    printf("Enter your choice: ");

                    if (scanf("%d", &choice) != 1) {
                        printf("Invalid input. Try again.\n");
                        continue;
                    }

                    if (choice == 3) {
                        break; // Go back to the main menu
                    } else if (choice == 1) {
                        if (recipeCount >= RECIPES_SIZE) {
                            printf("Maximum amount of recipes reached.\n");
                            continue;
                        }

                        printf("Enter recipe name: ");
                        scanf(" %[^\n]", recipes[recipeCount].name);

                        printf("How many ingredients will you be using? (Max %d): ", ING_AMT);
                        scanf("%d", &ingNum);

                        if (ingNum > ING_AMT) {
                            printf("Too many ingredients used.\n");
                            continue;
                        }

                        for (int i = 0; i < ingNum; i++) {
                            printf("Enter ingredient %d name: ", i + 1);
                            scanf(" %[^\n]", recipes[recipeCount].ingredients[i].name);
                            printf("Enter amount of %s (g): ", recipes[recipeCount].ingredients[i].name);
                            scanf("%d", &recipes[recipeCount].ingredients[i].amount);
                        }

                        printf("Recipe has been added!\n");
                        recipeCount++;
                    } else if (choice == 2) {
                        if (recipeCount == 0) {
                            printf("No available recipes.\n");
                        } else {
                            printf("Recipes:\n");
                            for (int i = 0; i < recipeCount; i++) {
                                printf("Recipe %d: \n", i + 1);
                                printf("Name: %s\n", recipes[i].name);
                                printf("Ingredients: \n");
                                for (int j = 0; j < ingNum; j++) {
                                    printf(" - %s: %dg\n", recipes[i].ingredients[j].name, recipes[i].ingredients[j].amount);
                                }
                            }
                        }
                    } else {
                        printf("Invalid input. Try again.\n");
                    }
                }
            break;

            case 3: // Games
                printf("Game Section (Feature Coming Soon!)\n");
            break;

            case 4: //Exit program
                    return 0;
            break;

            default:
                printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}

   

    // // Handle All Recipes selection
    // if (choice == 1) {
    //     // All Recipes menu with categories
        

    //         if (cat_choice_char == '0') {
    //             printf("Returning to the home page...\n");
    //             break;
    //         }

    //         // Handle category choices
    //         if (cat_choice_char == '1') {
    //             printf("You selected Breakfast & Brunch.\n");
    //         } else if (cat_choice_char == '2') {
    //             printf("You selected Lunch Specials.\n");
    //         } else if (cat_choice_char == '3') {
    //             printf("You selected Dinner Delights.\n");
    //         } else if (cat_choice_char == '4') {
    //             printf("You selected Desserts & Sweets.\n");
    //         } else if (cat_choice_char == '5') {
    //             // Handle Vegetarian & Vegan subcategories
    //             while (1) {
    //                 printf("\nVegetarian & Vegan Options:\n");
    //                 printf("[1] Vegetarian\n");
    //                 printf("[2] Vegan\n");
    //                 printf("[0] Go Back\n");
    //                 printf("[Q] Quit\n");
    //                 printf("Enter your choice: ");
    //                 getchar();  // To capture the newline character
    //                 char veg_choice_char = getchar();
    //                 veg_choice_char = toupper(veg_choice_char);  // Uppercase

    //                 if (veg_choice_char == 'Q') {
    //                     printf("Goodbye!\n");
    //                     return 0;
    //                 }

    //                 if (veg_choice_char == '0') {
    //                     printf("Returning to the previous level...\n");
    //                     break;
    //                 }

    //                 if (veg_choice_char == '1') {
    //                     printf("You selected Vegetarian Recipes.\n");
    //                 } else if (veg_choice_char == '2') {
    //                     printf("You selected Vegan Recipes.\n");
    //                 } else {
    //                     printf("Invalid choice. Try again.\n");
    //                 }
    //             }
    //         } else {
    //             printf("Invalid choice. Try again.\n");
    //         }
    //     }
    // }

    // // Handle Your Recipes selection
    // if (choice == 2) {
    //     printf("\nYour Recipes Section:\n");
    //     printf("This is where you can manage your saved recipes.\n");
    //     printf("Press any key to go back to the home page.\n");
    //     getchar();  // To capture the enter key
    //     getchar();  // Wait for user to press a key to continue
    // }

    // // Handle Game Section selection
    // if (choice == 3) {
    //     printf("\nGame Section:\n");
    //     printf("This is the game section! (You can add a game later)\n");
    //     printf("Press any key to go back to the home page.\n");
    //     getchar();  // To capture the enter key
    //     getchar();  // Wait for user to press a key to continue
    // }

    // // Quit the program
    // if (choice == 4) {
    //     printf("Goodbye!\n");
    //     return 0;
    // }

