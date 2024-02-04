#include "Bullet.h"
#include <Novice.h>

Bullet::Bullet()
{
	for (int i = 0; i < 10; i++) 
	{
		pos_.x[i] = { 0 };
		pos_.y[i] = { 0 };
		isShot_[i] = false;
	}
	radius_ = 10;
	speed_ = 10;
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	for (int i = 0; i < 10; i++)
	{
		if (isShot_[i] == true)
		{
			pos_.y[i] -= speed_;

			if (pos_.y[i] <=-20)
			{
				pos_.y[i] = -50;
				isShot_[i] = false;
			}
		}
	}
}

void Bullet::Draw()
{
	for (int i = 0; i < 10; i++)
	{
		if (isShot_[i] == true)
		{
			Novice::DrawBox((int)pos_.x[i], (int)pos_.y[i], (int)radius_, (int)radius_, 0.0f, RED, kFillModeSolid);
		}
	}
}