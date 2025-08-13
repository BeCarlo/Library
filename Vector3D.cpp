#include "Vector3D.h"

#include <iostream>

namespace Math {

	template<typename T> FINLINE TVector3D<T>::TVector3D(T x, T y, T z) : _x(x), _y(y), _z(z) {
	}

	template<typename T> FINLINE T TVector3D<T>::getX() const {
		return _x;
	}

	template<typename T> FINLINE T TVector3D<T>::getY() const {
		return _y;
	}

	template<typename T> FINLINE T TVector3D<T>::getZ() const {
		return _z;
	}


	template<typename T> FINLINE void TVector3D<T>::setX(const T x) {
		_x = x;
	}

	template<typename T> FINLINE void TVector3D<T>::setY(const T y) {
		_y = y;
	}

	template<typename T> FINLINE void TVector3D<T>::setZ(const T z) {
		_z = z;
	}

	//Vectors
	template <typename T> const TVector3D<T> TVector3D<T>::zeroVector(0, 0, 0);
	template <typename T> const TVector3D<T> TVector3D<T>::oneVector(0, 0, 0);
	template <typename T> const TVector3D<T> TVector3D<T>::rightVector(1, 0, 0);
	template <typename T> const TVector3D<T> TVector3D<T>::leftVector(-1, 0, 0);
	template <typename T> const TVector3D<T> TVector3D<T>::upVector(0, 1, 0);
	template <typename T> const TVector3D<T> TVector3D<T>::downVector(0, -1, 0);
	template <typename T> const TVector3D<T> TVector3D<T>::forwardVector(0, 0, 1);
	template <typename T> const TVector3D<T> TVector3D<T>::backwardVector(0, 0, -1);

	template<typename T> FINLINE T TVector3D<T>::squaredNorm() const {
		return dot(*this, *this);
	}

	template<typename T> FINLINE T TVector3D<T>::norm() const {
		return sqrt(squaredNorm());
	}

	template<typename T> FINLINE void TVector3D<T>::operator*=(const T k) {
		_x *= k;
		_y *= k;
		_z *= k;
	}

	template<typename T> FINLINE TVector3D<T> TVector3D<T>::operator*(const T k) const {
		return TVector3D<T>(_x * k, _y * k, _z * k);
	}

	template<typename T> FINLINE TVector3D<T> operator*(const T k, const TVector3D<T>& vector) {
		return vector * k;
	}

	template<typename T> FINLINE TVector3D<T> TVector3D<T>::normalize() {
		*this *= 1.0f / norm();
		return *this;
	}

	template<typename T> FINLINE TVector3D<T> TVector3D<T>::normalized() const {
		return *this * (1.0f / norm());
	}

	template<typename T> FINLINE TVector3D<T> TVector3D<T>::lerp(const TVector3D<T>& vector, T k) {
		k = k > 1.f ? 1.f : k;
		k = k < 0.f ? 0.f : k;
		TVector3D<T> difference = vector - *this;
		_x += difference.X() * k;
		_y += difference.Y() * k;
		_z += difference.Z() * k;
		return *this;
	}

	template<typename T> inline TVector3D<T> TVector3D<T>::lerp(const TVector3D<T>& vectorA, const TVector3D<T>& vectorB, T k) {
		return TVector3D<T>(vectorA).lerp(vectorB, k);
	}

	template<typename T> FINLINE void TVector3D<T>::operator^=(const TVector3D<T>& vector) {
		T crossX = _y * vector.getZ() - _z * vector.getY();
		T crossY = _z * vector.getX() - _x * vector.getZ();
		T crossZ = _x * vector.getY() - _y * vector.getX();

		*this = { crossX, crossY, crossZ };
	}

	template<typename T> FINLINE TVector3D<T> TVector3D<T>::operator^(const TVector3D<T>& vector) const {
		return TVector3D<T>(
			_y * vector.getZ() - _z * vector.getY(),
			_z * vector.getX() - _x * vector.getZ(),
			_x * vector.getY() - _y * vector.getX());
	}

	template<typename T> inline static TVector3D<T> TVector3D<T>::crossProduct(const TVector3D<T>& vectorA, const TVector3D<T>& vectorB) {
		return vectorA ^ vectorB;
	}

	template<typename T> FINLINE T TVector3D<T>::dot(const TVector3D<T>& vector) const {
		return _x * vector.getX() + _y * vector.getY() + _z * vector.getZ();
	}

	template<typename T> inline static T TVector3D<T>::dot(const TVector3D<T>& vectorA, const TVector3D<T>& vectorB) {
		return vectorA.dot(vectorB);
	}

	template<typename T> FINLINE void TVector3D<T>::operator+=(const TVector3D<T>& vector) {
		_x + vector.getX();
		_y + vector.getY();
		_z + vector.getZ();
	}

	template<typename T> FINLINE void TVector3D<T>::operator-=(const TVector3D<T>& vector) {
		_x - vector.getX();
		_y - vector.getY();
		_z - vector.getZ();
	}

	template<typename T> FINLINE TVector3D<T> TVector3D<T>::operator+(const TVector3D<T>& vector) {
		return TVector3D<T>(
			_x + vector.getX(),
			_y + vector.getY(),
			_z + vector.getZ());
	}

	template<typename T> FINLINE TVector3D<T> TVector3D<T>::operator-(const TVector3D<T>& vector) {
		return TVector3D<T>(
			_x - vector.getX(),
			_y - vector.getY(),
			_z - vector.getZ());
	}

	template<typename T> FINLINE bool TVector3D<T>::operator==(const TVector3D<T>& vector) {
		bool isXEqual = abs(_x - vector.getX()) <= epsilon;
		bool isYEqual = abs(_y - vector.getY()) <= epsilon;
		bool isZEqual = abs(_z - vector.getZ()) <= epsilon;
		return isXEqual && isYEqual && isZEqual;
	}

	template<typename T> FINLINE bool TVector3D<T>::equals(const TVector3D<T>& vector, T tolerance) {
		bool isXEqual = abs(_x - vector.getX()) <= tolerance;
		bool isYEqual = abs(_y - vector.getY()) <= tolerance;
		bool isZEqual = abs(_z - vector.getZ()) <= tolerance;
		return isXEqual && isYEqual && isZEqual;
	}


	template<typename T> FINLINE void TVector3D<T>::print() {
		std::cout << "(" << _x << ", " << _y << ", " << _z << ")" << std::endl;
	}

}