// manage_dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "manage_dll.h"
#include <iostream>
#include <string>
#include <msclr\marshal.h> 
#include <msclr\marshal_cppstd.h>
#include <vcclr.h>

using namespace std;
using namespace msclr::interop;


void MarshalString(String^ s, string& os) {
	using namespace System::Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

namespace manage_dll
{
	manage_cls::manage_cls()
	{
		m_cls = new Ccls();
	}
	manage_cls::manage_cls(String ^img_path)
	{
		std::string std_img_path;
		MarshalString(img_path, std_img_path);
		//pin_ptr<const wchar_t> wch = PtrToStringChars(img_path);
		//std_img_path = marshal_as<std::string>(img_path);
		//std::cout << std_img_path << std::endl;
		m_cls = new Ccls(std_img_path);
	}
	manage_cls::~manage_cls()
	{
		delete m_cls;
	}
	int manage_cls::cls_id::get()
	{
		return m_cls->get_cls_id();
	}
	double manage_cls::cls_prob::get()
	{
		return m_cls->get_cls_prob();
	}
}

namespace manage_dll
{
	manage_seg::manage_seg()
	{
		m_arr = gcnew cli::array<int>(65536);
		m_seg = new Cseg();
	}
	manage_seg::manage_seg(String ^img_path)
	{
		m_arr = gcnew cli::array<int>(65536);
		std::string std_img_path;
		MarshalString(img_path, std_img_path);
		//pin_ptr<const wchar_t> wch = PtrToStringChars(img_path);
		//std_img_path = marshal_as<std::string>(img_path);
		//std::cout << std_img_path << std::endl;
		m_seg = new Cseg(std_img_path);
	}
	manage_seg::~manage_seg()
	{
		delete m_seg;
		m_arr = nullptr;
		//delete m_arr;
	}
	cli::array<int>^ manage_seg::get_reult()
	{
		int * result = m_seg->get_seg_result();
		for (int i = 0; i < 65536; ++i)
		{
			m_arr[i] = result[i];
		}
		return m_arr;
	}
}

