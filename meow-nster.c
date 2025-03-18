// ⭐️ code by JAISMIN

#include "raylib.h"
#include <stdio.h>
#include <stdlib.h> 

// structure for the falling food items
typedef struct {
    float x, y;
    bool active;
    int textureIndex;  // which image is being used for the food
} Food;

// Function declarations
void UnloadAllTextures(Texture2D background, Texture2D logo, Texture2D startButton, Texture2D soundButton);
void scaleWhenHover(Rectangle startButtonRect, Rectangle soundButtonRect, float *scaleStart, float *scaleSound);
void DrawSprite(Texture2D texture, int frameWidth, int frameHeight, int currentFrame, float spritePosX, float spritePosY, float scaleFactor);
void DrawFood(Texture2D textures[], Food food, float scaleFactor);
void DrawHomePageFood (Texture2D foodTextures[], int numTextures, float scaleFactor, float startX, float startY, float gapX);
void UpdateFood(Food *food, float *fallSpeed, int screenHeight, int score);
void UpdateMovement(float *spritePosX, int frameWidth, float scaleFactor);
void UpdateAnimation(int *currentFrame, int *frameCounter, int frameSpeed, int totalFrames);
bool CheckCollision(float spritePosX, float spritePosY, int spriteWidth, int spriteHeight, Food food, int foodWidth, int foodHeight);

//main function
int main() {
    //variable declaration
    const int screenWidth = 1000;
    const int screenHeight = 600;
    bool gameStarted = false;
    bool soundOn = true;
    int score = 0;  // Score variable

    // initialize the window and audio devie
    InitWindow(screenWidth, screenHeight, "Meow-nster: Eats it all!");
    InitAudioDevice();

    // load images to be used
    Texture2D background = LoadTexture("assets/homepage/sky.png");
    Texture2D logo = LoadTexture("assets/homepage/meownsterlogo.png");
    Texture2D startButton = LoadTexture("assets/homepage/start-button.png");
    Texture2D soundButton = LoadTexture("assets/homepage/sound-on-button.png");
    Texture2D popcat = LoadTexture("assets/popcat_spritesheet.png"); //this is a spritesheet
    Music music = LoadMusicStream("assets/music.mp3"); //source: "Cats" by The Living Tombstone (2023)

    // load array of food images
    Texture2D foodTextures[11]; // Array to store 11 textures
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
    float foodScaleFactor = 3.0f; //scaling images to desired size

    // so that hover of buttons is not blocky
    SetTextureFilter(startButton, TEXTURE_FILTER_BILINEAR);
    SetTextureFilter(soundButton, TEXTURE_FILTER_BILINEAR);

    //play music on start
    PlayMusicStream(music);

    // variables for button scaling
    float scaleStart = 1.0f; 
    float scaleSound = 1.0f; 
    Rectangle startButtonRect = {300, 245, startButton.width, startButton.height};
    Rectangle soundButtonRect = {930, 20, soundButton.width, soundButton.height};

    // variables for spritesheet animation
    int totalFrames = 6;  // number of frames in the sprite sheet
    int frameWidth = popcat.width / totalFrames; //setting width of frame, that is 1/6 width of the spritehseet
    int frameHeight = popcat.height;
    int currentFrame = 0, frameCounter = 0, frameSpeed = 250;  // frame rate
    float spritePosX = 30.0f, spritePosY = 460.0f, scaleFactor = 0.3f; //starting position of the cat and scaling the image

    while (!WindowShouldClose()) { // Game loop runs forever

        // updating stuff
        UpdateAnimation(&currentFrame, &frameCounter, frameSpeed, totalFrames);
        UpdateMusicStream(music);

        // this function handles hover of start and sound button
        scaleWhenHover(startButtonRect, soundButtonRect, &scaleStart, &scaleSound);

        // if Start button is pressed
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointRec(GetMousePosition(), startButtonRect)) {
                gameStarted = true;  // Start the game
            }
        }       


        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(background, 0, 0, WHITE);

            // draw sound button with scaling effect
            Vector2 soundButtonPosition = {soundButtonRect.x + soundButtonRect.width / 2 - soundButton.width * scaleSound / 2,
                                           soundButtonRect.y + soundButtonRect.height / 2 - soundButton.height * scaleSound / 2};
            DrawTextureEx(soundButton, soundButtonPosition, 0.0f, scaleSound, WHITE);          

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { //if mouse button is pressed we check if user pressed the sound button
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

            
    if (!gameStarted) {
    //this is the homepage
        
    // Draw the logo, start button, and sound button
    DrawTexture(logo, 100, 20, WHITE);
    DrawHomePageFood(foodTextures, 11, 3.0f, 130.0f, 195.0f, 22.0f);

            // draw start button with scaling effect
            Vector2 startButtonPosition = {startButtonRect.x + startButtonRect.width / 2 - startButton.width * scaleStart / 2, 
                                           startButtonRect.y + startButtonRect.height / 2 - startButton.height * scaleStart / 2};
            DrawTextureEx(startButton, startButtonPosition, 0.0f, scaleStart, WHITE);

            
    DrawTextureEx(startButton, startButtonPosition, 0.0f, scaleStart, WHITE);
    DrawTextureEx(soundButton, soundButtonPosition, 0.0f, scaleSound, WHITE);
    } else {
    
    // gameplay happens here
        UpdateMovement(&spritePosX, frameWidth, scaleFactor);

        UpdateFood(&food, &fallSpeed, GetScreenHeight(), score);

        int foodWidth = foodTextures[food.textureIndex].width * foodScaleFactor;
        int foodHeight = foodTextures[food.textureIndex].height * foodScaleFactor;

        DrawFood(foodTextures, food, foodScaleFactor);  // Drawing the selected food
        DrawText(TextFormat("Score: %d", score), 20, 20, 30, WHITE);
        
        // Check for collision bw cat and food item
        if (CheckCollision(spritePosX, spritePosY, frameWidth * scaleFactor, frameHeight * scaleFactor, food, foodWidth, foodHeight)) {
            score++;  // increment score
            food.y = -50;  // Reset food position
            food.x = GetRandomValue(50, GetScreenWidth() - 50);
            food.textureIndex = GetRandomValue(0, 10);  // Randomly choose a texture (0-10)
        } 
    }
        DrawSprite(popcat, frameWidth, frameHeight, currentFrame, spritePosX, spritePosY, scaleFactor);
        EndDrawing();
    }

    // Unload all textures before closing
    UnloadAllTextures(background, logo, startButton, soundButton);
    UnloadTexture(popcat);
    for (int i = 0; i < 10; i++) {
        UnloadTexture(foodTextures[i]);  // Unload all food textures
    }
    CloseAudioDevice();
    StopMusicStream(music);

    CloseWindow(); // Close the window
    return 0;
}

// Unload all textures before closing
void UnloadAllTextures(Texture2D background, Texture2D logo, Texture2D startButton, Texture2D soundButton) {
    UnloadTexture(background);
    UnloadTexture(logo);
    UnloadTexture(startButton);
    UnloadTexture(soundButton);
}

// handles scaling when these buttons are hovered
void scaleWhenHover(Rectangle startButtonRect, Rectangle soundButtonRect, float *scaleStart, float *scaleSound) {
    // check for mouse hover on start button
    if (CheckCollisionPointRec(GetMousePosition(), startButtonRect)) {
        *scaleStart = 1.1f; // scale up when hovering over start button
    } else {
        *scaleStart = 1.0f; // reset scale when not hovering
    }

    // check for mouse hover on sound button
    if (CheckCollisionPointRec(GetMousePosition(), soundButtonRect)) {
        *scaleSound = 1.1f; // scale up when hovering over sound button
    } else {
        *scaleSound = 1.0f; // reset scale when not hovering
    }
}

// function to draw the cat sprite
void DrawSprite(Texture2D texture, int frameWidth, int frameHeight, int currentFrame, float spritePosX, float spritePosY, float scaleFactor) {
    Rectangle sourceRec = { frameWidth * currentFrame, 0.0f, frameWidth, frameHeight };
    Rectangle destRec = { spritePosX, spritePosY, frameWidth * scaleFactor, frameHeight * scaleFactor };
    DrawTexturePro(texture, sourceRec, destRec, (Vector2){ 0.0f, 0.0f }, 0.0f, WHITE);
}

// function to update frame animation of the cat
void UpdateAnimation(int *currentFrame, int *frameCounter, int frameSpeed, int totalFrames) {
    (*frameCounter)++;  
    if (*frameCounter >= frameSpeed) {  
        *currentFrame = (*currentFrame + 1) % totalFrames;  
        *frameCounter = 0;  
    }
}

// function to draw the food
void DrawFood(Texture2D textures[], Food food, float scaleFactor) {
    if (food.active) {
        // Draw the food based on the textureIndex
        DrawTextureEx(textures[food.textureIndex], (Vector2){food.x, food.y}, 0.0f, scaleFactor, WHITE);
    }
}

// Function to update the falling food
void UpdateFood(Food *food, float *fallSpeed, int screenHeight, int score) {
    if (food->active) {
        food->y += *fallSpeed;  

        // If the food goes off-screen, reset it to the top and randomize its x position
        if (food->y > screenHeight) {  
            food->y = -50;  
            food->x = GetRandomValue(50, GetScreenWidth() - 50);  
            food->textureIndex = GetRandomValue(0, 10);  // Randomly choose a texture (0-10)
        }
    }

    // Increase fall speed every 10 points, 0.15 is base speed
    *fallSpeed = 0.15f + (score / 10) * 0.02f;
}

// Function for user controls and moving the character 
void UpdateMovement(float *spritePosX, int frameWidth, float scaleFactor) {
    float spriteWidth = frameWidth * scaleFactor;  
    float screenWidth = GetScreenWidth();  

    if (IsKeyDown(KEY_RIGHT) && *spritePosX + spriteWidth < screenWidth) {
        *spritePosX += 0.4f;  
    } 
    if (IsKeyDown(KEY_LEFT) && *spritePosX > 0) {
        *spritePosX -= 0.4f;  
    }
}

// Function to check collision between cat and food
bool CheckCollision(float spritePosX, float spritePosY, int spriteWidth, int spriteHeight, Food food, int foodWidth, int foodHeight) {
    Rectangle catRect = { spritePosX, spritePosY, spriteWidth, spriteHeight };

    // this is the food collision box
    Rectangle foodRect = { food.x + 10, food.y + 10, foodWidth - 20, foodHeight - 20 };

    return CheckCollisionRecs(catRect, foodRect);
}

// Function to draw all food textures with a given scale and position
void DrawHomePageFood (Texture2D foodTextures[], int numTextures, float scaleFactor, float startX, float startY, float gapX) {
    // Loop through the textures array and draw
    for (int i = 0; i < numTextures; i++) {
        // Calculate the X position for each food item based on the index and the gap
        float posX = startX + (i * (foodTextures[i].width * scaleFactor + gapX));

        // Draw the food image at the calculated position with the given scale factor
        DrawTextureEx(foodTextures[i], (Vector2){ posX, startY }, 0.0f, scaleFactor, WHITE);  // Y-position is constant 
    }
}