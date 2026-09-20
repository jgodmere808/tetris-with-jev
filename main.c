
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "raylib.h"
#include "shape/shape.h"

struct StorePosition {
    int row;
    int col;
};

struct RawPosition {
    int x;
    int y;
};

struct StorePosition rawToStore(struct RawPosition *rawPos)
{   
    struct StorePosition storePos;

    storePos.row = (rawPos->x - 250) / 30;
    storePos.col = (rawPos->y - 100) / 30;

    return storePos;
}

struct RawPosition storeToRaw(struct StorePosition *storePos)
{
    struct RawPosition rawPos;

    rawPos.x = 30 * storePos->row + 250;
    rawPos.y = 30 * storePos->col + 100;

    return rawPos;
}

void storeShape(struct ShapeSquare squareStore[40][20], struct Shape *shape)
{
    struct StorePosition storePos;

    // s1
    storePos = rawToStore(&(struct RawPosition){
        shape->states[shape->i].s1.borderPosX + shape->posX,
        shape->states[shape->i].s1.borderPosY + shape->posY
    });
    squareStore[storePos.row][storePos.col] = shape->states[shape->i].s1;

    // s2
    storePos = rawToStore(&(struct RawPosition){
        shape->states[shape->i].s2.borderPosX + shape->posX,
        shape->states[shape->i].s2.borderPosY + shape->posY
    });
    squareStore[storePos.row][storePos.col] = shape->states[shape->i].s2;

    // s3
    storePos = rawToStore(&(struct RawPosition){
        shape->states[shape->i].s3.borderPosX + shape->posX,
        shape->states[shape->i].s3.borderPosY + shape->posY
    });
    squareStore[storePos.row][storePos.col] = shape->states[shape->i].s3;

    // s4
    storePos = rawToStore(&(struct RawPosition){
        shape->states[shape->i].s4.borderPosX + shape->posX,
        shape->states[shape->i].s4.borderPosY + shape->posY
    });
    squareStore[storePos.row][storePos.col] = shape->states[shape->i].s4;
}

void storeFallingShape(struct ShapeSquare squareStore[40][20], struct Shape *fallingShape, struct Shape *nextShape)
{
    storeShape(squareStore, fallingShape);

    *fallingShape = *nextShape;
    moveShape(fallingShape, 340, 100);

    *nextShape = buildRandomShape();
    moveShape(nextShape, 600, 150);
}

int main()
{
    srand(time(NULL));

    bool hasMovedLeft = false, hasMovedRight = false, hasPressedUp = false;
    bool canMoveLeft = false, canMoveRight = false, canRotate = false;

    int row, col;

    double timeBuffer = 0;
    double blockSpeed = 1; // Start at 1 block per 1 seconds

    struct ShapeSquare squareStore[40][20] = { { 0 } };

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
            canMoveRight = true;

            for (row = 0; row < 40; row++) {
                for (col = 0; col < 20; col++) {
                    if (squareStore[row][col].borderWidth != 30) continue;

                    struct StorePosition storePos = { row, col };
                    struct RawPosition rawPos = storeToRaw(&storePos);

                    // s1 collision
                    if (
                        fallingShape.states[fallingShape.i].s1.borderPosX + fallingShape.posX + 30 == rawPos.x &&
                        fallingShape.states[fallingShape.i].s1.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canMoveRight = false;
                        break;
                    }

                    // s2 collision
                    if (
                        fallingShape.states[fallingShape.i].s2.borderPosX + fallingShape.posX + 30 == rawPos.x &&
                        fallingShape.states[fallingShape.i].s2.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canMoveRight = false;
                        break;
                    }

                    // s3 collision
                    if (
                        fallingShape.states[fallingShape.i].s3.borderPosX + fallingShape.posX + 30 == rawPos.x &&
                        fallingShape.states[fallingShape.i].s3.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canMoveRight = false;
                        break;
                    }

                    // s4 collision
                    if (
                        fallingShape.states[fallingShape.i].s4.borderPosX + fallingShape.posX + 30 == rawPos.x &&
                        fallingShape.states[fallingShape.i].s4.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canMoveRight = false;
                        break;
                    }
                }

                if (!canMoveRight) break;
            }

            if (canMoveRight) fallingShape.posX += 30;
            hasMovedRight = true;
        }
        if (IsKeyDown(KEY_LEFT) && !hasMovedLeft) {

            canMoveLeft = true;

            for (row = 0; row < 40; row++) {
                for (col = 0; col < 20; col++) {
                    if (squareStore[row][col].borderWidth != 30) continue;

                    struct StorePosition storePos = { row, col };
                    struct RawPosition rawPos = storeToRaw(&storePos);

                    // s1 collision
                    if (
                        fallingShape.states[fallingShape.i].s1.borderPosX + fallingShape.posX - 30 == rawPos.x &&
                        fallingShape.states[fallingShape.i].s1.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canMoveLeft = false;
                        break;
                    }

                    // s2 collision
                    if (
                        fallingShape.states[fallingShape.i].s2.borderPosX + fallingShape.posX - 30 == rawPos.x &&
                        fallingShape.states[fallingShape.i].s2.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canMoveLeft = false;
                        break;
                    }

                    // s3 collision
                    if (
                        fallingShape.states[fallingShape.i].s3.borderPosX + fallingShape.posX - 30 == rawPos.x &&
                        fallingShape.states[fallingShape.i].s3.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canMoveLeft = false;
                        break;
                    }

                    // s4 collision
                    if (
                        fallingShape.states[fallingShape.i].s4.borderPosX + fallingShape.posX - 30 == rawPos.x &&
                        fallingShape.states[fallingShape.i].s4.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canMoveLeft = false;
                        break;
                    }
                }

                if (!canMoveLeft) break;
            }

            if (canMoveLeft) fallingShape.posX -= 30;
            hasMovedLeft = true;
        }
        if (IsKeyDown(KEY_UP) && !hasPressedUp) {

            canRotate = true;

            for (row = 0; row < 40; row++) {
                for (col = 0; col < 20; col++) {
                    if (squareStore[row][col].borderWidth != 30) continue;

                    struct StorePosition storePos = { row, col };
                    struct RawPosition rawPos = storeToRaw(&storePos);

                    // s1 rotate collision
                    if (
                        fallingShape.states[fallingShape.i + 1].s1.borderPosX + fallingShape.posX == rawPos.x &&
                        fallingShape.states[fallingShape.i + 1].s1.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canRotate = false;
                        break;
                    }

                    // s2 rotate collision
                    if (
                        fallingShape.states[fallingShape.i + 1].s2.borderPosX + fallingShape.posX == rawPos.x &&
                        fallingShape.states[fallingShape.i + 1].s2.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canRotate = false;
                        break;
                    }

                    // s3 rotate collision
                    if (
                        fallingShape.states[fallingShape.i + 1].s3.borderPosX + fallingShape.posX == rawPos.x &&
                        fallingShape.states[fallingShape.i + 1].s3.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canRotate = false;
                        break;
                    }

                    // s4 rotate collision
                    if (
                        fallingShape.states[fallingShape.i + 1].s4.borderPosX + fallingShape.posX == rawPos.x &&
                        fallingShape.states[fallingShape.i + 1].s4.borderPosY + fallingShape.posY == rawPos.y
                    ) {
                        canRotate = false;
                        break;
                    }
                }

                if (!canRotate) break;
            }

            if (canRotate) rotateShape(&fallingShape);
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
        if (fallingShape.posY + fallingShape.states[fallingShape.i].maxBottom + 30 > 700) {
            storeFallingShape(&squareStore, &fallingShape, &nextShape);
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

            for (row = 0; row < 40; row++) {
                for (col = 0; col < 20; col++) {
                    if (squareStore[row][col].borderWidth != 30) continue;

                    struct StorePosition storePos = { row, col };
                    struct RawPosition rawPos = storeToRaw(&storePos);

                    // s1 collision
                    if (
                        fallingShape.states[fallingShape.i].s1.borderPosY + fallingShape.posY + 30 == rawPos.y &&
                        fallingShape.states[fallingShape.i].s1.borderPosX + fallingShape.posX == rawPos.x
                    ) {
                        storeFallingShape(&squareStore, &fallingShape, &nextShape);
                    }

                    // s2 collision
                    if (
                        fallingShape.states[fallingShape.i].s2.borderPosY + fallingShape.posY + 30 == rawPos.y &&
                        fallingShape.states[fallingShape.i].s2.borderPosX + fallingShape.posX == rawPos.x
                    ) {
                        storeFallingShape(&squareStore, &fallingShape, &nextShape);
                    }

                    // s3 collision
                    if (
                        fallingShape.states[fallingShape.i].s3.borderPosY + fallingShape.posY + 30 == rawPos.y &&
                        fallingShape.states[fallingShape.i].s3.borderPosX + fallingShape.posX == rawPos.x
                    ) {
                        storeFallingShape(&squareStore, &fallingShape, &nextShape);
                    }

                    // s4 collision
                    if (
                        fallingShape.states[fallingShape.i].s4.borderPosY + fallingShape.posY + 30 == rawPos.y &&
                        fallingShape.states[fallingShape.i].s4.borderPosX + fallingShape.posX == rawPos.x
                    ) {
                        storeFallingShape(&squareStore, &fallingShape, &nextShape);
                    }

                    DrawRectangle(
                        rawPos.x, rawPos.y,
                        squareStore[row][col].borderWidth,
                        squareStore[row][col].borderHeight,
                        squareStore[row][col].borderColor
                    );
                    DrawRectangle(
                        rawPos.x + 2, rawPos.y + 2,
                        squareStore[row][col].width,
                        squareStore[row][col].height,
                        squareStore[row][col].color
                    );
                }
            }

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