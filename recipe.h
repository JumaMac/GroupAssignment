#pragma once
#define NAME_SIZE 50
#define ING_SIZE 50
#define ING_AMT 10

struct Ingredient {
    char name[ING_SIZE];
    int amount; 
};

struct Recipe {
    char name[NAME_SIZE];
    struct Ingredient ingredients[ING_AMT]; //struct of ingredients so i can loop through the amount and name separately from the recipe
    int ingCount; //ingredient count needed so each recipe could have differing amounts of ingredients
    int servings;
};


// Function to adjust ingredient amounts based on servings
void adjustIngredients(struct Recipe* recipe, int newServings) {
    if (newServings <= 0) {
        printf("Invalid number of servings.\n");
        return;
    }
    float factor = (float)newServings / recipe->servings; // Calculate adjustment factor

    for (int i = 0; i < recipe->ingCount; i++) {
        recipe->ingredients[i].amount *= factor; // Adjust amount
    }

    recipe->servings = newServings;  // Update servings count
}
//⭐️ end of code by Mikey