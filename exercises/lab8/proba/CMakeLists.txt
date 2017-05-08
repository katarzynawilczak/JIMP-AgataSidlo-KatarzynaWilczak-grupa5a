
project(proba)

set(HEDEAR_FILES Proba.h)
set(SOURCE_FILES Proba.cpp)

add_library(libproba STATIC ${SOURCE_FILES})
target_include_directories(libproba PUBLIC .)

add_executable(proba ${SOURCE_FILES} main.cpp)

target_link_libraries(proba libproba)

