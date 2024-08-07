#pragma once
#include <cstdint>

namespace SWGame {
template<typename TBit>
constexpr auto BITF(TBit x) { return 1 << x; }
//-----------------------------------------------------------
//-----------------------------------------------------------

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