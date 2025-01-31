// infoware - C++ System information Library
//
// Written in 2016-2020 by nabijaczleweli <nabijaczleweli@gmail.com> and ThePhD <phdofthehouse@gmail.com>
//
// To the extent possible under law, the author(s) have dedicated all copyright and related
// and neighboring rights to this software to the public domain worldwide. This software is
// distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along with this software.
// If not, see <http://creativecommons.org/publicdomain/zero/1.0/>


#ifndef _WIN32


#include "infoware/detail/cpuid.hpp"
#include "infoware/platform.hpp"
#include <cstdint>

#if INFOWARE_X86
#include <cpuid.h>

void iware::detail::cpuid(std::int32_t (&out)[4], std::int32_t x) {
	__cpuid_count(x, 0, out[0], out[1], out[2], out[3]);
}

std::uint64_t iware::detail::xgetbv(std::uint32_t index) {
	std::uint32_t eax, edx;
	__asm__ __volatile__("xgetbv" : "=a"(eax), "=d"(edx) : "c"(index));
	return ((uint64_t)edx << 32) | eax;
}
#endif


#endif
