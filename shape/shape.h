
#include "raylib.h"

enum ShapeType {
    LONG_RECTANGLE,
    SQUARE,
    RED_ZIGZAG,
    GREEN_ZIGZAG,
    PLUS,
    ORANGE_L,
    BLUE_L,
    SHAPE_COUNT // counter, not a valid shape
};

struct ShapeSquare
{
    int posX;
    int posY;
    int width;
    int height;
    Color color;

    int borderPosX;
    int borderPosY;
    int borderWidth;
    int borderHeight;
    Color borderColor;
};

struct ShapeState {
    struct ShapeSquare s1;
    struct ShapeSquare s2;
    struct ShapeSquare s3;
    struct ShapeSquare s4;
};

struct Shape {
    int i;
    int posX;
    int posY;

    enum ShapeType type;

    struct ShapeState states[4];
};

struct Shape buildShape(enum ShapeType type);

struct Shape buildRandomShape();

void moveShape(struct Shape *shape, int posX, int posY);

void rotateShape(struct Shape *shape);

void drawShape(struct Shape shape);