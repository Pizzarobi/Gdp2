bin_dir=bin
build_dir=build

test_name=${bin_dir}/pa1

compiler_path=g++

compiler_flags=-std=c++20 -Wall -Wextra -I"C:\Program Files\boost_1_78_0" -D BOOST_TEST_DYN_LINK
linker_flags=-L"C:\Program Files\boost_1_78_0\stage\lib" -l:libboost_unit_test_framework-mgw11-mt-d-x64-1_78.dll -lpthread

all: debug

debug: compiler_flags+=-O0 -g
debug: complete_build

release: compiler_flags+=-Werror -O3
release: complete_build

complete_build: ${test_name}

sources=${wildcard *.cpp}
headers=${wildcard *.h}

# Generate all required paths.
compile_sources=${patsubst src/%,${build_dir}/%,${sources}}
compile_headers=${patsubst src/%,${build_dir}/%,${headers}}
compile_objects=${patsubst %.cpp,%.o,${compile_sources}}

# Link the test executable.
${test_name}: ${compile_objects}
	mkdir -p ${dir $@}
	${compiler_path} -o $@ ${compile_objects} ${compiler_flags} ${linker_flags}

# Compile any objects.
${build_dir}/%.o: ${build_dir}/%.cpp ${compile_headers}
	mkdir -p ${dir $@}
	${compiler_path} -o $@ $< -c ${compiler_flags}

# Copy files from the source directory.
${build_dir}/%: src/%
	mkdir -p ${dir $@}
	cp $< $@

clean:
	rm -rf ${bin_dir} ${build_dir}
