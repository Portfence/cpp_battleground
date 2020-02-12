add_executable(${PROJECT_NAME}
  main.cpp
)

target_compile_features(${PROJECT_NAME}
  PRIVATE cxx_std_20
)

target_compile_options(${PROJECT_NAME}
  PRIVATE -Wall
)

target_link_libraries(${PROJECT_NAME}
  # PRIVATE MyLibrary::MyLibrary
)

set_target_properties(${PROJECT_NAME}
	PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
