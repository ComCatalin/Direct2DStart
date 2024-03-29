#pragma once

#define NOMINMAX

#include <atlbase.h>
#include <atlwin.h>
#include <wrl.h>
#include <d2d1.h>
#pragma comment(lib, "d2d1")

#define ASSERT ATLASSERT
#define VERIFY ATLVERIFY
#define TRACE ATLTRACE

#ifdef DEBUG
#define HR(expression) ASSERT(S_OK == (expression))
#else
struct ComException
{
	HRESULT const hr;
	ComException(HRESULT const value) : hr(value) {}
};

inline void HR(HRESULT hr)
{
	if (S_OK != hr) throw ComException(hr);
}
#endif

#pragma warning(disable: 4706)
