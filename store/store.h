#pragma once
#include "../shape/shape.h"

struct ShapeSquare squareStore[40][20];

struct StorePosition {
    int row;
    int col;
};

struct RawPosition {
    int x;
    int y;
};

struct StorePosition rawToStore(struct RawPosition *rawPos);

struct RawPosition storeToRaw(struct StorePosition *storePos);

void storeShape(struct Shape *shape);

void storeFallingShape(struct Shape *fallingShape, struct Shape *nextShape);