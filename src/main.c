/*******************************************************************************************
*
*   Made by Lukyy !
*
********************************************************************************************/

#include "../include/raylib.h"
#include <stdio.h>
#include "../include/oto.h"
//#include "../include/resource_manager.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 256;
    const int screenHeight = 240;

    InitWindow(screenWidth, screenHeight, "Oto Oto");
    Image icon = LoadImage("../resources/oto.png");
    SetWindowIcon(icon);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    SetExitKey(0);

    
    
    OtoInit();       // Initialize Player Character
    //--------------------------------------------------------------------------------------

    // Declare Functions
    //----------------------------------------------------------------------------------
    void Update();
    void Draw();

    //----------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        Update();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);

        Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    UnloadOto();
    //--------------------------------------------------------------------------------------

    return 0;
}

void Update()
{
    OtoUpdate();
    
}

void Draw()
{
    OtoDraw();
}