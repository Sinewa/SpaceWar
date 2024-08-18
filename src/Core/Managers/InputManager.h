#pragma once
#include <utility>
#include <vector>

#include <SFML/Window/Keyboard.hpp>

#include "src/Core/Utils/Utils.h"

namespace SWGame {
	enum InputFlags {
		Up = BITF(0),
		Down = BITF(1),
		Left = BITF(2),
		Right = BITF(3),
		Fire = BITF(4),
		Back = BITF(5),
		Confirm = BITF(6),
		Cancel = BITF(7),
		RotateL = BITF(8),
		RotateR = BITF(9),
		DEBUG = BITF(10)
	};

	class InputManager {
		Flags<InputFlags> m_pressedFlags;
		Flags<InputFlags> m_justPressedFlags;
		std::vector<std::pair<InputFlags, sf::Keyboard::Scancode>> m_aInputPairs;
	public:
		void LoadInputs();
		void HandleInputs();
		bool IsKeyPressed(InputFlags key);
		bool WasKeyJustPressed(InputFlags key);
	protected:
		void SetIfPressed(InputFlags keyFlag, sf::Keyboard::Scancode pKey);
		void SetIfJustPressed(InputFlags keyFlag, sf::Keyboard::Scancode pKey);
		void InsertInput(InputFlags keyFlag, sf::Keyboard::Scancode pKey);
		void RemoveInput(InputFlags keyFlag, sf::Keyboard::Scancode pKey);
	};
}