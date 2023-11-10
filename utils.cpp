// Copyright (c) 2022 tsl0922. All rights reserved.
// SPDX-License-Identifier: GPL-2.0-only

#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cstring>
#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#elif defined(__APPLE__)
#include <limits.h>
#include <sysdir.h>
#include <glob.h>
#endif
#include "utils.h"

namespace ImPlay {
    void OptionParser::parse(int argc, char** argv) {
        /*bool optEnd = false;

        int wideArgc;
        wchar_t** wideArgv = CommandLineToArgvW(GetCommandLineW(), &wideArgc);
        for (int i = 1; i < wideArgc; i++) {
            std::string arg = WideToUTF8(wideArgv[i]);

            if (arg[0] == '-' && !optEnd) {
                if (arg[1] == '\0') {
                    paths.emplace_back(arg);
                    break;
                }
                if (arg[1] == '-') {
                    if (arg[2] == '\0') {
                        optEnd = true;
                        continue;
                    }
                    else {
                        arg = arg.substr(2);
                    }
                }
                else {
                    arg = arg.substr(1);
                }
                if (arg.starts_with("no-")) {
                    if (arg[3] == '\0') continue;
                    options.emplace(arg.substr(3), "no");
                }
                else if (auto n = arg.find_first_of('='); n != std::string::npos) {
                    options.emplace(arg.substr(0, n), arg.substr(n + 1));
                }
                else {
                    options.emplace(arg, "yes");
                }
            }
            else {
                paths.emplace_back(arg);
            }
        }*/
    }

    bool OptionParser::check(std::string key, std::string value) {
        auto it = options.find(key);
        return it != options.end() && it->second == value;
    }

    bool fileExists(std::string path) {
        if (path == "") return false;
        auto fp = std::filesystem::path(reinterpret_cast<char8_t*>(path.data()));
        return std::filesystem::exists(fp);
    }

    int openUrl(std::string url) {
        return 1;
        //return ShellExecuteW(0, 0, UTF8ToWide(url).c_str(), 0, 0, SW_SHOW) > (HINSTANCE)32 ? 0 : 1;

    }

    void revealInFolder(std::string path) {
        //auto fp = std::filesystem::path(reinterpret_cast<char8_t*>(path.data()));
        //if (!std::filesystem::exists(fp)) return;

        //std::string arg = fmt::format("/select,\"{}\"", path);
        //ShellExecuteW(0, 0, L"explorer", UTF8ToWide(arg).c_str(), 0, SW_SHOW);

    }

    std::filesystem::path dataPath() {
        //std::string dataDir;

        //std::wstring path(MAX_PATH, '\0');
        //if (GetModuleFileNameW(nullptr, path.data(), path.length()) > 0) {
        //    auto dir = std::filesystem::path(path).parent_path() / "portable_config";
        //    if (std::filesystem::exists(dir) && std::filesystem::is_directory(dir)) return dir;
        //}
        //wchar_t* dir = nullptr;
        //if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_RoamingAppData, KF_FLAG_CREATE, nullptr, &dir))) {
        //    dataDir = WideToUTF8(dir);
        //    CoTaskMemFree(dir);
        //}

        //return std::filesystem::path(dataDir) / "implay";
        return std::filesystem::path("");

    }

    std::vector<std::string> split(const std::string & str, const std::string & sep) {
        std::vector<std::string> v;
        std::string::size_type pos1 = 0, pos2 = 0;
        while ((pos2 = str.find(sep, pos1)) != std::string::npos) {
            v.push_back(str.substr(pos1, pos2 - pos1));
            pos1 = pos2 + sep.size();
        }
        if (pos1 != str.length()) v.push_back(str.substr(pos1));
        return v;
    }
    }  // namespace ImPlay