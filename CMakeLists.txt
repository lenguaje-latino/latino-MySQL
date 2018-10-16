cmake_minimum_required(VERSION 3.6)
project(latino-mysql)
if (WIN32)
  set (MySQL_PATH "C:/Program Files/MySQL/MySQL Server 8.0" CACHE FILEPATH "Ruta de instalacion de MySQL")
  set (LATINO_PATH "C:/src/latino" CACHE FILEPATH "Ruta de instalacion de latino")

  include_directories(${MySQL_PATH}/include)
  include_directories(${LATINO_PATH}/include)

  link_directories(${MySQL_PATH}/lib)
  link_directories(${LATINO_PATH}/msvc/x64/Debug)
endif()
add_library(latino-mysql SHARED src/latino-mysql.c)
target_link_libraries(latino-mysql libmysql liblatino_static)
