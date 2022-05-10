CC = g++ -g -std=c++17
CFLAG = -c -Wall -Werror -Wextra
GCOVFLAG = -fprofile-arcs -ftest-coverage
GTESTFLAGS = -lgtest
CPPFILE = s21_matrix_operation.cpp s21_matrix_oop.cpp s21_matrix_operator.cpp s21_matrix_sub_function.cpp
OFILE = s21_matrix_operation.o s21_matrix_oop.o s21_matrix_operator.o s21_matrix_sub_function.o

all: clean s21_matrix_oop.a test

s21_matrix_operation.o:
	$(CC) $(CFLAG) s21_matrix_operation.cpp -o s21_matrix_operation.o

s21_matrix_oop.o:
	$(CC) $(CFLAG) s21_matrix_oop.cpp -o s21_matrix_oop.o

s21_matrix_operator.o:
	$(CC) $(CFLAG) s21_matrix_operator.cpp -o s21_matrix_operator.o

s21_matrix_sub_function.o:
	$(CC) $(CFLAG) s21_matrix_sub_function.cpp -o s21_matrix_sub_function.o

test.o:
	$(CC) -c test.cpp -o test.o

s21_matrix_oop.a: $(OFILE)
	ar rcs s21_matrix_oop.a $(OFILE)

test: s21_matrix_oop.a test.o
	$(CC) s21_matrix_oop.a test.o -o test $(GTESTFLAGS)
	./test

gcov_report: $(OFILE)
	$(CC) $(GCOVFLAG) $(OFILE) test.cpp -o gcov $(GTESTFLAGS)
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
	CK_FORK=no leaks --atExit -- ./test
	rm -rf CPPLINT.cfg
