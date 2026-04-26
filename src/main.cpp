#include "raylib.h"
#include <iostream>
#include <filesystem>
#include <algorithm>
const int BASE_W = 1280;
const int BASE_H = 720;

int main()
{
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(BASE_W, BASE_H, "Swarm");
  SetTargetFPS(60);

  Texture2D background = LoadTexture("Assets/images/Floor.png");
  Texture2D walls = LoadTexture("Assets/images/Walls.png");
  // Texture2D playerTex = LoadTexture("Assets/images/survivor-idle_shotgun_0.png");

  RenderTexture2D canvas = LoadRenderTexture(BASE_W, BASE_H);
  SetTextureFilter(canvas.texture, TEXTURE_FILTER_BILINEAR);

  float mapW = (float)background.width;
  float mapH = (float)background.height;
  float halfW = BASE_W * 0.5f;
  float halfH = BASE_H * 0.5f;

  Camera2D camera = {};
  camera.zoom = 1.f;
  camera.target = {400.f, 400.f};
  camera.offset = {halfW, halfH};

  while (!WindowShouldClose())
  {

    float dt = GetFrameTime();

    float moveX = (IsKeyDown(KEY_D) ? 1.0f : 0.0f) - (IsKeyDown(KEY_A) ? 1.0f : 0.0f);
    float moveY = (IsKeyDown(KEY_S) ? 1.0f : 0.0f) - (IsKeyDown(KEY_W) ? 1.0f : 0.0f);

    camera.target.x += dt * 300.0f * moveX;
    camera.target.y += dt * 300.0f * moveY;

    camera.target.x = std::clamp(camera.target.x, halfW, mapW - halfW);
    camera.target.y = std::clamp(camera.target.y, halfH, mapH - halfH);

    BeginTextureMode(canvas);
    BeginMode2D(camera);
    ClearBackground(BLACK);
    DrawTexture(background, 0, 0, WHITE);
    // DrawTextureEx(playerTex, {400.0f, 400.0f}, 0.0f, 0.3f, WHITE);
    DrawTexture(walls, 0, 0, WHITE);
    EndMode2D();

    DrawRectangle(0, BASE_H - 32, BASE_W, 32, ColorAlpha(DARKBLUE, 0.6f));
    const char *labelText = TextFormat("Camera:%.0f,%.0f", camera.target.x, camera.target.y);
    DrawText(labelText, 12, BASE_H - 24, 20, LIME);

    EndTextureMode();

    float scale = std::min(
        (float)GetScreenWidth() / BASE_W,
        (float)GetScreenWidth() / BASE_H);

    float offsetX = (GetScreenWidth() - BASE_W * scale) * 0.5f;
    float offsetY = (GetScreenHeight() - BASE_H * scale) * 0.5f;

    Rectangle src = {0, 0, (float)BASE_W, -(float)BASE_H};
    Rectangle dest = {offsetX, offsetY, BASE_W * scale, BASE_H * scale};

    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexturePro(canvas.texture, src, dest, {0, 0}, 0.0f, WHITE);

    EndDrawing();
  }

  UnloadTexture(background);
  UnloadTexture(walls);
  // UnloadTexture(playerTex);
  UnloadRenderTexture(canvas);
  CloseWindow();
  return 0;
}