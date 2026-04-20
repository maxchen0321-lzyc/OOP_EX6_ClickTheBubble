#ifndef BUBBLE_H
#define BUBBLE_H

#include "raylib.h"

class Bubble {
private:
    Vector2 position;
    float radius;
    int scoreValue;
    bool alive;

public:
    Bubble();
    Bubble(float x, float y, float r, int score);

    void draw() const;
    bool isClicked(Vector2 mousePos) const;
    void respawn(int screenWidth, int screenHeight);

    int getScoreValue() const;
    bool isAlive() const;
    void pop();
};

#endif