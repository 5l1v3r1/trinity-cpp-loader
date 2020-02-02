// dear imgui: standalone example application for GLFW + OpenGL2, using legacy fixed pipeline
// If you are new to dear imgui, see examples/README.txt and documentation at the top of imgui.cpp.
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan graphics context creation, etc.)

// **DO NOT USE THIS CODE IF YOUR CODE/ENGINE IS USING MODERN OPENGL (SHADERS, VBO, VAO, etc.)**
// **Prefer using the code in the example_glfw_opengl2/ folder**
// See imgui_impl_glfw.cpp for details.

#include "imgui\imgui.h"
#include "imgui\imgui_impl_glfw.h"
#include "imgui\imgui_impl_opengl2.h"
#include "utils.hpp"
#include <stdio.h>
#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#endif
#include <GLFW/glfw3.h>

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char**)
{
    FreeConsole(); //hide console
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);

    if (!glfwInit())
        return 1;

    GLFWwindow* window = glfwCreateWindow(500, 300, "Your Application", NULL, NULL);
    //glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_FALSE);
    //dunno why the fucking setwindowattrib doesnt exist

    if (window == NULL)
        return 1;

    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();

    bool show_another_window = false;
    bool register_window = false;
    bool activate_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    utils::check_dlls();
    if (utils::is_dll_valid == true)
    {
        TrinitySeal::Seal::Secret = "JepGs66jhcClSk98QhqiFiBs0AGzb6I2ZlI62pTrKCytO"; //your trinity program secret
        TrinitySeal::Seal::Initialize("1.0");
    }
    else if (utils::is_dll_valid == false) 
    {
        exit(0);
    }
    bool freemode = TrinitySeal::ProgramVariables::Freemode;
    if (freemode)
    {
        // do freemode actions here
    }

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL2_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            ImGui::SetNextWindowPos(ImVec2{ 0, 0 });
            ImGui::SetNextWindowSize(ImVec2{ 500, 300 });

            static char username[128] = "";
            static char password[128] = "";

            ImGui::Begin("Login Page", 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);                          // Create a window called "Hello, world!" and append into it.

            ImGui::InputTextWithHint("##1", "username", username, IM_ARRAYSIZE(username));

            ImGui::InputTextWithHint("##2", "password", password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password | ImGuiInputTextFlags_CharsNoBlank);

            if (ImGui::Button("login")) {
                System::String^ csharp_username = gcnew System::String(utils::string_to_wstring(username).c_str());

                System::String^ csharp_password = gcnew System::String(utils::string_to_wstring(password).c_str());

                if (TrinitySeal::Seal::Login(csharp_username, csharp_password, true)) {
                    // do whatever you wanna do if youre logged in
                }
            }
            ImGui::SameLine();
            if (ImGui::Button("register page")) {
                register_window = true;
            }
            ImGui::SameLine();
            if (ImGui::Button("activate page")) {
                activate_window = true;
            }
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

            ImGui::End();
        }

        if (register_window) {
            static char username[128] = "";
            static char email[128] = "";
            static char password[128] = "";
            static char token[128] = "";

            ImGui::Begin("Register", &register_window);
            ImGui::InputTextWithHint("##1", "username", username, IM_ARRAYSIZE(username));

            ImGui::InputTextWithHint("##2", "email", email, IM_ARRAYSIZE(email));

            ImGui::InputTextWithHint("##3", "password", password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password | ImGuiInputTextFlags_CharsNoBlank);

            ImGui::InputTextWithHint("##4", "token", token, IM_ARRAYSIZE(token));

            if (ImGui::Button("register")) {

                System::String^ csharp_username = gcnew System::String(utils::string_to_wstring(username).c_str());

                System::String^ csharp_password = gcnew System::String(utils::string_to_wstring(password).c_str());

                System::String^ csharp_email = gcnew System::String(utils::string_to_wstring(email).c_str());

                System::String^ csharp_token = gcnew System::String(utils::string_to_wstring(token).c_str());

                if (TrinitySeal::Seal::Register(csharp_username, csharp_password, csharp_email, csharp_token, true)) {
                    register_window = false;
                    // you can leave this alone or put an message box i dunno
                }
            }
            ImGui::End();
        }

        if (activate_window) {
            static char username[128] = "";
            static char password[128] = "";
            static char token[128] = "";

            ImGui::Begin("Activate", &activate_window);
            ImGui::InputTextWithHint("##1", "username", username, IM_ARRAYSIZE(username));
            ImGui::Spacing();
            ImGui::InputTextWithHint("##3", "password", password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password | ImGuiInputTextFlags_CharsNoBlank);
            ImGui::Spacing();
            ImGui::InputTextWithHint("##4", "token", token, IM_ARRAYSIZE(token));
            ImGui::Spacing();
            if (ImGui::Button("activate")) {
                System::String^ csharp_username = gcnew System::String(utils::string_to_wstring(username).c_str());

                System::String^ csharp_password = gcnew System::String(utils::string_to_wstring(password).c_str());

                System::String^ csharp_token = gcnew System::String(utils::string_to_wstring(token).c_str());

                if (TrinitySeal::Seal::RedeemToken(csharp_username, csharp_password, csharp_token, true)) {
                    activate_window = false;
                    // you can leave this alone or put an message box i dunno
                }
            }
            ImGui::End();
        }

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);


        ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());


        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

