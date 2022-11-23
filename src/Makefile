CXX = g++ -std=c++17 
CFLAG = -c -Wall -Werror -Wextra -fsanitize=address
GCOVFLAG = -fprofile-arcs -ftest-coverage
GTESTFLAGS = -lgtest
CPPFILE = matrix.cpp
OFILE = matrix.o

all: clean matrix.a test

matrix.o:
	$(CXX) $(CFLAG) matrix.cpp -o matrix.o

matrix.a: $(OFILE)
	ar rcs matrix.a $(OFILE)

test: matrix.a
	$(CXX) matrix.cpp test.cpp -o test $(GTESTFLAGS)
	./test

gcov_report: clean test.o
	$(CXX) $(CFLAG) $(GCOVFLAG) matrix.cpp -o matrix.o
	$(CXX) $(GCOVFLAG) $(OFILE) test.o -o gcov $(GTESTFLAGS)
	./gcov
	lcov -t "gcov_report" -o gcov_report.info -c -d ./
	genhtml -o report gcov_report.info
	open report/index-sort-f.html

clean:
	rm -rf *.a *.o test gcov *.info report *.dSYM *.gc*

check: test
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=cpp *.cpp
	python3 ../materials/linters/cpplint.py --extensions=hpp *.hpp
	cppcheck --enable=all --suppress=missingIncludeSystem *.cpp *.hpp
	CK_FORK=no leaks --atExit -- test
	rm -rf CPPLINT.cfg
