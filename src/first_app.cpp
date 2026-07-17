#include "first_app.h"

namespace lve {
    void FirstApp::run() {
        while (!lveWindow.shouldClose()) {
            glfwPollEvents(); // 只要窗口没关闭 就处理窗口事件
        }
    }
}
