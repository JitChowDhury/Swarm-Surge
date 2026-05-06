#pragma once

#include "raylib.h"
#include "Transform2D.hpp"
#include "Sprite.hpp"
#include "Movement.hpp"

class CollisionMap;

class Player
{
private:
  Transform2D transform;
  Sprite sprite;
  Movement movement;
  const CollisionMap *collisionMap = nullptr;

public:
  Player(Texture2D *tex);
  void Draw() const;
  void Update(Vector2 moveDir, float delta);
  Vector2 GetPosition() const;
  void SetPosition(Vector2 position);
  void SetCollisionMap(const CollisionMap *collisionMap);
};
