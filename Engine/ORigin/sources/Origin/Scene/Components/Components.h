// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "Origin/Animation/Animator.h"
#include "Origin/Animation/AnimationState.h"
#include "Origin/Animation/SpriteAnimation.h"
#include "Origin/Animation/ModelAnimation.h"

#include "Origin/Audio/AudioListener.h"
#include "Origin/Math/Math.h"
#include "Origin/Core/UUID.h"
#include "Origin/Renderer/Texture.h"
#include "Origin/Renderer/Font.h"
#include "Origin/Renderer/ParticleSystem.h"
#include "Origin/Renderer/Material.h"
#include "Origin/Renderer/Framebuffer.h"
#include "Origin/Renderer/MeshVertexData.h"
#include "Origin/Renderer/VertexArray.h"
#include "Origin/Renderer/Buffer.h"

#include "Origin/Scene/Camera.h"
#include "Origin/Scene/SceneCamera.h"
#include "Origin/Scene/SpriteSheet.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/compatibility.hpp>

#include <box2d/types.h>

namespace origin
{
    class OGN_API Lighting;
    class OGN_API AudioSource;
    class OGN_API SpriteAnimation;
    class OGN_API ScriptableEntity;
    class OGN_API RigidbodyComponent;
    class OGN_API BoxColliderComponent;
    class OGN_API SphereColliderComponent;
    class OGN_API CapsuleColliderComponent;

    enum class OGN_API EntityType
    {
        Entity   = BIT(1),
        Prefabs  = BIT(2),
        Audio    = BIT(3),
        UI       = BIT(4),
        Mesh     = BIT(5),
        Bone     = BIT(6),
        Camera   = BIT(7),
        Lighting = BIT(8)
    };

    namespace Utils
    {
        static std::string EntityTypeToString(EntityType type)
        {
            switch (type)
            {
            case EntityType::Entity:   return "Entity";
            case EntityType::Prefabs:  return "Prefabs";
            case EntityType::Audio:    return "Audio";
            case EntityType::UI:       return "UI";
            case EntityType::Mesh:     return "Mesh";
            case EntityType::Bone:     return "Bone";
            case EntityType::Camera:   return "Camera";
            case EntityType::Lighting: return "Lighting";
            default:                   return "Invalid";
            }
        }

        static EntityType EntityTypeStringToType(const std::string &type)
        {
            if      ("Entity")   return EntityType::Entity;
            else if ("Prefabs")  return EntityType::Prefabs;
            else if ("Audio")    return EntityType::Audio;
            else if ("UI")       return EntityType::UI;
            else if ("Mesh")     return EntityType::Mesh;
            else if ("Bone")     return EntityType::Bone;
            else if ("Camera")   return EntityType::Camera;
            else if ("Lighting") return EntityType::Lighting;
            return (EntityType)-1;
        }
    }

    class OGN_API IDComponent
    {
    public:
        UUID ID;
        UUID Parent = UUID(0);
        EntityType Type = EntityType::Entity;

        IDComponent() = default;
        IDComponent(const IDComponent &) = default;
        IDComponent(UUID id, UUID parent = UUID(0)) : ID(id), Parent(parent) { }
    };

    class OGN_API TagComponent
    {
    public:
        std::string Tag;
        TagComponent() = default;
        TagComponent(const TagComponent &) = default;
        TagComponent(const std::string &tag) : Tag(tag)
        {
        }
    };

    class OGN_API SpriteAnimationComponent
    {
    public:
        std::shared_ptr<AnimationState<SpriteAnimation>> State;

        SpriteAnimationComponent()
        {
            State = std::make_shared<AnimationState<SpriteAnimation>>();
        }

        SpriteAnimationComponent(const SpriteAnimationComponent &) = default;
        static const AnimationType Type = AnimationType::Sprite;
    };

    class OGN_API AudioListenerComponent
    {
    public:
        AudioListener Listener;
        u32 Index = 0;
        bool Enable = true;
        AudioListenerComponent() = default;
        AudioListenerComponent(const AudioListenerComponent &) = default;
    };

    class OGN_API AudioComponent
    {
    public:
        AssetHandle Audio = UUID(0);
        std::string Name;
        f32 Volume = 1.0f;
        f32 Panning = 0.0f;
        f32 Pitch = 1.0f;
        f32 MinDistance = 10.0f;
        f32 MaxDistance = 20.0f;
        bool Spatializing = false;
        bool Looping = false;
        bool PlayAtStart = false;
        bool Overlapping = false;
        i32 OverlapCount = 10;

        AudioComponent() = default;
        AudioComponent(const AudioComponent &) = default;
    };

    class OGN_API ParticleComponent
    {
    public:
        ParticleSystem Particle;

        glm::vec3 Velocity = glm::vec3(0.0f);
        glm::vec3 VelocityVariation = glm::vec3(1.0f);
        glm::vec3 Rotation = glm::vec3(1.0f);

        glm::vec4 ColorBegin = { 254 / 255.0f, 212 / 255.0f, 123 / 255.0f, 1.0f };
        glm::vec4 ColorEnd = { 254 / 255.0f, 109 / 255.0f, 41 / 255.0f, 1.0f };
        u32 PoolIndex = 1000;

        f32 SizeBegin = 0.5f;
        f32 SizeEnd = 0.0f;
        f32 SizeVariation = 0.3f;
        f32 ZAxis = 0.0f;
        f32 LifeTime = 1.0f;

        ParticleComponent() = default;
        ParticleComponent(const ParticleComponent &) = default;
    };

    class OGN_API StaticMeshComponent
    {
    public:
        enum class OGN_API Type
        {
            Default = 0,
            Cube,
            Sphere,
            Capsule
        };

        std::string Name;
        std::shared_ptr<StaticMeshData> Data;
        AssetHandle HMaterial = UUID(0);
        AssetHandle HMesh = UUID(0);
        Type mType = Type::Default;

        StaticMeshComponent() = default;
        StaticMeshComponent(const StaticMeshComponent &) = default;
    };

    class OGN_API MeshComponent
    {
    public:
        std::string Name;
        std::shared_ptr<MeshData> Data;
        AssetHandle HMaterial = UUID(0);
        AssetHandle HMesh = UUID(0);
        f32 PlaybackSpeed = 1.0f;
        Animator AAnimator;

        MeshComponent() = default;
        MeshComponent(const MeshComponent &) = default;
    };

    class OGN_API MeshRendererComponent
    {
    public:
        std::shared_ptr<VertexArray> Va;
        AssetHandle HMaterial = UUID(0);

        MeshRendererComponent() = default;
        MeshRendererComponent(const MeshRendererComponent &) = default;
    };

    class OGN_API TextComponent
    {
    public:
        AssetHandle FontHandle = UUID(0);
        std::string TextString = "This is text component";
        glm::vec4 Color = glm::vec4(1.0f);
        glm::vec2 Size = { 0.0f, 0.0f };
        glm::vec3 Position = { 0.0f, 0.0f, 0.0f };

        f32 Kerning = 0.0f;
        f32 LineSpacing = 0.0f;
        bool ScreenSpace = false;

        TextComponent() = default;
        TextComponent(const TextComponent &) = default;
    };

    class OGN_API TransformComponent
    {
    public:
        glm::vec3 WorldTranslation = glm::vec3(0.0f);
        glm::quat WorldRotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
        glm::vec3 WorldScale = glm::vec3(1.0f);
        glm::vec3 Translation = glm::vec3(0.0f);
        glm::quat Rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
        glm::vec3 Scale = glm::vec3(1.0f);

        bool Visible = true;

        TransformComponent() = default;
        TransformComponent(const TransformComponent &) = default;

        TransformComponent(const glm::vec3 &translation)
            : Translation(translation)
        {
        }

        bool operator != (const TransformComponent &other) const
        {
            return WorldTranslation != other.Translation
                || WorldRotation != other.WorldRotation
                || WorldScale != other.WorldScale;
        }

        void SetTransform(glm::mat4 transform)
        {
            Math::DecomposeTransform(transform, WorldTranslation, WorldRotation, WorldScale);
        }

        glm::mat4 GetTransform() const
        {
            return glm::translate(glm::mat4(1.0f), WorldTranslation) * glm::toMat4(WorldRotation) * glm::scale(glm::mat4(1.0f), WorldScale);
        }

        void SetLocalTansform(glm::mat4 transform)
        {
            Math::DecomposeTransform(transform, Translation, Rotation, Scale);
        }

        glm::mat4 GetLocalTransform() const
        {
            return glm::translate(glm::mat4(1.0f), Translation) * glm::toMat4(Rotation) * glm::scale(glm::mat4(1.0f), Scale);
        }

        glm::vec3 GetForward() const
        {
            return glm::normalize(WorldRotation * glm::vec3(0.0f, 0.0f, -1.0f));
        }

        glm::vec3 GetUp() const
        {
            return glm::normalize(WorldRotation * glm::vec3(0.0f, 1.0f, 0.0f));
        }

        glm::vec3 GetRight() const
        {
            return glm::normalize(WorldRotation * glm::vec3(1.0f, 0.0f, 0.0f));
        }

        void SetForward(const glm::vec3 &forward)
        {
            glm::vec3 currentForward = GetForward();
            glm::quat rotationQuat = glm::rotation(currentForward, forward);
            WorldRotation = rotationQuat * WorldRotation;
        }

        void SetUp(const glm::vec3 &up)
        {
            glm::vec3 currentUp = GetUp();
            glm::quat rotationQuat = glm::rotation(currentUp, up);
            WorldRotation = rotationQuat * WorldRotation;
        }

        void SetRight(const glm::vec3 &right)
        {
            glm::vec3 currentRight = GetRight();
            glm::quat rotationQuat = glm::rotation(currentRight, right);
            WorldRotation = rotationQuat * WorldRotation;
        }

        void Translate(const glm::vec3 &delta)
        {
            WorldTranslation += delta;
        }

        void Rotate(const glm::quat &delta)
        {
            WorldRotation = glm::normalize(delta * WorldRotation);
        }
    };

    class OGN_API SpriteRenderer2DComponent
    {
    public:
        AssetHandle Texture = UUID(0);

        glm::vec4 Color = glm::vec4(1.0f);
        glm::vec2 Min = glm::vec2(0.0f, 0.0f);
        glm::vec2 Max = glm::vec2(1.0f, 1.0f);
        glm::vec2 TillingFactor = glm::vec2(1.0f);

        bool FlipX = false;
        bool FlipY = false;

        SpriteRenderer2DComponent() = default;
        SpriteRenderer2DComponent(const SpriteRenderer2DComponent &) = default;
        SpriteRenderer2DComponent(f32 r, f32 g, f32 b, f32 a)
            : Color(r, g, b, a)
        {
        }
    };

    class OGN_API LightComponent
    {
    public:
        std::shared_ptr<Lighting> Light;
        LightComponent() = default;
        LightComponent(const LightComponent &) = default;
    };

    class OGN_API CircleRendererComponent
    {
    public:
        glm::vec4 Color = glm::vec4(1.0f);
        f32 Thickness = 1.0f;
        f32 Fade = 0.005f;

        CircleRendererComponent() = default;
        CircleRendererComponent(const CircleRendererComponent &) = default;
    };

    class OGN_API CameraComponent
    {
    public:
        SceneCamera Camera;

        bool Primary = true;
        CameraComponent() = default;
        CameraComponent(const CameraComponent &) = default;
    };

    class OGN_API ScriptComponent
    {
    public:
        std::string ClassName = "None";
        ScriptComponent() = default;
        ScriptComponent(const ScriptComponent &) = default;
    };

    class OGN_API NativeScriptComponent
    {
    public:
        ScriptableEntity *Instance;
        ScriptableEntity *(*InstantiateScript)();

        void (*DestroyScript)(NativeScriptComponent *nsc);

        template <typename T>
        void Bind()
        {
            InstantiateScript = []() { return static_cast<ScriptableEntity *>(new T()); };
            DestroyScript = [](NativeScriptComponent *nsc)
            {
                delete nsc->Instance;
                nsc->Instance = nullptr;
            };
        }
    };

    class OGN_API Rigidbody2DComponent
    {
    public:
        void *RuntimeBody = nullptr;

        enum class OGN_API BodyType { Static = 0, Dynamic, Kinematic };
        BodyType Type = BodyType::Static;

        glm::vec2 LinearVelocity = glm::vec2(0.0f);
        f32  AngularVelocity = 0.0f;
        glm::vec2 MassCenter = glm::vec2(0.0f);

        f32 Mass = 1.0f;
        f32 LinearDamping = 0.0f;
        f32 AngularDamping = 0.01f;
        f32 RotationalInertia = 0.0f;
        f32 GravityScale = 1.0f;
        bool FixedRotation = false;
        bool EnableSleep = true;
        bool IsAwake = true;
        bool IsBullet = true;
        bool IsEnabled = true;

        b2BodyId BodyId;

        std::string ContactWith;

        Rigidbody2DComponent() = default;
        Rigidbody2DComponent(const Rigidbody2DComponent &) = default;
    };

    class OGN_API BoxCollider2DComponent
    {
    public:
        glm::vec2 Offset = { 0.0f, 0.0f };
        glm::vec2 Size = { 0.5f, 0.5f };
        glm::vec2 CurrentSize = { 0.0f, 0.0f };

        f32 Density = 1.0f;
        f32 Friction = 0.5f;
        f32 Restitution = 0.0f;
        bool IsSensor = false;

        // All fixtures with the same group index always collide (positive index)
        // or never collide(negative index)
        i32 Group = 1;
        b2ShapeId ShapeId;

        BoxCollider2DComponent() = default;
        BoxCollider2DComponent(const BoxCollider2DComponent &) = default;
    };

    class OGN_API CircleCollider2DComponent
    {
    public:

        glm::vec2 Offset = { 0.0f, 0.0f };
        f32 Radius = 0.5f;
        f32 Density = 1.0f;
        f32 Friction = 0.5f;
        f32 Restitution = 0.0f;
        bool IsSensor = false;

        // All fixtures with the same group index always collide(positive index)
        // or never collide(negative index)
        i32 Group = 1;
        b2ShapeId ShapeId;

        CircleCollider2DComponent() = default;
        CircleCollider2DComponent(const CircleCollider2DComponent &) = default;
    };

    class OGN_API RevoluteJoint2DComponent
    {
    public:
        glm::vec2 AnchorPoint = glm::vec2(0.0f);
        glm::vec2 AnchorPointB = glm::vec2(0.0f);

        // Angles in degrees 
        // (it is converted to radians when creating component)
        bool EnableLimit = false;
        bool EnableMotor = true;
        bool EnableSpring = false;
        bool CollideConnected = false;
        f32 MaxMotorTorque = 100.0f;
        f32 MotorSpeed = 0.0f;
        f32 SpringDampingRatio = 1.0f;
        f32 LowerAngle = 0.0f;
        f32 UpperAngle = 0.0f;

        UUID ConnectedBodyID = 0;
        b2JointId JointId;

        RevoluteJoint2DComponent() = default;
        RevoluteJoint2DComponent(const RevoluteJoint2DComponent &) = default;
    };

    struct BaseUIData
    {
        virtual ~BaseUIData() = default;
        enum class OGN_API Anchor
        {
            Center,
            Left, Right,
            TopLeft, TopRight,
            BottomLeft, BottomRight
        };

        std::string Name;
        Anchor AnchorType;
        TransformComponent Transform;

        BaseUIData() = default;
        BaseUIData(const std::string &name, Anchor anchorType = Anchor::Center)
            : Name(name), AnchorType(anchorType)
        {
        }

    };

    template<typename T>
    struct UIData : public BaseUIData
    {
        T Component;

        UIData() = default;
        UIData(const std::string &name, const T &component, BaseUIData::Anchor anchorType = BaseUIData::Anchor::Center)
            : BaseUIData(name, anchorType), Component(component)
        {
        }
    };

    class OGN_API UIComponent
    {
    public:
        UIComponent() = default;

        template<typename T>
        void AddComponent(const std::string &name, UIData<T> component)
        {
            component.Name = GenerateUniqueKey(name);
            Components.push_back(std::make_shared<UIData<T>>(component));
        }

        template<typename T>
        UIData<T> *GetComponent(const std::string &name)
        {
            for (auto &c : Components)
            {
                if (name == c->Name)
                    return dynamic_cast<UIData<T>*>(c.get());
            }
            return nullptr;
        }

        bool RenameComponent(i32 index, const std::string &newName)
        {
            if (newName.empty())
                return false;

            bool foundSameName = false;
            for (auto &d : Components)
            {
                foundSameName = d->Name == newName;
                if (foundSameName)
                    break;
            }

            if (foundSameName)
            {
                Components[index]->Name = GenerateUniqueKey(newName);
            }
            else
            {
                Components[index]->Name = newName;
            }

            return true;
        }

        void RemoveComponent(i32 index)
        {
            Components.erase(Components.begin() + index);
        }

        std::vector<std::shared_ptr<BaseUIData>> Components;
        std::unordered_map<std::string, i32> ComponentCounters;
        std::shared_ptr<Framebuffer> OFramebuffer;

    private:
        std::string GenerateUniqueKey(const std::string &name)
        {
            // check if the name already exists
            bool found = false;
            for (auto &c : Components)
            {
                if (c->Name == name)
                {
                    found = true;
                    break;
                }
            }

            // if the name does not exist, return it as the unique key
            if (!found)
                return name;

            // generate a unique key if the name already exists
            i32 counter = 1;
            std::string uniqueKey;
            bool unique = false;

            while (!unique)
            {
                uniqueKey = name + std::to_string(counter);
                unique = true;
                for (auto &c : Components)
                {
                    if (c->Name == uniqueKey)
                    {
                        unique = false;
                        break;
                    }
                }
                counter++;
            }

            // update the counter to reflect the highest number used
            ComponentCounters[name] = counter - 1;

            // clean up counters for names that no longer exist in Components
            for (auto it = ComponentCounters.begin(); it != ComponentCounters.end();)
            {
                bool exists = false;
                for (auto &c : Components)
                {
                    if (c->Name.find(it->first) == 0)
                    {
                        exists = true;
                        break;
                    }
                }

                if (!exists)
                    it = ComponentCounters.erase(it);
                else
                    ++it;
            }

            return uniqueKey;
        }
    };

    template <typename... Component>
    struct ComponentGroup
    {
    };

    using AllComponents = ComponentGroup <
        TransformComponent,
        CameraComponent,
        UIComponent,
        SpriteAnimationComponent,
        AudioComponent,
        AudioListenerComponent,
        LightComponent,
        SpriteRenderer2DComponent,
        StaticMeshComponent,
        MeshComponent,
        MeshRendererComponent,
        TextComponent,
        CircleRendererComponent,
        ParticleComponent,
        ScriptComponent,
        NativeScriptComponent,
        Rigidbody2DComponent,
        BoxCollider2DComponent,
        CircleCollider2DComponent,
        RevoluteJoint2DComponent,
        RigidbodyComponent,
        BoxColliderComponent,
        SphereColliderComponent,
        CapsuleColliderComponent>;
}

#endif
