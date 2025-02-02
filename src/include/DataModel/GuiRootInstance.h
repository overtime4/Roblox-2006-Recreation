#pragma once
#include "Instance.h"

class ImageButtonInstance;

class TextButtonInstance;

class LocalBackpackItem;

class GuiRootInstance : public Instance
{
public:
	GuiRootInstance();
	GuiRootInstance::~GuiRootInstance();
	TextButtonInstance*		makeTextButton();
	LocalBackpackItem*		makeLocalBackpackItem();
	void					drawButtons(RenderDevice* rd);
	ImageButtonInstance*	makeImageButton(G3D::TextureRef newImage, G3D::TextureRef overImage, G3D::TextureRef downImage, G3D::TextureRef disableImage);
	void					renderGUI(G3D::RenderDevice* rd, double fps);
	void					setDebugMessage(std::string msg, G3D::RealTime msgTime);
	void					update();
	bool					mouseInGUI(G3D::RenderDevice* renderDevice,int x,int y);
	void					onMouseLeftUp(G3D::RenderDevice* renderDevice, int x,int y);
private:
	std::string			_message;
	G3D::RealTime		_messageTime;
};