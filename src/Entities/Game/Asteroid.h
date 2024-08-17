#pragma once 

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	class Asteroid : public BaseEntity {
	
	public:
		virtual void OnDelete() override;
	};
}