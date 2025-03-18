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
    struct AdjustedValues;
    int ingCount; //ingredient count needed so each recipe could have differing amounts of ingredients
    char instructions[INSTRUCT_SIZE]; //defining instructions to be added in database.h - THOMAS 
    int servings;
    float newAMT;
};


void viewRecipes(struct Recipe recipes[], int recipeCount);
void addRecipes(struct Recipe recipes[], int *recipeCount);
void editRecipes(struct Recipe recipes[], int *recipeCount);
void deleteRecipes(struct Recipe recipe[], int *recipeCount);
void searchRecipe(struct Recipe recipes[], int recipeCount);


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
                printf(" -%s: %.2fg\n", recipes[i].ingredients[j].name, recipes[i].ingredients[j].amount);
            }
            printf("Instructions: \n");
            printf("%s", recipes[i].instructions);
        }
    }
}
// using a pointer for recipeCount as I want the changes to be reflected within main 
void addRecipes(struct Recipe recipes[], int *recipeCount) {

    int ingNum;

     // error handling if more than the required recipes are added
    if (*recipeCount > RECIPES_SIZE){
        printf("Maximum amount of recipes reached");
        // needed the program to keep running even when an error is hit
        return; 
    }
    // Add recipes 
    printf("Enter recipe name: ");
    scanf(" %[^\n]", recipes[*recipeCount].name); //  %[^\n] allows spaces to be read as strings as well, %s would break the program when adding recipe names that have spaces inbetween
    // add number of ingredients being used
    printf("How many ingredients will you be using?(%d ingredients allowed): ", ING_AMT);
    scanf("%d", &ingNum);

    // error handling if more than the specified ingredients are added
    if (ingNum > ING_AMT) {
        printf("Too many ingredients used"); 
        return;
    }
    
    // add ingredients and amount being used
    // depending on the entered amount of ingredients being used, it takes that many inputs storing the data in recipes array
    for (int i = 0; i < ingNum; i++) { 
        printf("Enter ingredient %d name: ", i + 1);
        scanf(" %[^\n]", &recipes[*recipeCount].ingredients[i].name);
        printf("Enter amount of %s: ", recipes[*recipeCount].ingredients[i].name);
        scanf("%f", &recipes[*recipeCount].ingredients[i].amount);
    }

     // setting ingCount within the recipes array to what was set as the amount of ingredients used
    recipes[*recipeCount].ingCount = ingNum;
    // increment recipe by 1 to reflect how many recipes are within the recipes array, without it new recipes would overwrite existing ones as the index remains the same  
    (*recipeCount)++;  
    printf("Recipe has been added\n");
}

void editRecipes(struct Recipe recipes[], int *recipeCount) {
    float newIngAmt;
    int recipeIndex, ingIndex;
    char newName[50];

    if (*recipeCount == 0) {
        printf("No recipes to update\n");
        return;
    }
    // View numbered list of recipe names before editing
    printf("Recipes\n");
    
    for (int i = 0; i < *recipeCount; i++) {
        printf("%d. %s\n", i + 1, recipes[i].name);
    }
    // allow user to choose recipe by its number on the list of recipes
    printf("Enter recipe # to update (1-%d)\n", *recipeCount);
    printf("Enter your choice: ");
    scanf("%d", &recipeIndex);
    // user input is set as the recipes index
    if (recipeIndex < 1 || recipeIndex > *recipeCount) {
        printf("Invalid Choice\n");
        return;
    }
    // decerement recipeIndex to map users input to array index at recipeCount - 1, in other words 1 = 0 (where 1 is user input and 0 is the index at that choice)
    recipeIndex--; 
    
    printf("Ingredients in %s:\n", recipes[recipeIndex].name);
    
    for (int i = 0; i < recipes[recipeIndex].ingCount; i++) {
        printf("%d. %s: %.2fg\n", i + 1, recipes[recipeIndex].ingredients[i].name, recipes[recipeIndex].ingredients[i].amount);
    }

    // user can choose specific ingredient to edit based on its index
    printf("Enter ingredient # to update (1-%d): ", recipes[recipeIndex].ingCount);
    scanf("%d", &ingIndex);

    if (ingIndex < 1 || ingIndex > recipes[recipeIndex].ingCount) {
        printf("Invalid Choice\n");
        return;
    }
    // similiar decrement is needed here as well since arrays are 0-based
    ingIndex--;
    // user can input a new name for ingredient, sets the value within name array of ing struct to user input at the specific index
    printf("Enter new ingredient name: ");
    scanf(" %[^\n]", recipes[recipeIndex].ingredients[ingIndex].name);
    // user inputs new ingredient amount set to the variable newIngAmt
    printf("Enter new amount for %s: ", recipes[recipeIndex].ingredients[ingIndex].name);
    scanf("%f", &newIngAmt);
    // the amount within the ing struct is set to the new value that was entered by the user
    recipes[recipeIndex].ingredients[ingIndex].amount = newIngAmt;
    
    printf("Ingredient updated successfully.\n");
}
// pointer used for recipeCount again as we want any changes to the count to be reflected within the main function
void deleteRecipes(struct Recipe recipes[], int *recipeCount) {
    
    int recipeIndex;
    // validation if no recipes exist yet 
    if (*recipeCount == 0) {
        printf("No recipes to delete.\n");
        return;
    }
    // print out list of recipes in order of index + 1
    printf("Recipes:\n");
    for (int i = 0; i < *recipeCount; i++) {
        printf("%d. %s\n", i + 1, recipes[i].name);
    }
    // user chooses recipe to delete based on index, input is set to recipeIndex
    printf("Enter recipe # to delete (1-%d): ", *recipeCount);
    scanf("%d", &recipeIndex);
    
    if (recipeIndex < 1 || recipeIndex > *recipeCount) {
        printf("Invalid Choice\n");
        return;
    }
    // decrement user choice by 1 to reflect 0 based indexing 
    recipeIndex--;

    // elements are shifted to replace the chosen recipe to be deleted
    for (int i = recipeIndex; i < *recipeCount - 1; i++) {
        recipes[i] = recipes[i + 1];
    }
    // decrement recipe count to reflect the change within the array
    (*recipeCount)--;

    printf("Recipe deleted successfully.\n");
}

void searchRecipe(struct Recipe recipes[], int recipeCount) {

    char searchName[50];
    printf("Enter recipe name to search: ");
    scanf(" %[^\n]", searchName); // recipes have spaces so must use %[^\n]
    // defining a variable found to false to set to true if the recipe is found
    int found = 0;
    for (int i = 0; i < recipeCount; i++) {
        // comparing recipes name within the array to the user input of searchName, 0 means the strings are identical
        // when searching case sensitivity matters, must match exact strings
        if (strcmp(recipes[i].name, searchName) == 0) {
            printf("\nRecipe found\n");
            printf("\nRecipe Name: %s\n", recipes[i].name);
            printf("Ingredients:\n");
            for (int j = 0; j < recipes[i].ingCount; j++) {
                printf(" - %s: %.2fg\n", recipes[i].ingredients[j].name, recipes[i].ingredients[j].amount);
            }
            // found is set to true when a match has been found
            found = 1;
            // stop searching after finding the first match
            break; 
        }
    }

    if (!found) {
        printf("\nRecipe not found.\n");
    }
}

// ⭐️ end of code by Justin

// ⭐️ start of code by Mikey

void adjustIngredients(struct Recipe* recipe, int newServings) {
    if (newServings <= 0) {
        printf("Enter the number of servings: ");
        scanf("%d", &newServings);
        printf("Invalid number of servings.\n");
        return;
    }
    float factor = (float)newServings / recipe->servings; // Calculate adjustment factor

    for (int i = 0; i < recipe->ingCount; i++) {
        recipe->ingredients[i].amount *= factor; // Adjust amount
    }

    recipe->servings = newServings;  // Update servings count
}

// ⭐️ end of code by Mikey 
