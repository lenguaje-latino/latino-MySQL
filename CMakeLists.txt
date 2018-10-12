project(latino-mysql)

add_library(latino-mysql SHARED src/latino-mysql.c)

target_link_libraries(latino-mysql libmysql latino)
