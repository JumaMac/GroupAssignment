#include <stdio.h>  // For printing output and reading input.
#include <stdlib.h> // For memory management and other general functions.
#include <ctype.h>  // For checking and modifying characters (like letters and numbers).
#include <string.h> // For working with strings (copy, compare, length, etc.).
#include "recipe.h"
#include "database.h"
#include "display.h"
#include "raylib.h"
#include "functions.h" // Include functions.h

// Game State enum
typedef enum {
    GAME_STATE_HOME,
    GAME_STATE_PLAYING,
    GAME_STATE_GAME_OVER
} GameState;


void rungame() {
    //variable declaration
    const int screenWidth = 1000;
    const int screenHeight = 600;
    GameState gameState = GAME_STATE_HOME;
    bool soundOn = true;
    int score = 0;
    int lives = 5;

    // initialize the window and audio device
    InitWindow(screenWidth, screenHeight, "Meow-nster: Eats it all!");
    InitAudioDevice();

    // load images to be used
    Texture2D background = LoadTexture("assets/homepage/sky.png");
    Texture2D logo = LoadTexture("assets/homepage/meownsterlogo.png");
    Texture2D startButton = LoadTexture("assets/homepage/start-button.png");
    Texture2D soundButton = LoadTexture("assets/homepage/sound-on-button.png");
    Texture2D popcat = LoadTexture("assets/popcat_spritesheet.png");
    Music music = LoadMusicStream("assets/music.mp3");
    Texture2D heart = LoadTexture("assets/heart.png");
    Texture2D restartButton = LoadTexture("assets/homepage/restart-button.png");

    // load array of food images
    Texture2D foodTextures[11];
    foodTextures[0] = LoadTexture("assets/food/cake_strawberry.png");
    foodTextures[1] = LoadTexture("assets/food/fruit_banana.png");
    foodTextures[2] = LoadTexture("assets/food/fruit_apple.png");
    foodTextures[3] = LoadTexture("assets/food/fruit_watermelon_slice.png");
    foodTextures[4] = LoadTexture("assets/food/eggs_fried.png");
    foodTextures[5] = LoadTexture("assets/food/soda_pepsi.png");
    foodTextures[6] = LoadTexture("assets/food/vegetable_carrot.png");
    foodTextures[7] = LoadTexture("assets/food/vegetable_corn.png");
    foodTextures[8] = LoadTexture("assets/food/fruit_strawberry.png");
    foodTextures[9] = LoadTexture("assets/food/coffee_tea.png");
    foodTextures[10] = LoadTexture("assets/food/icecream.png");

    // initialize the food
    Food food = {GetRandomValue(50, 950), -50, true, 0};
    float fallSpeed = 0.15f;
    float foodScaleFactor = 3.0f;

    // so that hover of buttons is not blocky
    SetTextureFilter(startButton, TEXTURE_FILTER_BILINEAR);
    SetTextureFilter(soundButton, TEXTURE_FILTER_BILINEAR);
    SetTextureFilter(restartButton, TEXTURE_FILTER_BILINEAR);

    //play music on start
    PlayMusicStream(music);

    // variables for button scaling
    float scaleStart = 1.0f;
    float scaleSound = 1.0f;
    float restartButtonScale = 0.8f;
    Rectangle startButtonRect = {300, 245, startButton.width, startButton.height};
    Rectangle soundButtonRect = {930, 20, soundButton.width, soundButton.height};
    Rectangle restartButtonRect = {screenWidth / 2 - restartButton.width / 2 * restartButtonScale, screenHeight / 2 + 75, restartButton.width * restartButtonScale, restartButton.height * restartButtonScale};

    // variables for spritesheet animation
    int totalFrames = 6;
    int frameWidth = popcat.width / totalFrames;
    int frameHeight = popcat.height;
    int currentFrame = 0, frameCounter = 0, frameSpeed = 250;
    float spritePosX = 30.0f, spritePosY = 460.0f, scaleFactor = 0.3f;

    while (!WindowShouldClose()) {
        // updating stuff
        UpdateAnimation(&currentFrame, &frameCounter, frameSpeed, totalFrames);
        UpdateMusicStream(music);

        // this function handles hover of start and sound button
        scaleWhenHover(startButtonRect, soundButtonRect, &scaleStart, &scaleSound);
        scaleGameOverButton(restartButtonRect, &restartButtonScale);

        // if Start button is pressed
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(GetMousePosition(), startButtonRect)) {
                gameState = GAME_STATE_PLAYING;
                score = 0;
                lives = 5;
                food.y = -50;
                food.x = GetRandomValue(50, GetScreenWidth() - 50);
                fallSpeed = 0.15f;
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(background, 0, 0, WHITE);

            // draw sound button with scaling effect
            Vector2 soundButtonPosition = {soundButtonRect.x + soundButtonRect.width / 2 - soundButton.width * scaleSound / 2,
                                           soundButtonRect.y + soundButtonRect.height / 2 - soundButton.height * scaleSound / 2};
            DrawTextureEx(soundButton, soundButtonPosition, 0.0f, scaleSound, WHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(GetMousePosition(), soundButtonRect)) {
                // Toggle the sound on and off
                soundOn = !soundOn;

                if (soundOn) {
                    // Load the sound-on button texture
                    soundButton = LoadTexture("assets/homepage/sound-on-button.png");
                    PlayMusicStream(music);
                } else {
                    // Load the sound-off button texture
                    soundButton = LoadTexture("assets/homepage/sound-off-button.png");
                    StopMusicStream(music);
                }
            }
        }

        if (gameState == GAME_STATE_HOME) {
            //this is the homepage
            DrawTexture(logo, 100, 20, WHITE);
            DrawHomePageFood(foodTextures, 11, 3.0f, 130.0f, 195.0f, 22.0f);
            DrawSprite(popcat, frameWidth, frameHeight, currentFrame, spritePosX, spritePosY, scaleFactor);
            Vector2 startButtonPosition = {startButtonRect.x + startButtonRect.width / 2 - startButton.width * scaleStart / 2,
                                           startButtonRect.y + startButtonRect.height / 2 - startButton.height * scaleStart / 2};
            DrawTextureEx(startButton, startButtonPosition, 0.0f, scaleStart, WHITE);
            DrawTextureEx(soundButton, soundButtonPosition, 0.0f, scaleSound, WHITE);
        } else if (gameState == GAME_STATE_PLAYING) {
            // gameplay happens here
            UpdateMovement(&spritePosX, frameWidth, scaleFactor);
            UpdateFood(&food, &fallSpeed, GetScreenHeight(), &lives, score);

            int foodWidth = foodTextures[food.textureIndex].width * foodScaleFactor;
            int foodHeight = foodTextures[food.textureIndex].height * foodScaleFactor;

            DrawFood(foodTextures, food, foodScaleFactor);
            DrawText(TextFormat("Score: %d", score), 20, 20, 30, WHITE);
            DrawLives(lives, screenWidth, screenHeight, heart);

            if (CheckCollision(spritePosX, spritePosY, frameWidth * scaleFactor, frameHeight * scaleFactor, food, foodWidth, foodHeight)) {
                score++;
                food.y = -50;
                food.x = GetRandomValue(50, GetScreenWidth() - 50);
                food.textureIndex = GetRandomValue(0, 10);
            }
            if (lives <= 0) {
                gameState = GAME_STATE_GAME_OVER;
            }
            DrawSprite(popcat, frameWidth, frameHeight, currentFrame, spritePosX, spritePosY, scaleFactor);
        } else if (gameState == GAME_STATE_GAME_OVER) {
            DrawGameOverScreen(screenWidth, screenHeight, score, restartButton, &restartButtonScale);
             if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (CheckCollisionPointRec(GetMousePosition(), restartButtonRect)) {
                    gameState = GAME_STATE_HOME;
                    lives = 5;
                    score = 0;
                    food.y = -50;
                    food.x = GetRandomValue(50, GetScreenWidth() - 50);
                    fallSpeed = 0.15f;
                }
            }
        }
        EndDrawing();
    }

    // Unload all textures before closing
    UnloadAllTextures(background, logo, startButton, soundButton, heart);
    UnloadTexture(popcat);
    UnloadTexture(restartButton);
    for (int i = 0; i < 10; i++) {
        UnloadTexture(foodTextures[i]);
    }
    CloseAudioDevice();
    StopMusicStream(music);
    CloseWindow();
}

int main()
{
    int choice;
    int cat_choice;
    struct Recipe recipes[RECIPES_SIZE];
    // call the initRecipes from database.h to load all recipes
    int recipeCount = initRecipes(recipes);
    loadRecipesFromFile(recipes, &recipeCount);

    // ⭐️ code by Jaismin
    while (1)
    { // Program loop to allow navigation back

        // Home page
        system("clear");
        printf("████████╗██╗  ██╗███████╗    ██████╗ ███████╗ ██████╗██╗██████╗ ███████╗    ██████╗  ██████╗ ██╗  ██╗\n");
        printf("╚══██╔══╝██║  ██║██╔════╝    ██╔══██╗██╔════╝██╔════╝██║██╔══██╗██╔════╝    ██╔══██╗██╔═══██╗╚██╗██╔╝\n");
        printf("   ██║   ███████║█████╗      ██████╔╝█████╗  ██║     ██║██████╔╝█████╗      ██████╔╝██║   ██║ ╚███╔╝ \n");
        printf("   ██║   ██╔══██║██╔══╝      ██╔══██╗██╔══╝  ██║     ██║██╔═══╝ ██╔══╝      ██╔══██╗██║   ██║ ██╔██╗ \n");
        printf("   ██║   ██║  ██║███████╗    ██║  ██║███████╗╚██████╗██║██║     ███████╗    ██████╔╝╚██████╔╝██╔╝ ██╗\n");
        printf("   ╚═╝   ╚═╝  ╚═╝╚══════╝    ╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝╚═╝     ╚══════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝\n");

        printf("=====================================================================================================\n");
        printf("              ░█▀▀░█▀█░█▀█░█░█░░░░░░█▀▀░█▀▄░█▀▀░█▀█░▀█▀░█▀▀░░░░░░█▀▀░█▀█░▀▀█░█▀█░█░█░░░              \n");
        printf("              ░█░░░█░█░█░█░█▀▄░░░░░░█░░░█▀▄░█▀▀░█▀█░░█░░█▀▀░░░░░░█▀▀░█░█░░░█░█░█░░█░░░░              \n");
        printf("              ░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀░░░░▀▀▀░▀░▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀░░░░▀▀▀░▀░▀░▀▀░░▀▀▀░░▀░░▀░              \n");
        printf("=====================================================================================================\n");

        printf("[1] All Recipes\n");
        printf("[2] Your Recipes\n");
        printf("[3] Game Section\n");
        printf("[0] Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        while (getchar() != '\n'); 

        switch (choice)
        {

            case 1: // All Recipes
            while (1) {  // Loop to stay in the category selection menu
                printf("\nSelect a Recipe Category:\n");
                printf("[1] Breakfast & Brunch\n");
                printf("[2] Lunch Specials\n");
                printf("[3] Dinner Delights\n");
                printf("[4] Desserts & Sweets\n");
                printf("[5] Vegetarian & Vegan\n");
                printf("[0] Go Back\n");
                printf("Enter your choice: ");

                scanf("%d", &cat_choice);
                while (getchar() != '\n');  

                if (cat_choice == 0) break; // Go back to home page

                switch (cat_choice) {
                    case 1:
                        printf("\n\033[1mBreakfast & Brunch:\033[0m\n");
                        printf("[1] 10-Minute Mushroom Avocado Toast\n");
                        printf("[2] Easy Vegan French Toast (10 Minutes!)\n");
                        printf("[0] Go back\n\n");

                            int recipe_choice, servings;

                        printf("Enter your choice: ");
                        scanf("%d", &recipe_choice);
                        while (getchar() != '\n');

                        if (recipe_choice == 0) {
                            break; // Goes back to category selection
                        }

                        switch (recipe_choice) {
                                case 1: // "10-Minute Mushroom Avocado Toast
                                        printf("\n\033[1m10-Minute Mushroom Avocado Toast\033[0m\n");
                                        printf("The ultimate plant-based breakfast: avocado toast with savory sautéed mushrooms.\n"
                                                "SO satisfying, perfectly toasty, and ready in just 10 minutes with 1 pan and 7 ingredients!\n\n");
                                        printf("How many servings do you want to make?: ");
                                        
                                        scanf("%d", &servings);
                                        while (getchar() != '\n');
// ⭐️ code by mikey 
                                        //ingredient list 
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

                                        
                                        printf("\nFor %d servings, you will need:\n", servings);
                                        for (int i = 0; i < 9; i++) {
                                                printf("%.2f %s\n", quantities[i], ingredients[i]);
                                        }
// ⭐️ end of code by mikey
// ⭐️ code by jaismin
                                        printf("\n\033[1mInstructions:\033[0m\n"
                                                "1. Heat vegan butter or olive oil in a large skillet over medium heat.\n"
                                                "2. Add the sliced mushrooms, thyme, and red pepper flakes (optional). Cook, stirring occasionally, until softened and lightly browned — about 5-7 minutes. If the mushrooms are sticking to the pan, reduce the heat slightly or add more butter or oil.\n"
                                                "3. Meanwhile, toast bread in the oven or a toaster.\n"
                                                "4. Once the mushrooms are lightly browned, turn off the heat and stir in the salt, pepper, and garlic powder. Taste and adjust as needed, adding more salt to taste or black pepper for spice.\n"
                                                "5. Top the toasted bread with ripe avocado and use a fork to smash. Then top with sautéed mushroom mixture and vegan parmesan cheese (optional).\n"
                                                "6. Eat, repeat, enjoy!\n\n"
                                                "Best when fresh. Not freezer friendly.\n\n");


                                        printf("\n[0] Return to Category Menu\n\n");
                                        printf("Enter your choice: ");
                                        scanf("%d", &recipe_choice);
                                        while (getchar() != '\n');
                                        if (recipe_choice == 0) {
                                                break; // Go back
                                        }
                                    break;

                                
                                default:
                                        printf("Invalid choice. Returning to menu.\n");
                                break;
                            }

                        break;
                    case 2:
                        printf("\n\033[1mLunch Specials:\033[0m\n");
                        printf("[1] Sun-Dried Tomato Pesto Pasta (Vegan + GF)\n");
                        printf("[2] The Ultimate Salmon Burger (30 Minutes!)\n\n");
                        break;
                    case 3:
                        printf("\n\033[1mDinner Delights:\033[0m\n");
                        printf("[1] Honey Garlic Salmon Bites\n");
                        printf("[2] Chicken Noodle Soup (Classic or Immune-Boosting!)\n\n");
                        break;
                    case 4:
                        printf("\n\033[1mDesserts & Sweets:\033[0m\n");
                        printf("[1] Homemade Gluten-Free Oreos (Vegan)\n");
                        printf("[2] The BEST Chocolate Cake Mix Cookies\n\n");
                        break;
                    case 5:
                        printf("\n\033[1mVegetarian & Vegan:\033[0m\n");
                        printf("[1] 10-Minute Mushroom Avocado Toast\n");
                        printf("[2] Easy Vegan French Toast (10 Minutes!)\n");
                        printf("[3] Sun-Dried Tomato Pesto Pasta (Vegan + GF)\n");
                        printf("[4] Homemade Gluten-Free Oreos (Vegan)\n");
                        printf("[5] The BEST Chocolate Cake Mix Cookies\n\n");
                        break;
                    default:
                        printf("Invalid input. Try again.\n");
                        break;
                }
            }
            break;

        case 2: // Your Recipes

            // ⭐️ code by Justin
            while (1)
            {
                char firstChar;
                printf("\n[1] Add Recipe\n");
                printf("[2] View Recipes\n");
                printf("[3] Edit Recipes\n");
                printf("[4] Delete Recipes\n");
                printf("[5] Search Recipes\n");
                printf("[6] Adjust a Recipe\n");
                printf("[0] Go Back\n");
                printf("Enter your choice: ");
                // if enter is pressed in the menu it takes the user back to the main menu
                if (scanf("%c", &firstChar) == 1 && firstChar == '\n') {
                    printf("Returning to main menu...\n");
                    break;
                }
                ungetc(firstChar, stdin);

                if (scanf("%d", &choice) != 1)
                {
                    while (getchar() != '\n'); //clear buffer input of new line
                    printf("Invalid input. Try again.\n");
                    continue;
                }
                if (choice == 1)
                {
                    while (getchar() != '\n'); 
                    addRecipes(recipes, &recipeCount);
                } 
                else if (choice == 2) 
                {
                    while (getchar() != '\n'); 
                    viewRecipes(recipes, &recipeCount);
                } 
                else if (choice == 3) 
                {
                    while (getchar() != '\n'); 
                    editRecipes(recipes, &recipeCount);
                } 
                else if (choice == 4) 
                {
                    while (getchar() != '\n'); 
                    deleteRecipes(recipes, &recipeCount);
                }
                else if (choice == 5) 
                {
                    while (getchar() != '\n'); 
                    searchRecipe(recipes, recipeCount);
                } 
                //⭐️ Added by Mikey
                else if (choice == 6) 
                {
                    while (getchar() != '\n'); 
                    adjustIngredients(recipes, &recipeCount);
                }
                //⭐️
                else if (choice == 0)
                {
                    break;
                }
                else
                {
                    printf("Invalid input. Try again.\n");
                }
            }
            // ⭐️ end of code by Justin
            break;
            // ⭐️ code by jaismin
        case 3: // Game Section
        {
            rungame();
        }
        break;

        case 0: // Exit program
            return 0;
            break;

        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}
// ⭐️ end of code by Jaismin
