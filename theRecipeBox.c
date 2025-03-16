#include <stdio.h>  // For printing output and reading input.
#include <stdlib.h> // For memory management and other general functions.
#include <ctype.h>  // For checking and modifying characters (like letters and numbers).
#include <string.h> // For working with strings (copy, compare, length, etc.).
#include "recipe.h"
#include "database.h"
#include "display.h"
int main()
{
    int choice;
    int cat_choice;
    struct Recipe recipes[RECIPES_SIZE];
    // call the initRecipes from database.h to load all recipes
    int recipeCount = initRecipes(recipes);
    int ingNum;

    // ⭐️ code by Jaismin
    while (1)
    { // Program loop to allow navigation back

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

        switch (choice)
        {

        case 1: // All Recipes
            while (1)
            { // Loop to stay in the category selection menu
                printf("\nSelect a Recipe Category:\n");
                printf("[1] Breakfast & Brunch\n");
                printf("[2] Lunch Specials\n");
                printf("[3] Dinner Delights\n");
                printf("[4] Desserts & Sweets\n");
                printf("[5] Vegetarian & Vegan\n");
                printf("[0] Go Back\n");
                printf("Enter your choice: ");

                scanf("%d", &cat_choice);

                if (cat_choice == 0)
                {
                    break; // Go back to home page
                }
                // ⭐️ end of code by jaismin

                // define foundRecipes array
                struct Recipe foundRecipes[RECIPES_SIZE];
                // find recipes based on category choice
                // pass all recipes
                // pass foundRecipes which is the array that will be populated by the function
                int foundRecipeCount = searchByCategory(recipes, recipeCount, foundRecipes, cat_choice);
                //call XXXXXXXX to print out 
                printRecipes(foundRecipes, foundRecipeCount);
            }
            break;

        case 2: // Your Recipes

            // ⭐️ code by Justin
            while (1)
            {
                printf("\n[1] Add Recipe\n");
                printf("[2] View Recipes\n");
                printf("[3] Edit Recipes\n");
                printf("[4] Delete Recipes\n");
                printf("[0] Go Back\n");
                printf("Enter your choice: ");

                if (scanf("%d", &choice) != 1)
                {
                    printf("Invalid input. Try again.\n");
                    continue;
                }

                if (choice == 1)
                {
                    addRecipes(recipes, &recipeCount);
                } 
                else if (choice == 2) 
                {
                    viewRecipes(recipes, recipeCount);
                } 
                else if (choice == 3) 
                {
                    editRecipes(recipes, &recipeCount);
                } 
                else if (choice == 4) 
                {
                    deleteRecipes(recipes, &recipeCount);
                } 
                else if (choice == 0)
                {
                    break;
                }
                else
                {
                    printf("Invalid input. Try again.\n");
                }
            }
            // ⭐️ end of code by Justin
            break;
            // ⭐️ code by jaismin
        case 3: // Game Section
        {
            printf("Play fun games here as your food cooks! (Feature Coming Soon)\n");
            printf("Press Enter to go back to the home page...\n");

            // Wait for user input to go back to the home page
            getchar(); // This is to capture the newline character left in the input buffer after previous input
            getchar(); // Wait for the user to press Enter
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
// ⭐️ end of code by Jaismin