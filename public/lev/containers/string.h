#pragma once

#include <lev/core/util.h>
#include <lev/containers/vector.h>

// note: easier to manage a fixed size string than one which constantly re-allocs

namespace lev
{
	template <u64 Size>
	class Str
	{
	public:
		Str();
		Str(const char* str);

		Str(const Str& other);
		Str(Str&& other) noexcept;

		Str& operator = (const Str& other);
		Str& operator = (Str&& other) noexcept;

		~Str();

		char* begin();
		const char* begin() const;
		char* end();
		const char* end() const;

		void clear();
		bool empty() const;

		Str& append(const Str& str);

		Str to_upper() const;
		Str to_lower() const;

		Str trim() const;
		Str trim_start() const;
		Str trim_end() const;

		Str strip_newline() const;

		Vector<Str> split(const char* delimiter = " ") const;

		int index_of(const Str& str) const;

		bool starts_with(const Str& str) const;
		bool ends_with(const Str& str) const;
		bool contains(const Str& str) const;

		void push_front(char c);
		void push_back(char c);

		void pop_front();
		void pop_back();

		char* c_str();
		const char* c_str() const;

		u64 length() const;
		constexpr u64 size() const;

		char& operator [] (u64 idx);
		char operator [] (u64 idx) const;

		bool operator == (const Str& other) const;
		bool operator != (const Str& other) const;

		Str operator + (const Str& rhs) const;
		Str& operator += (const Str& other);

		explicit operator char* ();
		explicit operator const char* () const;

	private:
		char* m_buf;
		u64 m_length;
	};

	using String = Str<64>;

	template <u64 Size>
	Str<Size>::Str()
		: m_length(0)
	{
		m_buf = new char[Size];
	}

	template <u64 Size>
	Str<Size>::Str(const char* str)
		: m_length(cstr::length(str))
	{
		LEV_ASSERT(m_length < (Size - 1), "Length must not exceed maximum size"); // -1 for '\0'

		m_buf = new char[Size];
		cstr::copy(m_buf, str, m_length);
		m_buf[m_length] = '\0';
	}
	
	template <u64 Size>
	Str<Size>::Str(const Str& other)
	{
		LEV_ASSERT(other.m_length < (Size - 1), "Length must not exceed maximum size");

		m_buf = new char[Size];
		m_length = other.m_length;
		cstr::copy(m_buf, other.m_buf, other.m_length);
		m_buf[m_length] = '\0';
	}
	
	template <u64 Size>
	Str<Size>::Str(Str&& other) noexcept
	{
		LEV_ASSERT(other.m_length < (Size - 1), "Length must not exceed maximum size");

		m_buf = new char[Size];

		m_length = std::move(other.m_length);
		m_buf = std::move(other.m_buf);

		other.m_length = 0;
		other.m_buf = nullptr;
	}
	
	template <u64 Size>
	Str<Size>& Str<Size>::operator = (const Str& other)
	{
		LEV_ASSERT(other.m_length < (Size - 1), "Length must not exceed maximum size");

		if (!m_buf)
			m_buf = new char[Size];
		
		if (m_length > other.m_length)
			mem::set(m_buf, 0, m_length);

		m_length = other.m_length;
		cstr::copy(m_buf, other.m_buf, other.m_length);
		m_buf[m_length] = '\0';

		return *this;
	}
	
	template <u64 Size>
	Str<Size>& Str<Size>::operator = (Str&& other) noexcept
	{
		LEV_ASSERT(other.m_length < (Size - 1), "Length must not exceed maximum size");

		if (!m_buf)
			m_buf = new char[Size];

		m_length = std::move(other.m_length);
		m_buf = std::move(other.m_buf);

		other.m_length = 0;
		other.m_buf = nullptr;

		return *this;
	}

	template <u64 Size>
	Str<Size>::~Str()
	{
		m_length = 0;
		delete[] m_buf;
	}

	template <u64 Size>
	char* Str<Size>::begin()
	{
		return m_buf;
	}

	template <u64 Size>
	const char* Str<Size>::begin() const
	{
		return m_buf;
	}

	template <u64 Size>
	char* Str<Size>::end()
	{
		return m_buf + m_length - 1;
	}

	template <u64 Size>
	const char* Str<Size>::end() const
	{
		return m_buf + m_length - 1;
	}

	template <u64 Size>
	void Str<Size>::clear()
	{
		mem::set(m_buf, 0, m_length);
		m_length = 0;
	}

	template <u64 Size>
	bool Str<Size>::empty() const
	{
		return cstr::compare(m_buf, "") == 0;
	}

	template <u64 Size>
	Str<Size>& Str<Size>::append(const Str<Size>& str)
	{
		LEV_ASSERT((m_length + str.m_length) < (Size - 1), "Final length must not exceed maximum size");

		m_length += str.length();
		cstr::cncat(m_buf, str.m_buf, str.length());

		return *this;
	}

	template <u64 Size>
	void Str<Size>::push_front(char c)
	{
		mem::move(m_buf + 1, m_buf, m_length);
		m_buf[0] = c;
		m_length++;
	}

	template <u64 Size>
	void Str<Size>::push_back(char c)
	{
		m_buf[m_length] = c;
		m_length++;
		m_buf[m_length] = '\0';
	}

	template <u64 Size>
	void Str<Size>::pop_front()
	{
		m_length--;
		mem::move(m_buf, m_buf + 1, m_length);
	}

	template <u64 Size>
	void Str<Size>::pop_back()
	{
		m_length--;
		m_buf[m_length] = '\0';
	}

	template <u64 Size>
	char* Str<Size>::c_str()
	{
		return m_buf;
	}

	template <u64 Size>
	const char* Str<Size>::c_str() const
	{
		return m_buf;
	}

	template <u64 Size>
	u64 Str<Size>::length() const
	{
		return m_length;
	}

	template <u64 Size>
	constexpr u64 Str<Size>::size() const
	{
		return Size;
	}

	template <u64 Size>
	Str<Size> Str<Size>::trim() const
	{
		return trim_start().trim_end();
	}

	template <u64 Size>
	Str<Size> Str<Size>::trim_start() const
	{
		const char* buffer = m_buf;
		while (cstr::is_space(*buffer)) buffer++;
		int whitespace = buffer - m_buf;

		Str trimmed = *this;
		trimmed.m_length -= whitespace;
		mem::move(trimmed.m_buf, trimmed.m_buf + whitespace, trimmed.m_length);

		return trimmed;
	}

	template <u64 Size>
	Str<Size> Str<Size>::trim_end() const
	{
		const char* end = m_buf + m_length - 1;

		const char* buffer = end;
		while (buffer > m_buf && cstr::is_space(*buffer)) buffer--;
		int whitespace = buffer - end;

		Str<Size> trimmed = *this;
		trimmed.m_length -= whitespace;
		trimmed.m_buf[trimmed.m_length] = '\0';

		return trimmed.strip_newline();
	}

	template <u64 Size>
	Str<Size> Str<Size>::strip_newline() const
	{
		Str<Size> cpy = *this;
		cpy.m_buf[cstr::cspan(cpy.m_buf, "\n")] = 0;
		cpy.m_buf[cstr::cspan(cpy.m_buf, "\r\n")] = 0;
		return cpy;
	}

	template <u64 Size>
	Vector<Str<Size>> Str<Size>::split(const char* delimiter) const
	{
		Vector<Str<Size>> tokens;

		char tokenbuf[Size] = { 0 };
		mem::copy(tokenbuf, m_buf, m_length);

		char* token = cstr::token(tokenbuf, delimiter);

		while (token)
		{
			tokens.push_back(token);
			token = cstr::token(nullptr, delimiter);
		}

		return tokens;
	}

	template <u64 Size>
	Str<Size> Str<Size>::to_upper() const
	{
		Str<Size> copy = *this;

		for (auto& c : copy)
			c = cstr::to_upper(c);

		return copy;
	}

	template <u64 Size>
	Str<Size> Str<Size>::to_lower() const
	{
		Str<Size> copy = *this;

		for (auto& c : copy)
			c = cstr::to_lower(c);

		return copy;
	}

	// todo: check if this works haven't tested it
	template <u64 Size>
	int Str<Size>::index_of(const Str& str) const
	{
		for (int j = 0; j < m_length - str.length(); j++)
		{
			bool cont = true;

			for (int i = 0; i < str.length(); i++)
			{
				if (m_buf[j+i] != str[i])
				{
					cont = false;
					break;
				}
			}

			if (cont)
				return j;
		}

		return -1;
	}

	template <u64 Size>
	bool Str<Size>::starts_with(const Str& str) const
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (m_buf[i] != str[i])
				return false;
		}

		return true;
	}

	template <u64 Size>
	bool Str<Size>::ends_with(const Str& str) const
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (m_buf[m_length - str.length() + i] != str[i])
				return false;
		}

		return true;
	}

	template <u64 Size>
	bool Str<Size>::contains(const Str& str) const
	{
		return index_of(str) != -1;
	}

	template <u64 Size>
	char& Str<Size>::operator [] (u64 idx)
	{
		LEV_ASSERT(idx < m_length, "Index must not be more than the length of the string");
		return m_buf[idx];
	}

	template <u64 Size>
	char Str<Size>::operator [] (u64 idx) const
	{
		LEV_ASSERT(idx < m_length, "Index must not be more than the length of the string");
		return m_buf[idx];
	}

	template <u64 Size>
	Str<Size> Str<Size>::operator + (const Str<Size>& other) const
	{
		Str str = *this;
		str.append(other);
		return str;
	}

	template <u64 Size>
	Str<Size>& Str<Size>::operator += (const Str<Size>& other)
	{
		return append(other);
	}

	template <u64 Size>
	bool Str<Size>::operator == (const Str& other) const
	{
		return cstr::compare(m_buf, other.m_buf) == 0;
	}

	template <u64 Size>
	bool Str<Size>::operator != (const Str& other) const
	{
		return !(*this == other);
	}

	template <u64 Size>
	Str<Size>::operator const char* () const
	{
		return m_buf;
	}

	template <u64 Size>
	Str<Size>::operator char* ()
	{
		return m_buf;
	}
}

namespace std
{
	// std::hash overload
	template <>
	struct hash<lev::String>
	{
		std::size_t operator()(const lev::String& k) const
		{
			return lev::cstr::hash(k.c_str());
		}
	};
}
