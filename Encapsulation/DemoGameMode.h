#pragma once
#include "GameMode.h"


class DemoGameMode : public GameMode
{
private:
	
public:
	DemoGameMode();
	~DemoGameMode();

	bool InitGameMode() override;
	void UpdateGameMode() override;
	void Draw() override;
	void EndGameMode() override;
};

