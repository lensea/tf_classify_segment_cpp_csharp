#pragma once
#define CLS_EXPORTS
#define SEG_EXPORTS

#include "cls_dll.h"
#include "seg_dll.h"

using namespace System;

namespace ManageDll
{
	public ref class ManageCls
	{
	public:
		ManageCls();
		ManageCls(String ^Aimg_path);
		~ManageCls();
		property int cls_id
		{
			int get();
		}
		property double cls_prob
		{
			double get();
		}
	private:
		Ccls *m_cls;
	};
}
namespace ManageDll
{
	public ref class ManageSeg
	{
	public:
		ManageSeg();
		ManageSeg(String ^Aimg_path);
		~ManageSeg();
		cli::array<int>^ GetReult();
	private:
		Cseg *m_seg;
		cli::array<int>^ m_arr ;
	};
}