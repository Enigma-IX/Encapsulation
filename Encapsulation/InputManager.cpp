#include "InputManager.h"

InputManager::InputManager() {
	for (int i = 0; i < 4; ++i)
	{
		user1Keys[i] = false;
		user2Keys[i] = false;
	}
}

bool InputManager::IsKeyPressed(int user, char key) const
{
	if (user == 1) {
		switch (key) {
			case 'u': return user1Keys[0];
			case 'd': return user1Keys[0];
			case 'l': return user1Keys[0];
			case 'r': return user1Keys[0];
		}
	}
	else if (user == 2) {
		switch (key) {
			case 'z': return user1Keys[0];
			case 's': return user1Keys[0];
			case 'q': return user1Keys[0];
			case 'd': return user1Keys[0];
		}
	}
	return false;
}