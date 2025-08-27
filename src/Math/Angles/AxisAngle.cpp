#include "AxisAngle.h"

namespace Math {
	template<typename T> FINLINE TAxisAngle<T>::TAxisAngle(const TVector3D<T>& axis, T angle) : _axis(axis), _angle(angle) {
	}

	template<typename T> FINLINE TAxisAngle<T>::TAxisAngle(const TQuaternion<T>& quaternion) {
		*this = quaternion.axisAngle();
	}

	template<typename T> FINLINE TQuaternion<T> TAxisAngle<T>::quaternion() const {
		TVector3D<T> axisN = _axis.normalized();
		T angle2 = _angle * T(0.5);
		return TQuaternion<T>(axisN * Funtions::tSin(angle2), Funtions::tCos(angle2));
	}


	template<typename T> FINLINE TVector3D<T> TAxisAngle<T>::getAxis() const {
		return _axis;
	}

	template<typename T> FINLINE T TAxisAngle<T>::getAngle() const {
		return _angle;
	}

	template<typename T> FINLINE void TAxisAngle<T>::setAxis(const TVector3D<T>& axis) {
		_axis = axis;
	}

	template<typename T> FINLINE void TAxisAngle<T>::setAngle(T angle) {
		_angle = angle;
	}
}