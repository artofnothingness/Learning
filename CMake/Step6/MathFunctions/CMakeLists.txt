add_library(MathFunctions 
            mysqrt.cxx
            ${CMAKE_CURRENT_BINARY_DIR}/Table.h
            )

add_executable(MakeTable MakeTable.cxx)
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
  )

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(MathFunctions
          PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
# does this system provide the log and exp functions?
# install rules
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
