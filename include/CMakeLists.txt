add_subdirectory(exceptions)

target_sources(${PROJECT_NAME} PRIVATE
    Painel.hpp
    Tabela.hpp
    Utils.hpp
    Metodo.hpp
    Gauss.hpp
    GaussJordan.hpp
    Cramer.hpp
)
