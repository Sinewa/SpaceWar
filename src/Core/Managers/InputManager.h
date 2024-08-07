#pragma once
#include <utility>
#include <vector>

#include <SFML/Window/Keyboard.hpp>

#include "src/Core/Utils/Utils.h"

namespace SWGame {
	enum InputFlags {
		Up			= BITF(0),
		Down		= BITF(1),
		Left		= BITF(2),
		Right		= BITF(3),
		Fire		= BITF(4),
		Back		= BITF(5),
		Confirm = BITF(6),
		Cancel	= BITF(7)
	};

	class InputManager {
		Flags<InputFlags> m_inputFlags;
		std::vector<std::pair<InputFlags, sf::Keyboard::Scancode>> m_aInputPairs;
	public:
		void LoadInputs();
		void HandleInputs();
		bool IsKeyPressed(InputFlags key);
	protected:
		void SetIfPressed(InputFlags keyFlag, sf::Keyboard::Scancode pKey);
		void InsertInput(InputFlags keyFlag, sf::Keyboard::Scancode pKey);
	};
}