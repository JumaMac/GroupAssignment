#include <stdio.h>
#include <math.h> // Needed for ceil()

int main(void)
{
    int servings;

    // Ingredient names
    const char* ingredients[] = {
        "salmon", "paprika (teaspoons)", "garlic powder (teaspoons)", "onion powder (teaspoons)",
        "salt (teaspoons)", "black pepper (teaspoons)", "olive oil (tablespoons)",
        "minced garlic (teaspoons)", "soy sauce (tablespoons)", "honey (cups)"
    };

    // Base ingredient quantities for 1 serving (except salmon which is 1 per 4 servings)
    const double base_quantities[] = {
        1, //salmon 0
        1, //paprika 1
        1, //garlic powder 2
        1, //onion powder 3
        0.75, //salt 4
        1, //black pepper 5
        3, //olive oil 6
        2, //minced garlic 7
        3, //soy sauce 8
        0.25 //honey 9
    };

    double scaled_quantities[10]; // Store the new calculated values

    // Get user input
    printf("How many servings do you want to make?: ");
    scanf("%d", &servings);

    // In case of invalid serving input number
    if (servings <= 0) {
        printf("Invalid input. Number of servings must be greater than zero.\n");
        return 1;
    }

    // Adjust quantities
    for (int i = 1; i < 10; i++) { // Start at index 1 (skip salmon for now)
        scaled_quantities[i] = base_quantities[i] * servings;
    }

    // Individual calculations for specific ingredients
    
    // 1 salmon per 4 servings
    scaled_quantities[0] = ceil((double)servings / 4); // Round up to whole salmon
    
    // 3 Tablespoons of Soy sauce per 4 servings
    scaled_quantities[8] = ceil((double)servings *3 / 4);
    
    // 3 Tablespoons of olive oil per 4 servings
    scaled_quantities[6] = ceil((double)servings *3 / 4);
    


    // Display the adjusted quantities
    printf("\nFor %d servings, you will need:\n", servings);
    for (int i = 0; i < 10; i++) {
        printf("%.2f %s\n", scaled_quantities[i], ingredients[i]);
    }

    return 0;
}
//he he