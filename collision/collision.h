#pragma once

#include "../store/store.h"
#include "../shape/shape.h"

bool moveLeftCollides(struct Shape *fallingShape);

bool moveRightCollides(struct Shape *fallingShape);

bool moveDownCollides(struct Shape *fallingShape);

bool rotateCollides(struct Shape *fallingShape);