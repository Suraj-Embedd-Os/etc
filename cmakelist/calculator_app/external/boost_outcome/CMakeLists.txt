cmake_minimum_required(VERSION 2.8.10)

project(External.Reviewed_Boost.outcome)

set(VERSION 2.0)
set(DESCRIPTION "Boost.Outcome headed-only lib")

add_library(Reviewed_Boost.outcome INTERFACE
			IMPORTED GLOBAL)

target_include_directories(Reviewed_Boost.outcome PROPERTIES INTERFACE /opt/boost-outcome/include)

target_compile_features(Boost::outcome PROPERTIES INTERFACE cxx_std_14)

add_library(Boost::outcome ALIAS Reviewed_Boost.outcome )