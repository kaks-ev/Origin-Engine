﻿// Copyright (c) 2022 Evangelion Manuhutu | ORigin Engine

#pragma once
#include <Origin.h>
#include "Panels/Dockspace.h"
#include "Panels/SceneHierarchyPanel.h"
#include "Panels/ContentBrowserPanel.h"

#include <ImGuizmo.h>
#include <ImSequencer.h>

namespace origin {

  class EditorLayer : public Layer
  {
  private:
    Entity m_HoveredEntity = {};
    Entity m_SelectedEntity = {};

    // Scene
    enum class SceneState
    {
      Edit = 0,
      Play = 1,
      Simulate = 2
    };

    SceneState m_SceneState = SceneState::Edit;
    std::filesystem::path m_ScenePath, m_ProjectPath;
    std::shared_ptr<Scene> m_ActiveScene, m_EditorScene;

    glm::vec4 m_GridColor = glm::vec4(0.8f, 0.8f, 0.8f, 0.31f);
    int m_GridSize = 10;

    // panels
    Dockspace m_Dockspace;
    SceneHierarchyPanel m_SceneHierarchy;
    std::shared_ptr<Texture2D> m_PlayButton, m_SimulateButton, m_StopButton, m_PauseButton, m_SteppingButton;
    EditorCamera m_EditorCamera;
    ShaderLibrary m_ShaderLibrary;
    std::shared_ptr<Framebuffer> m_Framebuffer, m_GameFramebuffer;

    enum ViewportMenuContext { CreateMenu = 0, EntityProperties = 1 };
    ViewportMenuContext m_VpMenuContext = ViewportMenuContext::CreateMenu;
    bool VpMenuContextActive;
    std::unique_ptr<ContentBrowserPanel> m_ContentBrowser;

    glm::vec4 clearColor = glm::vec4(0.1f, 0.1f, 0.1f, 1.0f);
    glm::vec2 m_GameViewportSize = { 0.0f, 0.0f };
    glm::vec2 m_GameViewportBounds[2] = { glm::vec2(0.0f), glm::vec2(0.0f) };

    // Scene Viewport
    glm::vec2 m_SceneViewportSize = { 0.0f, 0.0f };
    glm::vec2 m_SceneViewportBounds[2] = { glm::vec2(0.0f), glm::vec2(0.0f) };
    glm::vec3 cameraPosition = {};

    int lastMouseX = 0, mouseX = 0;
    int lastMouseY = 0, mouseY = 0;
    int m_GizmosType = -1;
    int m_GizmosMode = 0;
    int m_PixelData = -1;
    int m_RenderTarget = 0;

    float cameraYaw = 0.0f, cameraPitch = 0.0f;
    float m_Time = 0.0f;

    bool drawLineMode = false;
    bool m_VisualizeCollider = true;
    bool m_SceneViewportHovered;
    bool m_SceneViewportFocused;

    float RMHoldTime = 0.0f;
    float LMHoldTime = 0.0f;

  public:
    bool guiDockingSpaceOpen = true;
    bool guiMenuFullscreen = false;
    bool guiMenuStyle = false;
    bool guiPrompt = false;
    bool guiRenderStatusWindow = true;
    bool guiDebugInfo = true;
    bool guiImGuiDemoWindow = false;
    bool guiOverlay = true;

    // Audio
    bool guiAudioLibraryWindow = false;
    bool guiAudioCreationWindow = false;

    // Animation
    bool guiAnimationWindow = true;

  public:
    EditorLayer();
    ~EditorLayer();

    void OnAttach() override;
    void OnUpdate(Timestep ts) override;

    inline static EditorLayer& Get() { return *s_Instance; }
    
    SceneHierarchyPanel& GetSceneHierarchy() { return m_SceneHierarchy; }

  private:
    static EditorLayer* s_Instance;
    float m_CameraFov = 45.0f;

    // Scene Viewport
  	void SceneViewport();
    void SceneViewportToolbar();
    void SceneViewportMenu();
    void OverlayBeginScene();

    bool NewProject();
    bool OpenProject();
    bool OpenProject(const std::filesystem::path& path);
    void SaveProject();

	  void MenuBar();

    void NewScene();
    void SaveScene();
    void SaveSceneAs();
    void OpenScene();
    void OpenScene(AssetHandle handle);

    void SerializeScene(std::shared_ptr<Scene>& scene, const std::filesystem::path& scenePath);

    void OnDuplicateEntity();
    void OnOverlayRenderer();

    bool OnWindowDrop(WindowDropEvent& e);
    bool OnWindowResize(WindowResizeEvent& e);
    bool OnMouseMovedEvent(MouseMovedEvent& e);
    bool OnMouseButtonEvent(MouseButtonEvent& e);

    void OnEvent(Event& e) override;
    bool OnKeyPressed(KeyPressedEvent& e);
    bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
    void InputProcedure(Timestep time);
    void OnGuiRender() override;

    void OnScenePlay();
    void OnScenePause();
    void OnSceneSimulate();
    void OnSceneStop();

    void GUIRender();
  };
}