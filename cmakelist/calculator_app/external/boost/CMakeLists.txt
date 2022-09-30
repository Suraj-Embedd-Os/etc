
set(BOOST_VERSION 1.58.0)

set(Boost_USE_STATIC_LIBS FALSE)
set(Boost_USE_MULTITHREADED TRUE)
set(Boost_USE_STATIC_RUNTIME TRUE)
set(Boost_ADDITIONAL_VERSION "${BOOST_VERSION}")
set(Boost_COMPILER "-gcc")


find_package(Boots ${BOOST_VERSION} EXACT REQUIRED COMPONENTS program_option graph)

if (Boost_FOUND)
set_target_properties(Boost::boost Boost::program_option Boost::graph
					PROPERTIES IMPORTED_GLOBAL TRUE)

endif()
