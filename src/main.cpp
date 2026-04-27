#include "raylib.h"
#include <iostream>
#include <filesystem>
#include <algorithm>
#include "GameConfig.hpp"
#include "Sprite.hpp"

int main()
{
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(GameConfig::BASE_W, GameConfig::BASE_H, "Swarm");
  SetTargetFPS(60);

  Texture2D background = LoadTexture("Assets/images/Floor.png");
  Texture2D walls = LoadTexture("Assets/images/Walls.png");
  Texture2D playerTex = LoadTexture("Assets/tds_textures/citizenplayer_handgun.png");

  RenderTexture2D canvas = LoadRenderTexture(GameConfig::BASE_W, GameConfig::BASE_H);
  SetTextureFilter(canvas.texture, TEXTURE_FILTER_BILINEAR);

  float mapW = (float)background.width;
  float mapH = (float)background.height;
  float halfW = GameConfig::BASE_W * 0.5f;
  float halfH = GameConfig::BASE_H * 0.5f;

  Camera2D camera = {};
  camera.zoom = 1.f;
  camera.target = {400.f, 400.f};
  camera.offset = {halfW, halfH};

  Transform2D playerTransform;
  playerTransform.position = {mapW * 0.5f, mapH * 0.5f};
  playerTransform.scale = GameConfig::PLAYER_SCALE;

  Sprite playerSprite;
  playerSprite.Init(&playerTex);

  while (!WindowShouldClose())
  {

    if (IsKeyPressed(KEY_F1))
      Sprite::showDebug = !Sprite::showDebug;

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
    playerSprite.Draw(playerTransform);
    DrawTexture(walls, 0, 0, WHITE);
    EndMode2D();

    DrawRectangle(0, GameConfig::BASE_H - 32, GameConfig::BASE_W, 32, ColorAlpha(DARKBLUE, 0.6f));
    const char *labelText = TextFormat("Camera:%.0f,%.0f", camera.target.x, camera.target.y);
    DrawText(labelText, 12, GameConfig::BASE_H - 24, 20, LIME);

    EndTextureMode();

    float scale = std::min(
        (float)GetScreenWidth() / GameConfig::BASE_W,
        (float)GetScreenWidth() / GameConfig::BASE_H);

    float offsetX = (GetScreenWidth() - GameConfig::BASE_W * scale) * 0.5f;
    float offsetY = (GetScreenHeight() - GameConfig::BASE_H * scale) * 0.5f;

    Rectangle src = {0, 0, (float)GameConfig::BASE_W, -(float)GameConfig::BASE_H};
    Rectangle dest = {offsetX, offsetY, GameConfig::BASE_W * scale, GameConfig::BASE_H * scale};

    BeginDrawing();
    ClearBackground(BLACK);
    DrawTexturePro(canvas.texture, src, dest, {0, 0}, 0.0f, WHITE);

    EndDrawing();
  }

  UnloadTexture(background);
  UnloadTexture(walls);
  UnloadTexture(playerTex);
  UnloadRenderTexture(canvas);
  CloseWindow();
  return 0;
}