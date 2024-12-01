.PHONY: tests
build:
	cmake -S ./ -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS_DEBUG="-g -fprofile-arcs -ftest-coverage -std=c++17"
	cmake --build build

rebuild: uninstall build

uninstall:
	rm -rf build

tests:
	cd build/tests && ./tests

clean:
	rm -rf report *build*

gcov_report: tests
	mkdir -p report
	gcovr -r . --html-details -o ./report/gcov_report.html -f core/Segment3D.cc -f core/Vector3D.cc
	open ./report/gcov_report.html
