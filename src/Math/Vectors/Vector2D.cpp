#include "Vector2D.h"

#include <iostream>

namespace Math {

	template<typename T> FINLINE TVector2D<T>::TVector2D(T x, T y) : _x(x), _y(y) {
	}

	template<typename T> FINLINE T TVector2D<T>::getX() const {
		return _x;
	}

	template<typename T> FINLINE T TVector2D<T>::getY() const {
		return _y;
	}

	template<typename T> FINLINE void TVector2D<T>::setX(const T x) {
		_x = x;
	}

	template<typename T> FINLINE void TVector2D<T>::setY(const T y) {
		_y = y;
	}

	//Vectors
	template <typename T> const TVector2D<T> TVector2D<T>::zeroVector(0, 0);
	template <typename T> const TVector2D<T> TVector2D<T>::oneVector(1, 1);
	template <typename T> const TVector2D<T> TVector2D<T>::rightVector(1, 0);
	template <typename T> const TVector2D<T> TVector2D<T>::leftVector(-1, 0);
	template <typename T> const TVector2D<T> TVector2D<T>::upVector(0, 1);
	template <typename T> const TVector2D<T> TVector2D<T>::downVector(0, -1);

	template<typename T> FINLINE T TVector2D<T>::squaredNorm() const {
		return dot(*this, *this);
	}

	template<typename T> FINLINE T TVector2D<T>::norm() const {
		return sqrt(squaredNorm());
	}

	template<typename T> FINLINE void TVector2D<T>::operator*=(const T k) {
		_x *= k;
		_y *= k;
	}

	template<typename T> FINLINE TVector2D<T> TVector2D<T>::operator*(const T k) const {
		return TVector2D<T>(_x * k, _y * k);
	}

	template<typename T> FINLINE TVector2D<T> operator*(const T k, const TVector2D<T>& vector) {
		return vector * k;
	}

	template<typename T> FINLINE TVector2D<T> TVector2D<T>::normalize() {
		*this *= 1.0f / norm();
		return *this;
	}

	template<typename T> FINLINE TVector2D<T> TVector2D<T>::normalized() const {
		return *this * (1.0f / norm());
	}

	template<typename T> FINLINE TVector2D<T> TVector2D<T>::lerp(const TVector2D<T>& vector, T t) {
		t = t > 1.f ? 1.f : t;
		t = t < 0.f ? 0.f : t;
		TVector2D<T> difference = vector - *this;
		_x += difference.X() * t;
		_y += difference.Y() * t;
		return *this;
	}

	template<typename T> FINLINE TVector2D<T> TVector2D<T>::lerp(const TVector2D<T>& vectorA, const TVector2D<T>& vectorB, T t) {
		return TVector2D<T>(vectorA).lerp(vectorB, t);
	}

	template<typename T> FINLINE T TVector2D<T>::operator^(const TVector2D<T>& vector) const {
		return _x * vector.getY() - _y * vector.getY();
	}

	template<typename T> FINLINE T TVector2D<T>::crossProduct(const TVector2D<T>& vectorA, const TVector2D<T>& vectorB) {
		return vectorA ^ vectorB;
	}

	template<typename T> FINLINE T TVector2D<T>::dot(const TVector2D<T>& vector) const {
		return _x * vector.getX() + _y * vector.getY();
	}

	template<typename T> FINLINE T TVector2D<T>::dot(const TVector2D<T>& vectorA, const TVector2D<T>& vectorB) {
		return vectorA.dot(vectorB);
	}

	template<typename T> FINLINE void TVector2D<T>::operator+=(const TVector2D<T>& vector) {
		_x + vector.getX();
		_y + vector.getY();
	}

	template<typename T> FINLINE void TVector2D<T>::operator-=(const TVector2D<T>& vector) {
		_x - vector.getX();
		_y - vector.getY();
	}

	template<typename T> FINLINE TVector2D<T> TVector2D<T>::operator+(const TVector2D<T>& vector) const {
		return TVector2D<T>(
			_x + vector.getX(),
			_y + vector.getY());
	}

	template<typename T> FINLINE TVector2D<T> TVector2D<T>::operator-(const TVector2D<T>& vector) const {
		return TVector2D<T>(
			_x - vector.getX(),
			_y - vector.getY());
	}

	template<typename T> FINLINE bool TVector2D<T>::operator==(const TVector2D<T>& vector) const {
		return equals(vector);
	}

	template<typename T> FINLINE bool TVector2D<T>::equals(const TVector2D<T>& vector, T tolerance) const {
		bool isXEqual = abs(_x - vector.getX()) <= tolerance;
		bool isYEqual = abs(_y - vector.getY()) <= tolerance;
		return isXEqual && isYEqual;
	}

	template<typename T> FINLINE void TVector2D<T>::print() {
		std::cout << "(" << _x << ", " << _y << ")" << std::endl;
	}
}