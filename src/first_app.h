#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"

namespace lve {
    class FirstApp {
        public:
            static constexpr int WIDTH = 800;
            static constexpr int HEIGHT = 600;

        void run();
        private:
            LveWindow lveWindow{WIDTH, HEIGHT, "HELLO VULKAN!"};
            LveDevice lveDevice{lveWindow};
            LvePipeline lvePipeline{lveDevice, LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT),"shader/simple_shader.vert.spv" , "shader/simple_shader.frag.spv"};
    };
}