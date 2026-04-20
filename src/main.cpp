#include "raylib.h"
#include "Bubble.h"
#include <ctime>
#include <cstdlib>
#include <vector>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int bubbleCount = 5;
    const float gameTime = 30.0f;

    InitWindow(screenWidth, screenHeight, "EX6 Click the Bubble");
    SetTargetFPS(60);

    srand((unsigned int)time(nullptr));

    int score = 0;
    float timeLeft = gameTime;
    bool gameOver = false;

    std::vector<Bubble> bubbles(bubbleCount);
    for (int i = 0; i < bubbleCount; i++) {
        bubbles[i].respawn(screenWidth, screenHeight);
    }

    while (!WindowShouldClose()) {
        if (!gameOver) {
            timeLeft -= GetFrameTime();
            if (timeLeft <= 0.0f) {
                timeLeft = 0.0f;
                gameOver = true;
            }

            Vector2 mousePos = GetMousePosition();

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                for (int i = 0; i < bubbleCount; i++) {
                    if (bubbles[i].isClicked(mousePos)) {
                        score += bubbles[i].getScoreValue();
                        bubbles[i].pop();
                        bubbles[i].respawn(screenWidth, screenHeight);
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!gameOver) {
            for (int i = 0; i < bubbleCount; i++) {
                bubbles[i].draw();
            }

            DrawText("Click the Bubble!", 20, 20, 30, DARKBLUE);
            DrawText(TextFormat("Score: %d", score), 20, 60, 30, MAROON);
            DrawText(TextFormat("Time: %.1f", timeLeft), 20, 100, 30, DARKGREEN);
        }
        else {
            DrawText("Game Over", 280, 220, 50, RED);
            DrawText(TextFormat("Final Score: %d", score), 260, 300, 40, DARKBLUE);
            DrawText("Press ESC to close", 270, 360, 25, GRAY);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}