#pragma once
#include "Device.h"
#include "RenderObject.h"
namespace Core {
	struct Point2 {
		int x;
		int y;
		Point2() = default;
		Point2(int x_,int y_):x(x_),y(y_){}
		static Point2 lerp(const Point2& p1, const Point2& p2, float scale) {
			double one_scale = 1.0 - scale;
			return Point2(
				p1.x * one_scale + p2.x * scale,
				p1.y * one_scale + p2.y * scale
			);
		}
	};
	class DrawHelper {
	public:
		static void drawLineSB(Device& device, Vertex p1, Vertex p2);//斜率累加
		static void drawLineBSH(Device& device, Vertex p1, Vertex p2);//Bresenham
		static void drawTriangleLine(Device& device, Vertex p1, Vertex p2, Vertex p3);//线框模式
		static void drawTriangleFill(Device& device, Vertex p1, Vertex p2, Vertex p3);//填充模式

		static void drawTriangle(Device& device, Vertex p1, Vertex p2, Vertex p3);
	private:
		static void drawTriangleImmediate(Device& device, Vertex p1, Vertex p2, Vertex p3);
		static float* calculateWeight(Point2 p1, Point2 p2, Point2 p3);

	};
}