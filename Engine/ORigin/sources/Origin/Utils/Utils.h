// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef UTILS_H
#define UTILS_H

#include "imgui.h"
#include <string>
#include <filesystem>

namespace origin::Utils
{
	OGN_API void CenteredText(const char *text);
    OGN_API void CenteredWrappedText(const char *fmt, ...);
    OGN_API void ExecuteScript(const std::string &scriptPath);
}

#endif
