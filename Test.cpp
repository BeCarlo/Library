#include "MathVectors.h"
#include "MathAngles.h"



int main() {
	EulerAngle t = EulerAngle(1.0, 1.0, 1.0);
	t.print();
	Quat q = t;
	Quat f = Quat(1.0, 1.0, 1.0, 1.0);
	t = q.unRotate(t);
	t = q * q;
	q.print();
	q.conjugate();
	q.print();
	q.conjugate();
	t = q.eulerAngle();
	t.print();
	AxisAngle aa(q.axisAngle());
	Vector3D b(1.0, 3.0, 2.0);
	b.normalize();
	b.print();
	b.normalize();
	b.print();
}