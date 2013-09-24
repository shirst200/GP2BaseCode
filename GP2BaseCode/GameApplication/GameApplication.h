//headerguard, so this file is only compiled once
#pragma once

#include <string>

using namespace std;

//forward declaration of our windows interface
class IWindow;

//structure for holding GameOptions, this will be loaded from config files
struct GameOptionsDesc
{
	wstring gamename;
	int width;
	int height;
	bool fullscreen;
};

//we have this all so we dont have to  prefix all
//standard libuary types with std::
using namespace std;
//our Game Application Class
class CGameApplication
{
public:
	CGameApplication(void);
	//virtual deconstructure, so this class can be overridden
	virtual ~CGameApplication(void);
	//virtual funvtion for overriding
	virtual bool init();
	void run();
	//virtual function can be overridden
	virtual void render();
	//virtual function can be overridden
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
	GameOptionsDesc m_GameOptionDesc;
	wstring m_ConfigFileName;
};