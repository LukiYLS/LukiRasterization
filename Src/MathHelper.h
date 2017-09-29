#pragma once
#include <windows.h>
#include "Vector3D.h"
#include "Vector4D.h"
#include "Matrix4D.h"
namespace Core {
	class MathHelper {

	public:

		static UINT ColorTo32(const Vector3D& color) {
			BYTE red = 255 * color[0];
			BYTE green = 255 * color[1];
			BYTE blue = 255 * color[2];
			return (UINT)((BYTE)blue | (WORD)((BYTE)green << 8) | (DWORD)((BYTE)red << 16));
		}
		static bool Clip(Vector4D v)
		{
			if (v[0] >= -v[3] && v[0] <= v[3] && v[1] >= -v[3] && v[1] <= v[3] &&
				v[2] >= -v[3] && v[2] <= v[3])
				return true;
			return false;
		}
		static void ToNDC(Vector4D v)
		{
			v[0] /= v[3];
			v[1] /= v[3];
			v[2] /= v[3];
			v[3] = 1;
		}
		static bool cullFace(Vector3D p1, Vector3D p2, Vector3D p3);
		static Matrix4D PerspectiveFovH(float angle, float aspect, float near, float far);
		static Matrix4D LookAt(Vector3D pos, Vector3D target, Vector3D up);
		static Matrix4D ViewPort(int x, int y, int width, int height);		
	};
}