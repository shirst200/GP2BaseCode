#include "GameApplication.h"

//should check to see if we are on a windows platform
#include"../Window/Win32Window.h"

//constrctor
CGameApplication::CGameApplication(void)
{
	//set to null
	m_pWindow=NULL;
	//set the window name to GP2
	m_GameOptionDesc.gameName=TEXT("GP2");
	//window hight and width
	m_GameOptionDesc.width=640;
	m_GameOptionDesc.height=480;
	//fullscreen
	m_GameOptionDesc.fullscreen=false;
	//config options
	m_ConfigFileName=TEXT("game.cfg");
}

//deconstructor
CGameApplication::~CGameApplication(void)
{
	//deletethings in reverse order
	if (m_pWindow)
	{
		delete m_pWindow;
		m_pWindow=NULL;
	}
}

//Init
//This initialises all subsystems
bool CGameApplication::init()
{
	if(!parseConfigFile())
		return false;
	if (!initWindow())
		return false;
	if (!initGraphics())
		return false;
	if (!initInput())
		return false;
	if (!initGame())
		return false;
	return true;
}

