add_executable(${PROJECT_NAME}
  main.cpp
)

target_compile_features(${PROJECT_NAME}
  PRIVATE cxx_std_20
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE fmt::fmt-header-only
)

set_target_properties(${PROJECT_NAME}
	PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
