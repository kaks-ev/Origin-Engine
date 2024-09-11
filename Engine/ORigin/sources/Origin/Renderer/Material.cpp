// Copyright (c) Evangelion Manuhutu | ORigin Engine

#include "pch.h"

#include "Material.h"
#include "Origin/Asset/AssetManager.h"

#include "Renderer.h"

namespace origin {

#define ALBEDO_MAP		"u_AlbedoMap"
#define SPECULAR_MAP	"u_SpecularMap"

	namespace Utils
	{
		void LoadMatTextures(std::unordered_map<aiTextureType, std::shared_ptr<Texture2D>> *tex, const std::string &modelFilepath, aiMaterial *mat, aiTextureType type)
		{
			static std::vector<std::shared_ptr<Texture2D>> loadedTextures;
			std::unordered_map<aiTextureType, std::shared_ptr<Texture2D>> textures;

			for (uint32_t i = 0; i < mat->GetTextureCount(type); i++)
			{
				OGN_PROFILER_SCOPE("Material::LoadTextures TextureCount");

				aiString str;

				mat->GetTexture(type, i, &str);
				bool skip = false;
				for (uint32_t j = 0; j < loadedTextures.size(); j++)
				{
					if (std::strcmp(loadedTextures[j]->GetName().c_str(), str.C_Str()) == 0)
					{
						tex->insert({ type, loadedTextures[j] });
						skip = true;
						break;
					}
				}

				if (!skip)
				{
					OGN_PROFILER_SCOPE("Material::LoadTextures TextureCount");

					auto textureDirectory = modelFilepath.substr(0, modelFilepath.find_last_of('/'));
					std::string textureName = std::string(str.C_Str());

					std::shared_ptr<Texture2D> newTexture = Texture2D::Create(textureDirectory + "/" + textureName);
					tex->insert({ type, newTexture });
					loadedTextures.push_back(newTexture);
				}
			}
			loadedTextures.clear();
		}
	}

	Material::Material(const std::string &name)
		: m_Name(name)
	{
		OGN_PROFILER_RENDERING();

		m_Shader = Renderer::GetShader("BatchMesh");
		m_Shader->Enable();
		m_UniformBuffer = UniformBuffer::Create(sizeof(MaterialBufferData), MATERIAL_BINDING);

		Albedo.Texture = Renderer::WhiteTexture;
		Metallic.Texture = Renderer::WhiteTexture;
	}

	Material::Material(const std::shared_ptr<Shader> &shader)
		: m_Shader(shader)
	{
		OGN_PROFILER_RENDERING();

		OGN_CORE_ASSERT(m_Shader, "[Material] Shader is uninitialized or empty!");
		m_Shader->Enable();

		m_UniformBuffer = UniformBuffer::Create(sizeof(MaterialBufferData), MATERIAL_BINDING);

        Albedo.Texture = Renderer::WhiteTexture;
        Metallic.Texture = Renderer::WhiteTexture;
	}

	void Material::Bind()
	{
		OGN_PROFILER_RENDERING();

		m_UniformBuffer->Bind();
		m_UniformBuffer->SetData(&BufferData, sizeof(MaterialBufferData));
		m_Shader->Enable();
	}

	void Material::Unbind()
	{
		OGN_PROFILER_RENDERING();

		m_Shader->Disable();
		m_UniformBuffer->Unbind();
	}

	void Material::AddShader(const std::shared_ptr<Shader> &shader)
	{
		m_Shader = shader;
	}

	bool Material::RefreshShader()
	{
		m_Shader->Reload();
		return true;
	}

	void Material::SetAlbedoMap(AssetHandle handle)
	{
		Albedo.Handle = handle;
		Albedo.Texture = AssetManager::GetAsset<Texture2D>(handle);
	}

	void Material::SetMetallicMap(AssetHandle handle)
	{
		Metallic.Handle = handle;
		Metallic.Texture = AssetManager::GetAsset<Texture2D>(handle);
	}

	std::shared_ptr<Material> Material::Create(const std::string &name)
	{
		OGN_PROFILER_RENDERING();

		return std::make_shared<Material>(name);
	}

	std::shared_ptr<Material> Material::Create(const std::shared_ptr<Shader> &shader)
	{
		return std::make_shared<Material>(shader);
	}

}