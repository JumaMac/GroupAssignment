// functions.h

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "raylib.h"

// structure for the falling food items
typedef struct {
    float x, y;
    bool active;
    int textureIndex;
} Food;

// Function declarations
void UnloadAllTextures(Texture2D background, Texture2D logo, Texture2D startButton, Texture2D soundButton, Texture2D heart);
void scaleWhenHover(Rectangle startButtonRect, Rectangle soundButtonRect, float *scaleStart, float *scaleSound);
void DrawSprite(Texture2D texture, int frameWidth, int frameHeight, int currentFrame, float spritePosX, float spritePosY, float scaleFactor);
void DrawFood(Texture2D textures[], Food food, float scaleFactor);
void DrawHomePageFood (Texture2D foodTextures[], int numTextures, float scaleFactor, float startX, float startY, float gapX);
void UpdateFood(Food *food, float *fallSpeed, int screenHeight, int *lives, int score);
void UpdateMovement(float *spritePosX, int frameWidth, float scaleFactor);
void UpdateAnimation(int *currentFrame, int *frameCounter, int frameSpeed, int totalFrames);
bool CheckCollision(float spritePosX, float spritePosY, int spriteWidth, int spriteHeight, Food food, int foodWidth, int foodHeight);
void DrawLives(int lives, int screenWidth, int screenHeight, Texture2D heart);
void DrawGameOverScreen(int screenWidth, int screenHeight, int score, Texture2D restartButton, float *restartButtonScale);
void scaleGameOverButton(Rectangle restartButtonRect, float *restartButtonScale);

#endif
