// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef EDITOR_CAMERA_H
#define EDITOR_CAMERA_H

#include "Origin/Core/Event.h"
#include "Origin/Core/MouseEvent.h"
#include "Origin/Audio/AudioListener.h"
#include "Origin/Core/Time.h"
#include "Camera.h"

#include <glm/glm.hpp>

namespace origin {

	class OGN_API Entity;
	class OGN_API EditorCamera : public Camera
	{
	public:
		EditorCamera() = default;
		void InitPerspective(f32 fovy, f32 aspectRatio, f32 nearClip, f32 farClip) override;
		void InitOrthographic(f32 size, f32 nearClip, f32 farClip) override;
        void SetProjectionType(ProjectionType type) override;
		void OnUpdate(Timestep ts, const glm::vec2 &screenMin, const glm::vec2 &screenMax) override;
		void OnEvent(Event& e) override;
        void SetOrthoScale(f32 value) override;
        void SetOrthoScaleMax(f32 max) override;
		void SetViewportSize(f32 width, f32 height) override;
        void SetFov(f32 fovy) override;
        void SetNear(f32 nearClip) override;
        void SetFar(f32 farClip) override;
		void SetPosition(const glm::vec3 &position);
		void SetFocalPoint(const glm::vec3 &position);
        void SetStyle(CameraStyle style);
		void SetPitch(f32 pitch);
		void SetYaw(f32 yaw);
        bool OnMouseScroll(MouseScrolledEvent &e);
        void MousePan(const glm::vec2 &delta);
        void MouseRotate(const glm::vec2 &delta, f32 dt);
        void MouseZoom(const f32 dela);
		void SetDistance(f32 distance);
        void SetViewMatrix(const glm::mat4 &viewMatrix) override;
        f32 RotationSpeed() const;

        std::pair<f32, f32> PanSpeed() const;
        void UpdateAudioListener(Timestep ts);
        const f32 GetDistance() const { return m_Distance; }
		f32 GetZoomSpeed() const;
        const f32 GetYaw() const override { return m_Yaw; }
        const f32 GetPitch() const override { return m_Pitch; }
        const f32 GetFOV() const  override{ return m_FOV; }
        const f32 GetNear() const override { return m_NearClip; }
        const f32 GetFar() const override { return m_FarClip; }
        const f32 GetAspectRatio() const override { return m_AspectRatio; }
        const f32 GetOrthoScale() const override { return m_OrthoScale; }
        const f32 GetOrthoNear() const override { return m_OrthoNearClip; }
        const f32 GetOrthoFar() const override { return m_OrthoFarClip; }
        const bool IsPerspective() const override { return m_ProjectionType == ProjectionType::Perspective; }
		const glm::mat4 GetProjectionMatrix() const override;
		const glm::mat4 GetViewMatrix() const override;
        const glm::mat4 GetViewProjection() const override;
        const glm::vec3 GetPosition() const override;
        const glm::vec2 GetViewportSize() const override;
        const glm::vec2 GetOrthoSize() const override { return m_OrthoSize; }
        glm::vec3 GetUpDirection() const { return glm::rotate(glm::quat({ -m_Pitch, -m_Yaw, 0.0f }), { 0.0f, 1.0f, 0.0f }); }
        glm::vec3 GetRightDirection() const { return glm::rotate(glm::quat({ -m_Pitch, -m_Yaw, 0.0f }), { 1.0f, 0.0f, 0.0f }); }
        glm::vec3 GetForwardDirection() const { return glm::rotate(glm::quat({ -m_Pitch, -m_Yaw, 0.0f }), { 0.0f, 0.0f, -1.0f }); }
        const CameraStyle GetStyle() { return m_CameraStyle; }
        const ProjectionType GetProjectionType() const override { return m_ProjectionType; }

        void SetAllowedMove(bool active);

	private:
        void UpdateProjection() override;
        void UpdateView() override;
        CameraStyle m_CameraStyle = FreeMove;
        f32 m_Distance = 8.0f;
        f32 m_Pitch = 0.0f, m_Yaw = 0.0f;
        bool m_IsInViewport = false;
        bool m_AllowedMove = false;
        glm::vec3 m_Velocity = glm::vec3(0.0f);
        glm::vec2 m_LastMousePos = glm::vec2(0.0f);

        const f32 ACCELERATION = 70.0f;
        const f32 DECELERATION = 130.0f;
        const f32 MAX_SPEED = 100.0f;
	};
}

#endif