#pragma once
#include "recipe.h"
#include <stdio.h>
#include "string.h"
#include <mm_malloc.h>

int initRecipes(struct Recipe recipes[])
{
    // now i have an empty array of recipes called 'recipes'
    // I'm going to go one element of the array at a time and populate each recipe
    
    // recipe #1 - potato salad
    strcpy(recipes[0].name, "Potato Salad");
    recipes[0].ingCount = 2;

    strcpy(recipes[0].ingredients[0].name, "potato");
    recipes[0].ingredients[0].amount = 5;
    strcpy(recipes[0].ingredients[1].name, "salad");
    recipes[0].ingredients[1].amount = 2;


    strcpy(recipes[1].name, "French Onion Soup");
    recipes[1].ingCount = 3;

    strcpy(recipes[1].ingredients[0].name, "French");
    recipes[1].ingredients[0].amount = 7;
    strcpy(recipes[1].ingredients[1].name, "Onion");
    recipes[1].ingredients[1].amount = 4;
    strcpy(recipes[1].ingredients[2].name, "Soup");
    recipes[1].ingredients[2].amount = 9;





    return 2;

}