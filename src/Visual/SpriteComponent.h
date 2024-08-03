#pragma once
#include <iostream>


#include "src/Core/Component.h"


namespace SWGame {
	class SpriteComponent : public Component {
	public:
		void Test() const {
			std::cout << "Test message" << std::endl;
		}
	};
}