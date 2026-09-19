
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "shape.h"
#include "raylib.h"

struct Shape buildShape(enum ShapeType type)
{
    struct Shape shape;

    shape.i = 0;
    shape.posX = 0;
    shape.posY = 0;
    shape.type = type;

    switch (type) {
        case LONG_RECTANGLE:
            Color skyBlueBorder = { 0, 158, 158, 255 };
            Color skyBlue = { 0, 198, 198, 255 };
            shape.states[0].s1 = (struct ShapeSquare){  2, 2, 26, 26, skyBlue, 0,  0, 30, 30, skyBlueBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 32, 2, 26, 26, skyBlue, 30, 0, 30, 30, skyBlueBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 62, 2, 26, 26, skyBlue, 60, 0, 30, 30, skyBlueBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 92, 2, 26, 26, skyBlue, 90, 0, 30, 30, skyBlueBorder };

            shape.states[1].s1 = (struct ShapeSquare){ 62, -58, 26, 26, skyBlue, 60, -60, 30, 30, skyBlueBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 62, -28, 26, 26, skyBlue, 60, -30, 30, 30, skyBlueBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 62, 2, 26, 26, skyBlue, 60, 0, 30, 30, skyBlueBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 62, 32, 26, 26, skyBlue, 60, 30, 30, 30, skyBlueBorder };

            shape.states[2].s1 = (struct ShapeSquare){ 2, 2, 26, 26, skyBlue, 0, 0, 30, 30, skyBlueBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 32, 2, 26, 26, skyBlue, 30, 0, 30, 30, skyBlueBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 62, 2, 26, 26, skyBlue, 60, 0, 30, 30, skyBlueBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 92, 2, 26, 26, skyBlue, 90, 0, 30, 30, skyBlueBorder };

            shape.states[3].s1 = (struct ShapeSquare){ 32, -58, 26, 26, skyBlue, 30, -60, 30, 30, skyBlueBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 32, -28, 26, 26, skyBlue, 30, -30, 30, 30, skyBlueBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 32, 2, 26, 26, skyBlue, 30, 0, 30, 30, skyBlueBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 32, 32, 26, 26, skyBlue, 30, 30, 30, 30, skyBlueBorder };
            break;
        case SQUARE:
            Color yellowBorder = { 158, 158, 2, 255 };
            Color yellow = { 198, 198, 2, 255 };
            shape.states[0].s1 = (struct ShapeSquare){ 2, 2, 26, 26, yellow, 0, 0, 30, 30, yellowBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 32, 2, 26, 26, yellow, 30, 0, 30, 30, yellowBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 2, 32, 26, 26, yellow, 0, 30, 30, 30, yellowBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 32, 32, 26, 26, yellow, 30, 30, 30, 30, yellowBorder };

            shape.states[1].s1 = (struct ShapeSquare){ 2, 2, 26, 26, yellow, 0, 0, 30, 30, yellowBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 32, 2, 26, 26, yellow, 30, 0, 30, 30, yellowBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 2, 32, 26, 26, yellow, 0, 30, 30, 30, yellowBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 32, 32, 26, 26, yellow, 30, 30, 30, 30, yellowBorder };

            shape.states[2].s1 = (struct ShapeSquare){ 2, 2, 26, 26, yellow, 0, 0, 30, 30, yellowBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 32, 2, 26, 26, yellow, 30, 0, 30, 30, yellowBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 2, 32, 26, 26, yellow, 0, 30, 30, 30, yellowBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 32, 32, 26, 26, yellow, 30, 30, 30, 30, yellowBorder };

            shape.states[3].s1 = (struct ShapeSquare){ 2, 2, 26, 26, yellow, 0, 0, 30, 30, yellowBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 32, 2, 26, 26, yellow, 30, 0, 30, 30, yellowBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 2, 32, 26, 26, yellow, 0, 30, 30, 30, yellowBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 32, 32, 26, 26, yellow, 30, 30, 30, 30, yellowBorder };
            break;
        case RED_ZIGZAG:
            Color redBorder = { 157, 2, 1, 255 };
            Color red = { 197, 2, 1, 255 };
            shape.states[0].s1 = (struct ShapeSquare){ 2, 2, 26, 26, red, 0, 0, 30, 30, redBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 32, 2, 26, 26, red, 30, 0, 30, 30, redBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 32, 32, 26, 26, red, 30, 30, 30, 30, redBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 62, 32, 26, 26, red, 60, 30, 30, 30, redBorder };

            shape.states[1].s1 = (struct ShapeSquare){ 32, 2, 26, 26, red, 30, 0, 30, 30, redBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 32, 32, 26, 26, red, 30, 30, 30, 30, redBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 2, 32, 26, 26, red, 0, 30, 30, 30, redBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 2, 62, 26, 26, red, 0, 60, 30, 30, redBorder };

            shape.states[2].s1 = (struct ShapeSquare){ -28, 2, 26, 26, red, -30, 0, 30, 30, redBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 2, 2, 26, 26, red, 0, 0, 30, 30, redBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 2, 32, 26, 26, red, 0, 30, 30, 30, redBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 32, 32, 26, 26, red, 30, 30, 30, 30, redBorder };

            shape.states[3].s1 = (struct ShapeSquare){ 32, -28, 26, 26, red, 30, -30, 30, 30, redBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 32, 2, 26, 26, red, 30, 0, 30, 30, redBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 2, 2, 26, 26, red, 0, 0, 30, 30, redBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 2, 32, 26, 26, red, 0, 30, 30, 30, redBorder };
            break;
        case GREEN_ZIGZAG:
            Color greenBorder = { 0, 158, 0, 255 };
            Color green = { 0, 198, 0, 255 };
            shape.states[0].s1 = (struct ShapeSquare){ 32, 2, 26, 26, green, 30, 0, 30, 30, greenBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 62, 2, 26, 26, green, 60, 0, 30, 30, greenBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 2, 32, 26, 26, green, 0, 30, 30, 30, greenBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 32, 32, 26, 26, green, 30, 30, 30, 30, greenBorder };

            shape.states[1].s1 = (struct ShapeSquare){ 2, 2, 26, 26, green, 0, 0, 30, 30, greenBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 2, 32, 26, 26, green, 0, 30, 30, 30, greenBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 32, 32, 26, 26, green, 30, 30, 30, 30, greenBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 32, 62, 26, 26, green, 30, 60, 30, 30, greenBorder };

            shape.states[2].s1 = (struct ShapeSquare){ 2, 2, 26, 26, green, 0, 0, 30, 30, greenBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 32, 2, 26, 26, green, 30, 0, 30, 30, greenBorder };
            shape.states[2].s3 = (struct ShapeSquare){ -28, 32, 26, 26, green, -30, 30, 30, 30, greenBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 2, 32, 26, 26, green, 0, 30, 30, 30, greenBorder };

            shape.states[3].s1 = (struct ShapeSquare){ 2, 2, 26, 26, green, 0, 0, 30, 30, greenBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 2, 32, 26, 26, green, 0, 30, 30, 30, greenBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 32, 32, 26, 26, green, 30, 30, 30, 30, greenBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 32, 62, 26, 26, green, 30, 60, 30, 30, greenBorder };
            break;
        case PLUS:
            Color purpleBorder = { 133, 0, 158, 255 };
            Color purple = { 148, 0, 198, 255 };
            shape.states[0].s1 = (struct ShapeSquare){ 32, 2, 26, 26, purple, 30, 0, 30, 30, purpleBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 2, 32, 26, 26, purple, 0, 30, 30, 30, purpleBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 32, 32, 26, 26, purple, 30, 30, 30, 30, purpleBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 62, 32, 26, 26, purple, 60, 30, 30, 30, purpleBorder };

            shape.states[1].s1 = (struct ShapeSquare){ 32, 2, 26, 26, purple, 30, 0, 30, 30, purpleBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 62, 32, 26, 26, purple, 60, 30, 30, 30, purpleBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 32, 32, 26, 26, purple, 30, 30, 30, 30, purpleBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 32, 62, 26, 26, purple, 30, 60, 30, 30, purpleBorder };

            shape.states[2].s1 = (struct ShapeSquare){ 62, 32, 26, 26, purple, 60, 30, 30, 30, purpleBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 2, 32, 26, 26, purple, 0, 30, 30, 30, purpleBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 32, 32, 26, 26, purple, 30, 30, 30, 30, purpleBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 32, 62, 26, 26, purple, 30, 60, 30, 30, purpleBorder };

            shape.states[3].s1 = (struct ShapeSquare){ 32, 2, 26, 26, purple, 30, 0, 30, 30, purpleBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 2, 32, 26, 26, purple, 0, 30, 30, 30, purpleBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 32, 32, 26, 26, purple, 30, 30, 30, 30, purpleBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 32, 62, 26, 26, purple, 30, 60, 30, 30, purpleBorder };
            break;
        case ORANGE_L:
            Color orangeBorder = { 157, 90, 2, 255 };
            Color orange = { 197, 100, 2, 255 };
            shape.states[0].s1 = (struct ShapeSquare){ 2, 32, 26, 26, orange, 0, 30, 30, 30, orangeBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 32, 32, 26, 26, orange, 30, 30, 30, 30, orangeBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 62, 32, 26, 26, orange, 60, 30, 30, 30, orangeBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 62, 2, 26, 26, orange, 60, 0, 30, 30, orangeBorder };

            shape.states[1].s1 = (struct ShapeSquare){ 32, -28, 26, 26, orange, 30, -30, 30, 30, orangeBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 32, 2, 26, 26, orange, 30, 0, 30, 30, orangeBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 32, 32, 26, 26, orange, 30, 30, 30, 30, orangeBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 62, 32, 26, 26, orange, 60, 30, 30, 30, orangeBorder };

            shape.states[2].s1 = (struct ShapeSquare){ 32, 2, 26, 26, orange, 30, 0, 30, 30, orangeBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 62, 2, 26, 26, orange, 60, 0, 30, 30, orangeBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 92, 2, 26, 26, orange, 90, 0, 30, 30, orangeBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 32, 32, 26, 26, orange, 30, 30, 30, 30, orangeBorder };

            shape.states[3].s1 = (struct ShapeSquare){ 32, 2, 26, 26, orange, 30, 0, 30, 30, orangeBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 62, 2, 26, 26, orange, 60, 0, 30, 30, orangeBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 62, 32, 26, 26, orange, 60, 30, 30, 30, orangeBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 62, 62, 26, 26, orange, 60, 60, 30, 30, orangeBorder };
            break;
        case BLUE_L:
            Color blueBorder = { 0, 0, 150, 255 };
            Color blue = { 0, 0, 190, 255 };

            shape.states[0].s1 = (struct ShapeSquare){ 2, 2, 26, 26, blue, 0, 0, 30, 30, blueBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 2, 32, 26, 26, blue, 0, 30, 30, 30, blueBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 32, 32, 26, 26, blue, 30, 30, 30, 30, blueBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 62, 32, 26, 26, blue, 60, 30, 30, 30, blueBorder };

            shape.states[1].s1 = (struct ShapeSquare){ 2, 2, 26, 26, blue, 0, 0, 30, 30, blueBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 2, 32, 26, 26, blue, 0, 30, 30, 30, blueBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 2, 62, 26, 26, blue, 0, 60, 30, 30, blueBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 32, 2, 26, 26, blue, 30, 0, 30, 30, blueBorder };

            shape.states[2].s1 = (struct ShapeSquare){ -28, 2, 26, 26, blue, -30, 0, 30, 30, blueBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 2, 2, 26, 26, blue, 0, 0, 30, 30, blueBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 32, 2, 26, 26, blue, 30, 0, 30, 30, blueBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 32, 32, 26, 26, blue, 30, 30, 30, 30, blueBorder };

            shape.states[3].s1 = (struct ShapeSquare){ 2, 2, 26, 26, blue, 0, 0, 30, 30, blueBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 2, 32, 26, 26, blue, 0, 30, 30, 30, blueBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 2, 62, 26, 26, blue, 0, 60, 30, 30, blueBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 32, 2, 26, 26, blue, 30, 0, 30, 30, blueBorder };
            break;
        case SHAPE_COUNT:
            perror("INVALID SHAPE: SHAPE_COUNT");
            break;
    }

    return shape;
}

struct Shape buildRandomShape()
{
    enum ShapeType type = rand() % SHAPE_COUNT;
    
    return buildShape(type);
}

void moveShape(struct Shape *shape, int posX, int posY)
{
    shape->posX = posX;
    shape->posY = posY;
}

void rotateShape(struct Shape *shape)
{
    shape->i++;
    if (shape->i > 3) shape->i = 0;
}

void drawShape(struct Shape shape)
{
    int i = shape.i;

    DrawRectangle(
        shape.states[i].s1.borderPosX + shape.posX,
        shape.states[i].s1.borderPosY + shape.posY,
        shape.states[i].s1.borderWidth,
        shape.states[i].s1.borderHeight,
        shape.states[i].s1.borderColor);
    DrawRectangle(
        shape.states[i].s1.posX + shape.posX,
        shape.states[i].s1.posY + shape.posY,
        shape.states[i].s1.width,
        shape.states[i].s1.height,
        shape.states[i].s1.color);

    DrawRectangle(
        shape.states[i].s2.borderPosX + shape.posX,
        shape.states[i].s2.borderPosY + shape.posY,
        shape.states[i].s2.borderWidth,
        shape.states[i].s2.borderHeight,
        shape.states[i].s2.borderColor);
    DrawRectangle(
        shape.states[i].s2.posX + shape.posX,
        shape.states[i].s2.posY + shape.posY,
        shape.states[i].s2.width,
        shape.states[i].s2.height,
        shape.states[i].s2.color);

    DrawRectangle(
        shape.states[i].s3.borderPosX + shape.posX,
        shape.states[i].s3.borderPosY + shape.posY,
        shape.states[i].s3.borderWidth,
        shape.states[i].s3.borderHeight,
        shape.states[i].s3.borderColor);
    DrawRectangle(
        shape.states[i].s3.posX + shape.posX,
        shape.states[i].s3.posY + shape.posY,
        shape.states[i].s3.width,
        shape.states[i].s3.height,
        shape.states[i].s3.color);

    DrawRectangle(
        shape.states[i].s4.borderPosX + shape.posX,
        shape.states[i].s4.borderPosY + shape.posY,
        shape.states[i].s4.borderWidth,
        shape.states[i].s4.borderHeight,
        shape.states[i].s4.borderColor);
    DrawRectangle(
        shape.states[i].s4.posX + shape.posX,
        shape.states[i].s4.posY + shape.posY,
        shape.states[i].s4.width,
        shape.states[i].s4.height,
        shape.states[i].s4.color);
}