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

private:
	static GLFWwindow* window;

	static double dt;	//delta time
	double lastTime;
};



#endif