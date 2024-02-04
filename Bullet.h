#pragma once
#include"Initialize.h"

class Bullet
{
public:

	BulletPos pos_;
	float radius_;
	float speed_;
	bool isShot_[10];

public:
	Bullet();
	~Bullet();
	void Update();
	void Draw();
};