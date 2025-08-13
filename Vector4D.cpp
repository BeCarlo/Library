#include "Vector4D.h"

#include <iostream>

namespace Math {

	template<typename T> FINLINE TVector4D<T>::TVector4D(T x, T y, T z, T w) : _x(x), _y(y), _z(z), _w(w) {
	}

	template<typename T> FINLINE T TVector4D<T>::getX() const {
		return _x;
	}

	template<typename T> FINLINE T TVector4D<T>::getY() const {
		return _y;
	}

	template<typename T> FINLINE T TVector4D<T>::getZ() const {
		return _z;
	}

	template<typename T> FINLINE T TVector4D<T>::getW() const {
		return _w;
	}


	template<typename T> FINLINE void TVector4D<T>::setX(const T x) {
		_x = x;
	}

	template<typename T> FINLINE void TVector4D<T>::setY(const T y) {
		_y = y;
	}

	template<typename T> FINLINE void TVector4D<T>::setZ(const T z) {
		_z = z;
	}

	template<typename T> FINLINE void TVector4D<T>::setW(const T w) {
		_w = w;
	}

	//Vectors
	template <typename T> const TVector4D<T> TVector4D<T>::zeroVector(0, 0, 0, 0);
	template <typename T> const TVector4D<T> TVector4D<T>::oneVector(0, 0, 0, 0);

	template<typename T> FINLINE T TVector4D<T>::squaredNorm() const {
		return dot(*this, *this);
	}

	template<typename T> FINLINE T TVector4D<T>::norm() const {
		return sqrt(squaredNorm());
	}


	template<typename T> FINLINE void TVector4D<T>::operator*=(const T k) {
		_x *= k;
		_y *= k;
		_z *= k;
		_w *= k;
	}

	template<typename T> FINLINE TVector4D<T> TVector4D<T>::operator*(const T k) const {
		return TVector4D<T>(_x * k, _y * k, _z * k, _w * k);
	}

	template<typename T> FINLINE TVector4D<T> TVector4D<T>::lerp(const TVector4D<T>& vector, T k) {
		k = k > 1.f ? 1.f : k;
		k = k < 0.f ? 0.f : k;
		TVector4D<T> difference = vector - *this;
		_x += difference.X() * k;
		_y += difference.Y() * k;
		_z += difference.Z() * k;
		_w += difference.W() * k;
		return *this;
	}

	template<typename T> inline TVector4D<T> TVector4D<T>::lerp(const TVector4D<T>& vectorA, const TVector4D<T>& vectorB, T k) {
		return TVector4D<T>(vectorA).lerp(vectorB, k);
	}

	template<typename T> FINLINE TVector4D<T> operator*(const T k, const TVector4D<T>& vector) {
		return vector * k;
	}

	template<typename T> FINLINE TVector4D<T> TVector4D<T>::normalize() {
		*this *= 1.0f / norm();
		return *this;
	}

	template<typename T> FINLINE TVector4D<T> TVector4D<T>::normalized() const {
		return *this * (1.0f / norm());
	}

	template<typename T> FINLINE T TVector4D<T>::dot(const TVector4D<T>& vector) const {
		return _x * vector.getX() + _y * vector.getY() + _z * vector.getZ() + _w * vector.getW();
	}

	template<typename T> inline static T TVector4D<T>::dot(const TVector4D<T>& vectorA, const TVector4D<T>& vectorB) {
		return vectorA.dot(vectorB);
	}

	template<typename T> FINLINE void TVector4D<T>::operator+=(const TVector4D<T>& vector) {
		_x + vector.getX();
		_y + vector.getY();
		_z + vector.getZ();
		_w + vector.getW();
	}

	template<typename T> FINLINE void TVector4D<T>::operator-=(const TVector4D<T>& vector) {
		_x - vector.getX();
		_y - vector.getY();
		_z - vector.getZ();
		_w - vector.getW();
	}

	template<typename T> FINLINE TVector4D<T> TVector4D<T>::operator+(const TVector4D<T>& vector) {
		return TVector4D<T>(
			_x + vector.getX(),
			_y + vector.getY(),
			_z + vector.getZ(),
			_w + vector.getW()
			);
	}

	template<typename T> FINLINE TVector4D<T> TVector4D<T>::operator-(const TVector4D<T>& vector) {
		return TVector4D<T>(
			_x - vector.getX(),
			_y - vector.getY(),
			_z - vector.getZ(),
			_w - vector.getW()
			);
	}

	template<typename T> FINLINE bool TVector4D<T>::operator==(const TVector4D<T>& vector) {
		return equals(vector);
	}

	template<typename T> FINLINE bool TVector4D<T>::equals(const TVector4D<T>& vector, T tolerance) {
		bool isXEqual = abs(_x - vector.getX()) <= tolerance;
		bool isYEqual = abs(_y - vector.getY()) <= tolerance;
		bool isZEqual = abs(_z - vector.getZ()) <= tolerance;
		bool isWEqual = abs(_w - vector.getW()) <= tolerance;
		return isXEqual && isYEqual && isZEqual && isWEqual;
	}

	template<typename T> FINLINE void TVector4D<T>::print() {
		std::cout << "(" << _x << ", " << _y << ", " << _z << ", " << _w << ")" << std::endl;
	}

}