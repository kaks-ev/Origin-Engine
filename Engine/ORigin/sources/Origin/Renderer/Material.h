// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef MATERIAL_H
#define MATERIAL_H

#include "Shader.h"
#include "Texture.h"
#include "UniformBuffer.h"
#include "Origin/Asset/Asset.h"
#include "Origin/Profiler/Profiler.h"

#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <unordered_map>

namespace origin
{
	namespace Utils
	{
		OGN_API void LoadMatTextures(std::unordered_map<aiTextureType, std::shared_ptr<Texture2D>> *tex, const std::string &modelFilepath, aiMaterial *mat, aiTextureType type);
	}

	struct OGN_API MaterialBufferData
	{
		float Emission = 0.0f;
		float MetallicValue = 0.0f;
		float RoughnessValue = 0.0f;
		bool UseNormalMaps = false;
	};

	struct OGN_API MaterialTexture
	{
		UUID Handle = 0;
		std::shared_ptr<Texture2D> Texture;
	};

	class OGN_API Material : public Asset
	{
	public:
		Material(const std::string &name);
		Material(const std::shared_ptr<Shader> &shader);
		MaterialBufferData BufferData;

		void Bind();
		void Unbind();
		void AddShader(const std::shared_ptr<Shader> &shader);
		bool RefreshShader();

		void SetAlbedoMap(AssetHandle handle);
		void SetMetallicMap(AssetHandle handle);
		void SetName(const std::string &name) { m_Name = name; }

		const std::string &GetName() { return m_Name; }

		std::shared_ptr<Shader> m_Shader;
		static std::shared_ptr<Material> Create(const std::string &name);
		static std::shared_ptr<Material> Create(const std::shared_ptr<Shader> &shader);

		static AssetType GetStaticType() { return AssetType::Material; }
		virtual AssetType GetType() const { return GetStaticType(); }

		MaterialTexture Albedo;
		MaterialTexture Metallic;

		glm::vec4 Color = glm::vec4(1.0f);
		glm::vec2 TilingFactor = glm::vec2(1.0f);

	private:
		std::shared_ptr<UniformBuffer> m_UniformBuffer;
		friend class OpenGLModel;

		std::string m_Name = "Material";
	};
}

#endif