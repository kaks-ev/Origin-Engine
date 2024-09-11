// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include "Shader.h"

#include <vector>

namespace origin {

	struct OGN_API ParticleProps
	{
		glm::vec3 Position;
		glm::vec3 Rotation;
		glm::vec3 Scale;

		glm::vec3 Velocity;
		glm::vec3 VelocityVariation;
		glm::vec4 ColorBegin;
		glm::vec4 ColorEnd;

		f32 SizeBegin;
		f32 SizeEnd;
		f32 SizeVariation;
		f32 LifeTime;
	};

	class OGN_API ParticleComponent;
	class OGN_API ParticleSystem
	{
	public:
		ParticleSystem();

		void OnUpdate(f32 deltaTime);
		void OnRender();

		void Emit(const ParticleProps& particleProps);
		void Emit(ParticleComponent& component, const glm::vec3& position, const glm::vec3& scale, const glm::vec3& rotation);

		static std::shared_ptr<ParticleSystem> Create();

	private:

		struct Particle
		{
			glm::vec3 Position;
			glm::vec3 Rotation;
			glm::vec3 Scale;

			glm::vec3 Velocity;

			glm::vec4 ColorBegin, ColorEnd;
			f32 SizeBegin, SizeEnd;

			f32 LifeTime = 1.0f;
			f32 LifeRemaining = 0.0f;

			bool Active = false;
		};
		std::vector<Particle> m_ParticlePool;
		uint32_t m_PoolIndex = 9999;

		int m_EntityID = -1;
	};

}

#endif