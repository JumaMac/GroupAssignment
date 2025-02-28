#include <stdio.h>

int main(void)
{
    int servings;
    
    //Ingredient names
    const char* ingredients[] = {
        "salted butter (tablespoons)", "white sugar (grams)", "light brown sugar (grams)", "vanilla (teaspoons)", "eggs", "flour (grams)", "baking soda (teaspoons)", "salt (teaspoons)", "chocolate chips (grams)"
    };
    
    double quantities[] = {
        16,
        200,
        100,
        2,
        2,
        375,
        1,
        0.5,
        336,
    };
    
    printf("How many servings do you want to make?: ");
    scanf("%d", &servings);
    
    //Multiplies based on how many servings
    
    for (int i = 0; i < 9; i++){
        quantities[i] *= servings;
    }
    
    //Display the adjusted quantities
    printf("\n For %d servings, you will need:\n", servings);
    for (int i = 0; i < 9; i++){
        printf("%.2f %s\n", quantities[i], ingredients[i]);
    }
    
    return 0;
}
//test