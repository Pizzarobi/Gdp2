bin_dir=bin
build_dir=build

exectuable_name=${bin_dir}/excercise_4

compiler_path=g++

compiler_flags=-std=c++20 -Wall -Wextra
linker_flags=

all: ${exectuable_name}

debug: compiler_flags+=-O0 -g
debug: ${exectuable_name}

release: compiler_flags+=-Werror -O3
release: ${exectuable_name}

sources=${wildcard ./src/*.cpp}
objects=${patsubst %.cpp,${build_dir}/%.o,${sources}}

${exectuable_name}: ${objects}
	mkdir -p ${dir $@}
	${compiler_path} -o $@ $? ${compiler_flags} ${linker_flags}

${build_dir}/%.o: %.cpp
	mkdir -p ${dir $@}
	${compiler_path} -o $@ $< -c ${compiler_flags}

clean:
	rm -rf ${bin_dir} ${build_dir}
