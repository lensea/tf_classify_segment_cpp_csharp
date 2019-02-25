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


void MarshalString(String^ Aistr, string& Aostr) {
	using namespace System::Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(Aistr)).ToPointer();
	Aostr = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

namespace ManageDll
{
	ManageCls::ManageCls()
	{
		m_cls = new Ccls();
	}
	ManageCls::ManageCls(String ^Aimg_path)
	{
		std::string std_img_path;
		MarshalString(Aimg_path, std_img_path);
		//pin_ptr<const wchar_t> wch = PtrToStringChars(img_path);
		//std_img_path = marshal_as<std::string>(img_path);
		//std::cout << std_img_path << std::endl;
		m_cls = new Ccls(std_img_path);
	}
	ManageCls::~ManageCls()
	{
		delete m_cls;
	}
	int ManageCls::cls_id::get()
	{
		return m_cls->GetClsId();
	}
	double ManageCls::cls_prob::get()
	{
		return m_cls->GetClsProb();
	}
}

namespace ManageDll
{
	ManageSeg::ManageSeg()
	{
		m_arr = gcnew cli::array<int>(65536);
		m_seg = new Cseg();
	}
	ManageSeg::ManageSeg(String ^Aimg_path)
	{
		m_arr = gcnew cli::array<int>(65536);
		std::string std_img_path;
		MarshalString(Aimg_path, std_img_path);
		//pin_ptr<const wchar_t> wch = PtrToStringChars(img_path);
		//std_img_path = marshal_as<std::string>(img_path);
		//std::cout << std_img_path << std::endl;
		m_seg = new Cseg(std_img_path);
	}
	ManageSeg::~ManageSeg()
	{
		delete m_seg;
		m_arr = nullptr;
		//delete m_arr;
	}
	cli::array<int>^ ManageSeg::GetReult()
	{
		int * result = m_seg->GetSegResult();
		for (int i = 0; i < 65536; ++i)
		{
			m_arr[i] = result[i];
		}
		return m_arr;
	}
}

