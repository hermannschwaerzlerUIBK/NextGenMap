#ifndef __SEQUENCELOCATION_H__
#define __SEQUENCELOCATION_H__

#include "Types.h"
#include "IRefProvider.h"

//#pragma pack(push)
//#pragma pack(2)

struct SequenceLocation
{
	uint m_Location;
	short m_RefId;

	bool used() {
		return m_Location != 0;
	}

	bool operator< (SequenceLocation const & rhs) const
	{
		if (m_Location < rhs.m_Location)
			return true;
		else if (m_Location == rhs.m_Location)
			return (m_RefId < rhs.m_RefId);
		
		return false;
	}

	SequenceLocation() {

	}

	SequenceLocation(uint const loc, short const refid) {
		m_Location = loc;
		m_RefId = refid;
	}

	SequenceLocation(Location const & other) {
		m_Location = other.m_Location;
	}
};
//#pragma pack(pop)

#endif