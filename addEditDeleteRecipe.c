#include <stdio.h>
#include <string.h>
#include "recipe.h"


// ⭐️ start of code by Justin
void viewRecipes(struct Recipe recipes[], int *recipeCount) {
    // if user has no recipes in their book, error message pops up
    if (*recipeCount == 0) {
        printf("No available recipes.\n");
        return;
    // if not, prints the recipe
    } else {
        printf("Recipes: \n");
        for (int i = 0; i < *recipeCount; i++) {
            printf("Recipe %d: \n", i + 1);
            printf("Name: %s\n", recipes[i].name);
            printf("Ingredients: \n");
            for (int j = 0; j < recipes[i].ingCount; j++) {
                printf(" -%s: %.2f%s\n", 
                    recipes[i].ingredients[j].name, 
                    recipes[i].ingredients[j].amount,
                    recipes[i].ingredients[j].unit);
            }
            printf("Instructions: \n");
            printf("%s\n", recipes[i].instructions);
        }
    }
}

// using a pointer for recipeCount as I want the changes to be reflected within main 
void addRecipes(struct Recipe recipes[], int *recipeCount) {

    int ingNum;
     // error handling if more than the required recipes are added
    if (*recipeCount >= RECIPES_SIZE){
        printf("Maximum amount of recipes reached");
        // needed the program to keep running even when an error is hit
        return; 
    }
    // Add recipes 
    printf("Enter recipe name(Enter to go back): ");
    char firstChar;
    if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
        printf("Returning to menu...\n");
        return;
    }
    // if not, put the character back and read the full name
    ungetc(firstChar, stdin);
    scanf(" %49[^\n]", recipes[*recipeCount].name);
    while (getchar() != '\n'); 
    //  %[^\n] allows spaces to be read as strings as well, %s would break the program when adding recipe names that have spaces inbetween
    
    // add number of ingredients being used
    printf("How many ingredients will you be using?(%d ingredients allowed): ", ING_AMT);
    if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
        printf("Returning to menu...\n");
        return;
    }
    // if not, put the character back and read the full name
    ungetc(firstChar, stdin);
    scanf("%d", &ingNum);
    while (getchar() != '\n'); 

    // error handling if more than the specified ingredients are added
    if (ingNum > ING_AMT || ingNum <= 0) {
        printf("That's a questionable amount of ingredients used...going back"); 
        return;
    }
    
    // add ingredients and amount being used
    // depending on the entered amount of ingredients being used, it takes that many inputs storing the data in recipes array
    for (int i = 0; i < ingNum; i++) { 
        //enter ingredient name, with validation for when enter is pressed
        printf("Enter ingredient %d's name: ", i + 1);
        if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
            printf("Returning to menu...\n");
            return;
        }
        ungetc(firstChar, stdin);
        scanf(" %49[^\n]", recipes[*recipeCount].ingredients[i].name);
        while (getchar() != '\n'); 

        //print amount of ingredients, with enter validation check
        printf("Enter amount of %s: ", recipes[*recipeCount].ingredients[i].name);
        if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
            printf("Returning to menu...\n");
            return;
        }
        ungetc(firstChar, stdin);
        scanf("%f", &recipes[*recipeCount].ingredients[i].amount);
        while (getchar() != '\n'); 

        int unitChoice;
        printf("Select unit for %s:\n", recipes[*recipeCount].ingredients[i].name);
        printf("[1] grams (g)\n");
        printf("[2] milliliters (ml)\n");
        printf("[3] ounces (oz)\n");
        printf("Enter your choice (1-3): ");
        if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
            printf("Returning to menu...\n");
            return;
        }
        // if not, put the character back and read the full name
        ungetc(firstChar, stdin);
        scanf("%d", &unitChoice);
        while (getchar() != '\n'); 

        // depending on the users choice a string is copied into the ingredients.unit array and that value 
        // is stored for that certain ingredient 

        if (unitChoice == 1) {
            strcpy(recipes[*recipeCount].ingredients[i].unit, "g");
        }
        if (unitChoice == 2) {
            strcpy(recipes[*recipeCount].ingredients[i].unit, "ml");
        }
        if (unitChoice == 3) {
            strcpy(recipes[*recipeCount].ingredients[i].unit, "oz");
        }
    }
     // setting ingCount within the recipes array to what was set as the amount of ingredients used
    recipes[*recipeCount].ingCount = ingNum;

    // enter instructions here
    printf("Enter instructions (press Enter twice to finish):\n");
    int i = 0; //variable to keep track of counter of characters
    int newlines = 0; // variable to store newlines when user inputs enter
    int ch; // variable to store characters from user input
    
    while (i < INSTRUCT_SIZE - 1) {
        // as long as the counter is less than instruction size minus the null terminator 
        ch = getchar();
        // read a single char from input
        if (ch == '\n') {
            // if the input is a new line
            newlines++;
            //increment the counter 
            if (newlines >= 2) { // if user enters new line twice 
                i--; //decrement the counter
                break;  // break the loop
            }
        } else {
            newlines = 0; // reset if non-newline character is encountered
        }
    
        recipes[*recipeCount].instructions[i] = ch;
        // store input into instruction array
        i++;
        // increment i to move to next position in the array 
    }
    
    recipes[*recipeCount].instructions[i] = '\0'; // Null-terminate the string
    
    // increment recipe by 1 to reflect how many recipes are within the recipes array, without it new recipes would overwrite existing ones as the index remains the same  
    (*recipeCount)++;  
    
    // save recipes to file after adding
    saveRecipesToFile(recipes, *recipeCount);
}

void editRecipes(struct Recipe recipes[], int *recipeCount) {
    float newIngAmt;
    int recipeIndex, ingIndex, unitChoice;
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
    printf("Enter your choice(Press enter to go back): ");
    char firstChar;
    // setting a variable aside if it is a new line aka enter, it will return the user to the menu
    if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
        printf("Returning to menu...\n");
        return;
    }
    // if not, the character is put back and the whole line is read
    ungetc(firstChar, stdin);
    scanf("%d", &recipeIndex);
    while (getchar() != '\n'); // input buffer for new line

    // user input is set as the recipes index
    if (recipeIndex < 1 || recipeIndex > *recipeCount) {
        printf("Invalid Choice\n");
        return;
    }
    // decerement recipeIndex to map users input to array index at recipeCount - 1, in other words 1 = 0 (where 1 is user input and 0 is the index at that choice)
    recipeIndex--; 
    
    printf("Ingredients in %s:\n", recipes[recipeIndex].name);
    
    for (int i = 0; i < recipes[recipeIndex].ingCount; i++) {
        printf("%d. %s: %.2f%s\n", 
            i + 1, 
            recipes[recipeIndex].ingredients[i].name, 
            recipes[recipeIndex].ingredients[i].amount,
            recipes[recipeIndex].ingredients[i].unit
        );
    }

    // user can choose specific ingredient to edit based on its index
    printf("Enter ingredient # to update (1-%d)(Press enter to go back): ", recipes[recipeIndex].ingCount);
    if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
        printf("Returning to menu...\n");
        return;
    }
    // if not, put the character back and read the full name
    ungetc(firstChar, stdin);
    scanf("%d", &ingIndex);
    while (getchar() != '\n'); 
    // if any invalid indexes are entered the user is given an error
    if (ingIndex < 1 || ingIndex > recipes[recipeIndex].ingCount) {
        printf("Invalid Choice\n");
        return;
    }
    // similiar decrement is needed here as well since arrays are 0-based
    ingIndex--;
    // user can input a new name for ingredient, sets the value within name array of ing struct to user input at the specific index
    printf("Enter new ingredient name(Press enter to go back): ");
    if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
        printf("Returning to menu...\n");
        return;
    }
    // if not, put the character back and read the full name
    ungetc(firstChar, stdin);
    scanf(" %49[^\n]", recipes[recipeIndex].ingredients[ingIndex].name);
    while (getchar() != '\n'); 

    // user inputs new ingredient amount set to the variable newIngAmt
    printf("Enter new amount for %s: ", recipes[recipeIndex].ingredients[ingIndex].name);
    if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
        printf("Returning to menu...\n");
        return;
    }
    // if not, put the character back and read the full name
    ungetc(firstChar, stdin);

    if (scanf("%f", &newIngAmt) != 1 ) {
        printf("Invalid input.\n");
        return;
    } 
    while (getchar() != '\n'); 
    // the amount within the ing struct is set to the new value that was entered by the user
    recipes[recipeIndex].ingredients[ingIndex].amount = newIngAmt;
    
    printf("Ingredient updated successfully.\n");
    
    // save recipes to file after editing
    saveRecipesToFile(recipes, *recipeCount);
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
    printf("Enter recipe # to delete (1-%d)(Press enter to go back): ", *recipeCount);
    char firstChar;
    if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
        printf("Returning to menu...\n");
        return;
    }
    // if not, put the character back and read the full name
    ungetc(firstChar, stdin);
    scanf("%d", &recipeIndex);
    while (getchar() != '\n'); 
    
    if (recipeIndex < 1 || recipeIndex > *recipeCount) {
        printf("Invalid Choice\n");
        return;
    }
    // decrement user choice by 1 to reflect 0 based indexing 
    recipeIndex--;

    // elements are shifted to replace the chosen recipe to be deleted
    // loop stops when i = recipeCount - 1
    for (int i = recipeIndex; i < *recipeCount - 1; i++) {
        // eg. recipe[2] = recipe[3]
        // recipe 3 is replaced by recipe 4 and so on
        recipes[i] = recipes[i + 1];
    }
    // decrement recipe count to reflect the change within the array
    // hides whatever array was "deleted" as the array shifts
    (*recipeCount)--;

    printf("Recipe deleted successfully.\n");
    
    // save recipes to file after deleting
    saveRecipesToFile(recipes, *recipeCount);
}

void searchRecipe(struct Recipe recipes[], int recipeCount) {

    char searchName[50];
    char firstChar;
    int choice;
    printf("\n[1] Search by recipe name\n");
    printf("[2] Search by ingredient\n");
    printf("Enter your choice(Press enter to go back): ");
    if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
        printf("Returning to menu...\n");
        return;
    }
    // if not, put the character back and read the full name
    ungetc(firstChar, stdin);
    scanf("%d", &choice);
    while (getchar() != '\n'); 
   
    if (choice == 1) {
        printf("Enter recipe name to search(Press enter to go back): ");
        if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
            printf("Returning to menu...\n");
            return;
        }
        // if not, put the character back and read the full name
        ungetc(firstChar, stdin);
        scanf(" %49[^\n]", searchName); // recipes have spaces so must use %[^\n]
        // defining a variable found to false to set to true if the recipe is found
        while (getchar() != '\n'); 

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
            printf("Instructions:\n%s\n", recipes[i].instructions);
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
    else if (choice == 2) {
        printf("Enter an ingredient to search for(Press enter to go back): ");
        if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
            printf("Returning to menu...\n");
            return;
        }
    // if not, put the character back and read the full name
        ungetc(firstChar, stdin);
        scanf(" %49[^\n]", searchName); // allow spaces in input
        while (getchar() != '\n'); 

        int found = 0;
        // to access the nested ingredients struct we have to use a nested for loop 
        for (int i = 0; i < recipeCount; i++) {
            for (int j = 0; j < recipes[i].ingCount; j++) {
                // a string comparison is done between the ingredient name and the user input
                if (strcmp(recipes[i].ingredients[j].name, searchName) == 0) {
                    if (!found) {
                        printf("\nRecipes containing '%s':\n", searchName);
                        found = 1;
                    }
                    printf("\nRecipe Name: %s\n", recipes[i].name);
                    printf("Ingredients:\n");
                    for (int k = 0; k < recipes[i].ingCount; k++) {
                        printf(" - %s: %.2fg\n", recipes[i].ingredients[k].name, recipes[i].ingredients[k].amount);
                    }            
                    printf("Instructions:\n%s\n", recipes[i].instructions);
                    break; // stop searching for more ingredients in the same recipe
                }
            }
        }

        if (!found) {
            printf("\nNo recipes found with that ingredient.\n");
        }
    } 
    else {
        printf("Invalid choice.\n");
    }
}

// function to save user inputted array of recipes to a text file
void saveRecipesToFile(struct Recipe recipes[], int recipeCount) {
    // open the file "recipes.txt" in write mode ("w")
    FILE *file = fopen("recipes.txt", "w");

    // check if the file opened successfully
    if (file == NULL) {
        // print error message if file couldn't be opened
        printf("Error opening file for writing.\n");
        return;  // exit the function if there's an error
    }

    // loop through each recipe in the recipes array
    for (int i = 0; i < recipeCount; i++) {
        // recipe name header followed by the actual name
        fprintf(file, "Recipe Name: %s\n", recipes[i].name);
        
        // ingredients section header
        fprintf(file, "Ingredients:\n");

        // loop through each ingredient in the current recipe
        for (int j = 0; j < recipes[i].ingCount; j++) {
            // using the ingredient in the format: "- name: amount"
            fprintf(file, "- %s: %.2f%s\n", 
                   recipes[i].ingredients[j].name, 
                   recipes[i].ingredients[j].amount,
                   recipes[i].ingredients[j].unit
                );
        }

        // Write the instructions section
        fprintf(file, 
            "Instructions:\n"  // instructions header
            "%s\n"            // instructions content
            "-------------------------------\n",  // delimiter helps separate recipes
            recipes[i].instructions
        );
    }
    printf("\nFile has been successfully updated!\n");

    // close the file to ensure all data is written and resources freed
    fclose(file);
    
}

// function to load recipes from a text file into the recipes array
void loadRecipesFromFile(struct Recipe recipes[], int *recipeCount) {
    // open the recipes file in read mode
    FILE *file = fopen("recipes.txt", "r");
    
    // check if file opening failed
    if (file == NULL) {
        printf("No existing recipe file found. Starting fresh.\n");
        return;  // exit function if file doesn't exist
    }

    // initialize recipe count to 0 
    *recipeCount = 0;
    
    // loop to read recipes until array is full or EOF reached
    // checks if recipecount is less than the allowed recipesize and that the recipe has a name 
    while (*recipeCount < RECIPES_SIZE && 
           fscanf(file, "Recipe Name: %[^\n]", recipes[*recipeCount].name) == 1) {
        // %[^\n] holds the characters for the recipe name
        // conditions must hold true for the loop to occur
        
        // match the "Ingredients:" header line to discard
        fscanf(file, " Ingredients:\n");
        
        // initialize ingredient count for current recipe
        recipes[*recipeCount].ingCount = 0;
        
        // loop to read ingredients until format doesn't match
        while (fscanf(file, " - %[^:]: %f%2s", 
                     // ingredient format must match exactly to ingredients entered by a user
                     // store in current recipe's ingredients array
                     recipes[*recipeCount].ingredients[recipes[*recipeCount].ingCount].name,
                     &recipes[*recipeCount].ingredients[recipes[*recipeCount].ingCount].amount,
                     recipes[*recipeCount].ingredients[recipes[*recipeCount].ingCount].unit
                    ) == 3) {
            // increment ingredient count when read is successful
            recipes[*recipeCount].ingCount++;
            
            // discard newline after each ingredient line
            fscanf(file, "\n");
        }

        // read and discard the "Instructions:" header line
        fscanf(file, " Instructions:\n");
        
        // read instructions text until first hyphen (start of delimiter)
        // %[^-] reads all characters that are not hyphens
        fscanf(file, " %[^-] ", recipes[*recipeCount].instructions);
        
        // discard the delimiter line and new line
        fscanf(file, "-------------------------------\n");
        
        // move to next recipe slot in array
        (*recipeCount)++;
    }

    // Close the file when done
    fclose(file);
}
// ⭐️ end of code by Justin

// ⭐️ start of code by Mikey
void adjustIngredients(struct Recipe recipes[], int *recipeCount) {
    float adjustedIngAmt;
    int recipeIndex;
    int servings;
    char firstChar;

    if (*recipeCount == 0) {
        printf("No recipes to update\n");
        return;
    }
    // View numbered list of recipe names before adjusting
    printf("Recipes\n");
    
    for (int i = 0; i < *recipeCount; i++) {
        printf("%d. %s\n", i + 1, recipes[i].name);
    }
    // allow user to choose recipe by its number on the list of recipes
    printf("Enter recipe # to adjust (1-%d)\n", *recipeCount);
    printf("Enter your choice: ");
    if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
        printf("Returning to menu...\n");
        return;
    }
    // if not, put the character back and read the full name
    ungetc(firstChar, stdin);
    scanf("%d", &recipeIndex);
    while (getchar() != '\n'); 
    // user input is set as the recipes index
    if (recipeIndex < 1 || recipeIndex > *recipeCount) {
        printf("Invalid Choice\n");
        return;
    }
    // decerement recipeIndex to map users input to array index at recipeCount - 1, in other words 1 = 0 (where 1 is user input and 0 is the index at that choice)
    recipeIndex--; 
    
    printf("How many servings would you like to make?: ");
    if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
        printf("Returning to menu...\n");
        return;
    }
    // if not, put the character back and read the full name
    ungetc(firstChar, stdin);
    scanf("%d", &servings);
    while (getchar() != '\n'); 

    if (servings < 1) {
        printf("\nThat's not enough servings!\n");
        return;
    } else if (servings > 100) {
        printf("\nYou sure you want that many?\n");
        return;
    } 
    
    //loops through the array of ingredients in the recipe selected and adjusts based on servings inputted by user
    for(int i = 0; i < recipes[recipeIndex].ingCount; i++) {
        recipes[recipeIndex].ingredients[i].amount *= (float)servings;
    }

    //display adjusted ingredient amounts
    printf("Here are the adjusted ingredient amounts for %d serving(s)\n", servings);
    for (int i = 0; i < recipes[recipeIndex].ingCount; i++) {
        printf(" - %s: %.2f%s\n", 
            recipes[recipeIndex].ingredients[i].name, 
            recipes[recipeIndex].ingredients[i].amount,
            recipes[recipeIndex].ingredients[i].unit
        );
    }

    //negates the calculation so that the values return back to how they were
    for(int i = 0; i < recipes[recipeIndex].ingCount; i++) {
        recipes[recipeIndex].ingredients[i].amount /= (float)servings;
    }
}
// ⭐️ end of code by Mikey