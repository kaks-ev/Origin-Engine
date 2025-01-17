// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef SCRIPT_FIELDS_H
#define SCRIPT_FIELDS_H

extern "C" {
    typedef struct _MonoClassField MonoClassField;
}

namespace origin
{
    enum class ScriptFieldType
    {
        Invalid = 0,
        Entity,
        Float, Double,
        Bool, Char, Byte, Short, Int, Long,
        UByte, UShort, UInt, ULong,
        Vector2, Vector3, Vector4
    };

    struct ScriptField
    {
        ScriptFieldType Type = ScriptFieldType::Invalid;
        std::string Name;

        MonoClassField *ClassField = nullptr;
    };
}

#endif