#include <stdio.h>
#include "allRecipes.h" 

// Function to display breakfast recipes
void display_breakfast_recipes() {
    printf("\n\033[1mBreakfast & Brunch:\033[0m\n");
    printf("[1] 10-Minute Mushroom Avocado Toast\n");
    printf("[2] Easy Vegan French Toast (10 Minutes!)\n");
    printf("[0] Go Back\n\n");
}

// Function to display lunch recipes
void display_lunch_recipes() {
    printf("\n\033[1mLunch Specials:\033[0m\n");
    printf("[1] Sun-Dried Tomato Pesto Pasta (Vegan + GF)\n");
    printf("[2] The Ultimate Salmon Burger (30 Minutes!)\n");
    printf("[0] Go Back\n\n");
}

// Function to display dinner recipes
void display_dinner_recipes() {
    printf("\n\033[1mDinner Delights:\033[0m\n");
    printf("[1] Easy Shakshuka (with Fresh or Canned Tomatoes)\n");
    printf("[2] Chicken Noodle Soup (Classic or Immune-Boosting!)\n");
    printf("[0] Go Back\n\n");
}

// Function to display dessert recipes
void display_dessert_recipes() {
    printf("\n\033[1mDesserts & Sweets:\033[0m\n");
    printf("[1] Homemade Gluten-Free Oreos (Vegan)\n");
    printf("[2] The BEST Chocolate Cake Mix Cookies\n");
    printf("[0] Go Back\n\n");
}

// Function to display vegetarian/vegan recipes
void display_veg_vegan_recipes() {
    printf("\n\033[1mVegetarian & Vegan:\033[0m\n");
    printf("[1] 10-Minute Mushroom Avocado Toast\n");
    printf("[2] Easy Vegan French Toast (10 Minutes!)\n");
    printf("[3] Sun-Dried Tomato Pesto Pasta (Vegan + GF)\n");
    printf("[4] Homemade Gluten-Free Oreos (Vegan)\n");
    printf("[5] The BEST Chocolate Cake Mix Cookies\n");
    printf("[0] Go Back\n\n");
}

void breakfast_recipe_1(int servings) {
    printf("\n\033[1m10-Minute Mushroom Avocado Toast\033[0m\n");
    printf("The ultimate plant-based breakfast: avocado toast with savory sautéed mushrooms.\n"
           "SO satisfying, perfectly toasty, and ready in just 10 minutes with 1 pan and 7 ingredients!\n\n");

    // Ingredient list and quantities, similar to before
    char *ingredients[] = {
        "Bread Slices (oz)", 
        "Medium Ripe Avocado (each)", 
        "Vegan Butter (Tbsp)", 
        "Sliced Shiitake Mushrooms (oz)", 
        "Dried Thyme (tsp)", 
        "Red Pepper Flakes (pinch)", 
        "Sea Salt (pinch)", 
        "Black Pepper (pinch)", 
        "Garlic Powder (tsp)"
    };
    
    float quantities[] = {2, 0.5, 1, 7, 0.5, 1, 1, 1, 0.25}; // Base quantities for 2 servings

    for (int i = 0; i < 9; i++) {
        quantities[i] *= servings;
    }

    for (int i = 0; i < 9; i++) {
        printf("%.2f %s\n", quantities[i], ingredients[i]);
    }

    // Instructions
    printf("\nInstructions:\n");
    printf("1. Heat vegan butter or olive oil in a large skillet over medium heat.\n");
    printf("2. Add the sliced mushrooms, thyme, and red pepper flakes (optional). Cook, stirring occasionally, until softened and lightly browned — about 5-7 minutes.\n");
    printf("3. Meanwhile, toast bread in the oven or a toaster.\n");
    printf("4. Once the mushrooms are lightly browned, stir in the salt, pepper, and garlic powder.\n");
    printf("5. Top the toasted bread with ripe avocado, then top with sautéed mushroom mixture.\n");
    printf("6. Enjoy!\n\n");
}

// Function to display Vegan French Toast
void breakfast_recipe_2(int servings) {
    printf("\n\033[1mVegan French Toast (10 Minutes!)\033[0m\n");
    printf("This Vegan French Toast is crispy on the outside and soft on the inside, topped with your favorite vegan butter or syrup.\n");

    // Ingredient list and quantities
    char *ingredients[] = {
        "Cornstarch (Tbsp)", 
        "Almond Milk (cup)", 
        "Maple Syrup (tsp)", 
        "Vanilla Extract (tsp)", 
        "Black Salt (tsp)", 
        "Ground Cinnamon (tsp)", 
        "Mashed Ripe Banana (Tbsp)", 
        "Sturdy Day-Old Bread (pieces)", 
        "Vegan Butter (tsp)"
    };

    float quantities[] = {3, 0.5, 2, 1, 0.125, 0.5, 1, 2, 2}; // Quantities for 1 serving

    for (int i = 0; i < 9; i++) {
        quantities[i] *= servings;
    }

    for (int i = 0; i < 9; i++) {
        printf("%.2f %s\n", quantities[i], ingredients[i]);
    }

    // Instructions
    printf("\nInstructions:\n");
    printf("1. Batter: Whisk cornstarch and almond milk until smooth.\n");
    printf("2. Add maple syrup, vanilla extract, black salt, ground cinnamon, mashed banana (optional), and turmeric (optional).\n");
    printf("3. Dip & Cook: Soak bread slices in the batter for 15-20 seconds per side.\n");
    printf("4. Cook in vegan butter over medium heat for approximately 2 minutes per side, until golden.\n");
    printf("5. Serve: Enjoy with vegan butter/nut butter, fresh fruit, and maple syrup.\n");
    printf("Optional: Dust with powdered sugar or top with coconut whipped cream.\n");
    printf("6. Storage: Best enjoyed fresh. The batter can be made 2 days ahead.\n\n");
}

void lunch_recipe_1(int servings) {
    printf("\n\033[1mSun-Dried Tomato Pesto Pasta (Vegan + GF)\033[0m\n");
    printf("A simple and flavorful pasta dish with a rich sun-dried tomato pesto sauce.\n\n");

    // Ingredients for 2 servings, scale based on the input
    char *ingredients[] = {
        "Gluten-Free Pasta (oz)",
        "Sun-Dried Tomatoes (oz)",
        "Extra Virgin Olive Oil (Tbsp)",
        "Fresh Basil (cup)",
        "Garlic Cloves (cloves)",
        "Vegan Parmesan Cheese (Tbsp)"
    };

    float quantities[] = {10, 3, 4, 1, 2, 2};  // Base quantities for 2 servings

    // Scale the ingredients according to the number of servings
    for (int i = 0; i < 6; i++) {
        quantities[i] *= servings / 2.0;  // Scaling factor for servings
    }

    printf("For %d servings, you will need:\n", servings);
    for (int i = 0; i < 6; i++) {
        printf("%.2f %s\n", quantities[i], ingredients[i]);
    }

    // Instructions
    printf("\n\033[1mInstructions:\033[0m\n");
    printf("1. Boil and Salt Pasta: Cook gluten-free pasta in salted water according to package directions, ensuring al dente texture.\n");
    printf("2. Blend Pesto Ingredients: Combine sun-dried tomatoes, olive oil, basil, garlic, and vegan parmesan in a blender or food processor. Add pasta water for smoother consistency.\n");
    printf("3. Adjust Pesto Flavor: Taste pesto and add more garlic, basil, or parmesan as needed for desired flavor profile.\n");
    printf("4. Combine Pasta and Pesto: Toss drained pasta with pesto, adding extra olive oil and vegan parmesan.\n");
    printf("5. Serve Warm with Garnish: Serve immediately, garnishing with fresh basil and additional vegan parmesan.\n");
    printf("6. Store Leftovers: Refrigerate leftovers, and enjoy hot, chilled, or at room temperature.\n");

    printf("\nEnjoy your meal!\n");
}

void lunch_recipe_2(int servings) {
    printf("\n\033[1mThe Ultimate Salmon Burger (30 Minutes!)\033[0m\n");
    printf("A savory and flavorful salmon patty served with a quick sweet chili sauce.\n\n");

    // Ingredients for 4 servings (adjusted dynamically)
    char *ingredients[] = {
        "Boneless, Skinless Salmon (lb)",
        "Green Onion (stalks)",
        "Fresh Basil (cup)",
        "Panko Breadcrumbs (cup)",
        "Lemon Juice (Tbsp)",
        "Mayonnaise (Tbsp)",
        "Dijon Mustard (tsp)",
        "Sea Salt (tsp)"
    };

    // Base quantities (for 4 servings)
    float base_quantities[] = {1, 2, 0.33, 0.33, 2, 1.5, 2, 0.5};


    float quantities[8]; // Adjusted ingredient quantities

    for (int i = 0; i < 8; i++) {
        quantities[i] = base_quantities[i] * servings;
    }

    printf("For %d servings, you will need:\n", servings);
    for (int i = 0; i < 8; i++) {
        printf("%.2f %s\n", quantities[i], ingredients[i]);
    }

    // Instructions
    printf("\n\033[1mInstructions:\033[0m\n");
    printf("1. Blend Salmon Base: Process %.2f cup of salmon into a smooth paste in a food processor.\n", quantities[0] / 3);
    printf("2. Combine Patty Ingredients: Add remaining salmon, green onions, basil, breadcrumbs, lemon juice, mayo, mustard, and salt.\n");
    printf("3. Form Patties: Divide mixture into %d patties. Add breadcrumbs if too wet. Chill if needed.\n", servings);
    printf("4. Cook Patties: Heat oil in skillet, cook patties for 3-4 minutes per side.\n");
    printf("5. Make Chili Sauce: Mix honey, red pepper flakes, and rice vinegar.\n");
    printf("6. Assemble Burgers: Layer salmon patty with sauce, slaw (optional), and avocado on toasted buns.\n");
    printf("7. Store Leftovers: Refrigerate cooked patties for 1-2 days or freeze for 1 month.\n");

    printf("\nEnjoy your meal!\n");
}

void dinner_recipe_1(int servings) {
    printf("\n\033[1mShakshuka with Eggs\033[0m\n");
    printf("A savory tomato-based dish with eggs, perfect for breakfast or dinner.\n\n");

    // Ingredients for 4 servings, scale based on the input servings
    char *ingredients[] = {
        "Olive Oil (Tbsp)",
        "White or Yellow Onion (cup)",
        "Garlic Cloves (cloves)",
        "Red Bell Pepper (large)",
        "Sea Salt (tsp)",
        "Tomato Paste (Tbsp)",
        "Ground Cumin (tsp)",
        "Sweet Paprika (tsp)",
        "Red Pepper Flakes (tsp)",
        "Fresh Tomatoes (cup)",
        "Large Eggs (eggs)"
    };

    float quantities[] = {1, 1/2, 3, 1, 0.5, 1, 1, 1, 0.25, 4, 4};  // Base quantities for 4 servings

    // Scale the ingredients according to the number of servings
    for (int i = 0; i < 11; i++) {
        quantities[i] *= servings;  // Scaling factor for servings
    }

    printf("For %d servings, you will need:\n", servings);
    for (int i = 0; i < 11; i++) {
        printf("%.2f %s\n", quantities[i], ingredients[i]);
    }

    // Instructions
    printf("\n\033[1mInstructions:\033[0m\n");
    printf("1. Sauté Onions: Heat oil in a skillet, add onions, and sauté until translucent (2 minutes).\n");
    printf("2. Add Vegetables: Add garlic, red bell pepper, and salt; sauté until softened and fragrant (4-5 minutes).\n");
    printf("3. Spice the Sauce: Add tomato paste, cumin, paprika, and red pepper flakes; cook for 1 minute.\n");
    printf("4. Simmer Tomatoes: Add tomatoes, stir, simmer covered for 20-25 minutes until vegetables soften and sauce thickens.\n");
    printf("5. Adjust Flavors: Taste and add more cumin, red pepper flakes, or salt as needed.\n");
    printf("6. Add Eggs: Make wells in the sauce, crack eggs into them, and sprinkle with salt.\n");
    printf("7. Cook Eggs: Cover and cook for 4-8 minutes, depending on desired egg doneness.\n");
    printf("8. Garnish and Serve: Turn off heat, sprinkle with basil/parsley and black pepper (optional), and serve with bread, grilled cheese, or potatoes.\n");
    printf("9. Storage: Sauce alone: refrigerate 3-4 days, freeze 1 month. Avoid refrigerating/freezing with eggs.\n");

    printf("\nEnjoy your meal!\n");
}

void dinner_recipe_2(int servings) {
    printf("\n\033[1mChicken Noodle Soup\033[0m\n");
    printf("A comforting and hearty soup with tender chicken, vegetables, and noodles.\n\n");

    // Ingredients for 4 servings, scale based on the input servings
    char *ingredients[] = {
        "Pasta of Choice (oz)",
        "Salt (Tbsp)",
        "Olive Oil (Tbsp)",
        "Yellow or White Onion (large)",
        "Celery Stalks",
        "Medium Carrots",
        "Garlic Cloves",
        "Freshly Minced Ginger (Tbsp)",
        "Dried Thyme (tsp)",
        "Ground Turmeric (tsp)",
        "Sea Salt (tsp)",
        "Black Pepper (tsp)",
        "Chicken Broth or Stock (cups)",
        "Boneless, Skinless Chicken Thighs or Breasts (lb)"
    };

    float quantities[] = {8, 1, 1, 1, 3, 3, 4, 1.5, 1, 0.5, 0.25, 0.25, 8, 1};  // Base quantities for 4 servings

    // Scale the ingredients according to the number of servings
    for (int i = 0; i < 14; i++) {
        quantities[i] *= servings;  // Scaling factor for servings
    }

    printf("For %d servings, you will need:\n", servings);
    for (int i = 0; i < 14; i++) {
        printf("%.2f %s\n", quantities[i], ingredients[i]);
    }

    // Instructions
    printf("\n\033[1mInstructions:\033[0m\n");
    printf("1. Cook Pasta: Boil pasta in salted water until al dente, drain, and optionally toss with olive oil.\n");
    printf("2. Prep Vegetables: Chop vegetables, or cook them separately while pasta boils to save time.\n");
    printf("3. Sauté Vegetables: Sauté onion, celery, carrots, garlic, and ginger in olive oil until softened (5-7 minutes).\n");
    printf("4. Add Spices: Stir in thyme, turmeric, salt, and pepper; cook for 1 minute.\n");
    printf("5. Simmer Soup Base: Add chicken broth and raw chicken, simmer covered for 5-8 minutes until chicken is cooked.\n");
    printf("6. Shred Chicken: Remove cooked chicken, shred or dice, and return to soup (add pre-cooked chicken now). Cook for 1-2 more minutes.\n");
    printf("7. Season to Taste: Add more salt and pepper as needed.\n");
    printf("8. Serve: Divide pasta into bowls, ladle soup over, and garnish with parsley (optional).\n");
    printf("9. Store Leftovers: Refrigerate soup and pasta separately for 3-4 days, or freeze soup for 1 month. Reheat soup in a saucepan.\n");

    printf("\nEnjoy your meal!\n");
}

void dessert_recipe_1(int servings) {
    printf("\n\033[1mChocolate Sandwich Cookies\033[0m\n");
    printf("Rich and chocolatey cookies with a creamy filling.\n\n");

    // Ingredients for 12 servings (adjusted dynamically)
    char *ingredients[] = {
        "Softened Refined Coconut Oil (cup)",
        "Cane Sugar (cup)",
        "Cassava Flour (cup)",
        "Cocoa Powder (cup)",
        "Baking Powder (tsp)",
        "Sea Salt (tsp)",
        "Water (Tbsp)",
        "Powdered Sugar (cup)"
    };

    // Base quantities (for 12 servings)
    float base_quantities[] = {0.5, 0.67, 0.75, 0.67, 0.5, 0.25, 5, 1};


    float quantities[8];

    for (int i = 0; i < 8; i++) {
        quantities[i] = base_quantities[i] * servings;
    }

    printf("For %d servings, you will need:\n", servings);
    for (int i = 0; i < 8; i++) {
        printf("%.2f %s\n", quantities[i], ingredients[i]);
    }

    // Instructions
    printf("\n\033[1mInstructions:\033[0m\n");
    printf("1. Preheat & Prep: Preheat oven to 350°F (176°C) and line baking sheets with parchment paper.\n");
    printf("2. Cream Coconut Oil & Sugar: Beat %.2f cup coconut oil and %.2f cup cane sugar until light and fluffy (1-2 minutes).\n", 
            quantities[0], quantities[1]);
    printf("3. Combine Dry Ingredients: Mix in %.2f cup cassava flour, %.2f cup cocoa powder, %.2f tsp baking powder, and %.2f tsp salt until crumbly.\n", 
            quantities[2], quantities[3], quantities[4], quantities[5]);
    printf("4. Add Water & Form Dough: Add %.2f Tbsp water and mix until dough holds together. Adjust with more water or flour as needed.\n", 
            quantities[6]);
    printf("5. Roll & Cut Cookies: Roll dough to 1/8-inch thickness between parchment paper, cut with a 2-inch cutter.\n");
    printf("6. Bake Cookies: Place cookies 1 inch apart on sheets and bake 10-13 minutes until set.\n");
    printf("7. Cool Cookies: Cool on tray for 5 minutes, then transfer to a wire rack to fully cool.\n");
    printf("8. Prepare Filling: Beat %.2f cup coconut oil and %.2f cup powdered sugar until thick frosting forms.\n", 
            quantities[0], quantities[7]);
    printf("9. Assemble Cookies: Spread filling on one cookie and sandwich with another.\n");
    printf("10. Store Cookies: Store in an airtight container at room temperature for 4-5 days or freeze.\n");

    printf("\nEnjoy your cookies!\n");
}

void dessert_recipe_2(int servings) {
    printf("\n\033[1mThe BEST Chocolate Cake Mix Cookies\033[0m\n");
    printf("Soft, chocolatey cookies with a tart raspberry twist.\n\n");

    // Ingredients for 12 servings (adjusted dynamically)
    char *ingredients[] = {
        "Melted Vegan Butter (cup)",
        "Dairy-Free Milk (cup)",
        "Vanilla Extract (tsp)",
        "Vegan + Gluten-Free Chocolate Cake Mix (oz)",
        "Frozen Raspberries (cup)",
        "Dairy-Free Semi-Sweet Chocolate Chips (cup)",
        "Sea Salt (pinch)"
    };

    // Base quantities (for 12 servings)
    float base_quantities[] = {0.33, 0.25, 2, 15.5, 0.75, 0.75, 1};


    float quantities[7];

    for (int i = 0; i < 7; i++) {
        quantities[i] = base_quantities[i] * servings;
    }

    printf("For %d servings, you will need:\n", servings);
    for (int i = 0; i < 7; i++) {
        printf("%.2f %s\n", quantities[i], ingredients[i]);
    }

    // Instructions
    printf("\n\033[1mInstructions:\033[0m\n");
    printf("1. Preheat & Prep: Preheat oven to 350°F (176°C) and line baking sheets with parchment paper.\n");
    printf("2. Combine Wet Ingredients: Whisk %.2f cup melted vegan butter, %.2f cup dairy-free milk, and %.2f tsp vanilla extract in a bowl.\n", 
            quantities[0], quantities[1], quantities[2]);
    printf("3. Add Cake Mix: Stir in %.2f oz chocolate cake mix.\n", quantities[3]);
    printf("4. Fold in Add-ins: Gently fold in %.2f cup frozen raspberries and %.2f cup dairy-free chocolate chips.\n", 
            quantities[4], quantities[5]);
    printf("5. Scoop Cookies: Scoop 1 ½ Tbsp-sized mounds onto baking sheets, spacing 2 inches apart.\n");
    printf("6. Bake Cookies: Bake for 16-18 minutes until doubled and edges are dry.\n");
    printf("7. Cool Cookies: Cool on baking sheet for 5 minutes, then transfer to a wire rack.\n");
    printf("8. Optional Garnish: Sprinkle with sea salt.\n");
    printf("9. Serve: Enjoy warm or cooled.\n");
    printf("10. Store Cookies: Store in an airtight container at room temperature for 3-4 days.\n");
    printf("11. Freeze Dough: Scoop cookies, freeze on baking sheet, then transfer to an airtight container.\n");
    printf("    Bake frozen cookies for 1-2 minutes longer.\n");

    printf("\nEnjoy your delicious cookies!\n");
}
