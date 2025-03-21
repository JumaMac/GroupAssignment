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
                        printf("[2] Easy Vegan French Toast (10 Minutes!)\n");
                        printf("[0] Go back\n\n");

                            int recipe_choice, servings;

                        printf("Enter your choice: ");
                        scanf("%d", &recipe_choice);

                        if (recipe_choice == 0) {
                            break; // Goes back to category selection
                        }

                        switch (recipe_choice) {
                                case 1: // "10-Minute Mushroom Avocado Toast
                                        printf("\n\033[1m10-Minute Mushroom Avocado Toast\033[0m\n");
                                        printf("The ultimate plant-based breakfast: avocado toast with savory sautéed mushrooms.\n"
                                                "SO satisfying, perfectly toasty, and ready in just 10 minutes with 1 pan and 7 ingredients!\n\n");
                                        printf("How many servings do you want to make?: ");
                                        
                                        scanf("%d", &servings);
// ⭐️ code by mikey 
                                        //ingredient list 
                                        char *ingredients[] = {
                                            "Bread Slices (oz)", 
                                            "Medium Ripe Avocado (each)", 
                                            "Vegan Butter (Tbsp)", 
                                            "Sliced Shiitake Mushrooms (oz)", 
                                            "Dried Thyme (tsp)", 
                                            "Red Pepper Flakes (pinch)", 
                                            "Sea Salt (pinch)", 
                                            "Black Pepper (pinch)", 
                                            "Garlic Powder (tsp)"
                                        };


                                        float quantities[] = {2, 0.5, 1, 7, 0.5, 1, 1, 1, 0.25}; // Base quantities for 2 servings


                                        
                                        for (int i = 0; i < 9; i++) {
                                                quantities[i] *= servings;
                                        }

                                        
                                        printf("\nFor %d servings, you will need:\n", servings);
                                        for (int i = 0; i < 9; i++) {
                                                printf("%.2f %s\n", quantities[i], ingredients[i]);
                                        }
// ⭐️ end of code by mikey
// ⭐️ code by jaismin
                                        printf("\n\033[1mInstructions:\033[0m\n"
                                                "1. Heat vegan butter or olive oil in a large skillet over medium heat.\n"
                                                "2. Add the sliced mushrooms, thyme, and red pepper flakes (optional). Cook, stirring occasionally, until softened and lightly browned — about 5-7 minutes. If the mushrooms are sticking to the pan, reduce the heat slightly or add more butter or oil.\n"
                                                "3. Meanwhile, toast bread in the oven or a toaster.\n"
                                                "4. Once the mushrooms are lightly browned, turn off the heat and stir in the salt, pepper, and garlic powder. Taste and adjust as needed, adding more salt to taste or black pepper for spice.\n"
                                                "5. Top the toasted bread with ripe avocado and use a fork to smash. Then top with sautéed mushroom mixture and vegan parmesan cheese (optional).\n"
                                                "6. Eat, repeat, enjoy!\n\n"
                                                "Best when fresh. Not freezer friendly.\n\n");


                                        printf("\n[0] Return to Category Menu\n\n");
                                        printf("Enter your choice: ");
                                        scanf("%d", &recipe_choice);
                                        if (recipe_choice == 0) {
                                                break; // Go back
                                        }
                                    break;

                                
                                default:
                                        printf("Invalid choice. Returning to menu.\n");
                                break;
                            }

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

            // ⭐️ code by Justin
            while (1)
            {
                printf("\n[1] Add Recipe\n");
                printf("[2] View Recipes\n");
                printf("[3] Edit Recipes\n");
                printf("[4] Delete Recipes\n");
                printf("[5] Search Recipes\n");
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
                else if (choice == 5) 
                {
                    searchRecipe(recipes, recipeCount);
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
            printf("[1] Meow-nster: Eats it all!\n");
            printf("The game is not incorporated with the main code yet, but you can go check it out on https://github.com/JumaMac/GroupAssignment/blob/main/meow-nster.c\n");
            printf("Or view a demo video of it running on https://github.com/user-attachments/assets/fb11ec3d-6e46-4b2d-97be-d74a06217c62\n");
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
