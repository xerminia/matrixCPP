CC = g++ -g -std=c++17
CFLAG = -c -Wall -Werror -Wextra
GCOVFLAG = -fprofile-arcs -ftest-coverage
GTESTFLAGS = -lgtest
CPPFILE = s21_matrix_oop.cpp
OFILE = s21_matrix_oop.o

all: clean s21_matrix_oop.a test

s21_matrix_oop.o:
	$(CC) $(CFLAG) s21_matrix_oop.cpp -o s21_matrix_oop.o

test.o:
	$(CC) $(CFLAG) test.cpp -o test.o

s21_matrix_oop.a: $(OFILE)
	ar rcs s21_matrix_oop.a $(OFILE)

test: s21_matrix_oop.a test.o
	$(CC) s21_matrix_oop.a test.o -o test $(GTESTFLAGS)
	./test

gcov_report: clean test.o
	$(CC) $(CFLAG) $(GCOVFLAG) s21_matrix_oop.cpp -o s21_matrix_oop.o
	$(CC) $(GCOVFLAG) $(OFILE) test.o -o gcov $(GTESTFLAGS)
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
