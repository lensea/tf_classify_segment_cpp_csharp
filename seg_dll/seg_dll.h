#pragma once


#ifdef SEG_EXPORTS
#define SEG_API __declspec(dllexport)
#else
#define SEG_API __declspec(dllimport)
#endif

#define COMPILER_MSVC
#define NOMINMAX
#define PLATFORM_WINDOWS

#include <iostream>

// This class is exported from the classify.dll
class SEG_API Cseg {
public:
	Cseg()
	{
		m_seg_result = new int[65536]();
	}
	Cseg(std::string img_path);
	~Cseg();
	int * get_seg_result();
private:
	int *m_seg_result;
};
