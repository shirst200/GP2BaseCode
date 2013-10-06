#pragma once

//interface class
class IRenderer
{
public:
	//Always has to have an empty deconstrctor
	virtual ~IRenderer(){};
	//pure functions have to be implemented
	virtual bool init(void *pWindowHandle,bool fullScreen)=0;
	virtual void clear(float r,float g,float b,float a)=0;
	virtual void present()=0;
};