#pragma once
#include "recipe.h"
#include <stdio.h>
#include "string.h"
#include <mm_malloc.h>

int initRecipes(struct Recipe recipes[])
{
    // now i have an empty array of recipes called 'recipes'
    // I'm going to go one element of the array at a time and populate each recipe
    //name, ingcount, ingredients and amount are all defined in recipe.h



    // recipe #1 - potato salad
    //adding a name for recipe 1
    strcpy(recipes[0].name, "Potato Salad");
    //adding ingredient count for recipe 1 
    recipes[0].ingCount = 2;
    //adding ingredient 1 name
    strcpy(recipes[0].ingredients[0].name, "potato");
    //adding ingredient 1 amount 
    recipes[0].ingredients[0].amount = 5;
    //adding ingredient 2 name
    strcpy(recipes[0].ingredients[1].name, "salad");
    //adding ingredient 2 ammoint
    recipes[0].ingredients[1].amount = 2;

    //recipe #2 - french Onion Soup
    strcpy(recipes[1].name, "French Onion Soup");
    //adding ingredient count for recipe 2
    recipes[1].ingCount = 3;
    //adding ingredient 1 
    strcpy(recipes[1].ingredients[0].name, "French");
    //adding amount 
    recipes[1].ingredients[0].amount = 7;
    //adding ingredient 2
    strcpy(recipes[1].ingredients[1].name, "Onion");
    //adding amouint
    recipes[1].ingredients[1].amount = 4;
    //adding ingredient 3
    strcpy(recipes[1].ingredients[2].name, "Soup");
    //adding amount 3
    recipes[1].ingredients[2].amount = 9;



    //returning 2 for 2 recipe
    //Function is called in recipe.c line 9. 
    return 2;

}