#include <stdio.h>
#include "../include/raylib.h"

Texture2D oto; // Oto texture
int screenWidth; // Width of screen
int screenHeight; // Height of screen
Vector2 otoPosition; // Position of Oto

int horizontalMovement = 0; // Left and right movement integer

int keyCountR = 0; // Right key counter for sprinting
int keyCountL = 0; // Left key counter for sprinting

float sprintTimer = 0.0; // Timer for sprint double tap
bool isSprinting = false; // Bool to check if sprinting

void OtoInit() // Initilize Oto 
{
    oto = LoadTexture("resources/oto.png");
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
    otoPosition = (Vector2){(screenWidth / 2.0f) - (oto.width / 2.0f), (screenHeight / 2.0f)};
}

void UnloadOto() // Unload texture
{
    UnloadTexture(oto);
}

void OtoUpdate() // Movement
{
    // Set movement to 0 at start
    horizontalMovement = 0;

    // Check if moving to right
    if(IsKeyDown(KEY_RIGHT))
    {
        horizontalMovement += 1;        
    }

    // Check if moving to left
    if(IsKeyDown(KEY_LEFT))
    {
        horizontalMovement -= 1;        
    }

    // Sprinting right check
    if (IsKeyPressed(KEY_RIGHT))
    {
        // Count the keyCounter up
        keyCountR++;
        keyCountL = 0;

        // If the keyCounter is at 1, start the timer
        if (keyCountR == 1)
        {
            sprintTimer = 1.0;
        }
        
        // If the keyCounter is at 2, start sprinting
        if (keyCountR == 2)
        {
            isSprinting = true;
        }
        
    }

    // Sprinting left check
    if (IsKeyPressed(KEY_LEFT))
    {
        // Count the keyCounter up
        keyCountL++;
        keyCountR = 0;

        // If the keyCounter is at 1, start the timer
        if (keyCountL == 1)
        {
            sprintTimer = 1.0;
        }
        
        // If the keyCounter is at 2, start sprinting
        if (keyCountL == 2)
        {
            isSprinting = true;
        }
        
    }
    
    // If the sprintTimer started, count it back to zero
    if (sprintTimer > 0.0)
    {
        sprintTimer -= 0.1;
    }else // If the timer reached zero, reset the keyCounter
    {
        keyCountR = 0;
        keyCountL = 0;
    }
    // Stop sprinting if either no button is pressed or both left and right buttons are pressed
    if (horizontalMovement == 0)
    {
        isSprinting = false;
    }
    
    // Check if sprinting or not
    if (isSprinting == true)
    {
        otoPosition.x += horizontalMovement * 2;  
    }else{
        otoPosition.x += horizontalMovement;  
    }   
    
}

void OtoDraw()
{
    DrawTexture(oto, otoPosition.x , otoPosition.y, RAYWHITE);
    
}