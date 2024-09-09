﻿// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef ASSET_MANAGER_BASE_H
#define ASSET_MANAGER_BASE_H

#include "Asset.h"
#include <memory>
#include <map>

namespace origin {

    using AssetMap = std::map<AssetHandle, std::shared_ptr<Asset>>;

    class AssetManagerBase
    {
    public:
        virtual std::shared_ptr<Asset> GetAsset(AssetHandle handle) = 0;
        virtual bool IsAssetHandleValid(AssetHandle handle)   const = 0;
        virtual bool IsAssetLoaded(AssetHandle handle)        const = 0;
        virtual AssetType GetAssetType(AssetHandle handle)    const = 0;
    };
}

#endif