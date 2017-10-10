#include "Texture2D.h"

namespace Core {

	Texture2D::Texture2D(UINT width, UINT height)
	{
		m_width = width;
		m_height = height;
		m_pixelBuffer = new Vector3D*[width];
		for (int i = 0; i < width; ++i)
		{
			m_pixelBuffer[i] = new Vector3D[height];
		}
	}

	Texture2D::~Texture2D()
	{
		if (m_pixelBuffer)
		{
			for (int i = 0; i < m_width; ++i)
			{
				delete[] m_pixelBuffer[i];
			}
		}
	}

	Vector3D Texture2D::sample(const Vector2D& tex)
	{
		//纹理寻址采用d3d中的wrap方式 当坐标大于1时，通过去掉整数部分，根据得到的小数部分来得到纹理值；repeat
		//坐标小于0，则加上一个最小正数，让坐标大于0。

		if (tex.x >= 0 && tex.x <= 1 && tex.y >= 0 && tex.y <= 1)
		{
			UINT x = tex.x * (m_width - 1);
			UINT y = tex.y * (m_height - 1);
			return m_pixelBuffer[x][y];
		}
		else
		{
			float u, v;
			if (tex.x > 1)
				u = tex.x - static_cast<int>(tex.x);
			else if (tex.x < 0)
				u = (static_cast<int>(-tex.x) + 1) + tex.x;
			if (tex.y > 1)
				v = tex.y - static_cast<int>(tex.y);
			else if (tex.y < 0)
				v = (static_cast<int>(-tex.y) + 1) + tex.y;
			UINT x = u * (m_width - 1);
			UINT y = v * (m_height - 1);
			return m_pixelBuffer[x][y];
		}
	}

}