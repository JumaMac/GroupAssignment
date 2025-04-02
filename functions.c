// functions.c

#include "functions.h"

void UnloadAllTextures(Texture2D background, Texture2D logo, Texture2D startButton, Texture2D soundButton, Texture2D heart) {
    UnloadTexture(background);
    UnloadTexture(logo);
    UnloadTexture(startButton);
    UnloadTexture(soundButton);
    UnloadTexture(heart);
}

void scaleWhenHover(Rectangle startButtonRect, Rectangle soundButtonRect, float *scaleStart, float *scaleSound) {
    if (CheckCollisionPointRec(GetMousePosition(), startButtonRect)) {
        *scaleStart = 1.1f;
    } else {
        *scaleStart = 1.0f;
    }

    if (CheckCollisionPointRec(GetMousePosition(), soundButtonRect)) {
        *scaleSound = 1.1f;
    } else {
        *scaleSound = 1.0f;
    }
}

void DrawSprite(Texture2D texture, int frameWidth, int frameHeight, int currentFrame, float spritePosX, float spritePosY, float scaleFactor) {
    Rectangle sourceRec = { frameWidth * currentFrame, 0.0f, frameWidth, frameHeight };
    Rectangle destRec = { spritePosX, spritePosY, frameWidth * scaleFactor, frameHeight * scaleFactor };
    DrawTexturePro(texture, sourceRec, destRec, (Vector2){ 0.0f, 0.0f }, 0.0f, WHITE);
}

void UpdateAnimation(int *currentFrame, int *frameCounter, int frameSpeed, int totalFrames) {
    (*frameCounter)++;
    if (*frameCounter >= frameSpeed) {
        *currentFrame = (*currentFrame + 1) % totalFrames;
        *frameCounter = 0;
    }
}

void DrawFood(Texture2D textures[], Food food, float scaleFactor) {
    if (food.active) {
        DrawTextureEx(textures[food.textureIndex], (Vector2){food.x, food.y}, 0.0f, scaleFactor, WHITE);
    }
}

void UpdateFood(Food *food, float *fallSpeed, int screenHeight, int *lives, int score) {
    if (food->active) {
        food->y += *fallSpeed;

        if (food->y > screenHeight) {
            food->y = -50;
            food->x = GetRandomValue(50, GetScreenWidth() - 50);
            food->textureIndex = GetRandomValue(0, 10);
            *lives -= 1;
        }
    }

    *fallSpeed = 0.15f + (score / 10) * 0.02f;
}

void UpdateMovement(float *spritePosX, int frameWidth, float scaleFactor) {
    float spriteWidth = frameWidth * scaleFactor;
    float screenWidth = GetScreenWidth();

    if (IsKeyDown(KEY_RIGHT) && *spritePosX + spriteWidth < screenWidth) {
        *spritePosX += 0.3f;
    }
    if (IsKeyDown(KEY_LEFT) && *spritePosX > 0) {
        *spritePosX -= 0.3f;
    }
}

bool CheckCollision(float spritePosX, float spritePosY, int spriteWidth, int spriteHeight, Food food, int foodWidth, int foodHeight) {
    Rectangle catRect = { spritePosX, spritePosY, spriteWidth, spriteHeight };
    Rectangle foodRect = { food.x + 10, food.y + 10, foodWidth - 20, foodHeight - 20 };
    return CheckCollisionRecs(catRect, foodRect);
}

void DrawHomePageFood (Texture2D foodTextures[], int numTextures, float scaleFactor, float startX, float startY, float gapX) {
    for (int i = 0; i < numTextures; i++) {
        float posX = startX + (i * (foodTextures[i].width * scaleFactor + gapX));
        DrawTextureEx(foodTextures[i], (Vector2){ posX, startY }, 0.0f, scaleFactor, WHITE);
    }
}

void DrawLives(int lives, int screenWidth, int screenHeight, Texture2D heart) {
    int startX = 20;
    int gap = 40;
    float scale = 2.0f;

    for (int i = 0; i < lives; i++) {
        Vector2 heartPosition = { startX + i * gap, 60 };
        DrawTextureEx(heart, heartPosition, 0.0f, scale, WHITE);
    }
}

void DrawGameOverScreen(int screenWidth, int screenHeight, int score, Texture2D restartButton, float *restartButtonScale) {
    DrawRectangle(0, 0, screenWidth, screenHeight, Fade(BLACK, 0.8f));
    DrawText("Game Over", screenWidth / 2 - 100, screenHeight / 2 - 50, 40, WHITE);
    DrawText(TextFormat("Final Score: %d", score), screenWidth / 2 - 110, screenHeight / 2, 30, WHITE);

    Rectangle restartButtonRect = {screenWidth / 2 - restartButton.width / 2 * (*restartButtonScale), screenHeight / 2 + 75, restartButton.width * (*restartButtonScale), restartButton.height * (*restartButtonScale)};
    Vector2 restartButtonPosition = {restartButtonRect.x + restartButtonRect.width / 2 - restartButton.width * (*restartButtonScale) / 2,
                                   restartButtonRect.y + restartButtonRect.height / 2 - restartButton.height * (*restartButtonScale) / 2};
    DrawTextureEx(restartButton, restartButtonPosition, 0.0f, *restartButtonScale, WHITE);
}

void scaleGameOverButton(Rectangle restartButtonRect, float *restartButtonScale) {
     if (CheckCollisionPointRec(GetMousePosition(), restartButtonRect)) {
        *restartButtonScale = 0.7f;
    } else {
        *restartButtonScale = 0.6f;
    }
}
