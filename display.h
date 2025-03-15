#include "recipe.h"
#include <stdio.h>

// declare the printRecipes function and pass list of recipes to print along with the number of recipes

void printRecipes(struct Recipe recipeList[], int recipeCount)
{
  if (recipeCount == 0)
  {
    printf("\nNo recipes found\n");
    return;
  }
// loop through and print them
  for (int i = 0; i < recipeCount; i++)
  {    
    printf("\n%s\n----------------\n", recipeList[i].name);
    for (int j = 0; j < recipeList[i].ingCount; j++){
      printf("- %s\n", recipeList[i].ingredients[j].name);
    }

  }
  
}
