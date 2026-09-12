#pragma once
#include "raylib.h"

typedef enum {
// at most 8 elements
	INPUT_UP = 0,
	INPUT_DOWN,
	INPUT_LEFT,
	INPUT_RIGHT,
	INPUT_ACT,
	INPUT_BACK,
	INPUT_RESET,
} ControlInput;

typedef struct Planet {
	struct Planet* parent;
	int dist; // from parent
	float rot;  // angle from parent
	float rotd; // rotation speed
	float x;  // center x & y
	float y;
	int size; // for collision & draw
} Planet;

typedef struct Level {
	Texture2D backg;
	Planet p[5]; // at most 5 planets total
	int psize;
} Level;

typedef struct Game {
	int width; // virt. width & height
	int height;
	Level level[4]; // levels
	int curlvl; // current level
	char input;

	RenderTexture2D backg;
	RenderTexture2D foreg;
	RenderTexture2D uig;
	RenderTexture2D frame; // above textures summed
} Game;

