#pragma once
class InputManager
{
public:
	virtual ~InputManager() = default;
	virtual void Update() = 0;
	bool IsKeyPressed(int user, char) const = 0;

protected:
	InputManager();

	bool user1Keys[4];
	bool user2Keys[4];
};

