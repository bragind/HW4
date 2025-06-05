cmake_minimum_required(VERSION 3.20)
project(HW4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем заголовки
include_directories(${PROJECT_SOURCE_DIR}/lib)

# Создаем статическую библиотеку из исходников
add_library(HW4 STATIC
    src/point.cpp
    src/polygon.cpp
)

# Добавляем приложение
add_executable(app app/main.cpp)

# Связываем приложение с библиотекой
target_link_libraries(app PRIVATE HW4)