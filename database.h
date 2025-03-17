#pragma once
#include "recipe.h"
#include <stdio.h>
#include "string.h"
#include <mm_malloc.h>

int initRecipes(struct Recipe recipes[])
{
    // now i have an empty array of recipes called 'recipes'
    // I'm going to go one element of the array at a time and populate each recipe
    // name, ingcount, ingredients and amount are all defined in recipe.h

    // recipe #1 - potato salad
    // adding a name for recipe 1
    strcpy(recipes[0].name, "10-Minute Mushroom Avocado Toast");
    // adding a category for recipe 1
    recipes[0].category = 5;
    // adding ingredient count for recipe 1
    recipes[0].ingCount = 7;
    // adding ingredient 1 name
    strcpy(recipes[0].ingredients[0].name, "Whole Grain Seeded");
    // adding ingredient 1 amount
    recipes[0].ingredients[0].amount = 1;
    // adding ingredient 2 name
    strcpy(recipes[0].ingredients[1].name, "Ripe Avocado");
    // adding ingredient 2 amount
    recipes[0].ingredients[1].amount = 0.25;
    strcpy(recipes[0].ingredients[2].name, "Vegan Butter");
    // adding ingredient 3 amount
    recipes[0].ingredients[2].amount = 0.5;
    //adding ingredient 4 name
    strcpy(recipes[0].ingredients[3].name, "Shitake Mushroom");
    // adding ingredient 5 amount
    recipes[0].ingredients[3].amount = 0.35;
    // adding ingredient 5 name 
    strcpy(recipes[0].ingredients[4].name, "Dried Thyme");
    // adding ingredient 5 amount
    recipes[0].ingredients[4].amount = 0.25;
    // adding ingredient 6 name
    strcpy(recipes[0].ingredients[5].name, "red pepper flakes");
    // adding ingredient 7 amount
    recipes[0].ingredients[5].amount = 0.5;
    strcpy(recipes[0].ingredients[6].name, "Dried Thyme");
    // adding ingredient 7 amount
    recipes[0].ingredients[6].amount = 0.25;
    // adding instructions for this recipe
    strcpy(recipes[0].instructions,
           "1. Heat vegan butter or olive oil in a large skillet over medium heat.\n"
           "2. Add the sliced mushrooms, thyme, and red pepper flakes (optional). Cook, stirring occasionally, until softened and lightly browned — about 5-7 minutes. If the mushrooms are sticking to the pan, reduce the heat slightly or add more butter or oil.\n"
           "3. Meanwhile, toast bread in the oven or a toaster.\n"
           "4. Once the mushrooms are lightly browned, turn off the heat and stir in the salt, pepper, and garlic powder. Taste and adjust as needed, adding more salt to taste or black pepper for spice.\n"
           "5. Top the toasted bread with ripe avocado and use a fork to smash. Then top with sautéed mushroom mixture and vegan parmesan cheese (optional).\n"
           "6. Eat, repeat, enjoy!\n\n"
           "Best when fresh. Not freezer friendly.\n\n");

    // recipe #2 - french Onion Soup
    strcpy(recipes[1].name, "French Onion Soup");
    // adding ingredient count for recipe 2
    recipes[1].ingCount = 3;
    // adding ingredient 1
    strcpy(recipes[1].ingredients[0].name, "French");
    // adding amount
    recipes[1].ingredients[0].amount = 7;
    // adding ingredient 2
    strcpy(recipes[1].ingredients[1].name, "Onion");
    // adding amouint
    recipes[1].ingredients[1].amount = 4;
    // adding ingredient 3
    strcpy(recipes[1].ingredients[2].name, "Soup");
    // adding amount 3
    recipes[1].ingredients[2].amount = 5;

    // returning 2 for 2 recipe
    // Function is called in recipe.c line 9.
    return 2;
}

// define function searchByCategory which returns number of Recipes found
int searchByCategory(struct Recipe allRecipes[], int allRecipeCount, struct Recipe foundRecipes[], int categoryChoice)
{
    // iterate through all recipies and only return those that match the category

    // define how many recipes are found
    int foundRecipesCount = 0;
    // now we can iterate through allRecipies array by using a for loop
    for (int i = 0; i < allRecipeCount; i++)
    {
        // if the number that the user picked equals the category number listed in the recipe, then add it to foundRecipes and increment foundRecipesCount
        if (categoryChoice == allRecipes[i].category)
        {
            foundRecipes[foundRecipesCount] = allRecipes[i];
            foundRecipesCount++;
        }
    }
    return foundRecipesCount;
    // When this for loop finishes, we will have an array (foundRecipes) that holds all recipes with the category that the user inputed
}
