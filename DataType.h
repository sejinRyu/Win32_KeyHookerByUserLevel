#pragma once


template<class T, T min, T max> class ScopingType
{
	T value;

public:
	ScopingType(T value)
	{
		if (value > max)
			this->value = max;
		else if (value < min)
			this->value = min;
		else this->value = value;
	}
	operator T()
	{
		return value;
	}
};

#pragma region basic data type

#pragma region bit type
using Bit = bool;
using Boolean = Bit;
#pragma endregion

#pragma region signed integer type
using Byte1 = signed char;
using Byte2 = signed short;
using Byte4 = signed long;
using Byte8 = signed long long;

const Byte1 Byte1_Min = 0x80i8;
const Byte2 Byte2_Min = 0x8000i16;
const Byte4 Byte4_Min = 0x80000000i32;
const Byte8 Byte8_Min = 0x8000000000000000i64;

const Byte1 Byte1_Max = 0x7Fi8;
const Byte2 Byte2_Max = 0x7FFFi16;
const Byte4 Byte4_Max = 0x7FFFFFFFi32;
const Byte8 Byte8_Max = 0x7FFFFFFFFFFFFFFFi64;
#pragma endregion

#pragma region unsigned integer type
using uByte1 = unsigned char;
using uByte2 = unsigned short;
using uByte4 = unsigned long;
using uByte8 = unsigned long long;

const uByte1 uByte1_Min = 0x00ui8;
const uByte2 uByte2_Min = 0x0000ui16;
const uByte4 uByte4_Min = 0x00000000ui32;
const uByte8 uByte8_Min = 0x0000000000000000ui64;

const uByte1 uByte1_Max = 0xFFui8;
const uByte2 uByte2_Max = 0xFFFFui16;
const uByte4 uByte4_Max = 0xFFFFFFFFui32;
const uByte8 uByte8_Max = 0xFFFFFFFFFFFFFFFFui64;

#pragma endregion

#pragma region size type
using SizeType = uByte4;
#pragma endregion

#pragma endregion


#pragma region pointer type

#pragma endregion









