main: functions.o gui.o history.o
	cc -o test $^
functions.o: tokenizer.h
gui.o: tokenizer.h history.h
history.o: history.h tokenizer.h
clean:
	rm -f *.o *~ *# test
