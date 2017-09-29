#pragma once
#include <map>
#include <string>
#include <memory>
#include "AnyValue.h"
namespace Core {

	class Shader {

	public:
		typedef std::shared_ptr<Shader> ptr;
		void init();
		void addUnifom(const std::string& name, AnyValue value);
		void setViewMatrix();
		void setProjectMatrix();
	protected:
		std::map<std::string, AnyValue> _vs_uniform;
		std::map<std::string, AnyValue> _fs_uniform;
	};
}