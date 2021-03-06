#include "Engine.h"
#include "IO/Mouse.h"
#include "IO/Keyboard.h"

int Engine::SCREEN_WIDTH = 1280;
int Engine::SCREEN_HEIGHT = 720;
GLFWwindow* Engine::window = NULL;
double Engine::dt = 0;

Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::Initialize(const char* windowTitle) {

	if (!glfwInit()) {
		cout << "Error initializing GLFW" << endl;
		return false;
	}
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL) {
		cout << "Error creating window" << endl;
		return false;
	}

	//GLFW Setup
	glfwMakeContextCurrent(window);
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);	//Swaps buffer every frame

	glfwSetCursorPosCallback(window, Mouse::MousePosCallback);
	glfwSetMouseButtonCallback(window, Mouse::MouseButtonCallback);
	glfwSetKeyCallback(window, Keyboard::KeyCallback);

	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode-> width - SCREEN_WIDTH) / 2;
	int yPos = (mode-> height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	//GL Setup
	//Viewport
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -10, 10);
	glDepthRange(-10, 10);
	glMatrixMode(GL_MODELVIEW);


	//Alpha Blending
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lastTime = glfwGetTime();

	return true;
}

void Engine::Update() {
	double curTime = glfwGetTime();
	dt = curTime - lastTime;
	lastTime = curTime;
	glfwGetWindowSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT);
	glfwPollEvents();
	if (glfwWindowShouldClose(window)) {
		glfwTerminate();
	}

}

void Engine::BeginRender() {

	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

void Engine::EndRender() {

	glfwSwapBuffers(window);
}

void Engine::ShowMouse() {
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

void Engine::HideMouse() {
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

double Engine::GetDT() {
	return dt;
}

float Engine::GetWidthMult() {
	return ((float)SCREEN_WIDTH) / 1920;
}

float Engine::GetHeightMult() {
	return ((float)SCREEN_HEIGHT) / 1080;
}

bool Engine::IsMouseOver(float mouseX, float mouseY, float left, float bottom, float right, float top) {
	return mouseX >= left && mouseX <= right && mouseY >= bottom && mouseY <= top;
}