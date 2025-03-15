#include <stdio.h>
#include "recipe.h"
#define RECIPES_SIZE 25

void viewRecipes(struct Recipe recipes[], int recipeCount);
void editRecipes(struct Recipe recipes[], int recipeCount);

void viewRecipes(struct Recipe recipes[], int recipeCount) {

    if (recipeCount == 0) {
        printf("No available recipes.\n");
        return;

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

void editRecipes(struct Recipe recipes[], int recipeCount) {
    int recipeIndex, ingIndex, newIngAmt;
    char newName[50];

    if (recipeCount == 0) {
        printf("No recipes to update\n");
        return;
    }

    printf("Recipes\n");
    for (int i = 0; i < recipeCount; i++) {
        printf("%d. %s\n", i + 1, recipes[i].name);
    }

    printf("Enter recipe # to update (1-%d)\n", recipeCount);
    printf("Enter your choice: ");
    scanf("%d", &recipeIndex);

    if (recipeCount < recipeIndex) {
        printf("Invalid Choice\n");
        return; 
    }
    
    recipeIndex--; // decerement recipeIndex to map users input to array index at 0 - recipeCount
    
    printf("Ingredients in %s:\n", recipes[recipeIndex].name);
    for (int i = 0; i < recipes[recipeIndex].ingCount; i++) {
        printf("%d. %s: %dg\n", i + 1, recipes[recipeIndex].ingredients[i].name, recipes[recipeIndex].ingredients[i].amount);
    }

    printf("Enter ingredient # to update (1-%d): ", recipes[recipeIndex].ingCount);
    scanf("%d", &ingIndex);

    ingIndex--;

    printf("Enter new ingredient name: ");
    scanf(" %[^\n]", recipes[recipeIndex].ingredients[ingIndex].name);
   
    printf("Enter new amount for %s: ", recipes[recipeIndex].ingredients[ingIndex].name);
    scanf("%d", &newIngAmt);

    recipes[recipeIndex].ingredients[ingIndex].amount = newIngAmt;
    
    printf("Ingredient updated successfully.\n");
}
    

int main(void) {

    struct Recipe recipes[RECIPES_SIZE];
    int recipeCount = 0;
    int choice, ingNum;

    while(1) { // want code to run infinitely since you want to access the recipes even if it is completely filled 
        // initial display 
        printf("1. Add Recipe\n");
        printf("2. View Recipe\n");
        printf("3. Edit Recipes\n");
        printf("4. Exit\n");
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
                printf("Enter amount of %s: ", recipes[recipeCount].ingredients[i].name);
                scanf("%d", &recipes[recipeCount].ingredients[i].amount);
            }

            recipes[recipeCount].ingCount = ingNum; // setting ingCount within the recipes array to what was set as the amount of ingredients used
            recipeCount++; // increment recipe by 1 to reflect how many recipes are within the recipes array, without it new recipes would overwrite existing ones as the index remains the same   
            printf("Recipe has been added\n");
           
        } else if (choice == 2) {
            viewRecipes(recipes, recipeCount);
        } else if (choice == 3) {
            editRecipes(recipes, recipeCount);
        } else if (choice == 4) {
            printf("Exiting Software..\n");
            break;
        } else {
            printf("Invalid input\n");
        }        
    }

    return 0;
}