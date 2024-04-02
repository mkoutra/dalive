project(DAYS_ALIVE)

set(C_STANDARD 17)

add_library(days_alive days_alive.c)

add_executable(main main.c)

target_link_libraries(main days_alive)