BUILD:= $(LDTHW_HOME)/build
CMATRIX:= $(BUILD)/cmatrix
CMATRIX_ERROR:= $(BUILD)/cmatrix_error

$(shell mkdir -p $(BUILD))

all:
	gcc cmatrix.c

cmatrix:
	gcc cmatrix.c -o $(CMATRIX)

cmatrix_error:
	gcc cmatrix_error.c -o $(CMATRIX_ERROR)

cmatrix_error_gdb:
	gcc -g cmatrix_error.c -o $(CMATRIX_ERROR)

cmatrix_error_asan:
	gcc -fsanitize=address cmatrix_error.c -o $(CMATRIX_ERROR)

valgrind_cmatrix_error:
	valgrind $(CMATRIX_ERROR)

gdb_cmatrix_error:
	gdb $(CMATRIX_ERROR)
	
gdb_cmatrix_error_tui:
	gdb -tui $(CMATRIX_ERROR)

clean:
	rm -rf $(LDTHW_HOME)/a.out $(BUILD)

.PHONY: all clean cmatrix cmatrix_error cmatrix_error_gdb cmatrix_error_asan valgrind_cmatrix_error gdb_cmatrix_error gdb_cmatrix_error_tui
