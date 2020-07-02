#ifndef GAME_DESK
#define GAME_DESK

#include "../../Engine/GameStateManager/GameState.h"



class Desk: public GameState{

public:
	Desk(GameStateManager * _gsm);
	void Init(GameStateManager * _gsm) override;
	void Update() override;
	void Render() override;

private:
	Sprite background;
};




#endif