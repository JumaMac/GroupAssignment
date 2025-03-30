// ⭐️ start of code by Justin
#pragma once
#define NAME_SIZE 50
#define ING_SIZE 50
#define ING_AMT 10
#define INSTRUCT_SIZE 1000 //defining max for the instructions for ingredients - THOMAS 
#define CATEGORY_SIZE 50 //defining max for the category name 
#define RECIPES_SIZE 500 //moved this from main so that it can be read from database.h



struct Ingredient {
    char name[ING_SIZE];
     float amount;


};

struct Recipe {
    int category;
    char name[NAME_SIZE];
    struct Ingredient ingredients[ING_AMT]; //struct of ingredients so i can loop through the amount and name separately from the recipe
    int ingCount; //ingredient count needed so each recipe could have differing amounts of ingredients
    char instructions[INSTRUCT_SIZE]; //defining instructions to be added in database.h - THOMAS 
    // int servings;
    // float newAMT;
};


void viewRecipes(struct Recipe recipes[], int recipeCount);
void addRecipes(struct Recipe recipes[], int *recipeCount);
void editRecipes(struct Recipe recipes[], int *recipeCount);
void deleteRecipes(struct Recipe recipe[], int *recipeCount);
void searchRecipe(struct Recipe recipes[], int recipeCount);
void saveRecipesToFile(struct Recipe recipes[], int recipeCount);
void loadRecipesFromFile(struct Recipe recipes[], int *recipeCount);


// ⭐️ start of code by Mikey

// void adjustIngredients(struct Recipe* recipe, int newServings) {
//     if (newServings <= 0) {
//         printf("Enter the number of servings: ");
//         scanf("%d", &newServings);
//         printf("Invalid number of servings.\n");
//         return;
//     }
//     float factor = (float)newServings / recipe->servings; // Calculate adjustment factor

//     for (int i = 0; i < recipe->ingCount; i++) {
//         recipe->ingredients[i].amount *= factor; // Adjust amount
//     }

//     recipe->servings = newServings;  // Update servings count
// }

// ⭐️ end of code by Mikey 
