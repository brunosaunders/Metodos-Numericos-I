add_subdirectory(funcoes)
add_subdirectory(metodos)
add_subdirectory(outputs)

target_sources(${PROJECT_NAME} PRIVATE
    main.cpp
)
