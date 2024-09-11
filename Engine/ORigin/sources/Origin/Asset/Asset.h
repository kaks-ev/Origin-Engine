// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef ASSET_H
#define ASSET_H

#include "Origin/Core/UUID.h"
#include <string>

namespace origin {
    
    using AssetHandle = UUID;
    enum class OGN_API AssetType : u16
    {
        None = 0,
        Scene,
        Texture,
        Font,
        Audio,
        StaticMesh,
        Mesh,
        Material,
        Animation,
        SpritesSheet
    };

    const char *AssetTypeToString(AssetType type);
    AssetType AssetTypeFromString(const std::string_view &assetType);

    class OGN_API Asset
    {
    public:
        virtual ~Asset() = default;
        AssetHandle Handle;
        [[nodiscard]] virtual AssetType GetType() const = 0;
    };
}

#endif