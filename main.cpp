#include <Novice.h>
#include"Player.h"
#include"Enemy.h"

const char kWindowTitle[] = "LC1B_12_コマツザキ_カガリ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player();
	Enemy* enemy = new Enemy();

	int Scene = 0;

	int TitleGH = Novice::LoadTexture("./Resource/Title.png");
	int GameOverGH = Novice::LoadTexture("./Resource/GameOver.png");

	enum scene
	{
		title,
		game,
		clear,
		gameover
	};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		switch (Scene)
		{
		case title:
			player = new Player();
			enemy = new Enemy();
			if (keys[DIK_RETURN]) 
			{
				Scene = 1;
			}
			break;
		case game:
			player->Update(keys, preKeys);
			enemy->Update();

			if (keys[DIK_R])
			{
				Scene = 0;
			}

			//弾と敵の当たり判定
			for (int i = 0; i < 10; i++)
			{
				if (player->bullet->pos_.x[i] <= enemy->GetPosX() + enemy->GetRadius() &&
					enemy->GetPosX() <= player->bullet->pos_.x[i] + player->bullet->radius_ &&
					player->bullet->pos_.y[i] <= enemy->GetPosY() + enemy->GetRadius() &&
					enemy->GetPosY() <= player->bullet->pos_.y[i] + player->bullet->radius_)
				{
					enemy->SetisEnemyAlive(false);
				}
			}

			if (player->GetisPlayerAlive() == (float)true)
			{
				if (player->GetPosX() <= enemy->GetPosX() + enemy->GetRadius() &&
					enemy->GetPosX() <= player->GetPosX() + player->GetRadius() &&
					player->GetPosY() <= enemy->GetPosY() + enemy->GetRadius() &&
					enemy->GetPosY() <= player->GetPosY() + player->GetRadius())
				{
					player->SetisPlayerAlive(false);
					Scene = 3;
				}
				else
				{
					player->SetisPlayerAlive(true);
				}
			}
			break;
		case clear:
			/*if (keys[DIK_RETURN])
			{
				Scene = 0;
			}*/
			break;
		case gameover:
			if (keys[DIK_RETURN])
			{
				Scene = 0;
			}
			break;
		default:
			break;
		}
		

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		/*Novice::ScreenPrintf(0, 0, "isEnemyAlive=%f", enemy->GetisEnemyAlive());
		Novice::ScreenPrintf(0, 15, "isPlayerAlive=%f", player->GetisPlayerAlive());
		Novice::ScreenPrintf(0, 30, "Scene=%d", Scene);*/

		switch (Scene)
		{
		case title:
			Novice::DrawSprite(320, 340, TitleGH, 1, 1, 0.0f, 0xFFFFFFFF);
			break;
		case game:
			Novice::ScreenPrintf(0, 0, "WASD : move    SPACE : bullet shot    R : title");
			player->Draw();
			enemy->Draw();
			break;
		case 2:
			/*Novice::ScreenPrintf(360, 360, "clear");
			Novice::ScreenPrintf(360, 380, "please push ENTER");*/
			break;
		case gameover:
			Novice::DrawSprite(320, 340, GameOverGH, 1, 1, 0.0f, 0xFFFFFFFF);

			break;
		}
		

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemy;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
