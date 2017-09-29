#include "Vector4D.h"
#include "Vector3D.h"
#include "Matrix4D.h"

namespace Core {
	Vector4D::Vector4D()
		:x(0), y(0), z(0), w(0)
	{

	}

	Vector4D::Vector4D(const double& x_, const double& y_, const double& z_, const double& w_)
		: x(x_), y(y_), z(z_), w(w_)
	{

	}

	Vector4D::Vector4D(const Vector3D& v3, double w_)
	{
		x = v3.x;
		y = v3.y;
		z = v3.z;
		w = w_;
	}

	Vector4D::~Vector4D()
	{

	}
	inline Vector3D Vector4D::xyz() const
	{
		return Vector3D(x, y, z);
	}
	inline Vector4D& Vector4D::operator = (const Vector3D& rhs)
	{
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = 1.0f;
		return *this;
	}	
	
}