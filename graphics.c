#include "graphics.h"

inline static void
updatebg(Game* gs)
{
	BeginTextureMode(gs->backg);
		ClearBackground((Color){0,0,0,0});
	EndTextureMode();
}
inline static void
updatefg(Game* gs)
{
	float dt = GetFrameTime();

	Planet* p = gs->level[0].p;
	readinput(gs);
	if(gs->input) { // update planet coords
		if(input(gs, INPUT_UP))    p[0].y -= 165*dt;
		if(input(gs, INPUT_DOWN))  p[0].y += 165*dt;
		if(input(gs, INPUT_LEFT))  p[0].x -= 165*dt;
		if(input(gs, INPUT_RIGHT)) p[0].x += 165*dt;
		updatechild(p+1);
		updatechild(p+2);
	}

	Vector2 earthcenter = {
		gs->width/2+200*cos(dt),
		gs->height/2+200*sin(dt)
	};
	Planet earth = {
		0,
		.x = earthcenter.x,
		.y = earthcenter.y,
		.size = 50,
	};
	Vector2 moon = {
		earth.x+50*cos(dt*5),
		earth.y+50*sin(dt*5)
	};

	BeginTextureMode(gs->foreg);
		ClearBackground((Color){0,0,0,0});
		DrawCircle(p[0].x, p[0].y, p[0].size, BLACK);
		DrawCircle(p[1].x, p[1].y, p[1].size, BLACK);
		DrawCircle(p[2].x, p[2].y, p[2].size, BLACK);

	EndTextureMode();
}

inline static void
drawbg(Game* gs)
{
	DrawTexture(gs->backg.texture, 0,0, WHITE);
}
inline static void
drawfg(Game* gs)
{
	DrawTexture(gs->foreg.texture, 0,0, WHITE);
}
inline static void
drawui(Game* gs)
{
	DrawTexture(gs->uig.texture, 0,0, WHITE);
}

void
UpdateFrame(Game* gs)
{
	updatebg(gs);
	updatefg(gs);

	BeginTextureMode(gs->frame);
		ClearBackground(WHITE);
		drawbg(gs);
		drawfg(gs);
		drawui(gs);
	EndTextureMode();
}

void
DrawFrame(const Game* gs)
{
	const float scale =
		fminf((float)GetScreenWidth()/gs->width,
				(float)GetScreenHeight()/gs->height);
	BeginDrawing();
		ClearBackground(BLACK);
		DrawTexturePro(
				gs->frame.texture,
				(Rectangle){
					0.0f, 0.0f,
					(float)gs->frame.texture.width,
					(float)gs->frame.texture.height },
				(Rectangle){
					(GetScreenWidth() - ((float)gs->width * scale)) * 0.5f,
					(GetScreenHeight() - ((float)gs->height * scale)) * 0.5f,
					(float)gs->width * scale,
					(float)gs->height * scale },
				(Vector2){ 0, 0 }, 0.0f, WHITE);
	EndDrawing();
}

