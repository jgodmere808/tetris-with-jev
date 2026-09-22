
#include <stdbool.h>

#include "collision.h"

bool moveLeftCollides(struct Shape *fallingShape)
{
    int row, col;

    for (row = 0; row < 40; row++) {
        for (col = 0; col < 20; col++) {
            if (squareStore[row][col].borderWidth != 30) continue;

            struct StorePosition storePos = { row, col };
            struct RawPosition rawPos = storeToRaw(&storePos);

            // s1 collision
            if (
                fallingShape->states[fallingShape->i].s1.borderPosX + fallingShape->posX - 30 == rawPos.x &&
                fallingShape->states[fallingShape->i].s1.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }

            // s2 collision
            if (
                fallingShape->states[fallingShape->i].s2.borderPosX + fallingShape->posX - 30 == rawPos.x &&
                fallingShape->states[fallingShape->i].s2.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }

            // s3 collision
            if (
                fallingShape->states[fallingShape->i].s3.borderPosX + fallingShape->posX - 30 == rawPos.x &&
                fallingShape->states[fallingShape->i].s3.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }

            // s4 collision
            if (
                fallingShape->states[fallingShape->i].s4.borderPosX + fallingShape->posX - 30 == rawPos.x &&
                fallingShape->states[fallingShape->i].s4.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }
        }
    }

    return false;
}

bool moveRightCollides(struct Shape *fallingShape)
{
    int row, col;

    for (row = 0; row < 40; row++) {
        for (col = 0; col < 20; col++) {
            if (squareStore[row][col].borderWidth != 30) continue;

            struct StorePosition storePos = { row, col };
            struct RawPosition rawPos = storeToRaw(&storePos);

            // s1 collision
            if (
                fallingShape->states[fallingShape->i].s1.borderPosX + fallingShape->posX + 30 == rawPos.x &&
                fallingShape->states[fallingShape->i].s1.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }

            // s2 collision
            if (
                fallingShape->states[fallingShape->i].s2.borderPosX + fallingShape->posX + 30 == rawPos.x &&
                fallingShape->states[fallingShape->i].s2.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }

            // s3 collision
            if (
                fallingShape->states[fallingShape->i].s3.borderPosX + fallingShape->posX + 30 == rawPos.x &&
                fallingShape->states[fallingShape->i].s3.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }

            // s4 collision
            if (
                fallingShape->states[fallingShape->i].s4.borderPosX + fallingShape->posX + 30 == rawPos.x &&
                fallingShape->states[fallingShape->i].s4.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }
        }
    }

    return false;
}

bool moveDownCollides(struct Shape *fallingShape)
{
    int row, col;

    for (row = 0; row < 40; row++) {
        for (col = 0; col < 20; col++) {
            if (squareStore[row][col].borderWidth != 30) continue;

            struct StorePosition storePos = { row, col };
            struct RawPosition rawPos = storeToRaw(&storePos);

            // s1 rotate collision
            if (
                fallingShape->states[fallingShape->i].s1.borderPosX + fallingShape->posX == rawPos.x &&
                fallingShape->states[fallingShape->i].s1.borderPosY + fallingShape->posY + 30 == rawPos.y
            ) {
                return true;
            }

            // s2 rotate collision
            if (
                fallingShape->states[fallingShape->i].s2.borderPosX + fallingShape->posX == rawPos.x &&
                fallingShape->states[fallingShape->i].s2.borderPosY + fallingShape->posY + 30 == rawPos.y
            ) {
                return true;
            }

            // s3 rotate collision
            if (
                fallingShape->states[fallingShape->i].s3.borderPosX + fallingShape->posX == rawPos.x &&
                fallingShape->states[fallingShape->i].s3.borderPosY + fallingShape->posY + 30 == rawPos.y
            ) {
                return true;
            }

            // s4 rotate collision
            if (
                fallingShape->states[fallingShape->i].s4.borderPosX + fallingShape->posX == rawPos.x &&
                fallingShape->states[fallingShape->i].s4.borderPosY + fallingShape->posY + 30 == rawPos.y
            ) {
                return true;
            }
        }
    }

    if (fallingShape->posY + fallingShape->states[fallingShape->i].maxBottom + 30 > 700) {
        return true;
    }

    return false;
}

bool rotateCollides(struct Shape *fallingShape)
{
    int row, col;

    for (row = 0; row < 40; row++) {
        for (col = 0; col < 20; col++) {
            if (squareStore[row][col].borderWidth != 30) continue;

            struct StorePosition storePos = { row, col };
            struct RawPosition rawPos = storeToRaw(&storePos);

            // s1 rotate collision
            if (
                fallingShape->states[fallingShape->i + 1].s1.borderPosX + fallingShape->posX == rawPos.x &&
                fallingShape->states[fallingShape->i + 1].s1.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }

            // s2 rotate collision
            if (
                fallingShape->states[fallingShape->i + 1].s2.borderPosX + fallingShape->posX == rawPos.x &&
                fallingShape->states[fallingShape->i + 1].s2.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }

            // s3 rotate collision
            if (
                fallingShape->states[fallingShape->i + 1].s3.borderPosX + fallingShape->posX == rawPos.x &&
                fallingShape->states[fallingShape->i + 1].s3.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }

            // s4 rotate collision
            if (
                fallingShape->states[fallingShape->i + 1].s4.borderPosX + fallingShape->posX == rawPos.x &&
                fallingShape->states[fallingShape->i + 1].s4.borderPosY + fallingShape->posY == rawPos.y
            ) {
                return true;
            }
        }
    }

    return false;
}