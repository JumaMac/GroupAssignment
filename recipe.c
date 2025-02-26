#include <stdio.h>
#include "recipe.h"
#define RECIPES_SIZE 25

int main(void) {

    struct Recipe recipes[RECIPES_SIZE];
    int recipeCount = 0;
    int choice, ingNum;

    while(1) {
        
        printf("1. Add Recipe\n");
        printf("2. View Recipe\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){

            if (recipeCount > RECIPES_SIZE){
                printf("Maximum amount of recipes reached");
                continue;
            }

            printf("Enter recipe name: ");
            scanf(" %[^\n]", recipes[recipeCount].name);

            printf("How many ingredients will you be using?(%d ingredients allowed): ", ING_AMT);
            scanf("%d", &ingNum);

            if (ingNum > ING_AMT) {
                printf("Too many ingredients used");
                continue;
            }
            
            for (int i = 0; i < ingNum; i++) {
                printf("Enter ingredient %d name: ", i + 1);
                scanf(" %[^\n]", recipes[recipeCount].ingredients[i].name);
                printf("Enter amount of %s(g): ", recipes[recipeCount].ingredients[i].name);
                scanf("%d", &recipes[recipeCount].ingredients[i].amount);
            }

            printf("Recipe has been added\n");
            recipeCount++;    
        } else if (choice == 2) {

            if (recipeCount == 0) {
                printf("No available recipes.");
                continue;
            } else {
                printf("Recipes: \n");
                for (int i = 0; i < recipeCount; i++) {
                    printf("Recipe %d: \n", i + 1);
                    printf("Name: %s\n", recipes[i].name);
                    printf("Ingredients: \n");
                    for (int j = 0; j < ingNum; j++) {
                        printf(" -%s: %dg\n", recipes[i].ingredients[j].name, recipes[i].ingredients[j].amount);
                    }
                }
            }
        } else if (choice == 3) {
            printf("Exiting Software..");
            break;
        } else {
            printf("Invalid input");
        }        
    }

    return 0;
}