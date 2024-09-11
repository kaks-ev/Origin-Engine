// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef SUB_TEXTURE_2D_H
#define SUB_TEXTURE_2D_H

#include "Origin/Renderer/Texture.h"
#include "Origin/Scene/SpriteSheet.h"
#include <glm/glm.hpp>

namespace origin {

	class OGN_API SubTexture2D
	{
	public:
		SubTexture2D(const Ref<Texture2D>& texture, const glm::vec2& min, const glm::vec2& max);

		const Ref<Texture2D> GetTexture() const { return m_Texture; }
		const glm::vec2* GetTexCoords() const { return m_TexCoords; }

		static Ref<SubTexture2D> CreateFromCoords(const Ref<Texture2D>& texture, const glm::vec2& coords, const glm::vec2& cellSize, const glm::vec2& spriteSize = glm::vec2(1.0f));
		static Ref<SubTexture2D> CreateFromSpriteSheet(const Ref<Texture2D> &texture, SpriteSheetData data);

	private:
		Ref<Texture2D> m_Texture;
		glm::vec2 m_TexCoords[4];
	};
}

#endif