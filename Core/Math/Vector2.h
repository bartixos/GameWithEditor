#pragma once
#include "SFML/System.hpp"
#include "Utility/Define.h"
#include "imgui-master/imgui.h"
#include "cereal/cereal.hpp"

struct Vector2
{
	float x, y;

	template<typename Archive>
	void save(Archive& archive) const
	{
		archive(CEREAL_NVP_("X", x), CEREAL_NVP_("Y", y));
	}
	template<typename Archive>
	void load(Archive& archive)
	{
		archive(CEREAL_NVP_("X", x), CEREAL_NVP_("Y", y));
	}

#pragma region Constuct Regiom

	Vector2()noexcept :
		x(0), y(0)
	{}

	Vector2(float x, float y)noexcept :
		x(x), y(y)
	{}

	Vector2(const Vector2& vec)noexcept :
		x(vec.x), y(vec.y)
	{}

	Vector2(Vector2 && vec) noexcept :
		x(std::move(vec.x)), y(std::move(vec.y))
	{}

	Vector2(const sf::Vector2f& vec)noexcept :
		x(vec.x), y(vec.y)
	{	}

	explicit	Vector2(const sf::Vector2i& vec)noexcept :
		x(static_cast<float>(vec.x)), y(static_cast<float>(vec.y))
	{	}

	Vector2(const sf::Vector2u& vec)noexcept :
		x(static_cast<float>(vec.x)), y(static_cast<float>(vec.y))
	{	}

	Vector2(const ImVec2& vec)noexcept :
		x(static_cast<float>(vec.x)), y(static_cast<float>(vec.y))
	{	}

#pragma endregion

#pragma region  function

	FORCEINLINE static Vector2 AddVector(const Vector2& a, const Vector2& b) noexcept
	{
		return std::move(Vector2(a.x + b.x, a.y + b.y));
	}

	FORCEINLINE static Vector2 SubstractVector(const Vector2& a, const Vector2& b)noexcept
	{
		return std::move(Vector2(a.x - b.x, a.y - b.y));
	}

	FORCEINLINE static Vector2 MultipliVector(const Vector2& a, const Vector2& b)noexcept
	{
		return std::move(Vector2(a.x * b.x, a.y * b.y));
	}

	FORCEINLINE static Vector2 DivideVector(const Vector2& a, const Vector2& b)noexcept
	{
		return std::move(Vector2(a.x / b.x, a.y / b.y));
	}

	std::string ToString() noexcept
	{
		std::string result("Vector 2: pos x: ");
		result += std::to_string(x) + " pos y: " + std::to_string(y);
		return std::move(result);
	}

#pragma endregion

#pragma region Convertion

	FORCEINLINE	explicit operator sf::Vector2f()noexcept
	{
		return std::move(sf::Vector2f(x, y));
	}

	FORCEINLINE explicit operator sf::Vector2i()noexcept
	{
		return std::move(sf::Vector2i(static_cast<int>(x), static_cast<int>(y)));
	}

	FORCEINLINE explicit operator sf::Vector2u()noexcept
	{
		return std::move(sf::Vector2u(static_cast<unsigned int>(x), static_cast<unsigned int>(y)));
	}

#pragma endregion

#pragma region  operator overloading

	Vector2& operator +=(const Vector2& vec)noexcept
	{
		x += vec.x;
		y += vec.y;

		return *this;
	}

	Vector2& operator -=(const Vector2& vec)noexcept
	{
		x -= vec.x;
		y -= vec.y;

		return *this;
	}

	Vector2& operator *=(const Vector2& vec)noexcept
	{
		x *= vec.x;
		y *= vec.y;

		return *this;
	}

	Vector2& operator /=(const Vector2& vec)noexcept
	{
		x /= vec.x;
		y /= vec.y;

		return *this;
	}

	FORCEINLINE friend Vector2 operator +(const Vector2 &a, const Vector2 &b)noexcept
	{
		return std::move(AddVector(a, b));
	}

	FORCEINLINE friend Vector2 operator -(const Vector2 &a, const Vector2 &b)noexcept
	{
		return std::move(SubstractVector(a, b));
	}

	FORCEINLINE friend Vector2 operator *(const Vector2 &a, const Vector2 &b)noexcept
	{
		return std::move(MultipliVector(a, b));
	}

	FORCEINLINE friend Vector2 operator /(const Vector2 &a, const Vector2 &b)noexcept
	{
		return std::move(DivideVector(a, b));
	}

	FORCEINLINE  bool operator == (const Vector2& vec)
	{
		if (x == vec.x && y == vec.y)
		{
			return true;
		}
		return false;
	}

	FORCEINLINE bool operator !=(const Vector2& vec)
	{
		if (*this == vec)
		{
			return false;
		}
		return true;
	}

	FORCEINLINE friend bool operator >(const Vector2&a, const Vector2&b)
	{
		if (a.x > b.x && a.y > b.y)
		{
			return true;
		}
		else return false;
	}

	FORCEINLINE friend bool operator <(const Vector2&a, const Vector2&b)
	{
		if (a.x < b.x && a.y < b.y)
		{
			return true;
		}
		else return false;
	}

	FORCEINLINE friend bool operator  >= (const Vector2&a, const Vector2&b)
	{
		if (a.x >= b.x && a.y >= b.y)
		{
			return true;
		}
		else return false;
	}
	FORCEINLINE friend bool operator <=(const Vector2&a, const Vector2&b)
	{
		if (a.x <= b.x && a.y <= b.y)
		{
			return true;
		}
		else return false;
	}

	FORCEINLINE	Vector2 & operator = (const Vector2 &a)
	{
		if (*this != a)
		{
			x = a.x;
			y = a.y;
		}
		return *this;
	}

#pragma endregion
};