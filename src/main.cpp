#include "raylib.h"
#include <iostream>
#include <filesystem>

int main()
{
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(1280, 720, "Swarm");
  SetTargetFPS(60);

  Texture2D background = LoadTexture("Assets/images/Floor.png");
  Texture2D walls = LoadTexture("Assets/images/Walls.png");

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(walls, 0, 0, WHITE);
    DrawText("", 24, 24, 20, WHITE);

    EndDrawing();
  }

  UnloadTexture(background);
  CloseWindow();
  return 0;
}