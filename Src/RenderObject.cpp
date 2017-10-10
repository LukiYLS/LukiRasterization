#include "RenderObject.h"
#include "Matrix4D.h"
#include "Vector4D.h"
#include "MathHelper.h"
#include "DrawHelper.h"
namespace Core {

	void RenderObject::draw(Device& device)
	{
		//
		for (int index = 0; index < _indices.size(); index+=3)
		{
			Vector3D p1 = _vertices[_indices[index]].position;
			Vector3D p2 = _vertices[_indices[index + 1]].position;
			Vector3D p3 = _vertices[_indices[index + 2]].position;

			Matrix4D view = _camera->getViewMatrix().getInverse();

			Matrix4D projection = Matrix4D::makeProjectionMatrix(3.1415926f / 4, (float)600 / (float)800, 1.0, 100.f);

			Matrix4D vp = projection * view;

			

			Vector4D p1_vp = vp * Vector4D(p1);
			Vector4D p2_vp = vp * Vector4D(p2);
			Vector4D p3_vp = vp * Vector4D(p3);

			//onedivZ 与x',y'线性关系，透视投影纹理			

			_vertices[_indices[index]].perspectiveCorrection(1 / p1_vp.z);
			_vertices[_indices[index + 1]].perspectiveCorrection(1 / p2_vp.z);
			_vertices[_indices[index + 2]].perspectiveCorrection(1 / p3_vp.z);

			if (MathHelper::Clip(p1_vp) || MathHelper::Clip(p2_vp) || MathHelper::Clip(p3_vp))
				continue;

			if (MathHelper::cullFace(_camera->getPosition(), p1_vp, p2_vp, p3_vp))
				continue;

			MathHelper::ToNDC(p1_vp);
			MathHelper::ToNDC(p2_vp);
			MathHelper::ToNDC(p3_vp);

			Matrix4D screen = _camera->getScreenMatrix();

			p1_vp = screen * p1_vp;
			p2_vp = screen * p2_vp;
			p3_vp = screen * p3_vp;

			Vertex v1 = _vertices[_indices[index]];
			Vertex v2 = _vertices[_indices[index + 1]];
			Vertex v3 = _vertices[_indices[index + 2]];
			v1.position = p1_vp;
			v2.position = p2_vp;
			v3.position = p3_vp;

			
			
			DrawHelper::drawTriangleFill(device, v1, v2, v3);
		}
	}
}