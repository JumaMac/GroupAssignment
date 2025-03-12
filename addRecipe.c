#include <stdio.h>
#include "recipe.h"
#define RECIPES_SIZE 25

void viewRecipes(struct Recipe recipes[], int recipeCount);

void viewRecipes(struct Recipe recipes[], int recipeCount) {

    if (recipeCount == 0) {
        printf("No available recipes.");

    } else {
        // print out the recipes that were inputted outputting the names and ingredients being used
        printf("Recipes: \n");
        for (int i = 0; i < recipeCount; i++) {
            printf("Recipe %d: \n", i + 1);
            printf("Name: %s\n", recipes[i].name);
            printf("Ingredients: \n");
            for (int j = 0; j < recipes[i].ingCount; j++) {
                printf(" -%s: %dg\n", recipes[i].ingredients[j].name, recipes[i].ingredients[j].amount);
            }
        }
    }
}

int main(void) {

    struct Recipe recipes[RECIPES_SIZE];
    int recipeCount = 0;
    int choice, ingNum;

    while(1) { // want code to run infinitely since you want to access the recipes even if it is completely filled 
        // initial display 
        printf("1. Add Recipe\n");
        printf("2. View Recipe\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){

            if (recipeCount > RECIPES_SIZE){
                printf("Maximum amount of recipes reached"); // error handling if more than the required recipes are added
                continue; // needed the program to keep running even when an error is hit
            }
            // Add recipes 
            printf("Enter recipe name: ");
            scanf(" %[^\n]", recipes[recipeCount].name); //  %[^\n] allows spaces to be read as strings as well, %s would break the program when adding recipe names that have spaces inbetween
            // add number of ingredients being used
            printf("How many ingredients will you be using?(%d ingredients allowed): ", ING_AMT);
            scanf("%d", &ingNum);

            if (ingNum > ING_AMT) {
                printf("Too many ingredients used"); // error handling if more than the specified ingredients are added
                continue;
            }
            // add ingredients and amount being used
            for (int i = 0; i < ingNum; i++) { // depending on the entered amount of ingredients being used, it takes that many inputs storing the data in recipes array
                printf("Enter ingredient %d name: ", i + 1);
                scanf(" %[^\n]", recipes[recipeCount].ingredients[i].name);
                printf("Enter amount of %s(g): ", recipes[recipeCount].ingredients[i].name);
                scanf("%d", &recipes[recipeCount].ingredients[i].amount);
            }

            recipes[recipeCount].ingCount = ingNum; // setting ingCount within the recipes array to what was set as the amount of ingredients used
            recipeCount++; // increment recipe by 1 to reflect how many recipes are within the recipes array, without it new recipes would overwrite existing ones as the index remains the same   
            printf("Recipe has been added\n");
           
        } else if (choice == 2) {
            viewRecipes(recipes, recipeCount);
        } else if (choice == 3) {
            printf("Exiting Software..\n");
            break;
        } else {
            printf("Invalid input\n");
        }        
    }

    return 0;
}