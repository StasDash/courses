#pragma once

namespace figures {
	template<class T>
	class Option {
	private:
		T obj;
		bool isValue;
	public:
		Option() : obj(nullptr), isValue(false) {}
		Option(T& element) : obj(element), isValue(true) {}
		T& unwrap() {
			return obj;
		}
	};
}