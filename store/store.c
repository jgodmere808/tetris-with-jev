
#include "store.h"

struct ShapeSquare squareStore[40][20] = { { 0 } };

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

void storeShape(struct Shape *shape)
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

void storeFallingShape(struct Shape *fallingShape, struct Shape *nextShape)
{
    storeShape(fallingShape);

    *fallingShape = *nextShape;
    moveShape(fallingShape, 340, 100);

    *nextShape = buildRandomShape();
    moveShape(nextShape, 600, 150);
}