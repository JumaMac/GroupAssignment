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
    struct Ingredient ingredients[ING_AMT];
    int ingCount;
};