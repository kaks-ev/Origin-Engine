// Copyright (c) Evangelion Manuhutu | ORigin Engine

#ifndef RENDERER_H
#define RENDERER_H

#include "RenderCommand.h"
#include "Origin/Renderer/Texture.h"
#include "Origin/Scene/Components/Components.h"
#include "Origin/Scene/EditorCamera.h"

namespace origin {

#define CAMERA_BINDING 0
#define LIGHTING_BINDING 1
#define MATERIAL_BINDING 2

	struct OGN_API RenderData
	{
		static const u32 MaxTriangles = 1024;
		static const u32 MaxVertices = MaxTriangles * 24;
		static const u32 MaxQuadIndices = MaxTriangles * 6;
		static const u32 MaxTextureSlots = 32;
	};

	struct OGN_API Statistics
	{
		u32 DrawCalls = 0;
		u32 QuadCount = 0;
		u32 CircleCount = 0;
		u32 LineCount = 0;

		u32 CubeCount = 0;
		u32 SphereCount = 0;

		u32 GetTotalQuadVertexCount() const { return QuadCount * 4; }
		u32 GetTotalQuadIndexCount() const { return QuadCount * 6; }
		u32 GetTotalCubeVertexCount() const { return CubeCount * 24; }
		u32 GetTotalCubeIndexCount() const { return CubeCount * 36; }
        u32 GetTotalSphereVertexCount() const { return SphereCount * 544; }
        u32 GetTotalSphereIndexCount() const { return SphereCount * 768; }

		void Reset() { memset(this, 0, sizeof(Statistics)); };
	};

	class OGN_API ShaderLibrary;
	class OGN_API Renderer
	{
	public:
		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

		static bool Init();
		static void Shutdown();

		static void OnWindowResize(u32 width, u32 height);
		static void SetCurrentShader(const std::shared_ptr<Shader> &shader);

		const static std::shared_ptr<Shader>& GetCurrentShader() { return s_GlobalShader; }
		static std::shared_ptr<Shader> GetShader(const std::string &name);
		static ShaderLibrary &GetShaderLibrary();

		static std::shared_ptr<Material> GetMaterial(const std::string &name);

		static std::shared_ptr<Texture2D> WhiteTexture;
		static std::shared_ptr<Texture2D> BlackTexture;

		static Statistics &GetStatistics();
		static RenderData s_RenderData;

	private:
		static void LoadShaders();
		static void LoadMaterials();

		static std::shared_ptr<Shader> s_GlobalShader;
	};
}

#endif