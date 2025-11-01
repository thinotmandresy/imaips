#pragma once

#include "nlohmann/json.hpp"
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using json = nlohmann::json;

namespace PS {

// Reads and caches the userdata path
bool init(const std::string& stringtable_path);

// Returns the userdata path
const std::string& get_path();

// Returns userdata/AIM/persistent/shared.json
fs::path shared_path();

// Loads JSON from the specified path
json load(const fs::path& p);

// Saves JSON to the specified path
bool save(const fs::path& p, const json& j);

} // namespace PS
