#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "UMBRA");

    Vector2 earthPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    
    SetTargetFPS(60);
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_RIGHT))   earthPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT))    earthPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP))      earthPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN))    earthPosition.y += 2.0f;
        
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            // Draw Earth
            DrawCircleV(earthPosition, 50, BLUE);
            
            // Draw Moon
            
            DrawCircleV(earthPosition, 20, GRAY);
            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}