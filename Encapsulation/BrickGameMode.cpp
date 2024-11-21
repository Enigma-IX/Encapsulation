#include "BrickGameMode.h"

BrickGameMode::BrickGameMode()
{
}

BrickGameMode::~BrickGameMode()
{

}

bool BrickGameMode::InitGameMode()
{
	fpsCounter = new FPSCounter();
  
	scoreCounter = new ScoreCounter(WIN_WIDTH / 4, WIN_HEIGHT);
	ball = new Ball(WIN_WIDTH / 2, WIN_HEIGHT / 2);

	player1 = new Player(1, WIN_WIDTH / 2, WIN_HEIGHT - 50, false);

	InitBricks();

	return true;
}

void BrickGameMode::InitBricks() {
	const int rows = 5;
	const int cols = 10;

	float brickWidth = WIN_WIDTH / cols;
	float brickHeight = 30.0f; // Hauteur arbitraire

	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			float x = col * brickWidth;
			float y = row * brickHeight;
			bricks.push_back(new Brick(x, y, brickWidth - 5.0f, brickHeight - 5.0f)); // Ajout d'un petit espacement
		}
	}
}


void BrickGameMode::UpdateGameMode()
{
	ball->Update();
	fpsCounter->Update();
	scoreCounter->Update();

	player1->Update();

}

void BrickGameMode::Draw()
{
	for (auto brick : bricks) {
		brick->Draw();
	}

	ball->Draw();
	fpsCounter->Draw();
	scoreCounter->Draw();

	player1->Draw();
}

void BrickGameMode::CheckCollision()
{
	if (ball->CheckCollisionWithPlayer(player1))
	{
		ball->InvertDirectionY(); 
	}

	if (ball->CheckCollisionWithTopWall())
	{
		ball->InvertDirectionY(); 
	}

	if (ball->CheckCollisionWithLeftWall() || ball->CheckCollisionWithRightWall())
	{
		ball->InvertDirectionX();
	}

	if (ball->CheckCollisionWithBottomWall())
	{
		ball->Reset();
	}

	for (auto brick : bricks) {
		if (!brick->IsDestroyed() && brick->CheckCollisionWithBall(ball->GetSprite())) {
			brick->Destroy();
			ball->InvertDirectionY(); 
			break; 
		}
	}
}

void BrickGameMode::EndGameMode()
{
	//TO DO: Logique de fin de partie
}

void BrickGameMode::WipeGameMode()
{
	delete ball;
	delete fpsCounter;
	delete scoreCounter;

	delete player1;

	for (auto brick : bricks) {
		delete brick;
	}
	bricks.clear();

}

