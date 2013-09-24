#include "GameApplication.h"

//should really check to see if we are on a windows platform
#include "../Window/Win32Window.h"

//constructor
CGameApplication::CGameApplication(void)
{
	//set to null
	m_pWindow=NULL;
	//Set window name to Gp2
	m_GameOptionDesc.gamename=TEXT("GP2");
	//Window heightand Width
	m_GameOptionDesc.width=640;
	m_GameOptionDesc.height=480;
	//fullscreen
	m_GameOptionDesc.fullscreen=false;
	//Config options
	m_ConfigFileName=TEXT("game.cfg");

}

//deconstructor
CGameApplication::~CGameApplication(void)
{
	//Delete things in reverse order
	if (m_pWindow)
	{
		delete m_pWindow;
		m_pWindow=NULL;
	}
}

//Init
//This initialises allsubsystems
bool CGameApplication::init()
{
	if(!parseConfigFile())
		return false;
	if(!initWindow())
		return false;
	if(!initGraphics())
			return false;
	if(!initGame())
		return false;
	return true;
}

//called to parse the config file
bool CGameApplication::parseConfigFile()
{
	return true;
}

//initInput - initialises the input system
bool CGameApplication::initInput()
{
	return true;
}

//initPhysics initialises the physics system
bool CGameApplication::initPhysics()
{
	return true;
}

//initGraphice
bool CGameApplication::initGraphics()
{
	return true;
}

//init windpw - initialised the window
bool CGameApplication::initWindow()
{
	//create a win32 window
	m_pWindow=new CWin32Window();
	m_pWindow->init(m_GameOptionDesc.gamename,m_GameOptionDesc.width,m_GameOptionDesc.height,m_GameOptionDesc.fullscreen);
	return true;
}

//called to init the game options
bool CGameApplication::initGame()
{
	return true;
}