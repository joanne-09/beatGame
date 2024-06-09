//
// Created by Lee Eason on 2024/6/9.
//

#include "Server.hpp"
#include<bits/stdc++.h>
#include<cstdlib>

bool Server::Upload() {
#ifdef __APPLE__
    system("./Scripts/upload");
#elif defined _WIN32
    system("dist\\windows_upload.exe");
#else
    throw std::exception("Unsupported Operating System");
#endif
    return true;
}