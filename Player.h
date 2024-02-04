#pragma once
#include"Vector2.h"
#include"Bullet.h"
#include"Enemy.h"

class Player
{
private:

	Vector2 pos_;
	//Vector2 velo_;
	//Vector2 acc_;
	float radius_;
	float speed_;
	bool isPlayerAlive_;

	int PlayerGH;

public:

	Player();
	~Player();
	void Update(char *keys, char *preKeys);
	void Draw();

	float GetPosX() { return pos_.x; }
	float GetPosY() { return pos_.y; }
	float GetRadius() { return radius_; }
	float GetSpeed() { return speed_; }
	float GetisPlayerAlive() { return isPlayerAlive_; }
	void SetPos(float posx, float posy);
	void SetisPlayerAlive(bool isPlayerAlive);
	Bullet *bullet;
};