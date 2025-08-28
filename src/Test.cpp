#include "MathVectors.h"
#include "MathAngles.h"
#include <cassert>


void test_Vector3D_operators()
{
    Vector3D z{};
    assert(z == Vector3D::zeroVector);

    Vector3D l{ -1 , 0, 0};
    assert(l == Vector3D::leftVector);

    Vector3D v{ 3, 4, 5 };
    assert(v + Vector3D::oneVector == Vector3D(4, 5, 6));
    assert(v * 2 == Vector3D(6, 8, 10));
    v *= -1;
    assert(v == Vector3D(-3, -4, -5));

    const Vector3D w{ -1, -30, -8 };
    const Vector3D r = Vector3D::crossProduct(v, w);

    assert(Vector3D::dot(r, v) == 0.0);
    assert(Vector3D::dot(r, w) == 0.0);

    assert(Vector3D::lerp(z, v, 0) == z);
    assert(Vector3D::lerp(z, v, 1) == v);
    assert(Vector3D::lerp(z, v, 0.5) == 0.5 * v);
    assert(Vector3D::lerp(-v, v, 0.5) == Vector3D::zeroVector);
}

void test_quaternion()
{
    const Quat zero{};
    assert(zero.squaredNorm() != 1.0);

    const Quat i = { 1, 0, 0, 0 };
    const Quat j = { 0, 1, 0, 0 };
    const Quat k = { 0, 0, 1, 0 };

    assert(i.squaredNorm() == 1.0);
    assert(j.squaredNorm() == 1.0);
    assert(k.squaredNorm() == 1.0);

    assert(i * j == k);
    assert(j * k == i);
    assert(k * i == j);
    assert(j * i == -k);
    assert(k * j == -i);
    assert(i * k == -j);
    assert(i * k == -j);

    const Quat q{ 3, 2, -5 , -2 };
    Quat qco{ -3, -2, 5 , -2 };
    assert(q.conjugated() == qco);
    assert(qco.conjugated() == q);
    assert(q.squaredNorm() != 1.0);
    Quat qn = q.normalized();
}

void test_180_y()
{
    const Vector3D p = { 2, 1, 5 };

    AxisAngle aa({ 0., 1., 0. }, pi);

    Quat q = aa;

    const Vector3D p1 = q.rotate(p);

    // 180 deg rotation on Y axis keeps Y and inverts X and Z
    assert(p1 == Vector3D(-(p.getX()), p.getY(), -(p.getZ())));

    // Inverse of rotation should get back to the original
    const Vector3D p_inv = q.conjugated().rotate(p1);
    assert(p_inv == p);

    // Double 180 deg rotation should get back to the original
    const Vector3D p2 = q.rotate(p1);
    assert(p2 == p);
}

void test_60_axis()
{
    const Vector3D a = Vector3D{ 12, 3.2, -4.8 }.normalized();
    AxisAngle aa(a, pi);

    Quat q = aa;
    const Vector3D p = { 3, -1, 8 };

    Vector3D p1 = p;
    for (int i = 0; i < 6; ++i)
    {
        p1 = q.rotate(p1);
    }

    // 6 60 deg rotations should get back to the original
    assert(p1 == p);

    // Test optimized rotation against raw formula implementation
    assert(q.rotate(p) == q.unRotate(p));
}

void test_rot_matrix()
{
    const EulerAngle r = EulerAngle{ 32, 124, -54 };
    const Quat q = r;
    const Vector3D p = { 5, 3, 12 };

    const Vector3D p1 = q.rotate(p);
    const Vector3D Mp = q.rotationMatrix() * p;

    assert(p1 == Mp);

}

void test_conversion() {
    EulerAngle ea(23., 15., 2.);

    Quat q = ea;

    assert(q.eulerAngle().equals(ea));

    assert(q.rotationMatrix().quaternion() == q);
    assert(q.axisAngle().quaternion() == q);


}


int main()
{
    test_Vector3D_operators();
    test_quaternion();
    test_180_y();
    test_60_axis();
    test_rot_matrix();
    test_conversion();
    return 0;
}
