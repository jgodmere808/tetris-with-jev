
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "raylib.h"
#include "shape/shape.h"

int main()
{
    srand(time(NULL));

    bool hasMovedLeft = false, hasMovedRight = false, hasPressedUp = false;

    double timeBuffer = 0;
    double blockSpeed = 1.5; // Start at 1 block per 1.5 seconds

    struct ShapeSquare squareStore[40][20];

    const int screenWidth = 800;
    const int screenHeight = 800;

    // Typically, the first shape is always BLUE_L for some reason.
    // This fixes that by not using the first shape built.
    buildRandomShape();

    struct Shape nextShape = buildRandomShape();
    moveShape(&nextShape, 600, 150);

    struct Shape fallingShape = buildRandomShape();
    moveShape(&fallingShape, 340, 100);

    InitWindow(screenWidth, screenHeight, "Tetris with Jev");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // Update
        if (IsKeyDown(KEY_RIGHT) && !hasMovedRight) {
            fallingShape.posX += 30;
            hasMovedRight = true;
        }
        if (IsKeyDown(KEY_LEFT) && !hasMovedLeft) {
            fallingShape.posX -= 30;
            hasMovedLeft = true;
        }
        if (IsKeyDown(KEY_UP) && !hasPressedUp) {
            rotateShape(&fallingShape);
            hasPressedUp = true;
        }

        if (IsKeyUp(KEY_RIGHT)) hasMovedRight = false;
        if (IsKeyUp(KEY_LEFT)) hasMovedLeft = false;
        if (IsKeyUp(KEY_UP)) hasPressedUp = false;

        if (fallingShape.posX + fallingShape.states[fallingShape.i].maxLeft < 250) {
            fallingShape.posX = 250 - fallingShape.states[fallingShape.i].maxLeft;
        }
        if (fallingShape.posX + fallingShape.states[fallingShape.i].maxRight > 550) {
            fallingShape.posX = 550 - fallingShape.states[fallingShape.i].maxRight;
        }
        if (fallingShape.posY + fallingShape.states[fallingShape.i].maxBottom > 700) {
            fallingShape = nextShape;
            moveShape(&fallingShape, 340, 100);

            nextShape = buildRandomShape();
            moveShape(&nextShape, 600, 150);
        } else {
            timeBuffer += GetFrameTime();
            if (timeBuffer >= blockSpeed) {
                fallingShape.posY += 30;
                timeBuffer = 0;
            }
        }

        // Draw
        BeginDrawing();
            ClearBackground(DARKGRAY);

            // Main Rectangles
            // level
            DrawRectangle(95, 95, 135, 110, GRAY);
            DrawRectangle(100, 100, 125, 100, BLACK);
            // next
            DrawRectangle(570, 95, 160, 130, GRAY);
            DrawRectangle(575, 100, 150, 120, BLACK);
            // tetris field
            DrawRectangle(245, 95, 310, 610, GRAY);
            DrawRectangle(250, 100, 300, 600, BLACK);
            // score
            DrawRectangle(570, 240, 210, 410, GRAY);
            DrawRectangle(575, 245, 200, 400, BLACK);

            drawShape(fallingShape);
            drawShape(nextShape);

            // Main Cover Rectangles
            DrawRectangle(250, 0, 300, 95, DARKGRAY);
            DrawRectangle(250, 95, 300, 5, GRAY);

            // Main Text
            DrawText("TETRIS WITH JEV", 248, 30, 32, WHITE);
            DrawText("LEVEL", 110, 105, 32, WHITE);
            DrawText("NEXT", 605, 105, 32, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}