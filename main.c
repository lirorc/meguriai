#include "raylib.h"
#include "raymath.h"

#include "struct.h"
#include "graphics.h"

Game gs = {
	0,
	.width = 1680,
	.height = 1050,
	.level[0] = {
		.p[0].x=1680/2,
		.p[0].y=1050/2,
		.p[0].size=30,
		.p[1].parent=gs.level[0].p,
		.p[1].dist=80,
		.p[1].rotd=0.3,
		.p[1].size=12,
		.p[2].parent=gs.level[0].p+1,
		.p[2].dist=25,
		.p[2].rotd=1,
		.p[2].size=5,
	}
};

int
main()
{
	ChangeDirectory(GetApplicationDirectory());
	//ChangeDirectory("assets");

	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
	InitWindow(1680, 1050, "meguriai");

	gs.backg = LoadRenderTexture(gs.width, gs.height);
	gs.foreg = LoadRenderTexture(gs.width, gs.height);
	gs.uig   = LoadRenderTexture(gs.width, gs.height);

	gs.frame = LoadRenderTexture(gs.width, gs.height);
	SetTextureFilter(gs.frame.texture, TEXTURE_FILTER_BILINEAR);

	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		UpdateFrame(&gs);
		DrawFrame(&gs);
	}

	UnloadRenderTexture(gs.backg);
	UnloadRenderTexture(gs.foreg);
	UnloadRenderTexture(gs.uig);
	UnloadRenderTexture(gs.frame);

	CloseWindow();
	return 0;
}

