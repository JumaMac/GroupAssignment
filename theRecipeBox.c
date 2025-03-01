#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define RECIPES_SIZE 25
#define ING_AMT 10  // Define max ingredient amount for recipes user adds

struct Ingredient {
    char name[50];
    int amount;
};

struct Recipe {
    char name[100];
    struct Ingredient ingredients[ING_AMT];
    int ingCount;
};

int main() {
    int choice;
    int cat_choice;
    struct Recipe recipes[RECIPES_SIZE];
    int recipeCount = 0;
    int ingNum;

    while (1) {  // Program loop to allow navigation back

        // Home page
        system("clear");
        printf("████████╗██╗  ██╗███████╗    ██████╗ ███████╗ ██████╗██╗██████╗ ███████╗    ██████╗  ██████╗ ██╗  ██╗\n");
        printf("╚══██╔══╝██║  ██║██╔════╝    ██╔══██╗██╔════╝██╔════╝██║██╔══██╗██╔════╝    ██╔══██╗██╔═══██╗╚██╗██╔╝\n");
        printf("   ██║   ███████║█████╗      ██████╔╝█████╗  ██║     ██║██████╔╝█████╗      ██████╔╝██║   ██║ ╚███╔╝ \n");
        printf("   ██║   ██╔══██║██╔══╝      ██╔══██╗██╔══╝  ██║     ██║██╔═══╝ ██╔══╝      ██╔══██╗██║   ██║ ██╔██╗ \n");
        printf("   ██║   ██║  ██║███████╗    ██║  ██║███████╗╚██████╗██║██║     ███████╗    ██████╔╝╚██████╔╝██╔╝ ██╗\n");
        printf("   ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝╚═╝     ╚══════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝\n");

        printf("=====================================================================================================\n");
        printf("              ░█▀▀░█▀█░█▀█░█░█░░░░░░█▀▀░█▀▄░█▀▀░█▀█░▀█▀░█▀▀░░░░░░█▀▀░█▀█░▀▀█░█▀█░█░█░░░              \n");
        printf("              ░█░░░█░█░█░█░█▀▄░░░░░░█░░░█▀▄░█▀▀░█▀█░░█░░█▀▀░░░░░░█▀▀░█░█░░░█░█░█░░█░░░░              \n");
        printf("              ░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀░░░░▀▀▀░▀░▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀░░░░▀▀▀░▀░▀░▀▀░░▀▀▀░░▀░░▀░              \n");
        printf("=====================================================================================================\n");

        printf("[1] All Recipes\n");
        printf("[2] Your Recipes\n");
        printf("[3] Game Section\n");
        printf("[0] Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        

        switch (choice) {

            case 1: // All Recipes
                while (1) {  // Loop to stay in the category selection menu
                    printf("\nSelect a Recipe Category:\n");
                    printf("[1] Breakfast & Brunch\n");
                    printf("[2] Lunch Specials\n");
                    printf("[3] Dinner Delights\n");
                    printf("[4] Desserts & Sweets\n");
                    printf("[5] Vegetarian & Vegan\n");
                    printf("[0] Go Back\n");
                    printf("Enter your choice: ");

                    scanf("%d", &cat_choice);  

                    if (cat_choice == 0) break; // Go back to home page

                    switch (cat_choice) {
                        case 1:
                            printf("\n\033[1mBreakfast & Brunch:\033[0m\n");
                            printf("[1] 10-Minute Mushroom Avocado Toast\n");
                            printf("[2] Easy Vegan French Toast (10 Minutes!)\n\n");

                            break;
                        case 2:
                            printf("\n\033[1mLunch Specials:\033[0m\n");
                            printf("[1] Sun-Dried Tomato Pesto Pasta (Vegan + GF)\n");
                            printf("[2] The Ultimate Salmon Burger (30 Minutes!)\n\n");
                            break;
                        case 3:
                            printf("\n\033[1mDinner Delights:\033[0m\n");
                            printf("[1] Honey Garlic Salmon Bites\n");
                            printf("[2] Chicken Noodle Soup (Classic or Immune-Boosting!)\n\n");
                            break;
                        case 4:
                            printf("\n\033[1mDesserts & Sweets:\033[0m\n");
                            printf("[1] Homemade Gluten-Free Oreos (Vegan)\n");
                            printf("[2] The BEST Chocolate Cake Mix Cookies\n\n");
                            break;
                        case 5:
                            printf("\n\033[1mVegetarian & Vegan:\033[0m\n");
                            printf("[1] 10-Minute Mushroom Avocado Toast\n");
                            printf("[2] Easy Vegan French Toast (10 Minutes!)\n");
                            printf("[3] Sun-Dried Tomato Pesto Pasta (Vegan + GF)\n");
                            printf("[4] Homemade Gluten-Free Oreos (Vegan)\n");
                            printf("[5] The BEST Chocolate Cake Mix Cookies\n\n");
                            break;
                        default:
                            printf("Invalid input. Try again.\n");
                            break;
                    }
                }
                break;

            case 2: // Your Recipes
                while (1) {
                    printf("\n[1] Add Recipe\n");
                    printf("[2] View Recipes\n");
                    printf("[0] Go Back\n");
                    printf("Enter your choice: ");

                    if (scanf("%d", &choice) != 1) {
                        printf("Invalid input. Try again.\n");
                        continue;
                    }

                    if (choice == 0) {
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

                        recipes[recipeCount].ingCount = ingNum;
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
                                for (int j = 0; j < recipes[i].ingCount; j++) {
                                    printf(" - %s: %dg\n", recipes[i].ingredients[j].name, recipes[i].ingredients[j].amount);
                                }
                            }
                        }
                    } else {
                        printf("Invalid input. Try again.\n");
                    }
                }
                break;

            case 3: // Game Section
                {
                    printf("Play fun games here as your food cooks! (Feature Coming Soon)\n");
                    printf("Press Enter to go back to the home page...\n");

                    // Wait for user input to go back to the home page
                    getchar();  // This is to capture the newline character left in the input buffer after previous input
                    getchar();  // Wait for the user to press Enter

                }
                break;


            case 0: // Exit program
                return 0;
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}
