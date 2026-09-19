
#include <stdio.h>

#include "raylib.h"
#include "shape/shape.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    // Long Blue Rectangle
    struct Shape longRectangle = buildShape(LONG_RECTANGLE);
    moveShape(&longRectangle, 310, 160);

    // Yellow Square
    struct Shape square = buildShape(SQUARE);
    moveShape(&square, 250, 130);

    // Red ZigZag
    struct Shape redZigzag = buildShape(RED_ZIGZAG);
    moveShape(&redZigzag, 250, 190);

    // Green ZigZag
    struct Shape greenZigzag = buildShape(GREEN_ZIGZAG);
    moveShape(&greenZigzag, 250, 250);

    // Purple Plus
    struct Shape plus = buildShape(PLUS);
    moveShape(&plus, 250, 310);

    // Orange L
    struct Shape orangeL = buildShape(ORANGE_L);
    moveShape(&orangeL, 250, 400);

    // Blue L
    struct Shape blueL = buildShape(BLUE_L);
    moveShape(&blueL, 250, 490);

    InitWindow(screenWidth, screenHeight, "Tetris with Jev");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Update

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

            drawShape(longRectangle);
            drawShape(square);
            drawShape(redZigzag);
            drawShape(greenZigzag);
            drawShape(plus);
            drawShape(orangeL);
            drawShape(blueL);

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