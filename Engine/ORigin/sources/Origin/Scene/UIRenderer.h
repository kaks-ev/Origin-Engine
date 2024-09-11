// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef UI_RENDERER_H
#define UI_RENDERER_H

#include "Components/Components.h"
#include "Origin/Renderer/Shader.h"

namespace origin
{
	class OGN_API UIRenderer
	{
	public:
		UIRenderer() = default;

		void CreateFramebuffer(u32 vpW, u32 vpH, f32 orthoW, f32 orthoH);
		void SetViewportSize(u32 vpW, u32 vpH, f32 orthoW, f32 orthoH);
		void Unload();
		void RenderFramebuffer();
		void Render();
		void AddUI(const UIComponent &ui);
		std::vector<UIComponent> &GetUIs() { return m_UIs; }

	private:
		u32 m_VAO = 0, m_VBO = 0;
		Ref<Shader> m_ScreenShader;
		std::vector<UIComponent> m_UIs;
		glm::mat4 m_Projection;
	};
}
#endif