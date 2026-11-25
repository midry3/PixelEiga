#include "DialogBox.h"

namespace PixelEiga
{
	void  DialogBox::Initialize()
	{
		_speakerLabel = std::make_unique<Label>(GetAppState());
		_textLabel = std::make_unique<Label>(GetAppState());
		_speakerLabel->SetPosition(_speakerPosition);
		_textLabel->SetFont(GetFontManager()->Get(0)->CreateFont(36.0f));
		_textLabel->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
		_textLabel->SetText("abcd");
		_textLabel->SetPosition(_textPosition);
		_textLabel->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f });
	}

	void DialogBox::Update(float dt)
	{
		_time += dt;
		if (_textInterval <= _time) {
			_currentCharIndex = Min(_showText.size(), _currentCharIndex + 1);
			_time = 0.0f;
		}
	}

	void DialogBox::Draw()
	{
		SDL_SetRenderDrawBlendMode(GetDrawing()->GetRenderer(), SDL_BLENDMODE_BLEND);

		_textLabel->Draw();
		//GetDrawing()->DrawRect(_textBoxPosition, _textBoxSize, {0.0, 0.0, 1.0, 0.5});

	}

	void DialogBox::ShowText(const std::string& speaker, const std::string& text)
	{
		_speaker = speaker;
		_showText = text;
	}

	void DialogBox::SetSpeakerPosition(const Vec2& position)
	{
		_speakerPosition = position;
		_speakerLabel->SetPosition(_speakerPosition);
	}

	void DialogBox::SetTextPosition(const Vec2& position)
	{
		_textPosition = position;
		_textLabel->SetPosition(_textPosition);
	}
}