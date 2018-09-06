# =============================================================================
# ROOT dictionary

# Normally this is not needed, but rootcling cannot see these files
# if the current source directory (which is 'PROJECTBASEDIR/testanalysis' in our case)
# is not added to the include_directories list.
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR})

set(ROOTCLING_HEADERS TestAnalysis.h
                      )

ROOT_GENERATE_DICTIONARY(G__TestAnalysis ${ROOTCLING_HEADERS} LINKDEF TestAnalysisLinkDef.h)

# =============================================================================

include_directories(${CMAKE_SOURCE_DIR})

set(SOURCE_LIB G__TestAnalysis.cxx
               TestAnalysis.cxx
               )

add_library(TestAnalysis SHARED ${SOURCE_LIB})

#target_link_libraries(TestAnalysis ${PROJECT_PREFIX}Data ${PROJECT_PREFIX}SetupConfigCppWrapper)

# ???
#set_property(TARGET TestAnalysis PROPERTY INSTALL_RPATH_USE_LINK_PATH TRUE)

install(TARGETS TestAnalysis LIBRARY DESTINATION lib)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libTestAnalysis.rootmap DESTINATION lib)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/libTestAnalysis_rdict.pcm DESTINATION lib)
