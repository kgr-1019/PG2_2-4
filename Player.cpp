#include "Player.h"
#include "Novice.h"

Player::Player()
{
	pos_ = { 610, 470 };
	radius_ = 60;
	speed_ = 5;
	isPlayerAlive_ = true;

	PlayerGH = Novice::LoadTexture("./Resource/Player.png");

	//包含
	bullet = new Bullet();
}

Player::~Player()
{
	delete bullet;
}

void Player::Update(char* keys,char *preKeys)
{
	//移動
	if (keys[DIK_W])
	{
		pos_.y -= speed_;
	}
	if (keys[DIK_S])
	{
		pos_.y += speed_;
	}
	if (keys[DIK_A])
	{
		pos_.x -= speed_;
	}
	if (keys[DIK_D])
	{
		pos_.x += speed_;
	}

	//移動範囲制限
	if (pos_.x<= 0)
	{
		pos_.x = 0;
	}
	if (pos_.x >= 1220)
	{
		pos_.x = 1220;
	}
	if (pos_.y<= 0)
	{
		pos_.y = 0;
	}
	if (pos_.y >= 660)
	{
		pos_.y = 660;
	}

	//弾発射
	for (int i = 0; i < 10; i++) 
	{
		if (bullet->isShot_[i]==false)
		{
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				bullet->pos_.x[i] = pos_.x+25;
				bullet->pos_.y[i] = pos_.y;
				bullet->isShot_[i] = true;
				break;
			}
		}
	}
	bullet->Update();
}

void Player::Draw()
{
	bullet->Draw();
	if (isPlayerAlive_ == true)
	{
		Novice::DrawBox((int)pos_.x, (int)pos_.y, (int)radius_, (int)radius_, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawSprite((int)pos_.x, (int)pos_.y, PlayerGH, 1, 1, 0.0f, 0xFFFFFFFF);
	}
}

void Player::SetPos(float posx, float posy)
{
	pos_.x = posx;
	pos_.y = posy;
}

void Player::SetisPlayerAlive(bool isPlayerAlive)
{
	isPlayerAlive_ = isPlayerAlive;
}