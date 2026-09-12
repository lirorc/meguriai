#include "input.h"

void
readinput(Game *gs)
{
	gs->input = 0;
	if (
			IsKeyDown(KEY_UP) ||
			IsKeyDown(KEY_W) ||
			IsGamepadButtonDown(0,
				GAMEPAD_BUTTON_LEFT_FACE_UP))
		gs->input |= 1<<INPUT_UP;
	if (
			IsKeyDown(KEY_DOWN) ||
			IsKeyDown(KEY_S) ||
			IsGamepadButtonDown(0,
				GAMEPAD_BUTTON_LEFT_FACE_DOWN))
		gs->input |= 1<<INPUT_DOWN;
	if (
			IsKeyDown(KEY_LEFT) ||
			IsKeyDown(KEY_A) ||
			IsGamepadButtonDown(0,
				GAMEPAD_BUTTON_LEFT_FACE_LEFT))
		gs->input |= 1<<INPUT_LEFT;
	if (
			IsKeyDown(KEY_RIGHT) ||
			IsKeyDown(KEY_D) ||
			IsGamepadButtonDown(0,
				GAMEPAD_BUTTON_LEFT_FACE_RIGHT))
		gs->input |= 1<<INPUT_RIGHT;
	if (
			IsKeyDown(KEY_SPACE) ||
			IsKeyDown(KEY_ENTER) ||
			IsGamepadButtonDown(0,
				GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
		gs->input |= 1<<INPUT_ACT;
	if (
			IsKeyDown(KEY_BACKSPACE) ||
			IsKeyDown(KEY_ESCAPE) ||
			IsGamepadButtonDown(0,
				GAMEPAD_BUTTON_RIGHT_FACE_RIGHT))
		gs->input |= 1<<INPUT_BACK;
	if (
			IsKeyDown(KEY_R) ||
			IsGamepadButtonDown(0,
				GAMEPAD_BUTTON_RIGHT_FACE_UP))
		gs->input |= 1<<INPUT_RESET;
}

bool
input(Game *gs, ControlInput n)
{
	return gs->input & 1<<n;
}

