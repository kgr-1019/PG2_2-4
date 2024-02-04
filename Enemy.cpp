#include "Enemy.h"
#include"Novice.h"
#define _USE_MATH_DEFINES
#include<math.h>

Enemy::Enemy()
{
	pos_ = { 590,0 };
	radius_ = 100;
	speed_ = 5;
	theta = (1.0 / 8.0f) * float(M_PI);
	amplitude = 70.0f;//振れ幅
	enemyEntry_ = true;
	isEnemyAlive_ = true;
	entryTimer = 100;
	resTimer = 100;

	EnemyGH = Novice::LoadTexture("./Resource/Enemy.png");
	YeahGH = Novice::LoadTexture("./Resource/Yeah.png");
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	if (isEnemyAlive_ == true)
	{
		//登場
		if (enemyEntry_ == true)
		{
			speed_ = 1;
			pos_.y += speed_;

			if (pos_.y >= 80)
			{
				pos_.y = 80;
				entryTimer--;
				speed_ = 5;
			}
			if (entryTimer <= 0)
			{
				entryTimer = 0;
				enemyEntry_ = false;
			}
		}

		if (enemyEntry_ == false)
		{
			//挙動
			pos_.x += speed_;
			pos_.y = sinf(theta) * amplitude + 80;
			theta += float(M_PI) / 50.0f;

			//移動範囲制限
			if (pos_.x <= 0)
			{
				speed_ = -speed_;
			}
			if (pos_.x >= 1180)
			{
				speed_ = -speed_;
			}
		}
	}
	//リスポーン
	if (isEnemyAlive_ == false)
	{
		resTimer--;
	}
	if (resTimer <= 0)
	{
		isEnemyAlive_ = true;
		resTimer = 100;
	}
}

void Enemy::Draw()
{
	if (resTimer < 100 && resTimer >= 0)
	{
		Novice::DrawSprite(500, 640, YeahGH, 1, 1, 0.0f, 0xFFFFFFFF);
	}

	if (isEnemyAlive_ == true) 
	{
		Novice::DrawBox((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, BLACK, kFillModeSolid);
		Novice::DrawSprite((int)pos_.x, (int)pos_.y, EnemyGH, 1, 1, 0.0f, 0xFFFFFFFF);
	}
}

void Enemy::SetPos(float posx, float posy)
{
	pos_.x = posx;
	pos_.y = posy;
}

void Enemy::SetenemyEntry(bool enemyEntry)
{
	enemyEntry_ = enemyEntry;
}

void Enemy::SetisEnemyAlive(bool isEnemyAlive)
{
	isEnemyAlive_ = isEnemyAlive;
}
