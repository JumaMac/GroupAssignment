#pragma once
#define NAME_SIZE 50
#define ING_SIZE 50
#define ING_AMT 10

// ⭐️ start of code by Justin
struct Ingredient {
    char name[ING_SIZE];
    int amount; 
};

struct Recipe {
    char name[NAME_SIZE];
    struct Ingredient ingredients[ING_AMT]; //struct of ingredients so i can loop through the amount and name separately from the recipe
    int ingCount; //ingredient count needed so each recipe could have differing amounts of ingredients
};

// ⭐️ end of code by Justin