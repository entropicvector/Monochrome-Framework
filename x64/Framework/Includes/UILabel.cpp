#include "UILabel.h"

// Default Constructor
UILabel::UILabel(UIWindow* srcWindow)
{
	this->srcWindow = srcWindow;
}

UILabel::UILabel(UIWindow* srcWindow, std::string text)
{
	this->srcWindow = srcWindow;
	this->Text = text;
}

UILabel::UILabel(UIWindow* srcWindow, std::string text, std::string fontName)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
}

UILabel::UILabel(UIWindow* srcWindow, std::string text, std::string fontName, int FontSize)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
}

UILabel::UILabel(UIWindow* srcWindow, std::string text, std::string fontName, int FontSize, float xPos, float yPos, float Width, float Height)
{
	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
}

UILabel::UILabel(UIWindow* srcWindow, std::string text, std::string fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, Color color) {

	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->color = color;
}

UILabel::UILabel(UIWindow* srcWindow, std::string text, std::string fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, Color color, float stroke) {

	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->color = color;
	this->Stroke = stroke;
}

UILabel::UILabel(UIWindow* srcWindow, std::string text, std::string fontName,
	int FontSize, float xPos, float yPos, float Width, float Height, Color color, float stroke, float margins) {

	this->srcWindow = srcWindow;
	this->Text = text;
	this->FontName = fontName;
	this->FontSize = FontSize;
	this->xPos = xPos;
	this->yPos = yPos;
	this->Width = Width;
	this->Height = Height;
	this->color = color;
	this->Stroke = stroke;
	this->Margins = margins;
}


UILabel::~UILabel()
{
}

void UILabel::Draw()
{
	this->srcWindow->GetGraphics()->DrawRectangle(xPos, yPos, Width, Height, color.r, color.g, color.b, color.a, Stroke, Filled);

	DWRITE_TEXT_ALIGNMENT textAllignment;
	DWRITE_PARAGRAPH_ALIGNMENT paragraphAllignment;
	MakeTextAllignment(this->TextAllignment, textAllignment, paragraphAllignment);

	this->srcWindow->GetGraphics()->drawText(Text, FontName, FontSize,
		xPos+Margins, yPos+Margins, Width-Margins, Height-Margins, textColor.r, textColor.g, textColor.b, textColor.a,
		textAllignment, paragraphAllignment);
}
