#pragma once
#include"Vector2.h"
#include"Player.h"

class Enemy
{
public:
	Vector2 pos_;
	float radius_;
	float speed_;
	bool enemyEntry_;
	bool isEnemyAlive_;
	float theta;
	float amplitude;
	float entryTimer;
	float resTimer;

	int EnemyGH;
	int YeahGH;

public:
	Enemy();
	~Enemy();
	void Update();
	void Draw();

	float GetPosX() { return pos_.x; }
	float GetPosY() { return pos_.y; }
	float GetRadius() { return radius_; }
	float GetSpeed() { return speed_; }
	float GetisEnemyEntry() { return enemyEntry_; }
	float GetisEnemyAlive() { return isEnemyAlive_; }
	void SetPos(float posx, float posy);
	void SetenemyEntry(bool enemyEntry);
	void SetisEnemyAlive(bool isEnemyAlive);
};