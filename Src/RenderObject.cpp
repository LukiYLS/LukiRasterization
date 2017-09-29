#include "RenderObject.h"
#include "Matrix4D.h"
#include "Vector4D.h"
#include "MathHelper.h"
namespace Core {

	void RenderObject::draw(Shader::ptr shader)
	{
		//
		for (int index = 0; index < _indices.size() / 3; index++)
		{
			Vector3D p1 = _vertices[_indices[index]].position;
			Vector3D p2 = _vertices[_indices[index + 1]].position;
			Vector3D p3 = _vertices[_indices[index + 2]].position;

			Matrix4D view = _camera->getViewMatrix();
			Matrix4D projection = _camera->getProjectionMatrix();

			Matrix4D vp = projection * view;

			Vector4D p1_vp = vp * Vector4D(p1, 1.0);
			Vector4D p2_vp = vp * Vector4D(p2, 1.0);
			Vector4D p3_vp = vp * Vector4D(p3, 1.0);
			
			if (!MathHelper::Clip(p1_vp) || !MathHelper::Clip(p2_vp) || !MathHelper::Clip(p3_vp))
				continue;

			MathHelper::ToNDC(p1_vp);
			MathHelper::ToNDC(p2_vp);
			MathHelper::ToNDC(p3_vp);

			Matrix4D screen = _camera->getScreenMatrix();

			p1_vp = screen * p1_vp;
			p2_vp = screen * p2_vp;
			p3_vp = screen * p3_vp;
			

		}
	}
}