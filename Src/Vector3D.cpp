#include "Vector3D.h"
#include "Vector4D.h"
#include "Matrix4D.h"
namespace Core {
	Vector3D::Vector3D()
		:x(0), y(0), z(0)
	{

	}

	Vector3D::Vector3D(const double& x_, const double& y_, const double& z_)
		: x(x_), y(y_), z(z_)
	{

	}

	Vector3D::Vector3D(const Vector4D& v4)
	{
		x = v4.x;
		y = v4.y;
		z = v4.z;
	}

	Vector3D::~Vector3D()
	{

	}

	void Vector3D::operator=(const Vector4D& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}	
	
}