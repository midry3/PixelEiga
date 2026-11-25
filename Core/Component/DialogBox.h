#pragma once
#include <Component/Component.h>
#include "Label.h"
#include <memory>

#include <string>

namespace PixelEiga
{
	class DialogBox : public Component
	{
	private:
		std::unique_ptr<Label> _speakerLabel, _textLabel;
	protected:
		Vec2 _speakerPosition = Vec2(0.0, 0.0);
		Vec2 _textPosition = Vec2(0.0, 0.0);
		Vec2 _textBoxPosition = Vec2(0.0, 0.0);
		Vec2 _textBoxSize = Vec2(400.0, 200.0);
		std::string _speaker, _showText;
		int _currentCharIndex = 0;
		float _time = 0.0f;
		float _textInterval = 0.1f;
	public:
		DialogBox(AppState* appState) : Component(appState) {}
		~DialogBox() = default;

		void Initialize() override;
		void Update(float dt) override;
		void Draw() override;

		void ShowText(const std::string& speaker, const std::string& text);
		void SetTextInterval(float interval) { _textInterval = interval; }
		void SetSpeakerPosition(const Vec2& position);
		void SetTextPosition(const Vec2& position);
		void SetTextBoxPosition(const Vec2& position) { _textBoxPosition = position; }
		void SetTextBoxSize(const Vec2& size) { _textBoxSize = size; }
		[[nodiscard]] const Vec2& GetTextBoxPosition() const { return _textBoxPosition; }
		[[nodiscard]] const Vec2& GetTextBoxSize() const { return _textBoxSize; }
		[[nodiscard]] const Vec2& GetSpeakerPosition() const { return _speakerPosition; }
		[[nodiscard]] const Vec2& GetTextPosition() const { return _textPosition; }
		[[nodiscard]] float GetTextInterval() const { return _textInterval; }

		[[nodiscard]] const std::string& GetSpeaker() const { return _speaker; }
		[[nodiscard]] const std::string& GetShowText() const { return _showText; }
	};
}