#include "Player.hpp"
#include "GameConfig.hpp"

Player::Player(Texture2D *tex)
{
  sprite.Init(tex);
  transform.scale = GameConfig::PLAYER_SCALE;
  movement.speed = GameConfig::PLAYER_SPEED;
}

Vector2 Player::GetPosition() const
{
  return transform.position;
}

void Player::SetPosition(Vector2 position)
{
  transform.position = position;
}

void Player::Draw() const
{
  sprite.Draw(transform);
}

void Player::Update(Vector2 moveDir, float delta)
{
  movement.Update(transform, moveDir, delta);
}
