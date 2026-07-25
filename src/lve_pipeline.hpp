#pragma once

#include "lve_device.hpp"

// std
#include <string>
#include <vector>

struct PipelineConfigInfo {
    VkViewport viewport;
    VkRect2D scissor;
    VkPipelineViewportStateCreateInfo viewportInfo;
    VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
    VkPipelineRasterizationStateCreateInfo rasterizationInfo;
    VkPipelineMultisampleStateCreateInfo multisampleInfo;
    VkPipelineColorBlendAttachmentState colorBlendAttachment;
    VkPipelineColorBlendStateCreateInfo colorBlendInfo;
    VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
    VkPipelineLayout pipelineLayout = nullptr;
    VkRenderPass renderPass = nullptr;
    uint32_t subpass = 0;
};

namespace lve {
    class LvePipeline {
        public:
        LvePipeline(
            LveDevice& device,
            const PipelineConfigInfo& configInfo,
            const std::string& vertFilePath,
            const std::string& fragFilePath);

        ~LvePipeline();

        // 禁止行为
        LvePipeline(const LvePipeline&) = delete; // 禁止复制构造函数
        void operator=(const LvePipeline&) = delete; // 禁止 = 直接赋值

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

        private:
            static std::vector<char> readFile(
                const std::string& filePath);

            void createGraphicsPipeline(
                const std::string& vertFilePath,
                const std::string& fragFilePath,
                const PipelineConfigInfo& configInfo);

            void createShaderModule(
                const std::vector<char>& code,
                VkShaderModule* shaderModule);

        LveDevice& lveDevice; // 逻辑设备资源比管线存在时间更久
        VkPipeline graphicsPipeline; // Vulkan 管线对象句柄
        // shader Module
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}
