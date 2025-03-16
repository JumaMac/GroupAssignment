#include <stdio.h>
#include "recipe.h"

int main(void) {

    struct Recipe recipes[RECIPES_SIZE];
    int recipeCount = 0;
    int choice;

    while(1) { // want code to run infinitely since you want to access the recipes even if it is completely filled 
        // initial display 
        printf("\n1. Add Recipe\n");
        printf("2. View Recipe\n");
        printf("3. Edit Recipes\n");
        printf("4. Delete Recipe\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            addRecipes(recipes, &recipeCount);
        } else if (choice == 2) {
            viewRecipes(recipes, recipeCount);
        } else if (choice == 3) {
            editRecipes(recipes, recipeCount);
        } else if (choice == 4) {
            deleteRecipes(recipes, &recipeCount);
        } else if (choice == 5) {
            printf("Exiting Software..\n");
            break;
        } else {
            printf("Invalid input\n");
        }        
    }

    return 0;
}