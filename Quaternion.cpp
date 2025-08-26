#include "Quaternion.h"

#include <iostream>

namespace Math {
	template<typename T> FINLINE TQuaternion<T>::TQuaternion(const T x, const T y, const T z, const T w) {
		this->setX(x);
		this->setY(y);
		this->setZ(z);
		this->setW(w);
	}

	template<typename T> FINLINE TQuaternion<T>::TQuaternion(const TVector3D<T>& vector, T w) {
		*this = TQuaternion<T>(vector.getX(), vector.getY(), vector.getZ(), w);
	}

	template<typename T> FINLINE TQuaternion<T>::TQuaternion(const TAxisAngle<T>& axisAngle) {
		*this = axisAngle.quaternion();
	}

	template<typename T> FINLINE TQuaternion<T>::TQuaternion(const TEulerAngle<T>& eulerAngle) {
		*this = eulerAngle.quaternion();
	}

	template<typename T> FINLINE TQuaternion<T>::TQuaternion(const TRMatrix<T>& matrix) {
		*this = matrix.quaternion();
	}

	template<typename T> FINLINE TVector3D<T> TQuaternion<T>::vector3D() const {
		return TVector3D<T>(_x, _y, _z);
	}

	template<typename T> FINLINE TAxisAngle<T> TQuaternion<T>::axisAngle() const {

		const T angle = T(2.0) * (T(1.0) /  Funtions::tCos(_w));
		const TVector3D<T> axis = vector3D() * (T(1.0) / Funtions::tSin(angle * T(0.5)));

		return TAxisAngle<T>(axis, angle);
	}

	template<typename T> FINLINE TEulerAngle<T> TQuaternion<T>::eulerAngle() const {
		const T one = static_cast<T>(1.0);
		const T two = static_cast<T>(2.0);
		const T SingularityTest = _z * _x - _w * _y;
		const T YawY = two * (_w * _z + _x * _y);
		const T YawX = one - two * (Funtions::tSquare(_y) + Funtions::tSquare(_z));
		const T radToDeg = static_cast<T>(180.0 * pi);

		const T Pitch = std::asin(two * SingularityTest) * radToDeg;
		const T Yaw = Funtions::tAtan2(YawY, YawX) * radToDeg;

		T x = two * (_w * _z + _x * _y);
		T y = one - two * (_y * _y + _z * _z);
		const T Roll = Funtions::tAtan2(x, y) * radToDeg;

		return TEulerAngle<T>(Pitch, Yaw, Roll);
	}

	template<typename T> FINLINE TRMatrix<T> TQuaternion<T>::rotationMatrix() const {
		const T xx = _x * _x;
		const T xy = _x * _y;
		const T xz = _x * _z;
		const T xw = _x * _w;
		const T yy = _y * _y;
		const T yz = _y * _z;
		const T yw = _y * _w;
		const T zz = _z * _z;
		const T zw = _z * _w;

		const T zero = static_cast<T>(0.0);
		const T one = static_cast<T>(1.0);
		const T two = static_cast<T>(2.0);

		//Quaternions as Vectors4D
		const TQuaternion<T> x = TQuaternion<T>(one - two * (yy + zz), two * (xy + zw), two *(xz - yw), zero);
		const TQuaternion<T> y = TQuaternion<T>(two * (xy - zw), one - two * (xx + zz), two * (yz + xw), zero);
		const TQuaternion<T> z = TQuaternion<T>(two * (xz + yw), two * (yz - xw), one - two * (xx + yy), zero);
		const TQuaternion<T> w = TQuaternion<T>(zero, zero, zero, one);

		return TRMatrix<T>(x, y, z, w);
	}

	template<typename T> FINLINE T TQuaternion<T>::getX() const {
		return _x;
	}

	template<typename T> FINLINE T TQuaternion<T>::getY() const {
		return _y;
	}

	template<typename T> FINLINE T TQuaternion<T>::getZ() const {
		return _z;
	}

	template<typename T> FINLINE T TQuaternion<T>::getW() const {
		return _w;
	}


	template<typename T> FINLINE void TQuaternion<T>::setX(const T x) {
		_x = x;
	}

	template<typename T> FINLINE void TQuaternion<T>::setY(const T y) {
		_y = y;
	}

	template<typename T> FINLINE void TQuaternion<T>::setZ(const T z) {
		_z = z;
	}

	template<typename T> FINLINE void TQuaternion<T>::setW(const T w) {
		_w = w;
	}

	template<typename T> FINLINE TVector3D<T> TQuaternion<T>::getAxisX() const {
		return rotate(TVector3D<T>(static_cast<T>(1.0), static_cast<T>(0.0), static_cast<T>(0.0)));
	}

	template<typename T> FINLINE TVector3D<T> TQuaternion<T>::getAxisY() const {
		return rotate(TVector3D<T>(static_cast<T>(0.0), static_cast<T>(1.0), static_cast<T>(0.0)));
	}

	template<typename T> FINLINE TVector3D<T> TQuaternion<T>::getAxisZ() const {
		return rotate(TVector3D<T>(static_cast<T>(0.0), static_cast<T>(0.0), static_cast<T>(1.0)));
	}

	template<typename T> FINLINE TVector3D<T> TQuaternion<T>::operator*(const TVector3D<T>& vector) const {

		const TVector3D<T> vectorQ = TVector3D<T>(_x, _y, _z);

		return (_w * _w) * vector + 2.0 * _w * vectorQ.crossed(vector)  + vectorQ.dot(vector) * vectorQ  - vectorQ.crossed(vector).crossed(vectorQ);
	}

	template<typename T> FINLINE TVector3D<T> TQuaternion<T>::rotate(const TVector3D<T>& vector) const {
		return *this * vector;
	}

	template<typename T> FINLINE TVector3D<T> TQuaternion<T>::unRotate(const TVector3D<T>& vector) const {
		return this->conjugated() * vector;
	}

	template<typename T> FINLINE T TQuaternion<T>::squaredNorm() const {
		return dot(*this, *this);
	}

	template<typename T> FINLINE T TQuaternion<T>::norm() const {
		return sqrt(squaredNorm());
	}


	template<typename T> FINLINE void TQuaternion<T>::operator*=(const T k) {
		_x *= k;
		_y *= k;
		_z *= k;
		_w *= k;
	}

	template<typename T> FINLINE TQuaternion<T> TQuaternion<T>::operator*(const T k) const {
		return TQuaternion<T>(_x * k, _y * k, _z * k, _w * k);
	}

	template<typename T> FINLINE TQuaternion<T> TQuaternion<T>::lerp(const TQuaternion<T>& vector, T k) const {
		const T c = this->dot(vector);

		const T isShortest = static_cast<double>(dot) > 0.0 ? static_cast<T>(1.0) : static_cast<T>(-1.0);

		return (isShortest * *this * (1.0 - k)) + (vector * k);
	}

	template<typename T> FINLINE TQuaternion<T> TQuaternion<T>::lerp(const TQuaternion<T>& vectorA, const TQuaternion<T>& vectorB, T k) {
		return TQuaternion<T>(vectorA).lerp(vectorB, k);
	}

	template<typename T> FINLINE TQuaternion<T> operator*(const T k, const TQuaternion<T>& vector) {
		return vector * k;
	}

	template<typename T> FINLINE TQuaternion<T> TQuaternion<T>::normalize() {
		*this *= 1.0f / norm();
		return *this;
	}

	template<typename T> FINLINE TQuaternion<T> TQuaternion<T>::normalized() const {
		return *this * (1.0f / norm());
	}

	template<typename T> FINLINE TQuaternion<T> TQuaternion<T>::conjugate() {
		_x = -_x;
		_y = -_y;
		_z = -_z;
		return *this;
	}

	template<typename T> FINLINE TQuaternion<T> TQuaternion<T>::conjugated() const {
		return TQuaternion<T>(-_x, -_y, -_z, -_w);
	}

	template<typename T> FINLINE T TQuaternion<T>::dot(const TQuaternion<T>& vector) const {
		return _x * vector.getX() + _y * vector.getY() + _z * vector.getZ() + _w * vector.getW();
	}

	template<typename T> FINLINE T TQuaternion<T>::dot(const TQuaternion<T>& vectorA, const TQuaternion<T>& vectorB) {
		return vectorA.dot(vectorB);
	}

	template<typename T> FINLINE void TQuaternion<T>::operator*=(const TQuaternion<T>& vector) {

		*this = *this * vector;
	}

	template<typename T> FINLINE TQuaternion<T> TQuaternion<T>::operator*(const TQuaternion<T>& vector) const {

		const TVector3D<T> firstVector = this->vector3D();
		const TVector3D<T> secondVector = vector.vector3D();
		const TVector3D<T> pVector = firstVector * vector.getW() + secondVector * _w + firstVector.crossed(secondVector);

		return TQuaternion<T>(pVector, vector.getW() * _w - firstVector.dot(secondVector));

	}

	template<typename T> FINLINE bool TQuaternion<T>::operator==(const TQuaternion<T>& vector) const {
		return equals(vector);
	}

	template<typename T> FINLINE bool TQuaternion<T>::equals(const TQuaternion<T>& vector, T tolerance) const {
		bool isXEqual = abs(_x - vector.getX()) <= tolerance;
		bool isYEqual = abs(_y - vector.getY()) <= tolerance;
		bool isZEqual = abs(_z - vector.getZ()) <= tolerance;
		bool isWEqual = abs(_w - vector.getW()) <= tolerance;
		return isXEqual && isYEqual && isZEqual && isWEqual;
	}

	template<typename T> FINLINE void TQuaternion<T>::print() const {
		std::cout << "(" << _x << ", " << _y << ", " << _z << ", " << _w << ")" << std::endl;
	}
}