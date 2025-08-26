#ifndef MATH_ANGLE_H
#define MATH_ANGLE_H

#include "EulerAngle.cpp"
#include "Quaternion.cpp"
#include "RotationMatrix.cpp"
#include "AxisAngle.cpp"

typedef Math::TAxisAngle<double> AxisAngle;
typedef Math::TEulerAngle<double> EulerAngle;
typedef Math::TQuaternion<double> Quat;
typedef Math::TRMatrix<double> Matrix;

#endif // !MATH_ANGLE_H