
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
            shape.states[0].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, skyBlueBorder };
            shape.states[0].s1 = (struct ShapeSquare){ 2, 2, 26, 26, skyBlue };
            shape.states[0].borderS2 = (struct ShapeSquare){ 30, 0, 30, 30, skyBlueBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 32, 2, 26, 26, skyBlue };
            shape.states[0].borderS3 = (struct ShapeSquare){ 60, 0, 30, 30, skyBlueBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 62, 2, 26, 26, skyBlue };
            shape.states[0].borderS4 = (struct ShapeSquare){ 90, 0, 30, 30, skyBlueBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 92, 2, 26, 26, skyBlue };

            shape.states[1].borderS1 = (struct ShapeSquare){ 60, -60, 30, 30, skyBlueBorder };
            shape.states[1].s1 = (struct ShapeSquare){ 62, -58, 26, 26, skyBlue };
            shape.states[1].borderS2 = (struct ShapeSquare){ 60, -30, 30, 30, skyBlueBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 62, -28, 26, 26, skyBlue };
            shape.states[1].borderS3 = (struct ShapeSquare){ 60, 0, 30, 30, skyBlueBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 62, 2, 26, 26, skyBlue };
            shape.states[1].borderS4 = (struct ShapeSquare){ 60, 30, 30, 30, skyBlueBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 62, 32, 26, 26, skyBlue };

            shape.states[2].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, skyBlueBorder };
            shape.states[2].s1 = (struct ShapeSquare){ 2, 2, 26, 26, skyBlue };
            shape.states[2].borderS2 = (struct ShapeSquare){ 30, 0, 30, 30, skyBlueBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 32, 2, 26, 26, skyBlue };
            shape.states[2].borderS3 = (struct ShapeSquare){ 60, 0, 30, 30, skyBlueBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 62, 2, 26, 26, skyBlue };
            shape.states[2].borderS4 = (struct ShapeSquare){ 90, 0, 30, 30, skyBlueBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 92, 2, 26, 26, skyBlue };

            shape.states[3].borderS1 = (struct ShapeSquare){ 30, -60, 30, 30, skyBlueBorder };
            shape.states[3].s1 = (struct ShapeSquare){ 32, -58, 26, 26, skyBlue };
            shape.states[3].borderS2 = (struct ShapeSquare){ 30, -30, 30, 30, skyBlueBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 32, -28, 26, 26, skyBlue };
            shape.states[3].borderS3 = (struct ShapeSquare){ 30, 0, 30, 30, skyBlueBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 32, 2, 26, 26, skyBlue };
            shape.states[3].borderS4 = (struct ShapeSquare){ 30, 30, 30, 30, skyBlueBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 32, 32, 26, 26, skyBlue };
            break;
        case SQUARE:
            Color yellowBorder = { 158, 158, 2, 255 };
            Color yellow = { 198, 198, 2, 255 };
            shape.states[0].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, yellowBorder };
            shape.states[0].s1 = (struct ShapeSquare){ 2, 2, 26, 26, yellow };
            shape.states[0].borderS2 = (struct ShapeSquare){ 30, 0, 30, 30, yellowBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 32, 2, 26, 26, yellow };
            shape.states[0].borderS3 = (struct ShapeSquare){ 0, 30, 30, 30, yellowBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 2, 32, 26, 26, yellow };
            shape.states[0].borderS4 = (struct ShapeSquare){ 30, 30, 30, 30, yellowBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 32, 32, 26, 26, yellow };

            shape.states[1].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, yellowBorder };
            shape.states[1].s1 = (struct ShapeSquare){ 2, 2, 26, 26, yellow };
            shape.states[1].borderS2 = (struct ShapeSquare){ 30, 0, 30, 30, yellowBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 32, 2, 26, 26, yellow };
            shape.states[1].borderS3 = (struct ShapeSquare){ 0, 30, 30, 30, yellowBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 2, 32, 26, 26, yellow };
            shape.states[1].borderS4 = (struct ShapeSquare){ 30, 30, 30, 30, yellowBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 32, 32, 26, 26, yellow };

            shape.states[2].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, yellowBorder };
            shape.states[2].s1 = (struct ShapeSquare){ 2, 2, 26, 26, yellow };
            shape.states[2].borderS2 = (struct ShapeSquare){ 30, 0, 30, 30, yellowBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 32, 2, 26, 26, yellow };
            shape.states[2].borderS3 = (struct ShapeSquare){ 0, 30, 30, 30, yellowBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 2, 32, 26, 26, yellow };
            shape.states[2].borderS4 = (struct ShapeSquare){ 30, 30, 30, 30, yellowBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 32, 32, 26, 26, yellow };

            shape.states[3].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, yellowBorder };
            shape.states[3].s1 = (struct ShapeSquare){ 2, 2, 26, 26, yellow };
            shape.states[3].borderS2 = (struct ShapeSquare){ 30, 0, 30, 30, yellowBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 32, 2, 26, 26, yellow };
            shape.states[3].borderS3 = (struct ShapeSquare){ 0, 30, 30, 30, yellowBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 2, 32, 26, 26, yellow };
            shape.states[3].borderS4 = (struct ShapeSquare){ 30, 30, 30, 30, yellowBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 32, 32, 26, 26, yellow };
            break;
        case RED_ZIGZAG:
            Color redBorder = { 157, 2, 1, 255 };
            Color red = { 197, 2, 1, 255 };
            shape.states[0].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, redBorder };
            shape.states[0].s1 = (struct ShapeSquare){ 2, 2, 26, 26, red };
            shape.states[0].borderS2 = (struct ShapeSquare){ 30, 0, 30, 30, redBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 32, 2, 26, 26, red };
            shape.states[0].borderS3 = (struct ShapeSquare){ 30, 30, 30, 30, redBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 32, 32, 26, 26, red };
            shape.states[0].borderS4 = (struct ShapeSquare){ 60, 30, 30, 30, redBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 62, 32, 26, 26, red };

            shape.states[1].borderS1 = (struct ShapeSquare){ 30, 0, 30, 30, redBorder };
            shape.states[1].s1 = (struct ShapeSquare){ 32, 2, 26, 26, red };
            shape.states[1].borderS2 = (struct ShapeSquare){ 30, 30, 30, 30, redBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 32, 32, 26, 26, red };
            shape.states[1].borderS3 = (struct ShapeSquare){ 0, 30, 30, 30, redBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 2, 32, 26, 26, red };
            shape.states[1].borderS4 = (struct ShapeSquare){ 0, 60, 30, 30, redBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 2, 62, 26, 26, red };

            shape.states[2].borderS1 = (struct ShapeSquare){ -30, 0, 30, 30, redBorder };
            shape.states[2].s1 = (struct ShapeSquare){ -28, 2, 26, 26, red };
            shape.states[2].borderS2 = (struct ShapeSquare){ 0, 0, 30, 30, redBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 2, 2, 26, 26, red };
            shape.states[2].borderS3 = (struct ShapeSquare){ 0, 30, 30, 30, redBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 2, 32, 26, 26, red };
            shape.states[2].borderS4 = (struct ShapeSquare){ 30, 30, 30, 30, redBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 32, 32, 26, 26, red };

            shape.states[3].borderS1 = (struct ShapeSquare){ 30, -30, 30, 30, redBorder };
            shape.states[3].s1 = (struct ShapeSquare){ 32, -28, 26, 26, red };
            shape.states[3].borderS2 = (struct ShapeSquare){ 30, 0, 30, 30, redBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 32, 2, 26, 26, red };
            shape.states[3].borderS3 = (struct ShapeSquare){ 0, 0, 30, 30, redBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 2, 2, 26, 26, red };
            shape.states[3].borderS4 = (struct ShapeSquare){ 0, 30, 30, 30, redBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 2, 32, 26, 26, red };
            break;
        case GREEN_ZIGZAG:
            Color greenBorder = { 0, 158, 0, 255 };
            Color green = { 0, 198, 0, 255 };
            shape.states[0].borderS1 = (struct ShapeSquare){ 30, 0, 30, 30, greenBorder };
            shape.states[0].s1 = (struct ShapeSquare){ 32, 2, 26, 26, green };
            shape.states[0].borderS2 = (struct ShapeSquare){ 60, 0, 30, 30, greenBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 62, 2, 26, 26, green };
            shape.states[0].borderS3 = (struct ShapeSquare){ 0, 30, 30, 30, greenBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 2, 32, 26, 26, green };
            shape.states[0].borderS4 = (struct ShapeSquare){ 30, 30, 30, 30, greenBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 32, 32, 26, 26, green };

            shape.states[1].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, greenBorder };
            shape.states[1].s1 = (struct ShapeSquare){ 2, 2, 26, 26, green };
            shape.states[1].borderS2 = (struct ShapeSquare){ 0, 30, 30, 30, greenBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 2, 32, 26, 26, green };
            shape.states[1].borderS3 = (struct ShapeSquare){ 30, 30, 30, 30, greenBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 32, 32, 26, 26, green };
            shape.states[1].borderS4 = (struct ShapeSquare){ 30, 60, 30, 30, greenBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 32, 62, 26, 26, green };

            shape.states[2].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, greenBorder };
            shape.states[2].s1 = (struct ShapeSquare){ 2, 2, 26, 26, green };
            shape.states[2].borderS2 = (struct ShapeSquare){ 30, 0, 30, 30, greenBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 32, 2, 26, 26, green };
            shape.states[2].borderS3 = (struct ShapeSquare){ -30, 30, 30, 30, greenBorder };
            shape.states[2].s3 = (struct ShapeSquare){ -28, 32, 26, 26, green };
            shape.states[2].borderS4 = (struct ShapeSquare){ 0, 30, 30, 30, greenBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 2, 32, 26, 26, green };

            shape.states[3].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, greenBorder };
            shape.states[3].s1 = (struct ShapeSquare){ 2, 2, 26, 26, green };
            shape.states[3].borderS2 = (struct ShapeSquare){ 0, 30, 30, 30, greenBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 2, 32, 26, 26, green };
            shape.states[3].borderS3 = (struct ShapeSquare){ 30, 30, 30, 30, greenBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 32, 32, 26, 26, green };
            shape.states[3].borderS4 = (struct ShapeSquare){ 30, 60, 30, 30, greenBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 32, 62, 26, 26, green };
            break;
        case PLUS:
            Color purpleBorder = { 133, 0, 158, 255 };
            Color purple = { 148, 0, 198, 255 };
            shape.states[0].borderS1 = (struct ShapeSquare){ 30, 0, 30, 30, purpleBorder };
            shape.states[0].s1 = (struct ShapeSquare){ 32, 2, 26, 26, purple };
            shape.states[0].borderS2 = (struct ShapeSquare){ 0, 30, 30, 30, purpleBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 2, 32, 26, 26, purple };
            shape.states[0].borderS3 = (struct ShapeSquare){ 30, 30, 30, 30, purpleBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 32, 32, 26, 26, purple };
            shape.states[0].borderS4 = (struct ShapeSquare){ 60, 30, 30, 30, purpleBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 62, 32, 26, 26, purple };

            shape.states[1].borderS1 = (struct ShapeSquare){ 30, 0, 30, 30, purpleBorder };
            shape.states[1].s1 = (struct ShapeSquare){ 32, 2, 26, 26, purple };
            shape.states[1].borderS2 = (struct ShapeSquare){ 60, 30, 30, 30, purpleBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 62, 32, 26, 26, purple };
            shape.states[1].borderS3 = (struct ShapeSquare){ 30, 30, 30, 30, purpleBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 32, 32, 26, 26, purple };
            shape.states[1].borderS4 = (struct ShapeSquare){ 30, 60, 30, 30, purpleBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 32, 62, 26, 26, purple };

            shape.states[2].borderS1 = (struct ShapeSquare){ 60, 30, 30, 30, purpleBorder };
            shape.states[2].s1 = (struct ShapeSquare){ 62, 32, 26, 26, purple };
            shape.states[2].borderS2 = (struct ShapeSquare){ 0, 30, 30, 30, purpleBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 2, 32, 26, 26, purple };
            shape.states[2].borderS3 = (struct ShapeSquare){ 30, 30, 30, 30, purpleBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 32, 32, 26, 26, purple };
            shape.states[2].borderS4 = (struct ShapeSquare){ 30, 60, 30, 30, purpleBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 32, 62, 26, 26, purple };

            shape.states[3].borderS1 = (struct ShapeSquare){ 30, 0, 30, 30, purpleBorder };
            shape.states[3].s1 = (struct ShapeSquare){ 32, 2, 26, 26, purple };
            shape.states[3].borderS2 = (struct ShapeSquare){ 0, 30, 30, 30, purpleBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 2, 32, 26, 26, purple };
            shape.states[3].borderS3 = (struct ShapeSquare){ 30, 30, 30, 30, purpleBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 32, 32, 26, 26, purple };
            shape.states[3].borderS4 = (struct ShapeSquare){ 30, 60, 30, 30, purpleBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 32, 62, 26, 26, purple };
            break;
        case ORANGE_L:
            Color orangeBorder = { 157, 90, 2, 255 };
            Color orange = { 197, 100, 2, 255 };
            shape.states[0].borderS1 = (struct ShapeSquare){ 0, 30, 30, 30, orangeBorder };
            shape.states[0].s1 = (struct ShapeSquare){ 2, 32, 26, 26, orange };
            shape.states[0].borderS2 = (struct ShapeSquare){ 30, 30, 30, 30, orangeBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 32, 32, 26, 26, orange };
            shape.states[0].borderS3 = (struct ShapeSquare){ 60, 30, 30, 30, orangeBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 62, 32, 26, 26, orange };
            shape.states[0].borderS4 = (struct ShapeSquare){ 60, 0, 30, 30, orangeBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 62, 2, 26, 26, orange };

            shape.states[1].borderS1 = (struct ShapeSquare){ 30, -30, 30, 30, orangeBorder };
            shape.states[1].s1 = (struct ShapeSquare){ 32, -28, 26, 26, orange };
            shape.states[1].borderS2 = (struct ShapeSquare){ 30, 0, 30, 30, orangeBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 32, 2, 26, 26, orange };
            shape.states[1].borderS3 = (struct ShapeSquare){ 30, 30, 30, 30, orangeBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 32, 32, 26, 26, orange };
            shape.states[1].borderS4 = (struct ShapeSquare){ 60, 30, 30, 30, orangeBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 62, 32, 26, 26, orange };

            shape.states[2].borderS1 = (struct ShapeSquare){ 30, 0, 30, 30, orangeBorder };
            shape.states[2].s1 = (struct ShapeSquare){ 32, 2, 26, 26, orange };
            shape.states[2].borderS2 = (struct ShapeSquare){ 60, 0, 30, 30, orangeBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 62, 2, 26, 26, orange };
            shape.states[2].borderS3 = (struct ShapeSquare){ 90, 0, 30, 30, orangeBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 92, 2, 26, 26, orange };
            shape.states[2].borderS4 = (struct ShapeSquare){ 30, 30, 30, 30, orangeBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 32, 32, 26, 26, orange };

            shape.states[3].borderS1 = (struct ShapeSquare){ 30, 0, 30, 30, orangeBorder };
            shape.states[3].s1 = (struct ShapeSquare){ 32, 2, 26, 26, orange };
            shape.states[3].borderS2 = (struct ShapeSquare){ 60, 0, 30, 30, orangeBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 62, 2, 26, 26, orange };
            shape.states[3].borderS3 = (struct ShapeSquare){ 60, 30, 30, 30, orangeBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 62, 32, 26, 26, orange };
            shape.states[3].borderS4 = (struct ShapeSquare){ 60, 60, 30, 30, orangeBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 62, 62, 26, 26, orange };
            break;
        case BLUE_L:
            Color blueBorder = { 0, 0, 150, 255 };
            Color blue = { 0, 0, 190, 255 };

            /// WORKING HERE ///
            shape.states[0].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, blueBorder };
            shape.states[0].s1 = (struct ShapeSquare){ 2, 2, 26, 26, blue };
            shape.states[0].borderS2 = (struct ShapeSquare){ 0, 30, 30, 30, blueBorder };
            shape.states[0].s2 = (struct ShapeSquare){ 2, 32, 26, 26, blue };
            shape.states[0].borderS3 = (struct ShapeSquare){ 30, 30, 30, 30, blueBorder };
            shape.states[0].s3 = (struct ShapeSquare){ 32, 32, 26, 26, blue };
            shape.states[0].borderS4 = (struct ShapeSquare){ 60, 30, 30, 30, blueBorder };
            shape.states[0].s4 = (struct ShapeSquare){ 62, 32, 26, 26, blue };

            shape.states[1].borderS1 = (struct ShapeSquare){ 00, 0, 30, 30, blueBorder };
            shape.states[1].s1 = (struct ShapeSquare){ 2, 2, 26, 26, blue };
            shape.states[1].borderS2 = (struct ShapeSquare){ 0, 30, 30, 30, blueBorder };
            shape.states[1].s2 = (struct ShapeSquare){ 2, 32, 26, 26, blue };
            shape.states[1].borderS3 = (struct ShapeSquare){ 0, 60, 30, 30, blueBorder };
            shape.states[1].s3 = (struct ShapeSquare){ 2, 62, 26, 26, blue };
            shape.states[1].borderS4 = (struct ShapeSquare){ 30, 0, 30, 30, blueBorder };
            shape.states[1].s4 = (struct ShapeSquare){ 32, 2, 26, 26, blue };

            shape.states[2].borderS1 = (struct ShapeSquare){ -30, 0, 30, 30, blueBorder };
            shape.states[2].s1 = (struct ShapeSquare){ -28, 2, 26, 26, blue };
            shape.states[2].borderS2 = (struct ShapeSquare){ 0, 0, 30, 30, blueBorder };
            shape.states[2].s2 = (struct ShapeSquare){ 2, 2, 26, 26, blue };
            shape.states[2].borderS3 = (struct ShapeSquare){ 30, 0, 30, 30, blueBorder };
            shape.states[2].s3 = (struct ShapeSquare){ 32, 2, 26, 26, blue };
            shape.states[2].borderS4 = (struct ShapeSquare){ 30, 30, 30, 30, blueBorder };
            shape.states[2].s4 = (struct ShapeSquare){ 32, 32, 26, 26, blue };

            shape.states[3].borderS1 = (struct ShapeSquare){ 0, 0, 30, 30, blueBorder };
            shape.states[3].s1 = (struct ShapeSquare){ 2, 2, 26, 26, blue };
            shape.states[3].borderS2 = (struct ShapeSquare){ 0, 30, 30, 30, blueBorder };
            shape.states[3].s2 = (struct ShapeSquare){ 2, 32, 26, 26, blue };
            shape.states[3].borderS3 = (struct ShapeSquare){ 0, 60, 30, 30, blueBorder };
            shape.states[3].s3 = (struct ShapeSquare){ 2, 62, 26, 26, blue };
            shape.states[3].borderS4 = (struct ShapeSquare){ 30, 0, 30, 30, blueBorder };
            shape.states[3].s4 = (struct ShapeSquare){ 32, 2, 26, 26, blue };
            break;
    }

    return shape;
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
        shape.states[i].borderS1.posX + shape.posX,
        shape.states[i].borderS1.posY + shape.posY,
        shape.states[i].borderS1.width,
        shape.states[i].borderS1.height,
        shape.states[i].borderS1.color);
    DrawRectangle(
        shape.states[i].s1.posX + shape.posX,
        shape.states[i].s1.posY + shape.posY,
        shape.states[i].s1.width,
        shape.states[i].s1.height,
        shape.states[i].s1.color);

    DrawRectangle(
        shape.states[i].borderS2.posX + shape.posX,
        shape.states[i].borderS2.posY + shape.posY,
        shape.states[i].borderS2.width,
        shape.states[i].borderS2.height,
        shape.states[i].borderS2.color);
    DrawRectangle(
        shape.states[i].s2.posX + shape.posX,
        shape.states[i].s2.posY + shape.posY,
        shape.states[i].s2.width,
        shape.states[i].s2.height,
        shape.states[i].s2.color);

    DrawRectangle(
        shape.states[i].borderS3.posX + shape.posX,
        shape.states[i].borderS3.posY + shape.posY,
        shape.states[i].borderS3.width,
        shape.states[i].borderS3.height,
        shape.states[i].borderS3.color);
    DrawRectangle(
        shape.states[i].s3.posX + shape.posX,
        shape.states[i].s3.posY + shape.posY,
        shape.states[i].s3.width,
        shape.states[i].s3.height,
        shape.states[i].s3.color);
    
    DrawRectangle(
        shape.states[i].borderS4.posX + shape.posX,
        shape.states[i].borderS4.posY + shape.posY,
        shape.states[i].borderS4.width,
        shape.states[i].borderS4.height,
        shape.states[i].borderS4.color);
    DrawRectangle(
        shape.states[i].s4.posX + shape.posX,
        shape.states[i].s4.posY + shape.posY,
        shape.states[i].s4.width,
        shape.states[i].s4.height,
        shape.states[i].s4.color);
}