// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef OPENGL_SKYBOX_H
#define OPENGL_SKYBOX_H

#include "Origin/Renderer/VertexArray.h"
#include "Origin/Renderer/Shader.h"
#include "Origin/Renderer/Buffer.h"
#include "Origin/Renderer/RenderCommand.h"
#include "Origin/Scene/Skybox.h"

#include <glm/glm.hpp>
#include <string>

namespace origin
{
	class OGN_API OpenGLSkybox : public Skybox
	{
	public:
		OpenGLSkybox(const std::string& filepath, const std::string& format);
		void Draw(const glm::mat4& viewProjection) override;
		void Draw(const SceneCamera& camera) override;
		void Draw(const EditorCamera& camera) override;
		void SetBlur(float blur) override;

	private:
		void LoadTexture();
		std::string m_Filepath;
		std::string m_ImageFormat;

		Ref<VertexArray> m_VertexArray;
		Ref<VertexBuffer> m_VertexBuffer;
		Ref<Shader> m_Shader;
		u32 m_TextureID;
		const u32 IndicesCount = 36;
		float m_BlurFactor = 0.005f;
	};
}

#endif