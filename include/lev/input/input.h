#pragma once

#include <lev/math/vec2.h>
#include <lev/math/float2.h>

namespace Lev
{
	namespace Input
	{
		constexpr int MAX_TEXT_INPUT = 256;
	}

	// i hate c++ enum classes so much
	// its like this great idea and then they go "no screw you this is too good"
	// and make it so you have to type cast the crap out of them
	// ...
	// why?????????????????????
	// ...
	// i could just use a struct instead with static consts but then that looks super messy aswell :((

	enum class MouseButton
	{
		Left = 0,
		Middle = 1,
		Right = 2,
		Max
	};

	enum class Key
	{
		Unknown = 0,
		A = 4,
		B = 5,
		C = 6,
		D = 7,
		E = 8,
		F = 9,
		G = 10,
		H = 11,
		I = 12,
		J = 13,
		K = 14,
		L = 15,
		M = 16,
		N = 17,
		O = 18,
		P = 19,
		Q = 20,
		R = 21,
		S = 22,
		T = 23,
		U = 24,
		V = 25,
		W = 26,
		X = 27,
		Y = 28,
		Z = 29,
		D1 = 30,
		D2 = 31,
		D3 = 32,
		D4 = 33,
		D5 = 34,
		D6 = 35,
		D7 = 36,
		D8 = 37,
		D9 = 38,
		D0 = 39,
		Enter = 40,
		Escape = 41,
		Backspace = 42,
		Tab = 43,
		Space = 44,
		Minus = 45,
		Equals = 46,
		LeftBracket = 47,
		RightBracket = 48,
		BackSlash = 49,
		NonUSHash = 50,
		Semicolon = 51,
		Apostrophe = 52,
		Grave = 53,
		Comma = 54,
		Period = 55,
		Slash = 56,
		Capslock = 57,
		F1 = 58,
		F2 = 59,
		F3 = 60,
		F4 = 61,
		F5 = 62,
		F6 = 63,
		F7 = 64,
		F8 = 65,
		F9 = 66,
		F10 = 67,
		F11 = 68,
		F12 = 69,
		PrintScreen = 70,
		ScrollLock = 71,
		Pause = 72,
		Insert = 73,
		Home = 74,
		PageUp = 75,
		Delete = 76,
		End = 77,
		PageDown = 78,
		Right = 79,
		Left = 80,
		Down = 81,
		Up = 82,
		NumlockClear = 83,
		KP_Divide = 84,
		KP_Multiply = 85,
		KP_Minus = 86,
		KP_Plus = 87,
		KP_Enter = 88,
		KP_1 = 89,
		KP_2 = 90,
		KP_3 = 91,
		KP_4 = 92,
		KP_5 = 93,
		KP_6 = 94,
		KP_7 = 95,
		KP_8 = 96,
		KP_9 = 97,
		KP_0 = 98,
		KP_Period = 99,
		NonUSBackSlash = 100,
		Application = 101,
		Power = 102,
		KP_Equals = 103,
		F13 = 104,
		F14 = 105,
		F15 = 106,
		F16 = 107,
		F17 = 108,
		F18 = 109,
		F19 = 110,
		F20 = 111,
		F21 = 112,
		F22 = 113,
		F23 = 114,
		F24 = 115,
		Execute = 116,
		Help = 117,
		Menu = 118,
		Select = 119,
		Stop = 120,
		Again = 121,
		Undo = 122,
		Cut = 123,
		Copy = 124,
		Paste = 125,
		Find = 126,
		Mute = 127,
		VolumeUp = 128,
		VolumeDown = 129,
		KP_Comma = 133,
		KP_EqualsAs400 = 134,
		International1 = 135,
		International2 = 136,
		International3 = 137,
		International4 = 138,
		International5 = 139,
		International6 = 140,
		International7 = 141,
		International8 = 142,
		International9 = 143,
		Language1 = 144,
		Language2 = 145,
		Language3 = 146,
		Language4 = 147,
		Language5 = 148,
		Language6 = 149,
		Language7 = 150,
		Language8 = 151,
		Language9 = 152,
		AltErase = 153,
		SysReq = 154,
		Cancel = 155,
		Clear = 156,
		Prior = 157,
		Return2 = 158,
		Separator = 159,
		Out = 160,
		Oper = 161,
		ClearAgain = 162,
		CRSEL = 163,
		EXSEL = 164,
		KP_00 = 176,
		KP_000 = 177,
		ThousandsSeparator = 178,
		DecimalSeparator = 179,
		CurrencyUnit = 180,
		CurrencySubUnit = 181,
		KP_LeftParen = 182,
		KP_RightParent = 183,
		KP_LeftBrace = 184,
		KP_RightBrace = 185,
		KP_Tab = 186,
		KP_BackSpace = 187,
		KP_A = 188,
		KP_B = 189,
		KP_C = 190,
		KP_D = 191,
		KP_E = 192,
		KP_F = 193,
		KP_XOR = 194,
		KP_Power = 195,
		KP_Percent = 196,
		KP_Less = 197,
		KP_Greater = 198,
		KP_Ampersand = 199,
		KP_DoubleAmpersand = 200,
		KP_VerticalBar = 201,
		KP_DoubleVerticalBar = 202,
		KP_Colon = 203,
		KP_Hash = 204,
		KP_Space = 205,
		KP_At = 206,
		KP_EXCLAM = 207,
		KP_MemStore = 208,
		KP_MemRecall = 209,
		KP_MemClear = 210,
		KP_MemAdd = 211,
		KP_MemSubstract = 212,
		KP_MemMultiply = 213,
		KP_MemDivide = 214,
		KP_PlusMinus = 215,
		KP_Clear = 216,
		KP_ClearEntry = 217,
		KP_Binary = 218,
		KP_Octal = 219,
		KP_Decimal = 220,
		KP_Hexadecimal = 221,
		LeftControl = 224,
		LeftShift = 225,
		LeftAlt = 226,
		LeftSuper = 227,
		RightControl = 228,
		RightShift = 229,
		RightAlt = 230,
		RightSuper = 231,
		Max
	};

	struct KeyboardState
	{
		bool down[(int)Key::Max];
		bool released[(int)Key::Max];
		bool pressed[(int)Key::Max];

		char text[Input::MAX_TEXT_INPUT];
	};

	struct MouseState
	{
		bool down[(int)MouseButton::Max];
		bool released[(int)MouseButton::Max];
		bool pressed[(int)MouseButton::Max];

		Vec2 screen_position;
		Vec2 draw_position;
		Vec2 position;
		
		Float2 wheel;
	};

	namespace Input
	{
		bool down(MouseButton mouse);
		bool down(Key key);

		bool released(MouseButton mouse);
		bool released(Key key);

		bool pressed(MouseButton mouse);
		bool pressed(Key key);
	}
}
