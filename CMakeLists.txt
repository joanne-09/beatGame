cmake_minimum_required(VERSION 3.27)
project(Beat_Game)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

file(COPY Resource/audios DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Resource/fonts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Resource/images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Resource DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY allegro_monolith-5.2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY upload.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file (COPY Database DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file (COPY Scripts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(Python REQUIRED)

add_executable(2024_I2P2_TowerDefense_with_answer
        Engine/Allegro5Exception.cpp
        Engine/Allegro5Exception.hpp
        Engine/AudioHelper.cpp
        Engine/AudioHelper.hpp
        Engine/Collider.cpp
        Engine/Collider.hpp
        Engine/GameEngine.cpp
        Engine/GameEngine.hpp
        Engine/Group.cpp
        Engine/Group.hpp
        Engine/IControl.cpp
        Engine/IControl.hpp
        Engine/IObject.cpp
        Engine/IObject.hpp
        Engine/IScene.cpp
        Engine/IScene.hpp
        Engine/LOG.cpp
        Engine/LOG.hpp
        main.cpp
        Engine/Point.cpp
        Engine/Point.hpp
        Engine/Resources.cpp
        Engine/Resources.hpp
        Engine/Sprite.cpp
        Engine/Sprite.hpp

        # TODO: [HACKATHON-1-SCENE] (2/4) Add the new scene source files here
        Engine/FileIO.cpp
        Engine/FileIO.hpp
        Scene/MainMenu.cpp
        Scene/MainMenu.hpp
        Scene/Scoreboard.cpp
        Scene/Scoreboard.hpp
        Scene/PlayScene.cpp
        Scene/PlayScene.hpp
        Scene/MusicSelection.cpp
        Scene/MusicSelection.hpp
        Scene/Settings.cpp
        Scene/Settings.hpp
        UI/Component/Image.cpp
        UI/Component/ImageButton.cpp
        UI/Component/Label.cpp
        UI/Component/InputBox.cpp
        UI/Component/Slider.cpp
        Database/Server.cpp
        Database/Server.hpp
        UI/Component/MusicBlock.cpp
        UI/Component/MusicBlock.hpp
        Engine/joanne.hpp

        #        UI/Component/TextInput.cpp
#        UI/Component/TextInput.hpp
)

IF (WIN32)
    target_include_directories(2024_I2P2_TowerDefense_with_answer PUBLIC C:/allegro/include)
    target_link_directories(2024_I2P2_TowerDefense_with_answer PUBLIC C:/allegro/lib)
    target_compile_options(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_CFLAGS_OTHER})
    target_link_libraries(2024_I2P2_TowerDefense_with_answer liballegro_monolith)
ELSE()
    find_package(PkgConfig)
    pkg_check_modules(ALLEGRO5 REQUIRED allegro-5 allegro_main-5 allegro_font-5 allegro_dialog-5 allegro_primitives-5 allegro_image-5 allegro_ttf-5 allegro_audio-5 allegro_acodec-5)
    target_include_directories(2024_I2P2_TowerDefense_with_answer PUBLIC lib)
    target_include_directories(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_INCLUDE_DIRS})
    target_compile_options(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_CFLAGS_OTHER})
    target_link_libraries(2024_I2P2_TowerDefense_with_answer ${ALLEGRO5_LIBRARIES})
    target_link_directories(2024_I2P2_TowerDefense_with_answer PUBLIC ${ALLEGRO5_LIBRARY_DIRS})
ENDIF()