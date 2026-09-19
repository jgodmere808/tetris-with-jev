
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "shape/shape.h"

int main()
{
    srand(time(NULL));

    double timeBuffer = 0;
    double blockSpeed = 1.5; // Start at 1 block per 1.5 seconds

    const int screenWidth = 800;
    const int screenHeight = 800;

    struct Shape fallingShape = buildRandomShape();
    moveShape(&fallingShape, 340, 100);

    InitWindow(screenWidth, screenHeight, "Tetris with Jev");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        
        // Update
        timeBuffer += GetFrameTime();
        if (timeBuffer >= blockSpeed) {
            fallingShape.posY += 30;
            timeBuffer = 0;
        }

        // Draw
        BeginDrawing();
            ClearBackground(DARKGRAY);

            // Main Rectangles
            DrawRectangle(95, 95, 135, 110, GRAY);
            DrawRectangle(100, 100, 125, 100, BLACK);

            DrawRectangle(570, 95, 110, 110, GRAY);
            DrawRectangle(575, 100, 100, 100, BLACK);

            DrawRectangle(245, 95, 310, 610, GRAY);
            DrawRectangle(250, 100, 300, 600, BLACK);

            DrawRectangle(570, 220, 210, 410, GRAY);
            DrawRectangle(575, 225, 200, 400, BLACK);

            drawShape(fallingShape);

            // Main Cover Rectangles
            DrawRectangle(250, 0, 300, 95, DARKGRAY);
            DrawRectangle(250, 95, 300, 5, GRAY);

            // Main Text
            DrawText("TETRIS WITH JEV", 248, 30, 32, WHITE);
            DrawText("LEVEL", 110, 105, 32, WHITE);
            DrawText("NEXT", 581, 105, 32, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}