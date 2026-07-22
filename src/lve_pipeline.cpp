#include "lve_pipeline.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
namespace lve {
    lvePipeline::lvePipeline(const std::string& vertFilePath, const std::string& fragFilePath) {
        createGraphicsPipeline(vertFilePath, fragFilePath);
    }

    std::vector<char> lvePipeline::readFile(const std::string& filePath) {

        std::ifstream file(filePath, std::ios::ate | std::ios::binary);
            if (!file.is_open()) {
                throw std::runtime_error("Failed to open file" + filePath);
            }
            size_t fileSize = static_cast<size_t>(file.tellg());
            std::vector<char> buffer(fileSize); //创建缓冲区

            file.seekg(0);
            file.read(buffer.data(), fileSize);

            file.close();
            return buffer;
    }

    void lvePipeline::createGraphicsPipeline(
        const std::string& vertFilePath, const std::string& fragFilePath) {
            auto vertCode = readFile(vertFilePath);
            auto fragCode = readFile(fragFilePath);

            std::cout << "Vertex Shader Code Size: " << vertCode.size() << std::endl;
            std::cout << "Fragment Shader Code Size: " << fragCode.size() << std::endl;
        }
}
