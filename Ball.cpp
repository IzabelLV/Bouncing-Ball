#include <raylib.h>

struct Ball
{
	float x, y;
	float speedX, speedY;
	float radius;

	void Draw()
	{
		DrawCircle((int)x, (int)y, radius, WHITE);
	}
};
int main() {
	InitWindow(800, 600, "Ball");
	SetWindowState(FLAG_VSYNC_HINT);

	float ballX = GetScreenWidth() / 2;
	float ballY = GetScreenHeight() / 2;
	float ballR = 13;
	float SpeedX = 100;
	float SpeedY = 400;
	while (!WindowShouldClose()) {

		ballX += SpeedX * GetFrameTime();
		ballY += SpeedY * GetFrameTime();

		/*if (ballY > GetScreenWidth()) {
			ballY = GetScreenWidth();

			SpeedY *= 1;
		}
		*/
		if (ballX < 0) {
			ballX = 0;
			SpeedX *= -1;
		}
		if (ballX > GetScreenWidth()) {
			ballX = GetScreenWidth();
			SpeedX *= -1;
		}
		if (ballY < 0) {
			ballY = 0;
			SpeedY *= -1;
		}
		if (ballY > GetScreenHeight()) {
			ballY = GetScreenHeight();

			SpeedY *= -1;
		}
		BeginDrawing();
		ClearBackground(BLACK);
		EndDrawing();

		DrawCircle((int)ballX, (int)ballY, ballR, WHITE);
	}

	CloseWindow();
	return 0;
};