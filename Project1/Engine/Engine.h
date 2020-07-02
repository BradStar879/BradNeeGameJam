#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "GLFW/glfw3.h"
#pragma comment(lib, "opengl32.lib")

#include <iostream>
using namespace std;

class Engine {

public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static double GetDT();
		
	Engine();
	~Engine();

	bool Initialize(const char * windowTitle);

	void Update();
	void BeginRender();
	void EndRender();

	void ShowMouse();
	void HideMouse();

	static float GetWidthMult();
	static float GetHeightMult();

	static bool IsMouseOver(float mouseX, float mouseY, float left, float bottom, float right, float top);

private:
	static GLFWwindow* window;

	static double dt;	//delta time
	double lastTime;
};



#endif