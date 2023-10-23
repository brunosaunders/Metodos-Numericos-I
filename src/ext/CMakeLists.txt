add_subdirectory(fmt-10.1.0)

find_package(fmt)
target_link_libraries(${PROJECT_NAME} fmt::fmt)
