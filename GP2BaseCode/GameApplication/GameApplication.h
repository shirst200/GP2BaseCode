//Header guard so this file is only compiled once
#pragma once

//brings in the functions defined in string ie wstring
#include <string>

using namespace std;

//Forward declaration of o;ur window interface
class IWindow;
class IRenderer;

//Structure for holding Game Options, this will be loaded form config files
struct GameOptionsDesc
{
	//wstring is a string of wide charactors
	wstring gameName;
	int width;
	int height;
	bool fullscreen;
};

//we have used this here so we don't need to prefix all standard libuary types with std::
using namespace std;

//Our game application class
class CGameApplication
{
public:
	CGameApplication(void);
	//virtual deconstructor, so this class can be overridden
	virtual ~CGameApplication(void);
	virtual bool init();
	void run();
	//virtual functions can be overridden
	virtual void render();
	virtual void update();
private:
	bool parseConfigFile();
	bool initInput();
	bool initGame();
	bool initGraphics();
	bool initPhysics();

	bool initWindow();
private:
	IWindow * m_pWindow;
	IRenderer * m_pRenderer;
	GameOptionsDesc m_GameOptionDesc;
	wstring m_ConfigFileName;
};