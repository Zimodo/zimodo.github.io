#include "raylib.h"
#include <math.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "UMBRA");

    Vector2 earthPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    
    float theta = 0;
    
    SetTargetFPS(60);
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyDown(KEY_RIGHT))   earthPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT))    earthPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP))      earthPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN))    earthPosition.y += 2.0f;
        
        
        // Probably put this in a function later
        if (IsKeyDown(KEY_A))    theta -= .02;
        if (IsKeyDown(KEY_D))    theta += .02;
        
        Vector2 moonOffset = { cos(theta)*100, sin(theta)*100 };
        Vector2 moonPosition = { earthPosition.x + moonOffset.x, earthPosition.y + moonOffset.y };
        
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);
            
            DrawText(TextFormat("Theta: %f", theta), 200, 80, 20, RED);
            
            DrawText(TextFormat("Moon Offset X: %f", moonOffset.x), 200, 100, 20, RED);
            DrawText(TextFormat("Moon Offset Y: %f", moonOffset.y), 200, 120, 20, RED);

            // Draw Earth
            DrawCircleV(earthPosition, 50, BLUE);
            
            // Draw Moon
            
            DrawCircleV(moonPosition, 20, GRAY);
            
        EndDrawing();
    }

    CloseWindow();

    return 0;
}