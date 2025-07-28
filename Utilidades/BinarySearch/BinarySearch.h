#pragma once

namespace utils {

	template<class Type>
	class BinarySearch {
	protected:
		int m_index;
	public:
		BinarySearch() { m_index=0; }
		~BinarySearch() {}
		Type* search(Type *_vt1, Type *_vt2, bool Sort=true);
		bool search2(Type &_vt1, Type &_vt2, Type &_result, bool Sort=true);
		inline int  index() { return m_index; }
	};
	// **************<<_USAGE_>>****************
	void binarySearchUsage();

} // utils