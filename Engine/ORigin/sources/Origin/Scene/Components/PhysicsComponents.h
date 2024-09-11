// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef PHYSICS_COMPONENTS_H
#define PHYSICS_COMPONENTS_H

#include <Jolt/Jolt.h>

#include <glm/glm.hpp>

namespace origin
{
    static JPH::Vec3 GlmToJoltVec3(const glm::vec3 &v)
    {
        return JPH::Vec3(v.x, v.y, v.z);
    }

    static glm::vec3 JoltToGlmVec3(const JPH::Vec3 &v)
    {
        return glm::vec3(v.GetX(), v.GetY(), v.GetZ());
    }

    static JPH::Quat GlmToJoltQuat(const glm::quat &q)
    {
        return JPH::Quat(q.x, q.y, q.z, q.w);
    }

    static glm::quat JoltToGlmQuat(const JPH::Quat &q)
    {
        return glm::quat(q.GetW(), q.GetX(), q.GetY(), q.GetZ());
    }

    class OGN_API RigidbodyComponent
    {
    public:

        enum EMotionQuality
        {
            Discrete = 0,
            LinearCast = 1
        };

        EMotionQuality MotionQuality = Discrete;

        bool UseGravity = true;
        bool RotateX = true, RotateY = true, RotateZ = true;
        bool MoveX = true, MoveY = true, MoveZ = true;
        bool IsStatic = false;
        f32 Mass = 1.0f;
        bool AllowSleeping = true;
        f32 GravityFactor = 1.0f;
        glm::vec3 CenterMass = { 0.0f, 0.0f, 0.0f };
        glm::vec3 Offset = { 0.0f, 0.0f, 0.0f };

        void *Body = nullptr;
        RigidbodyComponent() = default;
        RigidbodyComponent(const RigidbodyComponent &) = default;

        void AddForce(const glm::vec3 &force);
        void AddTorque(const glm::vec3 &torque);
        void AddForceAndTorque(const glm::vec3 &force, const glm::vec3 &torque);
        void AddAngularImpulse(const glm::vec3 &impulse);
        void ActivateBody();
        void DeactivateBody();
        void DestroyBody();
        bool IsActive();
        void MoveKinematic(const glm::vec3 &targetPosition, const glm::vec3 &targetRotation, f32 deltaTime);
        void AddImpulse(const glm::vec3 &impulse);
        void AddLinearVelocity(const glm::vec3 &velocity);
        void SetRestitution(f32 value);
        void SetPosition(const glm::vec3 &position, bool activate);
        void SetEulerAngleRotation(const glm::vec3 &rotation, bool activate);
        void SetRotation(const glm::quat &rotation, bool activate);
        void SetLinearVelocity(const glm::vec3 &vel);
        void SetFriction(f32 value);
        void SetGravityFactor(f32 value);
        void SetMaxLinearVelocity(f32 max);
        void SetMaxAngularVelocity(f32 max);
        void SetMass(f32 mass);
        void SetOffset(const glm::vec3 &offset);
        void SetCenterMass(const glm::vec3 &center);
        void SetSleep(bool sleep);
        f32 GetRestitution();
        f32 GetFriction();
        f32 GetGravityFactor();

        glm::vec3 GetPosition();
        glm::vec3 GetEulerAngles();
        glm::quat GetRotation();
        glm::vec3 GetCenterOfMassPosition();
        glm::vec3 GetLinearVelocity();
    };

    class OGN_API PhysicsCollider
    {
    public:
        f32 Friction = 0.6f;
        f32 Restitution = 0.6f;
        f32 Density = 1.0f;

        void *Shape = nullptr;
    };

    class OGN_API BoxColliderComponent : public PhysicsCollider
    {
    public:
        glm::vec3 Scale = { 1.0f, 1.0f, 1.0f };
        
        BoxColliderComponent() = default;
        BoxColliderComponent(const BoxColliderComponent &) = default;
    };

    class OGN_API SphereColliderComponent : public PhysicsCollider
    {
    public:
        f32 Radius = 0.5f;

        SphereColliderComponent() = default;
        SphereColliderComponent(const SphereColliderComponent &) = default;
    };

    class OGN_API CapsuleColliderComponent : public PhysicsCollider
    {
    public:
        f32 HalfHeight = 1.0f;
        f32 Radius = 0.5f;

        CapsuleColliderComponent() = default;
        CapsuleColliderComponent(const CapsuleColliderComponent &) = default;
    };
}

#endif