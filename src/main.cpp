//
// Created by Virusbear on 25.06.2022.
//

#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "Nodes/Node.h"

void ShowDockSpace(bool *open);

void initImgui(GLFWwindow *window) {
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    io.Fonts->AddFontDefault();
    io.Fonts->AddFontFromFileTTF("../assets/fonts/roboto/Roboto-Regular.ttf", 14);

    ImGui_ImplGlfw_InitForOpenGL((GLFWwindow *) window, true);
    ImGui_ImplOpenGL3_Init("#version 430");
}

void updateWindow() {
    static CubiLight::Port *test = nullptr;
    static bool open = true;
    ImGui::Begin("Woohoooo!", &open);
    static bool checked;

    if(ImGui::Checkbox("There it is!", &checked)) {
        std::cout << "never change a running system" << std::endl;
    }

    if(checked) {
        ImGui::Text("Never change a running system");
    }

    ImGui::End();
}

void updateImGui() {
    bool show = true;
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGuiIO& io = ImGui::GetIO();

    ShowDockSpace(&show);

    updateWindow();

    ImGui::Render();

    if(io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
        GLFWwindow *ctx = glfwGetCurrentContext();
        ImGui::UpdatePlatformWindows();
        ImGui::RenderPlatformWindowsDefault();
        glfwMakeContextCurrent(ctx);
    }
}

int main() {
    if(!glfwInit()) {
        exit(1);
    }

    auto window = glfwCreateWindow(900, 600, "test", nullptr, nullptr);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

    initImgui(window);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        updateImGui();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

void ShowDockSpace(bool *open) {
    static bool opt_fullscreen_persistent = true;
    bool opt_fullscreen = opt_fullscreen_persistent;
    static ImGuiDockNodeFlags  dockspace_flags = ImGuiDockNodeFlags_None;

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if(opt_fullscreen) {
        ImGuiViewport *viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);

        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }

    if(dockspace_flags / ImGuiDockNodeFlags_PassthruCentralNode) {
        window_flags |= ImGuiWindowFlags_NoBackground;
    }

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("###DockSpace", open, window_flags);
    ImGui::PopStyleVar();

    if (opt_fullscreen)
        ImGui::PopStyleVar(2);

    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    } else {
        //ShowDockingDisabledMessage();
    }

    ImGui::End();
}
