#include "raylib.h"

int main()
{
  InitWindow(1280, 720, "Swarm");
  SetTargetFPS(60);

  while (!WindowShouldClose())
  {
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("It works!", 24, 24, 20, WHITE);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}