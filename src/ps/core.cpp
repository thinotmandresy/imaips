#include "ps/core.hpp"
#include "pugixml/pugixml.hpp"
#include "nlohmann/json.hpp"
#include <fstream>
#include <cstdlib>

namespace fs = std::filesystem;
using json = nlohmann::json;

namespace PS {

static std::string g_user_path;

bool init(const std::string& stringtable_path) {
  pugi::xml_document doc;
  if (!doc.load_file(stringtable_path.c_str())) {
    return false;
  }

  auto node = doc.select_node("/StringTable/Language/String[@symbol='cStringLuaFolder']");
  if (!node) {
    return false;
  }

  std::string folder = node.node().text().get();
  const char* profile = std::getenv("USERPROFILE");
  if (!profile) {
    return false;
  }

  fs::path p = fs::path(profile) / "Documents" / folder;
  g_user_path = p.string();
  return true;
}

const std::string& get_path() { return g_user_path; }

fs::path shared_path() {
  return fs::path(g_user_path) / "AIM" / "persistent" / "shared.json";
}

json load(const fs::path& p) {
  if (!fs::exists(p)) {
    return json::object();
  }
  std::ifstream f(p);
  if (!f) {
    return json::object();
  }
  json j;
  try { f >> j; } catch (...) { return json::object(); }
  return j;
}

bool save(const fs::path& p, const json& j) {
  fs::create_directories(p.parent_path());
  std::ofstream f(p);
  if (!f) {
    return false;
  }
  f << j.dump(4);
  return true;
}

} // namespace PS
