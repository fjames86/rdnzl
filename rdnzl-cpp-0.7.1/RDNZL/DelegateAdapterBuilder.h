// $Header: /usr/local/cvsrep/rdnzl-cpp/RDNZL/DelegateAdapterBuilder.h,v 1.7 2008/02/14 07:34:31 edi Exp $
//
// Copyright (c) 2004-2008, Dr. Edmund Weitz.  All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   * Redistributions of source code must retain the above copyright
//     notice, this list of conditions and the following disclaimer.
//
//   * Redistributions in binary form must reproduce the above
//     copyright notice, this list of conditions and the following
//     disclaimer in the documentation and/or other materials
//     provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR 'AS IS' AND ANY EXPRESSED
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include "stdafx.h"
#include "DelegateAdapter.h"

public ref class DelegateAdapterBuilder {
 public:
  static Type ^buildDelegateType (String ^typeName, Type ^returnType, cli::array<Type^> ^argTypes);
 private:
  static String ^privateAssemblyName = "RDNZLPrivateAssembly";
  // cache for ModuleBuilder object
  static ModuleBuilder ^moduleBuilder = nullptr;

  static ModuleBuilder ^getModuleBuilder();
  static void generateConstructor(ILGenerator ^ilGenerator);
  static void generateInvokeMethod(ILGenerator ^ilGenerator, Type ^returnType, cli::array<Type^> ^argTypes);
};

extern "C" {
  __declspec(dllexport) void *buildDelegateType(const __wchar_t *typeName, void *returnType, void *argTypes);
}
