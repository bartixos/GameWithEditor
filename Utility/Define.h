#pragma once
#include <memory>
#include <iostream>

constexpr bool isEditorMode = true;

template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;

#define FORCEINLINE __forceinline

template <typename T>
FORCEINLINE void const LOG(const T& message)  noexcept
{
	std::cout << message << "\n";
}
