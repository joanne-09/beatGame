//
// Created by Lee Eason on 2024/6/9.
//

#include "Server.hpp"
#include<bits/stdc++.h>
#include<cstdlib>

bool Server::Upload() {
#ifdef __APPLE__
    system("./Scripts/mac_upload");
#elif defined _WIN32
    system("start ./Scripts/windows_upload.exe");
#else
    throw std::exception("Unsupported Operating System");
#endif
    return true;
}

bool Server::Download() {
#ifdef __APPLE__
    system("./Scripts/mac_download");
#elif defined _WIN32
    system("start ./Scripts/windows_download.exe");
#else
    throw std::exception("Unsupported Operating System");
#endif
    return true;
}