add_subdirectory(funcoes)
add_subdirectory(metodos)

target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
)
