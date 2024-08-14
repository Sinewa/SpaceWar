#include "InputManager.h"

#include <SFML/Window/Keyboard.hpp>

#include "src/Core/Utils/Utils.h"


namespace SWGame {
	//-----------------------------------------------------------
	void InputManager::LoadInputs() {

		InsertInput(InputFlags::Up, sf::Keyboard::Scancode::W);
		InsertInput(InputFlags::Left, sf::Keyboard::Scancode::A);
		InsertInput(InputFlags::Right, sf::Keyboard::Scancode::D);
		InsertInput(InputFlags::Down, sf::Keyboard::Scancode::S);

		InsertInput(InputFlags::RotateL, sf::Keyboard::Scancode::Q);
		InsertInput(InputFlags::RotateR, sf::Keyboard::Scancode::E);
		
		InsertInput(InputFlags::Fire, sf::Keyboard::Scancode::Space);
		InsertInput(InputFlags::Back, sf::Keyboard::Scancode::Escape);
		InsertInput(InputFlags::Confirm, sf::Keyboard::Scancode::Enter);
		InsertInput(InputFlags::Cancel, sf::Keyboard::Scancode::Escape);

		InsertInput(InputFlags::DEBUG, sf::Keyboard::Scancode::Num0);
	}
	//-----------------------------------------------------------
	void InputManager::HandleInputs() {
		m_inputFlags.ClearAll();

		for (auto& input : m_aInputPairs) {
			SetIfPressed(input.first, input.second);
		}
	}
	//-----------------------------------------------------------
	bool InputManager::IsKeyPressed(InputFlags key) {
		return m_inputFlags.IsSet(key);
	}
	//-----------------------------------------------------------
	void InputManager::SetIfPressed(InputFlags keyFlag, sf::Keyboard::Scancode pKey) {
		if (sf::Keyboard::isKeyPressed(pKey)) {
			m_inputFlags.Set(keyFlag);
		}
	}
	//-----------------------------------------------------------
	void InputManager::InsertInput(InputFlags keyFlag, sf::Keyboard::Scancode pKey) {
		m_aInputPairs.push_back(std::make_pair(keyFlag, pKey));
	}
	//-----------------------------------------------------------
	void InputManager::RemoveInput(InputFlags keyFlag, sf::Keyboard::Scancode pKey) {
		for (int i = static_cast<int>(m_aInputPairs.size()) - 1; i >= 0; i--) {
			if (m_aInputPairs[i] == std::make_pair(keyFlag, pKey)) {
				m_aInputPairs[i] = m_aInputPairs[m_aInputPairs.size() - 1];
				m_aInputPairs.pop_back();
			}
		}
	}
	//-----------------------------------------------------------
}