#include "Bubble.h"
#include "raylib.h"
#include <cstdlib>

Bubble::Bubble() {
    position = {100, 100};
    radius = 30.0f;
    scoreValue = 10;
    alive = true;
}

Bubble::Bubble(float x, float y, float r, int score) {
    position = {x, y};
    radius = r;
    scoreValue = score;
    alive = true;
}

void Bubble::draw() const {
    if (alive) {
        DrawCircleV(position, radius, SKYBLUE);
        DrawCircleLines((int)position.x, (int)position.y, radius, BLUE);
    }
}

bool Bubble::isClicked(Vector2 mousePos) const {
    if (!alive) return false;
    return CheckCollisionPointCircle(mousePos, position, radius);
}

void Bubble::respawn(int screenWidth, int screenHeight) {
    position.x = (float)(50 + rand() % (screenWidth - 100));
    position.y = (float)(50 + rand() % (screenHeight - 100));
    radius = (float)(20 + rand() % 31);
    scoreValue = 100 / (int)radius;
    if (scoreValue < 1) scoreValue = 1;
    alive = true;
}

int Bubble::getScoreValue() const {
    return scoreValue;
}

bool Bubble::isAlive() const {
    return alive;
}

void Bubble::pop() {
    alive = false;
}