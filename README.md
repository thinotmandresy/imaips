<p align="center">
  <img src="image.png" />
</p>

# Improvement Mod

## AI Data Persistent Storage Plugin

This is a UHC Plugin (UPL) made specifically for the Improvement Mod in _Age of Empires III_. It enables AI scripters to persist data between game sessions using JSON (but in a very rudimentary way because XS is extremely limited).

---

## Table of Contents

1. [File Locations](#1-file-locations)
2. [Functions](#2-functions)
3. [Installation](#3-installation)
4. [TODO List](#4-todo-list)
5. [Credits & Links](#5-credits--links)
6. [License](#6-license)

---

## 1. File Locations

| Storage type | Path                                                          |
| ------------ | ------------------------------------------------------------- |
| SPS (Shared) | `My Games\AoE3 Improvement Mod\AIM\persistent\shared.json`    |
| OPS (Owned)  | `My Games\AoE3 Improvement Mod\AIM\persistent\<ai_name>.json` |

## 2. Functions

> [!WARNING]
> Please be extremely careful with shared persistent storage: your saves may be corrupted if multiple AIs write at the same time.

```cpp
// Write to shared storage
bool aiSPSSetInt(string key, int value);

// Read from shared storage
int aiSPSGetInt(string key);
```

## 3. Installation

Normally, everything is already in the mod so you don't have to do anything.
This repository is mainly for development purposes.

## 4. TODO List

- [ ] **Per-AI owned storage** (`aiOPSSetInt`, `aiOPSGetInt`, etc.)
- [ ] **Support for all (non-vector) XS data types**
- [ ] **Safety checks**
- [ ] **Delete/clear functions** (`aiSPSClear()`, `aiSPSRemoveKey()`)<sup>1</sup>

<sup>1</sup> There is intentionally no function to delete the persistent files themselves (same as the `.personality`, `.dmp.txt` and `.lxs` files)

## 5. Credits & Links

- [AoE3UnHardcoded](https://github.com/danielpereira/AoE3UnHardcoded): the original UHC Project
- [UHC2](https://eso-community.net/viewtopic.php?t=17284): a fork of UHC with more features and occasional updates
- [Improvement Mod](https://www.moddb.com/mods/improvement-mod): the mod this plugin is made for
- [pugixml](https://pugixml.org/)
- [nlohmann/json](https://json.nlohmann.me/)

## 6. License

This project is published under the [MIT License](LICENSE)
