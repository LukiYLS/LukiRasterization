#pragma once
#include "RenderObject.h"
namespace Core {

	class GeometryCreator {

	public:
		static RenderObject* createBox(int width, int height, int depth);
	};
}