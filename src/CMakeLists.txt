add_subdirectory(metodos)
add_subdirectory(outputs)
add_subdirectory(ext)

target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
)
