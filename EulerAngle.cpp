#include "EulerAngle.h"

namespace Math {
	template<typename T> FINLINE TEulerAngle<T>::TEulerAngle(const T x, const T y, const T z) {
		this->setX(x);
		this->setY(y);
		this->setZ(z);
	}
	template<typename T> FINLINE TEulerAngle<T>::TEulerAngle(const TVector3D<T>& vector) {
		*this = TEulerAngle<T>(vector.getX(), vector.getY(), vector.getZ());
	}

	template<typename T> FINLINE TEulerAngle<T>::TEulerAngle(const TQuaternion<T>& quaternion) {
		*this = quaternion.eulerAngle();
	}

	template<typename T> FINLINE TQuaternion<T> TEulerAngle<T>::quaternion() const {

		const T xRad = this->getX() * pi / 180;
		const T yRad = this->getY() * pi / 180;
		const T zRad = this->getZ() * pi / 180;



		const T cosX = Funtions::tCos(xRad * 0.5);
		const T senX = Funtions::tSin(xRad * 0.5);
		const T cosY = Funtions::tCos(yRad * 0.5);
		const T senY = Funtions::tSin(yRad * 0.5);
		const T cosZ = Funtions::tCos(zRad * 0.5);
		const T senZ = Funtions::tSin(zRad * 0.5);

		return TQuaternion<T>(
			cosX*senY*senZ - senX*cosY*cosZ,
			-cosX*senY*cosZ - senX*cosY*senZ,
			cosX*cosY*senZ - senX*senY*cosZ,
			cosX*cosY*cosZ + senX*senY*senZ
		);
	}
	
	template<typename T> FINLINE TEulerAngle<T>::operator TVector3D<T>() const {
		return TVector3D<T>(pitch(), yaw(), roll());
	}
}