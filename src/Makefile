CC = g++ -g -std=c++17
CFILE = -c -Wall -Werror -Wextra
GCOVFLAG = -fprofile-arcs -ftest-coverage
GTESTFLAGS = -lgtest
CPPFILE = s21_matrix_operation.cpp s21_matrix_oop.cpp s21_matrix_operator.cpp s21_matrix_sub_function.cpp
OFILE = s21_matrix_operation.o s21_matrix_oop.o s21_matrix_operator.o s21_matrix_sub_function.o

all: clean s21_matrix_oop.a

s21_matrix_operation.o:
	$(CC) $(CFILE) s21_matrix_operation.cpp -o s21_matrix_operation.o

s21_matrix_oop.o:
	$(CC) $(CFILE) s21_matrix_oop.cpp -o s21_matrix_oop.o

s21_matrix_operator.o:
	$(CC) $(CFILE) s21_matrix_operator.cpp -o s21_matrix_operator.o

s21_matrix_sub_function.o:
	$(CC) $(CFILE) s21_matrix_sub_function.cpp -o s21_matrix_sub_function.o

test.o:
	$(CC) $(CFILE) test.cpp -o test.o

s21_matrix_oop.a: $(OFILE)
	ar rcs s21_matrix_oop.a $(OFILE)

clean:
	rm -rf *.a *.o
