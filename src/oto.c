#include <stdio.h>
#include "../include/raylib.h"

Texture2D oto;
int screenWidth;
int screenHeight;
Vector2 otoPosition;
int horizontalMovement = 0;

void OtoInit()
{
    oto = LoadTexture("resources/oto.png");
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
    otoPosition = (Vector2){(screenWidth / 2.0f) - (oto.width / 2.0f), (screenHeight / 2.0f)};
}

void UnloadOto()
{
    UnloadTexture(oto);
}

void OtoUpdate()
{
    horizontalMovement = 0;

    if(IsKeyDown(KEY_RIGHT))
    {
        horizontalMovement += 1;
    }

    if(IsKeyDown(KEY_LEFT))
    {
        horizontalMovement -= 1;
    }

    otoPosition.x += horizontalMovement;    

    
}

void OtoDraw()
{
    DrawTexture(oto, otoPosition.x , otoPosition.y, RAYWHITE);
    
}