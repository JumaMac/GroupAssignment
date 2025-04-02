#include <stdio.h>  // For printing output and reading input.
#include <stdlib.h> // For memory management and other general functions.
#include <ctype.h>  // For checking and modifying characters (like letters and numbers).
#include <string.h> // For working with strings (copy, compare, length, etc.).
#include "recipe.h"
#include "database.h"
#include "display.h"
#include "raylib.h"
#include "functions.h" 
#include "allRecipes.h" 

// Game State enum
typedef enum {
    GAME_STATE_HOME,
    GAME_STATE_PLAYING,
    GAME_STATE_GAME_OVER
} GameState;

void rungame();

int main()
{
    int choice;
    int cat_choice;
    int recipe_choice, servings;
    struct Recipe recipes[RECIPES_SIZE];
    // call the initRecipes from database.h to load all recipes
    int recipeCount = initRecipes(recipes);
    loadRecipesFromFile(recipes, &recipeCount);
    int ingNum;

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

                if (cat_choice == 0) break; // Go back to home page

        switch (cat_choice) {
            case 1:
                display_breakfast_recipes();
                printf("Enter your choice: ");
                scanf("%d", &recipe_choice);
                if  (recipe_choice == 1) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    breakfast_recipe_1(servings);
                } else if (recipe_choice == 2) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    breakfast_recipe_2(servings);
                } else if (recipe_choice == 0) {
                    printf("Going back to Category Menu...\n");
                } else {
                    printf("Invalid Choice. Going back to Category Menu...\n");
                }
                break;

            case 2:
                display_lunch_recipes();
                printf("Enter your choice: ");
                scanf("%d", &recipe_choice);
                if  (recipe_choice == 1) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    lunch_recipe_1(servings);
                } else if (recipe_choice == 2) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    lunch_recipe_2(servings);
                } else if (recipe_choice == 0) {
                    printf("Going back to Category Menu...\n");
                } else {
                    printf("Invalid Choice. Going back to Category Menu...\n");
                }
                break;

            case 3:
                display_dinner_recipes();
                printf("Enter your choice: ");
                scanf("%d", &recipe_choice);
                if  (recipe_choice == 1) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    dinner_recipe_1(servings);
                } else if (recipe_choice == 2) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    dinner_recipe_2(servings);
                } else if (recipe_choice == 0) {
                    printf("Going back to Category Menu...\n");
                } else {
                    printf("Invalid Choice. Going back to Category Menu...\n");
                }
                break;

            case 4:
                display_dessert_recipes();
                printf("Enter your choice: ");
                scanf("%d", &recipe_choice);
                if  (recipe_choice == 1) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    dessert_recipe_1(servings);
                } else if (recipe_choice == 2) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    dessert_recipe_2(servings);
                } else if (recipe_choice == 0) {
                    printf("Going back to Category Menu...\n");
                } else {
                    printf("Invalid Choice. Going back to Category Menu...\n");
                }
                break;

            case 5:
                display_veg_vegan_recipes();
                printf("Enter your choice: ");
                scanf("%d", &recipe_choice);
                if  (recipe_choice == 1) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    breakfast_recipe_1(servings);
                } else if (recipe_choice == 2) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    breakfast_recipe_2(servings);
                } else if (recipe_choice == 3) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    lunch_recipe_1(servings);
                } else if (recipe_choice == 4) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    dessert_recipe_1(servings);
                } else if (recipe_choice == 5) {
                    printf("How many servings do you want to make?: ");
                    scanf("%d", &servings);
                    dessert_recipe_2(servings);
                } else if (recipe_choice == 0) {
                    printf("Going back to Category Menu...\n");
                } else {
                    printf("Invalid Choice. Going back to Category Menu...\n");
                }
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

// ⭐️ end of code by Jaismin
