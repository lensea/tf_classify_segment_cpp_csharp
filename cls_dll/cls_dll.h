// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CLASSIFY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CLASSIFY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#pragma once
#ifdef CLS_EXPORTS
#define CLS_API __declspec(dllexport)
#else
#define CLS_API __declspec(dllimport)
#endif

#define COMPILER_MSVC
#define NOMINMAX
#define PLATFORM_WINDOWS

#include <iostream>

// This class is exported from the classify.dll
class CLS_API Ccls{
public:
	Ccls()
	{
		m_cls_id = 0;
		m_cls_prob = 0.0;
	}
	Ccls(std::string Aimg_path);
	int GetClsId();
	double GetClsProb();
private:
	int m_cls_id;
	double m_cls_prob;
	// TODO: add your methods here.
};
