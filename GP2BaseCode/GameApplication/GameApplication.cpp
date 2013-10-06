#include "GameApplication.h"

//should check to see if we are on a windows platform
#include"C:/Users/Sam Hirst/Desktop/prog/Lab1/GP2BaseCode/GP2BaseCode/Window/Win32Window.h"
#include"C:/Users/Sam Hirst/Desctop/prog/Lab1/GP2BaseCode/GP2BaseCode/D3D10Renderer/D3D10Renderer.h"

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
//init
//this initialises all subsystems
bool CGameApplication::init()
{
	if(!parseConfigFile())
		return false;
	if(!initWindow())
		return false;
	if(!initGraphics())
		return false;
	if(!initInput())
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

//initInput - Initialises the input
bool CGameApplication::initInput()
{
	return true;
}

//initPhysics - Initalises the physics system
bool CGameApplication::initPhysics()
{
	return true;
}

//initGraphics - initialises the graphics subsystem
bool CGameApplication::initGraphics()
{
	//Check our settings first so wh know how to run
	m_pRenderer=new D3D10Renderer();
	if(!m_pRenderer->init(m_pWindow->getHandleToWindow(),m_GameOptionDesc.fullscreen))
		return false;
	return true;
}

//initWindow - initialises the window
bool CGameApplication::initWindow()
{
	//create a win 32 window
	m_pWindow=new CWin32Window();
	m_pWindow->init(m_GameOptionDesc.gameName,m_GameOptionDesc.width,m_GameOptionDesc.height,m_GameOptionDesc.fullscreen);
	return true;
}

//called to initialise the game elements
bool CGameApplication::initGame()
{
	return true;
}

//called to put the game in a loop(aka game loop)
void CGameApplication::run()
{
	//while the window is not closed
	while(m_pWindow->running())
	{
		//check for all window messages
		m_pWindow->checkForWindowMessages();
		//update
		update();
		//render
		render();
	}
}

//render, called to draw one frame of the game
void CGameApplication::render()
{
	m_pRenderer->clear(1.0f,0.0f,0.0f,1.0f);

	m_pRenderer->present();
}

//update, called to update the game
void CGameApplication::update()
{

}