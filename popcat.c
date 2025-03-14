#include "raylib.h"
#include <stdio.h>

// Function to update sprite movement
void UpdateMovement(float *spritePosX, int frameWidth, float scaleFactor) {
    float spriteWidth = frameWidth * scaleFactor;  // Get actual scaled width
    float screenWidth = GetScreenWidth();  // Get window width

    if (IsKeyDown(KEY_RIGHT) && *spritePosX + spriteWidth < screenWidth) {
        *spritePosX += 0.4f;  // Move right
    } 
    if (IsKeyDown(KEY_LEFT) && *spritePosX > 0) {
        *spritePosX -= 0.4f;  // Move left
    }
}


// Function to update frame animation with a delay
void UpdateAnimation(int *currentFrame, int *frameCounter, int frameSpeed, int totalFrames) {
    (*frameCounter)++;  // Increment frame counter

    if (*frameCounter >= frameSpeed) {  // Change frame after 'frameSpeed' updates
        *currentFrame = (*currentFrame + 1) % totalFrames;  
        *frameCounter = 0;  // Reset frame counter
    }
}

// Function to draw the sprite
void DrawSprite(Texture2D texture, int frameWidth, int frameHeight, int currentFrame, float spritePosX, float spritePosY, float scaleFactor) {
    Rectangle sourceRec = { frameWidth * currentFrame, 0.0f, frameWidth, frameHeight };
    Rectangle destRec = { spritePosX, spritePosY, frameWidth * scaleFactor, frameHeight * scaleFactor };

    DrawTexturePro(texture, sourceRec, destRec, (Vector2){ 0.0f, 0.0f }, 0.0f, WHITE);
}

int main() {
    // Initialize window
    InitWindow(1000, 600, "POP CAT");

    // Load sprite sheet
    Texture2D popcat = LoadTexture("assets/popcat_spritesheet.png");

    // Define sprite sheet dimensions
    int totalFrames = 6;  
    int frameWidth = popcat.width / totalFrames;
    int frameHeight = popcat.height;

    // Animation and movement variables
    int currentFrame = 0;
    int frameCounter = 0;  // Counts updates before switching frames
    int frameSpeed = 250;   // Higher = slower animation
    float spritePosX = 500.0f;
    float spritePosY = 480.0f;
    float scaleFactor = 0.25f;

    // Game loop
    while (!WindowShouldClose()) {
        // Update movement
        UpdateMovement(&spritePosX, frameWidth, scaleFactor);

        // Update animation with speed control
        UpdateAnimation(&currentFrame, &frameCounter, frameSpeed, totalFrames);

        // Start drawing
        BeginDrawing();
        ClearBackground(BLACK);

        // Draw sprite
        DrawSprite(popcat, frameWidth, frameHeight, currentFrame, spritePosX, spritePosY, scaleFactor);

        // End drawing
        EndDrawing();
    }

    // Unload texture and close window
    UnloadTexture(popcat);
    CloseWindow();

    return 0;
}
