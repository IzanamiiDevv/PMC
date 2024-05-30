#pragma once

#include <vector>

namespace PD {
    std::vector<std::vector<std::string>> read();
    void write(const std::vector<std::vector<std::string>>& data);
    void update(const std::string& project, const std::string& mode, const std::string& status);
    void removeProject(const std::string& project);
    void removeStatus(const std::string& status);
}