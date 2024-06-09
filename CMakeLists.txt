cmake_minimum_required(VERSION 3.27)
project(Beat_Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Reference/Resource)

file(COPY Reference/Resource/audios DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Reference/Resource/fonts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Reference/Resource/images DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY Reference/Resource DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY allegro_monolith-5.2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(2024_I2P2_TowerDefense_with_answer
        Engine/Allegro5Exception.cpp
        Engine/Allegro5Exception.hpp
        Engine/AudioHelper.cpp
        Engine/AudioHelper.hpp
        Reference/Bullet/Bullet.cpp
        Reference/Bullet/Bullet.hpp
        Engine/Collider.cpp
        Engine/Collider.hpp
        Reference/UI/Animation/DirtyEffect.cpp
        Reference/UI/Animation/DirtyEffect.hpp
        Reference/Enemy/Enemy.cpp
        Reference/Enemy/Enemy.hpp
        Reference/UI/Animation/ExplosionEffect.cpp
        Reference/UI/Animation/ExplosionEffect.hpp
        Reference/Bullet/FireBullet.cpp
        Reference/Bullet/FireBullet.hpp
        Engine/GameEngine.cpp
        Engine/GameEngine.hpp
        Engine/Group.cpp
        Engine/Group.hpp
        Engine/IControl.cpp
        Engine/IControl.hpp
        Reference/UI/Component/Image.cpp
        Reference/UI/Component/Image.hpp
        Reference/UI/Component/ImageButton.cpp
        Reference/UI/Component/ImageButton.hpp
        Engine/IObject.cpp
        Engine/IObject.hpp
        Engine/IScene.cpp
        Engine/IScene.hpp
        Reference/UI/Component/Label.cpp
        Reference/UI/Component/Label.hpp
        Reference/Bullet/LaserBullet.cpp
        Reference/Bullet/LaserBullet.hpp
        Reference/Turret/LaserTurret.cpp
        Reference/Turret/LaserTurret.hpp
        Engine/LOG.cpp
        Engine/LOG.hpp
        Reference/Scene/LoseScene.cpp
        Reference/Scene/LoseScene.hpp
        Reference/Turret/MachineGunTurret.cpp
        Reference/Turret/MachineGunTurret.hpp
        main.cpp
        Reference/Bullet/MissileBullet.cpp
        Reference/Bullet/MissileBullet.hpp
        Reference/Turret/MissileTurret.cpp
        Reference/Turret/MissileTurret.hpp
        Reference/UI/Animation/Plane.cpp
        Reference/UI/Animation/Plane.hpp
        Reference/Enemy/PlaneEnemy.cpp
        Reference/Enemy/PlaneEnemy.hpp
        Reference/Scene/PlayScene.cpp
        Reference/Scene/PlayScene.hpp
        Engine/Point.cpp
        Engine/Point.hpp
        Engine/Resources.cpp
        Engine/Resources.hpp
        Reference/UI/Component/Slider.cpp
        Reference/UI/Component/Slider.hpp
        Reference/Enemy/SoldierEnemy.cpp
        Reference/Enemy/SoldierEnemy.hpp
        Engine/Sprite.cpp
        Engine/Sprite.hpp
        Reference/Scene/StageSelectScene.cpp
        Reference/Scene/StageSelectScene.hpp
        Reference/Enemy/TankEnemy.cpp
        Reference/Enemy/TankEnemy.hpp
        Reference/Turret/Turret.cpp
        Reference/Turret/Turret.hpp
        Reference/Turret/TurretButton.cpp
        Reference/Turret/TurretButton.hpp
        Reference/Scene/WinScene.cpp
        Reference/Scene/WinScene.hpp

        # TODO: [HACKATHON-1-SCENE] (2/4) Add the new scene source files here
        Reference/Scene/StartScene.cpp
        Reference/Scene/StartScene.h
        Reference/Scene/SettingsScene.cpp
        Reference/Scene/SettingsScene.hpp
        Reference/Scene/ScoreBoardScene.cpp
        Reference/Scene/ScoreBoardScene.hpp
        Engine/FileIO.cpp
        Engine/FileIO.hpp
        Reference/UI/Component/InputBox.cpp
        Reference/UI/Component/InputBox.hpp
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