#pragma once
#include <cstdint>
#include <cstdlib>

namespace SWGame {
template<typename TBit>
constexpr auto BITF(TBit x) { return 1 << x; }
//-----------------------------------------------------------
//-----------------------------------------------------------

template<typename Degree>
constexpr auto ToRadians(Degree x) { return x * (3.141592653589793238463 / 180.f); }

template<typename Radian>
constexpr auto ToDegrees(Radian x) { return x * (180.0 / 3.141592653589793238463); }

struct Random {
	static float GetRandomFloat01() {
		return static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
	}

	static int GetRandomInt() {
		return rand();
	}
};

template<typename TEnum>
class Flags {
	uint32_t m_Flags = 0;
public:
	bool IsSet(TEnum flag) const {
		return m_Flags & flag; 
	}
	//-----------------------------------------------------------
	void Set(TEnum flags) 
	{ 
		m_Flags |= flags;
	}
	//-----------------------------------------------------------
	void Clear(TEnum flags) {
		m_Flags &= ~flags;
	}
	//-----------------------------------------------------------
	void ClearAll() {
		m_Flags = 0;
	}
};
}