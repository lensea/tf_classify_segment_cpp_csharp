#pragma once
#define CLS_EXPORTS
#define SEG_EXPORTS

#include "cls_dll.h"
#include "seg_dll.h"

using namespace System;

namespace manage_dll
{
	public ref class manage_cls
	{
	public:
		manage_cls();
		manage_cls(String ^img_path);
		~manage_cls();
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
namespace manage_dll
{
	public ref class manage_seg
	{
	public:
		manage_seg();
		manage_seg(String ^img_path);
		~manage_seg();
		cli::array<int>^ get_reult();
	private:
		Cseg *m_seg;
		cli::array<int>^ m_arr ;
	};
}